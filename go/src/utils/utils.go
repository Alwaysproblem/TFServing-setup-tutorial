// Package utils the helper function
package utils

import (
	"errors"
	"fmt"
	"reflect"
	
	pb "github.com/alwaysproblem/tensorflow_serving"
	framework "github.com/tensorflow/tensorflow/tensorflow/go/core/framework/tensor_go_proto"
	types_go_proto "github.com/tensorflow/tensorflow/tensorflow/go/core/framework/types_go_proto"
	resource_handle_go_proto "github.com/tensorflow/tensorflow/tensorflow/go/core/framework/resource_handle_go_proto"
	tensor_shape_go_proto "github.com/tensorflow/tensorflow/tensorflow/go/core/framework/tensor_shape_go_proto"
)

func str2bytes(tensor interface{}) ([][]byte, bool) {
	str, ok := tensor.([]string)
	bytes := make([][]byte, len(str))
	
	if !ok {
		fmt.Println("error: string to byte failed.")
		return nil, ok
	}
	
	for i, s := range str {
		bytes[i] = []byte(s)
	}

	return bytes, ok
}

// MakeTensorProto only for list and map 
func MakeTensorProto(tensor interface{}, dataType string, shapeSize []int64)(tp *framework.TensorProto, err error){
	v := reflect.ValueOf(tensor)
	if v.Kind() != reflect.Slice {
		return nil, errors.New("tensor must be slice")
	}
	size := v.Len()

	frameworkprotoMap := map[string]types_go_proto.DataType{
		"DT_HALF": types_go_proto.DataType_DT_HALF, 
		"DT_FLOAT": types_go_proto.DataType_DT_FLOAT, 
		"DT_DOUBLE": types_go_proto.DataType_DT_DOUBLE, 
		"DT_INT16": types_go_proto.DataType_DT_INT16, 
		"DT_INT32": types_go_proto.DataType_DT_INT32, 
		"DT_INT8": types_go_proto.DataType_DT_INT8, 
		"DT_UINT8": types_go_proto.DataType_DT_UINT8, 
		"DT_STRING": types_go_proto.DataType_DT_STRING, 
		"DT_COMPLEX64": types_go_proto.DataType_DT_COMPLEX64, 
		"DT_INT64": types_go_proto.DataType_DT_INT64, 
		"DT_BOOL": types_go_proto.DataType_DT_BOOL, 
		"DT_COMPLEX128": types_go_proto.DataType_DT_COMPLEX128, 
		"DT_RESOURCE": types_go_proto.DataType_DT_RESOURCE,
	}
	tp = &framework.TensorProto{
		Dtype: frameworkprotoMap[dataType],
	}

	var ok bool
	switch dataType {
		case "DT_HALF":
			tp.HalfVal, ok = tensor.([]int32)
		case "DT_FLOAT":
			tp.FloatVal, ok = tensor.([]float32)
		case "DT_DOUBLE":
			tp.DoubleVal, ok = tensor.([]float64)
		case "DT_INT16", "DT_INT32", "DT_INT8", "DT_UINT8":
			tp.IntVal, ok = tensor.([]int32)
		case "DT_STRING":
			// tp.StringVal, ok = tensor.([][]byte)
			tp.StringVal, ok = str2bytes(tensor)
		case "DT_COMPLEX64":
			tp.ScomplexVal, ok = tensor.([]float32)
		case "DT_INT64":
			tp.Int64Val, ok = tensor.([]int64)
		case "DT_BOOL":
			tp.BoolVal, ok = tensor.([]bool)
		case "DT_COMPLEX128":
			tp.DcomplexVal, ok = tensor.([]float64)
		case "DT_RESOURCE":
			tp.ResourceHandleVal, ok = tensor.([]*resource_handle_go_proto.ResourceHandleProto)
		default:
			err = errors.New("Unknown data type")
	}

	if !ok {
		if err != nil {
			err = errors.New("Type switch failed")
		}
		return
	}

	if shapeSize == nil {
		tp.TensorShape = &tensor_shape_go_proto.TensorShapeProto{
			Dim: []*tensor_shape_go_proto.TensorShapeProto_Dim{
				&tensor_shape_go_proto.TensorShapeProto_Dim{
					Size: int64(size),
				},
			},
		}
	} else {
		tp.TensorShape = &tensor_shape_go_proto.TensorShapeProto{
			Dim: []*tensor_shape_go_proto.TensorShapeProto_Dim{},
		}
		for _, size := range shapeSize {
			tp.TensorShape.Dim = append(tp.TensorShape.Dim, &tensor_shape_go_proto.TensorShapeProto_Dim{
				Size: size,
			})
		}
	}
	return
}


