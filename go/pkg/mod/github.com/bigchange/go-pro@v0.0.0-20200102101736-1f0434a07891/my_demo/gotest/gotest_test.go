package gotest

import (
	"testing"
)

// 执行`go test -v`

func Test_Division_1(t *testing.T) {
	if i, e := Division(6, 2); i != 3 || e != nil { //try a unit test on function
		t.Error("除法函数测试没通过") // 如果不是如预期的那么就报错
	} else {
		t.Log("第一个测试通过了") //记录一些你期望记录的信息
	}
}

func Test_Division_2(t *testing.T) {
	if _, e := Division(6, 0); e == nil { //try a unit test on function
		t.Error("Division did not work as expected.") // 如果不是如预期的那么就报错
	} else {
		t.Log("one test passed.", e) //记录一些你期望记录的信息
	}
}
