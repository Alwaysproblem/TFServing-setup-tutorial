package gotest

// 压力测试
/** go test不会默认执行压力测试的函数，如果要执行压力测试需要带上参数-test.bench，
语法:-test.bench="test_name_regex",例如go test -test.bench=".*"表示测试全部的压力测试函数
在压力测试用例中,请记得在循环体内使用testing.B.N,以使测试可以正常的运行
文件名也必须以_test.go结尾
go test -file webbench_test.go -test.bench=".*"
*/
import (
	"testing"
)

func Benchmark_Division(b *testing.B) {
	for i := 0; i < b.N; i++ { //use b.N for looping
		Division(4, 5)
	}
}

func Benchmark_TimeConsumingFunction(b *testing.B) {
	b.StopTimer() //调用该函数停止压力测试的时间计数

	//做一些初始化的工作,例如读取文件数据,数据库连接之类的,
	//这样这些时间不影响我们测试函数本身的性能

	b.StartTimer() //重新开始时间
	for i := 0; i < b.N; i++ {
		Division(4, 5)
	}
}
