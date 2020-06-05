package gotest

import (
	"context"
	"github.com/bgfurfeature/dgo"
	"github.com/bigchange/go-pro/my_demo/clients"
	"github.com/bigchange/go-pro/my_demo/utils"
	"github.com/dgraph-io/dgo/protos/api"
	"google.golang.org/grpc"
	"log"
	"testing"
)

func TestQuaryVars(t *testing.T) {
	dclient, err := clients.NewDClients([]string{"127.0.0.1:9080"})
	dg, err := dclient.Dial()
	if err != nil {
		utils.GetLogger().Criticalf("can't create dgraph client")
	}
	utils.GetLogger().Info("create dgraph client success")
	defer dclient.Close()
	query := `query candidate($a: string) {
		candidate(func: uid($a)) {
			name
			uid
			candidate_company {
				name
				uid
			}
 		}
	}`
	variables := make(map[string]string)
	variables["$a"] = "0x3"
	resp, err := dg.NewTxn().QueryWithVars(context.Background(), query, variables)
	if err != nil {
		log.Fatal(err)
	}
	log.Println("resp:", resp)

}

// PASS
func TestDgraphClient(t *testing.T) {
	conn, err := grpc.Dial("127.0.0.1:9080", grpc.WithInsecure())
	if err != nil {
		log.Fatal("While trying to dial gRPC")
	}
	defer conn.Close()
	dc := api.NewDgraphClient(conn)
	dg := dgo.NewDgraphClient(dc)
	query := `{
		query(func: uid(0x3)) {
			name
			uid
			candidate_company {
				name
				uid
			}
 		}
	}`
	ctx := context.Background()
	resp, err := dg.NewTxn().Query(ctx, query)
	if err != nil {
		log.Fatal(err)
	}
	log.Println("resp:", resp)
}

// PASS
func DgraphClient() {
	dclient, err := clients.NewDClients([]string{"127.0.0.1:9080"})
	dg, err := dclient.Dial()
	if err != nil {
		utils.GetLogger().Criticalf("can't create dgraph client")
	}
	utils.GetLogger().Info("create dgraph client success")
	defer dclient.Close()
	query := `{
		query(func: uid(0x3)) {
			name
			uid
			candidate_company {
				name
				uid
			}
 		}
	}`
	ctx := context.Background()
	resp, err := dg.NewTxn().Query(ctx, query)
	if err != nil {
		log.Fatal(err)
	}
	log.Println("resp:", resp)
}

func init() {
}

func TestInitDgraphClient(t *testing.T) {
	DgraphClient()
}
