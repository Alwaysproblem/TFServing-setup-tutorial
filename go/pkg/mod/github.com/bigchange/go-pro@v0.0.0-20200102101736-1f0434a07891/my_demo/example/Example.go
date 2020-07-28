package example

import (
	"fmt"
	"io"
	"net/http"
)

// 定义一个 DivideError 结构 (除数不能为零)
type DivideError struct {
	up   int
	down int
}

type Resume struct {
	name    string
	phone   string
	address string
}

// 实现 	`error` 接口  Error() 方法
func (divide *DivideError) Error() string {
	stringFormat := `
	Cannot proceed, the divider is zero.
	dividee: %d
	divider: 0
						`
	return fmt.Sprintf(stringFormat, divide.up)
}

func (resume *Resume) Error() string {

	msg := `format resume error()`

	return msg

}

// func 首字母大写
func NewResume(name string, phone string, address string) *Resume {
	return &Resume{name: name, phone: phone, address: address}
}

// 定义 `int` 类型除法运算的函数
func Divide(varDividee int, varDivider int) (result int, errorMsg string) {

	if varDivider == 0 {

		var dData DivideError
		dData.up = varDividee
		dData.down = varDivider

		/*errorData := DivideError {
			up:varDividee,
			down:varDivider,
		}*/
		errorMsg = dData.Error()
		// errorMsg = errorData.Error()
		return
	} else {
		return varDividee / varDivider, ""
	}

}

func (resume *Resume) GetName() string {
	return resume.name
}

func (resume *Resume) GetPhone() string {
	return resume.phone
}

// handler request
func helloHandler(writer http.ResponseWriter, request *http.Request) {
	io.WriteString(writer, "hello, world!!")
}

func echoHandler(writer http.ResponseWriter, request *http.Request) {
	io.WriteString(writer, request.URL.Path)
}

// router
func router() {
	mux := http.NewServeMux()
	mux.HandleFunc("/hello", helloHandler)
	mux.HandleFunc("/", echoHandler)

	http.ListenAndServe(":12345", mux)
}

func formatResponse(msg string) {
	fmt.Sprintf("hello world -> %s", msg)
}
