package services

import (
	"encoding/xml"
	"fmt"
	"io/ioutil"
	"os"
)

// 解析xml文件 (../../public)
type Recurlyservers struct {
	// XMLName     xml.Name `xml:"servers"`
	Version     string   `xml:"version,attr"`
	Svs         []server `xml:"server"`
	Description string   `xml:",innerxml"`
}

type server struct {
	// XMLName    xml.Name `xml:"server"`
	ServerName string `xml:"serverName"`
	ServerIP   string `xml:"serverIP"`
}

func XMLPareser(filePath string) {
	file, err := os.Open(filePath) // For read access.
	if err != nil {
		fmt.Printf("error: %v", err)
		return
	}
	defer file.Close()
	data, err := ioutil.ReadAll(file)
	if err != nil {
		fmt.Printf("error: %v", err)
		return
	}
	v := Recurlyservers{}
	err = xml.Unmarshal(data, &v)
	if err != nil {
		fmt.Printf("error: %v", err)
		return
	}

	fmt.Println(v)
}

func XMLFormat() {

	v := &Recurlyservers{Version: "1"}
	v.Svs = append(v.Svs, server{"Shanghai_VPN", "127.0.0.1"})
	v.Svs = append(v.Svs, server{"Beijing_VPN", "127.0.0.2"})
	output, err := xml.MarshalIndent(v, "  ", "    ")
	if err != nil {
		fmt.Printf("error: %v\n", err)
	}
	os.Stdout.Write([]byte(xml.Header))

	os.Stdout.Write(output)
}

// 解析 json
