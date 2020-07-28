package main

import (
	"io/ioutil"
	"os"
	"path/filepath"
	"testing"

	pb "github.com/bigchange/go-pro/proto"
	"github.com/golang/glog"
	"github.com/stretchr/testify/assert"
	"golang.org/x/net/context"
)

func TestGreet(t *testing.T) {
	testCases := []struct {
		x, y, sum float32
	}{
		{0.1, 0.2, 0.3},
		{-0.1, 0.2, 0.1},
		{100, 10000, 10100},
	}

	fn := filepath.Join(os.Getenv("TEST_SRCDIR"), os.Getenv("TEST_WORKSPACE"), "/Users/chaojiangyou/lls/src/github.com/bigchange/go-pro/model/model.pb")
	def, err := ioutil.ReadFile(fn)
	if err != nil {
		glog.Fatal(err)
	}
	s := NewServlet(def)
	for _, test := range testCases {
		resp, err := s.Sum(context.Background(), &pb.Request{
			X: test.x,
			Y: test.y,
		})
		assert.Nil(t, err)
		assert.Equal(t, test.sum, resp.Sum)
	}
}
