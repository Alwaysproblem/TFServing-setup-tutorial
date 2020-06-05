package services

import (
	"crypto/md5"
	"fmt"
	"html/template"
	"io"
	"log"
	"net/http"
	"regexp"
	"strconv"
	"strings"
	"time"
)

type CaseApi struct{}

// login
func (api *CaseApi) Login(w http.ResponseWriter, r *http.Request) {

	// set cookie
	expiration := time.Now()
	expiration = expiration.AddDate(1, 0, 0)
	cookie := http.Cookie{Name: "username", Value: "jerry", Expires: expiration}
	http.SetCookie(nil, &cookie)

	r.ParseForm()
	fmt.Println("method:", r.Method) //获取请求的方法
	if r.Method == "GET" {
		t, _ := template.ParseFiles("../../public/login.html")
		crutime := time.Now().Unix()
		h := md5.New()
		io.WriteString(h, strconv.FormatInt(crutime, 10))
		token := fmt.Sprintf("%x", h.Sum(nil))

		log.Println(t.Execute(w, token))
	} else {

		token := r.Form.Get("token")
		if token != "" {
			//验证token的合法性
		} else {
			//不存在token报错
		}

		//请求的是登陆数据，那么执行登陆的逻辑判断
		fmt.Println("username:", r.Form["username"])
		fmt.Println("password:", r.Form["password"])

		// 表单验证操作
		// 1.必填字段
		if len(r.Form["username"][0]) == 0 {
			//为空的处理
		}
		// 2.数字
		getint, err := strconv.Atoi(r.Form.Get("age"))
		if err != nil {
			//数字转化出错了，那么可能就不是数字
		}

		//接下来就可以判断这个数字的大小范围了
		if getint > 100 {
			//太大了
		}
		if m, _ := regexp.MatchString("^[0-9]+$", r.Form.Get("age")); !m {
			//不是数字
		}
		// 3.中文
		if m, _ := regexp.MatchString("^\\p{Han}+$", r.Form.Get("realname")); !m {
			// 不是中文
		}

		// 4. 英文
		if m, _ := regexp.MatchString("^[a-zA-Z]+$", r.Form.Get("engname")); !m {
			// 不是英文
		}
		// 5.电子邮件
		if m, _ := regexp.MatchString(`^([\w\.\_]{2,10})@(\w{1,}).([a-z]{2,4})$`, r.Form.Get("email")); !m {
			fmt.Println("no")
		} else {
			fmt.Println("yes")
		}
		// 6.手机号码
		if m, _ := regexp.MatchString(`^(1[3|4|5|8][0-9]\d{4,8})$`, r.Form.Get("mobile")); !m {
			fmt.Println("no")
		}

		// 7.下拉菜单
		slice := []string{"apple", "pear", "banane"}

		v := r.Form.Get("fruit")
		for _, item := range slice {
			if item == v {
				fmt.Println("yes")
			}
		}

		fmt.Println("no")
		// 8. 单选按钮
		sliceRadio := []int{1, 2}

		for _, value := range sliceRadio {
			if item, m := strconv.Atoi(r.Form.Get("gender")); m == nil && value == item {
				fmt.Println("yes")
			}
		}
		fmt.Println("no")

		// 9. 复选框
		sliceCheckBox := []string{"football", "basketball", "tennis"}
		sel := r.Form["interest"]
		var index = 0
		for _, item := range sel {
			for _, check := range sliceCheckBox {
				if item == check {
					index++
				}
			}
		}
		if index == len(sel) {
			fmt.Println("yes")
		}

		fmt.Println("no")
		// 10. 时间
		t := time.Date(2009, time.November, 10, 23, 0, 0, 0, time.UTC)
		fmt.Printf("Go launched at %s\n", t.Local())
		// 11. 身份证
		//验证15位身份证，15位的是全部数字
		if m, _ := regexp.MatchString(`^(\d{15})$`, r.Form.Get("usercard")); !m {
			fmt.Println("no")
		}

		//验证18位身份证，18位前17位为数字，最后一位是校验位，可能为数字或字符X。
		if m, _ := regexp.MatchString(`^(\d{17})([0-9]|X)$`, r.Form.Get("usercard")); !m {
			fmt.Println("no")
		}

	}
}

// index
func (api *CaseApi) SayHello(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()       //解析参数，默认是不会解析的
	fmt.Println(r.Form) //这些信息是输出到服务器端的打印信息
	fmt.Println("path", r.URL.Path)
	fmt.Println("scheme", r.URL.Scheme)
	fmt.Println(r.Form["url_long"])
	for k, v := range r.Form {
		fmt.Println("key:", k)
		fmt.Println("val:", strings.Join(v, ""))
	}
	fmt.Fprintf(w, "Hello astaxie!") //这个写入到w的是输出到客户端的
}
