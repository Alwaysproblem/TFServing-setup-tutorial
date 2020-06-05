package main

import (
	"strconv"
	// "encoding/binary"
	"bufio"
	"fmt"
	"github.com/bigchange/go-pro/my_demo/badgerdb"
	"github.com/dgraph-io/badger"
	"io"
	"io/ioutil"
	"log"
	"math"
	"net/http"
	"os"
	"reflect"
	"strings"
	"sync"
	"testing"
	"time"

	"errors"
	"github.com/bigchange/go-pro/my_demo/utils"
	// ldb "github.com/bigchange/go-pro/myproject/leveldb"
	"github.com/bigchange/go-pro/my_demo/example"
	"math/rand"
)

func TestSpeed() {
	InitDB()
	db := badgerdb.GetDB()
	defer db.Close()
	start := (time.Now().Unix())
	var total = 1000000
	var sst string
	for i := 0; i < 57; i++ {
		sst += "v"
	}
	addcount := 0
	txn := db.NewTransaction(true)
	batch := 0
	for i := 0; i < total; i++ {
		batch = batch + 1
		txn.Set([]byte(strconv.Itoa(rand.Intn(total))+"333333333"), []byte(strconv.Itoa(rand.Intn(total))+sst))
		if batch >= 10000 {
			err := txn.Commit(nil)
			if err != nil {
				println("1 error:" + err.Error())
			}
			txn = db.NewTransaction(true)
			batch = 0
		}
		addcount++
	}
	if batch > 0 {
		err := txn.Commit(nil)
		if err != nil {
			println("2 error:" + err.Error())
		}
	}
	println(addcount)
	stop := time.Now().Unix()
	println(stop - start)
}

func main() {
	// ldb.TestBatchWrite()
	// rdb.TestRocksDB()
	TestSpeed()
}

func InitDB() {
	config := &utils.LLBConfig{
		BadgerDir: "./data/db"}
	badgerdb.InitBadgerDB(config)
}
func checkError(msg string, err error) {
	if err != nil {
		log.Println(msg, err.Error())
	}
}
func int64ToBytes(i int64) []byte {
	return []byte(string(strconv.FormatInt(i, 10)))
}

func bytesToInt64(b []byte) int64 {
	res, _ := strconv.ParseInt(string(b), 10, 64)
	return res
}

// Merge function to add two uint64 numbers
func addIntValue(existing, new []byte) []byte {
	existInt, _ := strconv.ParseInt(string(existing), 10, 64)
	newInt, _ := strconv.ParseInt(string(new), 10, 64)
	ret := strconv.FormatInt(existInt+newInt, 10)
	return []byte(ret)
}

// command run: go test
func TestUpdateBadgerDB(t *testing.T) {
	InitDB()
	db := badgerdb.GetDB()
	defer db.Close()
	err := db.Update(func(txn *badger.Txn) error {
		for i := 1; i < 10; i++ {
			key := fmt.Sprintf("answer%v", i)
			value := fmt.Sprintf("4%v", i)
			err := txn.Set([]byte(key), []byte(value))
			if err != nil {
				return err
			}
		}
		return nil
	})
	checkError("update error", err)
}

func SetDBValue(key string, value interface{}, txn *badger.Txn) {
	// Use the transaction...
	if val, ok := value.(string); ok {
		err := txn.Set([]byte(key), []byte(val))
		if err != nil {
			return
		} else {
			log.Println("set key:", key, ",db value:", value)
		}
	} else if val, ok := value.(int64); ok {
		err := txn.Set([]byte(key), int64ToBytes(val))
		if err != nil {
			return
		} else {
			fmt.Printf("set key: %s, value:%v, con:%v\n", key, value, bytesToInt64(int64ToBytes(val)))
		}
	}
}
func TestSetBadgerDB(t *testing.T) {
	// test manage txn by self
	InitDB()
	db := badgerdb.GetDB()
	txn := db.NewTransaction(true)
	defer txn.Discard()
	defer db.Close()
	// var v2 uint64 = 0
	SetDBValue("answer", strconv.FormatUint(40, 10), txn)
	SetDBValue("answers", "4", txn)
	SetDBValue("merge", strconv.FormatUint(100, 10), txn)
	// Commit the transaction and check for error.
	if err := txn.Commit(nil); err != nil {
		checkError("commit error", err)
		return
	}
}

