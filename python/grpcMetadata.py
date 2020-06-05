import grpc
from tensorflow_serving.apis import prediction_service_pb2_grpc
from tensorflow_serving.apis import get_model_metadata_pb2

host = '0.0.0.0'
port = 8500
server = host+":"+str(port)


if __name__ == "__main__":

    import argparse

    parse = argparse.ArgumentParser(prog="the tensorflow client for python.")
    parse.add_argument('-m', '--model', type=str, action="store", dest="model", default="Toy")
    parse.add_argument('-v', '--version', type=int, action="store", dest="version", default=-1)

    args = parse.parse_args()

    channel = grpc.insecure_channel(server)
    stub = prediction_service_pb2_grpc.PredictionServiceStub(channel)

    get_model_metadata_request = get_model_metadata_pb2.GetModelMetadataRequest()
    get_model_metadata_request.model_spec.name = args.model
    if args.version > -1:
        get_model_metadata_request.model_spec.version.value = args.version 
    get_model_metadata_request.metadata_field.append("signature_def")

    resp = stub.GetModelMetadata(get_model_metadata_request)
    print(resp)