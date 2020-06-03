module client

go 1.13

replace github.com/tensorflow/tensorflow/tensorflow/go/core => ./proto/tensorflow/core

replace github.com/alwaysproblem/tensorflow_serving => ./proto/tensorflow/serving

require (
	github.com/alwaysproblem/tensorflow_serving v0.0.0-00010101000000-000000000000
	github.com/golang/protobuf v1.4.2
	github.com/tensorflow/tensorflow/tensorflow/go/core v0.0.0-00010101000000-000000000000
	go.uber.org/ratelimit v0.1.0 // indirect
	golang.org/x/net v0.0.0-20200602114024-627f9648deb9 // indirect
	golang.org/x/sys v0.0.0-20200602225109-6fdc65e7d980 // indirect
	golang.org/x/text v0.3.2 // indirect
	google.golang.org/genproto v0.0.0-20200603110839-e855014d5736 // indirect
	google.golang.org/grpc v1.29.1 // indirect
)