func GetDBValue(key string, txn *badger.Txn) {
	item, err := txn.Get([]byte(key))
	if err != nil {
		log.Println("err", err.Error())
	}
	val, err := item.Value()
	checkError("get error", err)
	fmt.Printf("get key: %s, value:%s\n", key, string(val))
}
func TestGetBadgerDB(t *testing.T) {
	InitDB()
	// test manage txn by self
	db := badgerdb.GetDB()
	txn := db.NewTransaction(true)
	defer db.Close()
	defer txn.Discard()
	GetDBValue("answer", txn)
	GetDBValue("answers", txn)
	GetDBValue("merge", txn)
	GetDBValue("answer1", txn)
	err := db.View(func(txn *badger.Txn) error {
		for i := 1; i < 10; i++ {
			key := fmt.Sprintf("answer%v", i)
			item, err := txn.Get([]byte(key))
			if err != nil {
				return err
			}
			val, err := item.Value()
			if err != nil {
				return err
			}
			fmt.Printf("key: %s, view value:%s\n", key, string(val))
		}
		return nil
	})
	checkError("view error", err)
}

// confuse mergerOperator
func TestMergeOperator(t *testing.T) {
	InitDB()
	key := "answer"
	db := badgerdb.GetDB()
	m := db.GetMergeOperator([]byte(key), addIntValue, 2000*time.Millisecond)
	defer m.Stop()
	m.Add([]byte("1"))
	m.Add([]byte("2"))
	m.Add([]byte("3"))
	res, err := m.Get()
	if err != nil {
		log.Println("MergeOperator error:", err.Error())
		return
	} else {
		result, _ := strconv.ParseUint(string(res), 10, 64)
		log.Println("Merge:", result)
	}
}

func TestReflect(t *testing.T) {
	var x float64 = 3.4
	fmt.Printf("Reflect value is %v \n", x)
	p := reflect.ValueOf(&x)
	v := p.Elem()
	v.SetFloat(7.1)
	fmt.Printf("Reflect value is %v \n", x)
}

// defer

func testDefer() {
	for i := 0; i < 5; i++ {
		defer fmt.Printf("%d ", i)
		fmt.Printf("index - %v \n", i)
	}
}

// web 爬虫:
// 修改 Crawl 函数来并行的抓取 URLs，并且保证不重复。
// 提示：你可以用一个 map 来缓存已经获取的 URL，但是需要注意 map 本身并不是并发安全的！

type UrlMap struct {
	urls map[string]interface{}
	mux  sync.Mutex
}

var urlMap = &UrlMap{urls: make(map[string]interface{})}

type Fetcher interface {
	// Fetch 返回 URL 的 body 内容，并且将在这个页面上找到的 URL 放到一个 slice 中。
	Fetch(url string) (body string, urls []string, err error)
}

func dedupCrawlUrl(urlMap *UrlMap, url string, body string) error {
	urlMap.mux.Lock()
	if _, ok := urlMap.urls[url]; ok {
		fmt.Printf("already crawl url -> %v\n", url)
		urlMap.mux.Unlock()
		return errors.New("exits url dont need to crawl")
	} else {
		urlMap.urls[url] = body
		urlMap.mux.Unlock()
		return nil
	}

}

// Crawl 使用 fetcher 从某个 URL 开始递归的爬取页面，直到达到最大深度。
func Crawl(url string, depth int, fetcher Fetcher) {
	// TODO: 并行的抓取 URL。
	// TODO: 不重复抓取页面。
	// 下面并没有实现上面两种情况：
	if depth <= 0 {
		fmt.Printf("depth over\n")
		return
	}

	error := dedupCrawlUrl(urlMap, url, "exist")
	if error != nil {
		return
	}

	body, urls, err := fetcher.Fetch(url)
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Printf("found: %s %q\n", url, body)
	for _, u := range urls {
		Crawl(u, depth-1, fetcher)
	}
	return
}

// fakeFetcher 是返回若干结果的 Fetcher。
type fakeFetcher map[string]*fakeResult

type fakeResult struct {
	body string
	urls []string
}

func (f fakeFetcher) Fetch(url string) (string, []string, error) {
	if res, ok := f[url]; ok {
		return res.body, res.urls, nil
	}
	return "", nil, fmt.Errorf("not found: %s", url)
}

// fetcher 是填充后的 fakeFetcher。
var fetcher = fakeFetcher{
	"http://golang.org/": &fakeResult{
		"The Go Programming Language",
		[]string{
			"http://golang.org/pkg/",
			"http://golang.org/cmd/",
		},
	},
	"http://golang.org/pkg/": &fakeResult{
		"Packages",
		[]string{
			"http://golang.org/",
			"http://golang.org/cmd/",
			"http://golang.org/pkg/fmt/",
			"http://golang.org/pkg/os/",
		},
	},
	"http://golang.org/pkg/fmt/": &fakeResult{
		"Package fmt",
		[]string{
			"http://golang.org/",
			"http://golang.org/pkg/",
			"http://golang.org/pkg/cjyou/",
		},
	},
	"http://golang.org/pkg/os/": &fakeResult{
		"Package os",
		[]string{
			"http://golang.org/",
			"http://golang.org/pkg/",
		},
	},
	"http://golang.org/pkg/cjyou/": &fakeResult{
		"Package cjyou",
		[]string{
			"http://golang.org/",
			"http://golang.org/pkg/",
			"http://golang.org/cmd/",
		},
	},
}