// if tensor is one dim, shapeSize is nil
func AddInput(pr *pb.PredictRequest, tensorName string, dataType types_go_proto.DataType, tensor interface{},
	shapeSize []int64, shapeName []string) (err error) {
	v := reflect.ValueOf(tensor)
	if v.Kind() != reflect.Slice {
		return errors.New("tensor must be slice")
	}
	size := v.Len()
	tp := &framework.TensorProto{
		Dtype: dataType,
	}

	var ok bool
	switch dataType {
	case types_go_proto.DataType_DT_HALF:
		tp.HalfVal, ok = tensor.([]int32)
	case types_go_proto.DataType_DT_FLOAT:
		tp.FloatVal, ok = tensor.([]float32)
	case types_go_proto.DataType_DT_DOUBLE:
		tp.DoubleVal, ok = tensor.([]float64)
	case types_go_proto.DataType_DT_INT16, types_go_proto.DataType_DT_INT32,
		types_go_proto.DataType_DT_INT8, types_go_proto.DataType_DT_UINT8:
		tp.IntVal, ok = tensor.([]int32)
	case types_go_proto.DataType_DT_STRING:
		tp.StringVal, ok = tensor.([][]byte)
	case types_go_proto.DataType_DT_COMPLEX64:
		tp.ScomplexVal, ok = tensor.([]float32)
	case types_go_proto.DataType_DT_INT64:
		tp.Int64Val, ok = tensor.([]int64)
	case types_go_proto.DataType_DT_BOOL:
		tp.BoolVal, ok = tensor.([]bool)
	case types_go_proto.DataType_DT_COMPLEX128:
		tp.DcomplexVal, ok = tensor.([]float64)
	case types_go_proto.DataType_DT_RESOURCE:
		tp.ResourceHandleVal, ok = tensor.([]*resource_handle_go_proto.ResourceHandleProto)
	default:
		err = errors.New("Unknown data type")
	}

	if !ok {
		if err != nil {
			err = errors.New("Type switch failed")
		}
		return
	}

	if shapeSize == nil {
		name := ""
		if len(shapeName) != 0 {
			name = shapeName[0]
		}
		tp.TensorShape = &tensor_shape_go_proto.TensorShapeProto{
			Dim: []*tensor_shape_go_proto.TensorShapeProto_Dim{
				&tensor_shape_go_proto.TensorShapeProto_Dim{
					Size: int64(size),
					Name: name,
				},
			},
		}
	} else {
		if shapeName != nil && len(shapeName) != len(shapeSize) {
			return errors.New("shapeName and shapeSize have different size")
		}
		tp.TensorShape = &tensor_shape_go_proto.TensorShapeProto{
			Dim: []*tensor_shape_go_proto.TensorShapeProto_Dim{},
		}
		for i, size := range shapeSize {
			name := ""
			if shapeName != nil {
				name = shapeName[i]
			}
			tp.TensorShape.Dim = append(tp.TensorShape.Dim, &tensor_shape_go_proto.TensorShapeProto_Dim{
				Size: size,
				Name: name,
			})
		}
	}
	pr.Inputs[tensorName] = tp
	return
}


func PrintTP(tp *framework.TensorProto, dim, idx int, indexes []int) int {
	max := tp.TensorShape.Dim[dim]
	isLastDim := dim == len(tp.TensorShape.Dim)-1
	indexes = append(indexes, 0)
	// if isLastDim {
	// 	fmt.Printf("%v\n", indexes)
	// }
	for i := 0; i < int(max.Size); i++ {
		indexes[dim] = i
		if !isLastDim {
			idx = PrintTP(tp, dim+1, idx, indexes)
		} else {
			fmt.Printf("%f\n", tp.FloatVal[idx])
			idx++
		}
	}
	return idx
}

func PrintTensorProto(tp *framework.TensorProto) {
	// fmt.Printf("%v\n", tp.TensorShape)
	PrintTP(tp, 0, 0, nil)
}
