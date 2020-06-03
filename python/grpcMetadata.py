import grpc
from tensorflow_serving.apis import prediction_service_pb2_grpc
from tensorflow_serving.apis import get_model_metadata_pb2

channel = grpc.insecure_channel("localhost:8500")
stub = prediction_service_pb2_grpc.PredictionServiceStub(channel)

get_model_metadata_request = get_model_metadata_pb2.GetModelMetadataRequest()
get_model_metadata_request.model_spec.name = "Toy"
get_model_metadata_request.metadata_field.append("signature_def")
# get_model_metadata_request.metadata_field.append("signature_def")

resp = stub.GetModelMetadata(get_model_metadata_request)
print(resp)