func testCrawl() {
	Crawl("http://golang.org/", 4, fetcher)
}

// sync.Mutex : 互斥锁
// SafeCounter 的并发使用是安全的。
type SafeCounter struct {
	v   map[string]int
	mux sync.Mutex
}

// Inc 增加给定 key 的计数器的值。
func (c *SafeCounter) Inc(key string) {
	c.mux.Lock()
	// Lock 之后同一时刻只有一个 goroutine 能访问 c.v
	c.v[key]++
	c.mux.Unlock()
}

// Value 返回给定 key 的计数器的当前值。
func (c *SafeCounter) Value(key string) int {
	c.mux.Lock()
	// Lock 之后同一时刻只有一个 goroutine 能访问 c.v
	defer c.mux.Unlock()
	return c.v[key]
}

func testMutex() {
	c := SafeCounter{v: make(map[string]int)}
	for i := 0; i < 1000; i++ {
		go c.Inc("somekey")
	}

	time.Sleep(time.Second)
	fmt.Println(c.Value("somekey"))
}

// 等价二叉树
type Tree struct {
	Left  *Tree
	Value int
	Right *Tree
}

// Walk 步进 tree t 将所有的值从 tree 发送到 channel ch。
func Walk(t *Tree, ch chan int) {
	return
}

// Same 检测树 t1 和 t2 是否含有相同的值。
func Same(t1, t2 *Tree) bool {
	return false
}

// select: select 会阻塞，直到条件分支中的某个可以继续执行，这时就会执行那个条件分支。当多个都准备好的时候，会随机选择一个。
func fibonacciInSelect(c, quit chan int) {
	x, y := 0, 1
	for {
		select {
		case c <- x:
			x, y = y, x+y
		case <-quit:
			fmt.Println("quit")
			return
		default:
			fmt.Println("default")
		}
	}
}

func testSelect() {
	c := make(chan int)
	quit := make(chan int)
	go func() {
		for i := 0; i < 10; i++ {
			fmt.Println(<-c)
		}
		quit <- 0
	}()
	fibonacciInSelect(c, quit)
}

// 关闭管道
func fibonacciInChannel(n int, c chan int) {
	x, y := 0, 1
	for i := 0; i < n; i++ {
		c <- x
		x, y = y, x+y
	}
	close(c)
}

func testCloseChannel() {
	c := make(chan int, 10)
	go fibonacciInChannel(cap(c), c)
	for i := range c {
		fmt.Println(i)
	}
}

// 管道:channel 是有类型的管道，可以用 channel 操作符 <- 对其发送或者接收值。
// ch := make(chan int)
func sum(a []int, c chan int) {
	sum := 0
	for _, v := range a {
		sum += v
	}
	c <- sum // 将和送入 c
}

func testChannel() {
	a := []int{7, 2, 8, -9, 4, 0}

	c := make(chan int)
	go sum(a[:len(a)/2], c)
	go sum(a[len(a)/2:], c)
	x, y := <-c, <-c // 从 c 中获取

	fmt.Println(x, y, x+y)
}

// 线程: go f(x, y, z)
func say(s string) {
	for i := 0; i < 5; i++ {
		time.Sleep(100 * time.Millisecond)
		fmt.Println(s)
	}
}

func runThread() {
	go say("world")
	say("hello")
}

// image.NewNRGBA(image.Rect(0, 0, 100, 100))

type MyError struct {
	When time.Time
	What string
}

func (e *MyError) Error() string {
	return fmt.Sprintf("at %v, %s",
		e.When, e.What)
}

func run() error {
	return &MyError{
		time.Now(),
		"it didn't work",
	}
}

type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("cannot Sqrt negative number: %v", float64(e))
}

func Sqrt(x float64) (float64, error) {
	if x < 0 {
		return 0, ErrNegativeSqrt(x) // 类型强制装换
	}
	return 0, nil
}

// test error
func testError() {
	if err := run(); err != nil {
		fmt.Println(err)
	}
	fmt.Println(Sqrt(-2))
}

type IPAddr [4]byte

