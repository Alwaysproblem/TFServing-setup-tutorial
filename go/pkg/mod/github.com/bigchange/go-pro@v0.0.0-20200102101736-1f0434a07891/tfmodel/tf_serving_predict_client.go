package tfmodel

import (
	"context"
	"errors"
	"reflect"

	framework "github.com/bigchange/go-pro/tensorflow"
	pb "github.com/bigchange/go-pro/tensorflow_serving"
	"google.golang.org/grpc"

	google_protobuf "github.com/golang/protobuf/ptypes/wrappers"
)

type PredictionServiceClient struct {
	Conn    *grpc.ClientConn
	Address string
	Stub    pb.PredictionServiceClient
}

// NewClient
func NewPredictionServiceClient(address string) (client *PredictionServiceClient, err error) {
	// fmt.Println("grpcVersion:", grpc.Version)
	client = &PredictionServiceClient{Conn: nil, Address: address, Stub: nil}
	return client, nil
}

func (client *PredictionServiceClient) Dial() (err error) {
	client.Conn, err = grpc.Dial(client.Address, grpc.WithInsecure())
	if err != nil {
		return err
	}
	client.Stub = pb.NewPredictionServiceClient(client.Conn)
	// ctx, _ := context.WithTimeout(context.Background(), time.Duration(5*time.Second))
	return nil
}

func (client *PredictionServiceClient) Close() {
	client.Conn.Close()
}

// Note: all input tensors should be converted to 1D arry, for example: if you have a tensor [30,40], pls converted to [30 * 40] with specified tensor dim defined in tensor_shape
func (client *PredictionServiceClient) Predict(modelName string, signatureName string, modelVersion int64, tensorNames []string, dataTypes []framework.DataType, tensors []interface{}, shapeSizes [][]int64, shapeNames [][]string, outputNames []string) (out *pb.PredictResponse, err error) {
	err = client.Dial()
	if err != nil {
		return out, err
	}
	defer client.Close()
	if len(tensorNames) == len(dataTypes) && len(tensorNames) == len(tensors) {
		var pr *pb.PredictRequest
		pr = newPredictRequest(modelName, signatureName, modelVersion)
		// fmt.Println("pr new :", pr)
		for i, tensorName := range tensorNames {
			if shapeNames == nil {
				tensorProto, err := addInput(tensorName, dataTypes[i], tensors[i], shapeSizes[i], nil)
				if err != nil {
					return out, err
				}
				pr.Inputs[tensorName] = tensorProto
			} else {
				tensorProto, err := addInput(tensorName, dataTypes[i], tensors[i], shapeSizes[i], shapeNames[i])
				if err != nil {
					return out, err
				}
				pr.Inputs[tensorName] = tensorProto
			}
			// fmt.Println("tensorName:", tensorName, ",pr addInput:", pr)
		}

		// fmt.Println("pr final:", pr)
		out, err = client.Stub.Predict(context.Background(), pr)
	} else {
		return out, errors.New("inputs parameters length not match")
	}
	return out, err
}

func newPredictRequest(modelName string, signatureName string, modelVersion int64) (pr *pb.PredictRequest) {
	return &pb.PredictRequest{
		ModelSpec: &pb.ModelSpec{
			Name:          modelName,
			SignatureName: signatureName,
			VersionChoice: &pb.ModelSpec_Version{
				Version: &google_protobuf.Int64Value{
					Value: modelVersion,
				},
			},
		},
		Inputs: make(map[string]*framework.TensorProto),
	}
}

// if tensor is one dim, shapeSize is nil
func addInput(tensorName string, dataType framework.DataType, tensor interface{},
	shapeSize []int64, shapeName []string) (tp *framework.TensorProto, err error) {
	v := reflect.ValueOf(tensor)
	if v.Kind() != reflect.Slice {
		return tp, errors.New("tensor must be slice")
	}
	size := v.Len()
	tp = &framework.TensorProto{
		Dtype: dataType,
	}

	var ok bool
	switch dataType {
	case framework.DataType_DT_HALF:
		tp.HalfVal, ok = tensor.([]int32)
	case framework.DataType_DT_FLOAT:
		tp.FloatVal, ok = tensor.([]float32)
		// fmt.Println("tp:", tensorName, ",ok:", ok)
	case framework.DataType_DT_DOUBLE:
		tp.DoubleVal, ok = tensor.([]float64)
	case framework.DataType_DT_INT16, framework.DataType_DT_INT32,
		framework.DataType_DT_INT8, framework.DataType_DT_UINT8:
		tp.IntVal, ok = tensor.([]int32)
		// fmt.Println("tp:", tensorName, ",ok:", ok)
	case framework.DataType_DT_STRING:
		tp.StringVal, ok = tensor.([][]byte)
	case framework.DataType_DT_COMPLEX64:
		tp.ScomplexVal, ok = tensor.([]float32)
	case framework.DataType_DT_INT64:
		tp.Int64Val, ok = tensor.([]int64)
	case framework.DataType_DT_BOOL:
		tp.BoolVal, ok = tensor.([]bool)
		// fmt.Println("tp:", tensorName, ",ok:", ok)
	case framework.DataType_DT_COMPLEX128:
		tp.DcomplexVal, ok = tensor.([]float64)
	case framework.DataType_DT_RESOURCE:
		tp.ResourceHandleVal, ok = tensor.([]*framework.ResourceHandleProto)
	default:
		err = errors.New("unknown data type")
	}

	if !ok {
		if err != nil {
			err = errors.New("type switch failed")
		}
		return tp, err
	}
	// fmt.Println("tp2 :", tensorName)
	if shapeSize == nil {
		name := ""
		if len(shapeName) != 0 {
			name = shapeName[0]
		}
		tp.TensorShape = &framework.TensorShapeProto{
			Dim: []*framework.TensorShapeProto_Dim{
				&framework.TensorShapeProto_Dim{
					Size: int64(size),
					Name: name,
				},
			},
		}
	} else {
		if shapeName != nil && len(shapeName) != len(shapeSize) {
			return nil, errors.New("shapeName and shapeSize have different size")
		}
		tp.TensorShape = &framework.TensorShapeProto{
			Dim: []*framework.TensorShapeProto_Dim{},
		}
		for i, size := range shapeSize {
			name := ""
			if shapeName != nil {
				name = shapeName[i]
			}
			tp.TensorShape.Dim = append(tp.TensorShape.Dim, &framework.TensorShapeProto_Dim{
				Size: size,
				Name: name,
			})
		}
	}
	// fmt.Println("tp3 :", tensorName)
	return tp, nil
}
