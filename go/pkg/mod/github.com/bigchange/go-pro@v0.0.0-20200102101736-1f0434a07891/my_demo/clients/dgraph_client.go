/*
 * @Author: Jerry You
 * @CreatedDate: 2018-05-14 19:25:34
 * @Last Modified by: Jerry You
 * @Last Modified time: 2018-05-14 20:16:53
 */
// Package clients provide noraml grpc clients initial
package clients

import (
	"log"

	"github.com/bgfurfeature/dgo"
	"github.com/dgraph-io/dgo/protos/api"
	"google.golang.org/grpc"
	// api_go "higgs.com/inmind/idmg/lieluobo/dynamic_features/proto/api_proto_go"
)

type DClient struct {
	Conns   []*grpc.ClientConn
	Address []string
}

func NewDClients(address []string) (client *DClient, err error) {
	client = &DClient{
		Conns:   make([]*grpc.ClientConn, len(address)),
		Address: address}
	return client, nil
}

func NewDClient(address ...string) (client *DClient, err error) {
	client = &DClient{
		Conns:   make([]*grpc.ClientConn, len(address)),
		Address: address}
	return client, nil
}

func (client DClient) Dial() (dg *dgo.Dgraph, err error) {
	log.Println("address length:", len(client.Address))
	var size = len(client.Address)
	var dc = make([]api.DgraphClient, len(client.Address))
	for i := 0; i < size; i++ {
		conn, err := grpc.Dial(client.Address[i], grpc.WithInsecure())
		client.Conns[i] = conn
		dc[i] = api.NewDgraphClient(client.Conns[i])
		if err != nil {
			log.Fatal("While trying to dial gRPC")
			return nil, err
		}
	}
	dg = dgo.NewDgraphClients(dc)
	return dg, nil
}
func (client DClient) Close() {
	size := len(client.Conns)
	for i := 0; i < size; i++ {
		defer client.Conns[i].Close()
	}
}
