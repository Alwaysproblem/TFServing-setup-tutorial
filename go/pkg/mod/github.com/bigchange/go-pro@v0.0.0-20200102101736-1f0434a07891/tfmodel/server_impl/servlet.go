// Package servlet implements tfdemo.SumService.
package main

import (
	"errors"

	pb "github.com/bigchange/go-pro/proto"
	"github.com/golang/glog"
	tf "github.com/tensorflow/tensorflow/go"
	"golang.org/x/net/context"
)

var errEmptyName = errors.New("empty name.")

type Servlet struct {
	*tf.Graph
	*tf.Session
}

var _ (pb.SumServiceServer) = (*Servlet)(nil)

// NewServlet creates a servlet.
//
// NOTE(yi.sun): Unfortunately right now it is not possible to pass in a
// typed graph def struct, only the serialized proto.
func NewServlet(graphDef []byte) *Servlet {
	g := tf.NewGraph()
	if err := g.Import(graphDef, ""); err != nil {
		glog.Fatal(err)
	}
	sess, err := tf.NewSession(g, nil)
	if err != nil {
		glog.Fatal(err)
	}
	return &Servlet{Graph: g, Session: sess}
}

// Sum implements tfdemo.SumService.
func (s *Servlet) Sum(ctx context.Context, req *pb.Request) (*pb.Response, error) {
	// Convert request into proper tensors.
	x, err := tf.NewTensor(req.X)
	if err != nil {
		return nil, err
	}
	y, err := tf.NewTensor(req.Y)
	if err != nil {
		return nil, err
	}
	out, err := s.Session.Run(map[tf.Output]*tf.Tensor{
		s.Graph.Operation("x").Output(0): x,
		s.Graph.Operation("y").Output(0): y,
	}, []tf.Output{
		s.Graph.Operation("sum").Output(0),
	}, nil)
	if err != nil {
		return nil, err
	}
	return &pb.Response{Sum: out[0].Value().(float32)}, nil
}