// TODO: Add a "String() string" method to IPAddr.
// 让 IPAddr 类型实现 fmt.Stringer 以便用点分格式输出地址
// Stringer 是一个可以用字符串描述自己的类型。
func (a IPAddr) String() string {
	return fmt.Sprintf("%v.%v.%v.%v", a[0], a[1], a[2], a[3])
}

func testStringer() {
	addrs := map[string]IPAddr{
		"loopback":  {127, 0, 0, 1},
		"googleDNS": {8, 8, 8, 8},
	}
	for n, a := range addrs {
		fmt.Printf("%v: %v\n", n, a)
	}
}

// 接口类型是由一组方法定义的集合
type Abser interface {
	AbsIm() float64
}

// 实现接口：AbsIm()
func (f MyFloat) AbsIm() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

func testInterface() {
	var a Abser
	f := MyFloat(-math.Sqrt2)
	a = f
	fmt.Println(a.AbsIm())
	fmt.Println(f.AbsIm())
}

// 你可以对包中的 任意 类型定义任意方法，而不仅仅是针对结构体。
type MyFloat float64

func (f MyFloat) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

type Point struct {
	X, Y float64
}

// go 没有类，但可以在结构体类型上定义方法 方法：方法接收者 出现在 func 关键字和方法名之间的参数中。
// 有两个原因需要使用指针接收者。首先避免在每个方法调用中拷贝值（如果值类型是大的结构体的话会更有效率）。其次，方法可以修改接收者指向的值。
func (p *Point) Distance(p1 Point) float64 {
	return math.Sqrt(p.X*p1.X + p.Y*p1.Y)
}

func testMethod() {
	p := &Point{3, 4}
	p2 := *p
	fmt.Println(p.Distance(p2))
}

func testFibonacci() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}

// fibonacci 函数会返回一个返回 int 的函数。
// 函数 fibonacci 返回一个闭包。每个返回的闭包都被绑定到其各自的 sum 变量上
func fibonacci() func() int {
	var i = 1
	var j = 1
	var sum = 0
	return func() int {
		sum := sum + i
		var tmp = i
		i = j
		j = i + tmp
		return sum
	}
}

// http handler
func helloHandler(writer http.ResponseWriter, r *http.Request) {
	key := r.FormValue("key")
	value := r.FormValue("value")
	if key == "" || value == "" {
		fmt.Fprint(writer, "no param")
		return
	} else {
		fmt.Printf("key=%s,value=%s\n", key, value)
		io.WriteString(writer, "hello, world!!")
	}
}

// ioutil
func readFile(fileName string) (err error) {
	data, err := ioutil.ReadFile(fileName)

	if err == nil {
		var content = string(data)
		fmt.Printf("content -> %s", content)
	}
	return err

}

var dictMap = make(map[string]string, 2)

func readLineByLine(fileName string) (error error) {

	f, err := os.Open(fileName)
	if err != nil {
		return err
	}

	defer f.Close()

	reader := bufio.NewReader(f)

	for {
		line, _, err := reader.ReadLine()

		if err != nil {
			if err == io.EOF {
				return nil
			}
			return err
		}

		var lineContent = string(line)
		fmt.Printf("line content -> %s\n", lineContent)

		var sp []string = strings.Split(lineContent, "\t")

		fmt.Println("sp[0]", sp[0])

		dictMap[sp[0]] = sp[1]

	}

	return err

}

func test() {
	// 正常情况
	if result, errorMsg := example.Divide(100, 10); errorMsg == "" {
		fmt.Println("100/10 = ", result)
	}
	// 当被除数为零的时候会返回错误信息
	if _, errorMsg := example.Divide(100, 0); errorMsg != "" {
		fmt.Println("errorMsg is: ", errorMsg)
	}

	fmt.Printf("listen port:%d...\n", 12345)

	readFile("/Users/devops/workspace/go-pro/go-example/text")

	err := readLineByLine("/Users/devops/workspace/go-pro/go-example/text")

	// 读取文件成功返回
	if err == nil {
		fmt.Println("length map -> ", len(dictMap))
		for key := range dictMap {
			fmt.Println("map item -> " + dictMap[key])
		}
		fmt.Printf("read success")
	}
	var resumeInffo = example.NewResume("CJYOU", "188", "SH")

	fmt.Println("info: name -> " + resumeInffo.GetName())

	fmt.Println("time:->", time.Now().Unix())

	// http resquest
	// http.HandleFunc("/go", helloHandler)
	//  http.ListenAndServe(":12345", nil)

	// server filesystem
	// http.ListenAndServe(":12345", http.FileServer(http.Dir(".")))
}
