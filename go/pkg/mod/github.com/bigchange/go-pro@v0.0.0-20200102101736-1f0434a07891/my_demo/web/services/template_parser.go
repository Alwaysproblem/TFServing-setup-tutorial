package services

import (
	"html/template"
	"os"
)

type Person struct {
	UserName string
}

func ParserTemplate() {
	t := template.New("fieldname example")
	t, _ = t.Parse("hello {{.UserName}}!")
	p := Person{UserName: "Astaxie"}
	t.Execute(os.Stdout, p)
}
