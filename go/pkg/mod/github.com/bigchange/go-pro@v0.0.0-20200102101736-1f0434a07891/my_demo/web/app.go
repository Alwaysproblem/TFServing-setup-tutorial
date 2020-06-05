package main

import (
	"bytes"
	"fmt"
	"io"
	"io/ioutil"
	"log"
	"mime/multipart"
	"net/http"
	"os"
	// 如何导入其他包(hostname + project dir)
	// "github.com/bigchange/go-pro/src/web/services"
	"errors"
	"services"
)

var caseAPI = new(services.CaseApi)

// 客户端上传文件
func postFile(filename string, targetUrl string) error {
	bodyBuf := &bytes.Buffer{}
	bodyWriter := multipart.NewWriter(bodyBuf)

	//关键的一步操作
	fileWriter, err := bodyWriter.CreateFormFile("uploadfile", filename)
	if err != nil {
		fmt.Println("error writing to buffer")
		return err
	}

	//打开文件句柄操作
	fh, err := os.Open(filename)
	if err != nil {
		fmt.Println("error opening file")
		return err
	}
	defer fh.Close()

	//iocopy
	_, err = io.Copy(fileWriter, fh)
	if err != nil {
		return err
	}

	contentType := bodyWriter.FormDataContentType()
	bodyWriter.Close()

	resp, err := http.Post(targetUrl, contentType, bodyBuf)
	if err != nil {
		return err
	}
	defer resp.Body.Close()
	resp_body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return err
	}
	fmt.Println(resp.Status)
	fmt.Println(string(resp_body))
	return nil
}

func checkError(err error) error {
	if err != nil {
		return errors.New("Case not found")
	}
	return nil
}

// 最难破解的
// dk := scrypt.Key([]byte("some password"), []byte(salt), 16384, 8, 1, 32)

func main() {

	fmt.Println("hello world \n")

	services.ParserTemplate()

	http.HandleFunc("/index", caseAPI.SayHello)
	http.HandleFunc("/login", caseAPI.Login)
	err := http.ListenAndServe(":9090", nil) //设置监听的端口
	// var myMux = new(services.MyMux)
	// http.ListenAndServe(":9090", myMux)
	fmt.Println("listen port at :9090")
	if err != nil {
		log.Fatal("ListenAndServe: ", err)
	}

}
