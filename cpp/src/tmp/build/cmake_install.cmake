# Install script for directory: /cpp/src/tmp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/cpp/src/tmp/lib/libtfclient.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/cpp/src/tmp/lib" TYPE STATIC_LIBRARY FILES "/cpp/src/tmp/build/libtfclient.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/cpp/src/tmp/include/example.grpc.pb.h;/cpp/src/tmp/include/example.pb.h;/cpp/src/tmp/include/example_parser_configuration.grpc.pb.h;/cpp/src/tmp/include/example_parser_configuration.pb.h;/cpp/src/tmp/include/feature.grpc.pb.h;/cpp/src/tmp/include/feature.pb.h;/cpp/src/tmp/include/allocation_description.grpc.pb.h;/cpp/src/tmp/include/allocation_description.pb.h;/cpp/src/tmp/include/api_def.grpc.pb.h;/cpp/src/tmp/include/api_def.pb.h;/cpp/src/tmp/include/attr_value.grpc.pb.h;/cpp/src/tmp/include/attr_value.pb.h;/cpp/src/tmp/include/cost_graph.grpc.pb.h;/cpp/src/tmp/include/cost_graph.pb.h;/cpp/src/tmp/include/device_attributes.grpc.pb.h;/cpp/src/tmp/include/device_attributes.pb.h;/cpp/src/tmp/include/function.grpc.pb.h;/cpp/src/tmp/include/function.pb.h;/cpp/src/tmp/include/graph.grpc.pb.h;/cpp/src/tmp/include/graph.pb.h;/cpp/src/tmp/include/graph_transfer_info.grpc.pb.h;/cpp/src/tmp/include/graph_transfer_info.pb.h;/cpp/src/tmp/include/kernel_def.grpc.pb.h;/cpp/src/tmp/include/kernel_def.pb.h;/cpp/src/tmp/include/log_memory.grpc.pb.h;/cpp/src/tmp/include/log_memory.pb.h;/cpp/src/tmp/include/node_def.grpc.pb.h;/cpp/src/tmp/include/node_def.pb.h;/cpp/src/tmp/include/op_def.grpc.pb.h;/cpp/src/tmp/include/op_def.pb.h;/cpp/src/tmp/include/reader_base.grpc.pb.h;/cpp/src/tmp/include/reader_base.pb.h;/cpp/src/tmp/include/remote_fused_graph_execute_info.grpc.pb.h;/cpp/src/tmp/include/remote_fused_graph_execute_info.pb.h;/cpp/src/tmp/include/resource_handle.grpc.pb.h;/cpp/src/tmp/include/resource_handle.pb.h;/cpp/src/tmp/include/step_stats.grpc.pb.h;/cpp/src/tmp/include/step_stats.pb.h;/cpp/src/tmp/include/summary.grpc.pb.h;/cpp/src/tmp/include/summary.pb.h;/cpp/src/tmp/include/tensor.grpc.pb.h;/cpp/src/tmp/include/tensor.pb.h;/cpp/src/tmp/include/tensor_description.grpc.pb.h;/cpp/src/tmp/include/tensor_description.pb.h;/cpp/src/tmp/include/tensor_shape.grpc.pb.h;/cpp/src/tmp/include/tensor_shape.pb.h;/cpp/src/tmp/include/tensor_slice.grpc.pb.h;/cpp/src/tmp/include/tensor_slice.pb.h;/cpp/src/tmp/include/types.grpc.pb.h;/cpp/src/tmp/include/types.pb.h;/cpp/src/tmp/include/variable.grpc.pb.h;/cpp/src/tmp/include/variable.pb.h;/cpp/src/tmp/include/versions.grpc.pb.h;/cpp/src/tmp/include/versions.pb.h;/cpp/src/tmp/include/error_codes.grpc.pb.h;/cpp/src/tmp/include/error_codes.pb.h;/cpp/src/tmp/include/autotuning.grpc.pb.h;/cpp/src/tmp/include/autotuning.pb.h;/cpp/src/tmp/include/bfc_memory_map.grpc.pb.h;/cpp/src/tmp/include/bfc_memory_map.pb.h;/cpp/src/tmp/include/cluster.grpc.pb.h;/cpp/src/tmp/include/cluster.pb.h;/cpp/src/tmp/include/config.grpc.pb.h;/cpp/src/tmp/include/config.pb.h;/cpp/src/tmp/include/control_flow.grpc.pb.h;/cpp/src/tmp/include/control_flow.pb.h;/cpp/src/tmp/include/conv_autotuning.grpc.pb.h;/cpp/src/tmp/include/conv_autotuning.pb.h;/cpp/src/tmp/include/critical_section.grpc.pb.h;/cpp/src/tmp/include/critical_section.pb.h;/cpp/src/tmp/include/debug.grpc.pb.h;/cpp/src/tmp/include/debug.pb.h;/cpp/src/tmp/include/debug_event.grpc.pb.h;/cpp/src/tmp/include/debug_event.pb.h;/cpp/src/tmp/include/device_filters.grpc.pb.h;/cpp/src/tmp/include/device_filters.pb.h;/cpp/src/tmp/include/device_properties.grpc.pb.h;/cpp/src/tmp/include/device_properties.pb.h;/cpp/src/tmp/include/eager_service.grpc.pb.h;/cpp/src/tmp/include/eager_service.pb.h;/cpp/src/tmp/include/error_codes.grpc.pb.h;/cpp/src/tmp/include/error_codes.pb.h;/cpp/src/tmp/include/graph_debug_info.grpc.pb.h;/cpp/src/tmp/include/graph_debug_info.pb.h;/cpp/src/tmp/include/master.grpc.pb.h;/cpp/src/tmp/include/master.pb.h;/cpp/src/tmp/include/master_service.grpc.pb.h;/cpp/src/tmp/include/master_service.pb.h;/cpp/src/tmp/include/meta_graph.grpc.pb.h;/cpp/src/tmp/include/meta_graph.pb.h;/cpp/src/tmp/include/named_tensor.grpc.pb.h;/cpp/src/tmp/include/named_tensor.pb.h;/cpp/src/tmp/include/queue_runner.grpc.pb.h;/cpp/src/tmp/include/queue_runner.pb.h;/cpp/src/tmp/include/remote_tensor_handle.grpc.pb.h;/cpp/src/tmp/include/remote_tensor_handle.pb.h;/cpp/src/tmp/include/replay_log.grpc.pb.h;/cpp/src/tmp/include/replay_log.pb.h;/cpp/src/tmp/include/rewriter_config.grpc.pb.h;/cpp/src/tmp/include/rewriter_config.pb.h;/cpp/src/tmp/include/saved_model.grpc.pb.h;/cpp/src/tmp/include/saved_model.pb.h;/cpp/src/tmp/include/saved_object_graph.grpc.pb.h;/cpp/src/tmp/include/saved_object_graph.pb.h;/cpp/src/tmp/include/saver.grpc.pb.h;/cpp/src/tmp/include/saver.pb.h;/cpp/src/tmp/include/struct.grpc.pb.h;/cpp/src/tmp/include/struct.pb.h;/cpp/src/tmp/include/tensor_bundle.grpc.pb.h;/cpp/src/tmp/include/tensor_bundle.pb.h;/cpp/src/tmp/include/tensorflow_server.grpc.pb.h;/cpp/src/tmp/include/tensorflow_server.pb.h;/cpp/src/tmp/include/trackable_object_graph.grpc.pb.h;/cpp/src/tmp/include/trackable_object_graph.pb.h;/cpp/src/tmp/include/transport_options.grpc.pb.h;/cpp/src/tmp/include/transport_options.pb.h;/cpp/src/tmp/include/verifier_config.grpc.pb.h;/cpp/src/tmp/include/verifier_config.pb.h;/cpp/src/tmp/include/worker.grpc.pb.h;/cpp/src/tmp/include/worker.pb.h;/cpp/src/tmp/include/worker_service.grpc.pb.h;/cpp/src/tmp/include/worker_service.pb.h;/cpp/src/tmp/include/dnn.grpc.pb.h;/cpp/src/tmp/include/dnn.pb.h;/cpp/src/tmp/include/classification.grpc.pb.h;/cpp/src/tmp/include/classification.pb.h;/cpp/src/tmp/include/get_model_metadata.grpc.pb.h;/cpp/src/tmp/include/get_model_metadata.pb.h;/cpp/src/tmp/include/get_model_status.grpc.pb.h;/cpp/src/tmp/include/get_model_status.pb.h;/cpp/src/tmp/include/inference.grpc.pb.h;/cpp/src/tmp/include/inference.pb.h;/cpp/src/tmp/include/input.grpc.pb.h;/cpp/src/tmp/include/input.pb.h;/cpp/src/tmp/include/model.grpc.pb.h;/cpp/src/tmp/include/model.pb.h;/cpp/src/tmp/include/model_management.grpc.pb.h;/cpp/src/tmp/include/model_management.pb.h;/cpp/src/tmp/include/model_service.grpc.pb.h;/cpp/src/tmp/include/model_service.pb.h;/cpp/src/tmp/include/predict.grpc.pb.h;/cpp/src/tmp/include/predict.pb.h;/cpp/src/tmp/include/prediction_log.grpc.pb.h;/cpp/src/tmp/include/prediction_log.pb.h;/cpp/src/tmp/include/prediction_service.grpc.pb.h;/cpp/src/tmp/include/prediction_service.pb.h;/cpp/src/tmp/include/regression.grpc.pb.h;/cpp/src/tmp/include/regression.pb.h;/cpp/src/tmp/include/session_service.grpc.pb.h;/cpp/src/tmp/include/session_service.pb.h;/cpp/src/tmp/include/log_collector_config.grpc.pb.h;/cpp/src/tmp/include/log_collector_config.pb.h;/cpp/src/tmp/include/logging_config.grpc.pb.h;/cpp/src/tmp/include/logging_config.pb.h;/cpp/src/tmp/include/model_server_config.grpc.pb.h;/cpp/src/tmp/include/model_server_config.pb.h;/cpp/src/tmp/include/monitoring_config.grpc.pb.h;/cpp/src/tmp/include/monitoring_config.pb.h;/cpp/src/tmp/include/platform_config.grpc.pb.h;/cpp/src/tmp/include/platform_config.pb.h;/cpp/src/tmp/include/ssl_config.grpc.pb.h;/cpp/src/tmp/include/ssl_config.pb.h;/cpp/src/tmp/include/logging.grpc.pb.h;/cpp/src/tmp/include/logging.pb.h;/cpp/src/tmp/include/file_system_storage_path_source.grpc.pb.h;/cpp/src/tmp/include/file_system_storage_path_source.pb.h;/cpp/src/tmp/include/static_storage_path_source.grpc.pb.h;/cpp/src/tmp/include/static_storage_path_source.pb.h;/cpp/src/tmp/include/class_registration_test.grpc.pb.h;/cpp/src/tmp/include/class_registration_test.pb.h;/cpp/src/tmp/include/status.grpc.pb.h;/cpp/src/tmp/include/status.pb.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/cpp/src/tmp/include" TYPE FILE FILES
    "/cpp/src/tmp/../gen/tensorflow/core/example/example.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/example/example.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/example/example_parser_configuration.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/example/example_parser_configuration.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/example/feature.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/example/feature.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/allocation_description.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/allocation_description.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/api_def.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/api_def.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/attr_value.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/attr_value.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/cost_graph.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/cost_graph.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/device_attributes.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/device_attributes.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/function.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/function.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/graph.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/graph.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/graph_transfer_info.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/graph_transfer_info.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/kernel_def.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/kernel_def.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/log_memory.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/log_memory.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/node_def.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/node_def.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/op_def.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/op_def.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/reader_base.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/reader_base.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/remote_fused_graph_execute_info.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/remote_fused_graph_execute_info.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/resource_handle.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/resource_handle.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/step_stats.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/step_stats.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/summary.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/summary.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/tensor.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/tensor.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/tensor_description.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/tensor_description.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/tensor_shape.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/tensor_shape.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/tensor_slice.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/tensor_slice.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/types.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/types.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/variable.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/variable.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/versions.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/framework/versions.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/lib/core/error_codes.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/lib/core/error_codes.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/autotuning.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/autotuning.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/bfc_memory_map.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/bfc_memory_map.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/cluster.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/cluster.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/config.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/config.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/control_flow.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/control_flow.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/conv_autotuning.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/conv_autotuning.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/critical_section.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/critical_section.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/debug.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/debug.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/debug_event.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/debug_event.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/device_filters.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/device_filters.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/device_properties.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/device_properties.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/eager_service.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/eager_service.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/error_codes.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/error_codes.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/graph_debug_info.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/graph_debug_info.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/master.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/master.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/master_service.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/master_service.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/meta_graph.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/meta_graph.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/named_tensor.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/named_tensor.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/queue_runner.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/queue_runner.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/remote_tensor_handle.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/remote_tensor_handle.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/replay_log.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/replay_log.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/rewriter_config.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/rewriter_config.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/saved_model.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/saved_model.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/saved_object_graph.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/saved_object_graph.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/saver.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/saver.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/struct.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/struct.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/tensor_bundle.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/tensor_bundle.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/tensorflow_server.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/tensorflow_server.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/trackable_object_graph.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/trackable_object_graph.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/transport_options.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/transport_options.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/verifier_config.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/verifier_config.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/worker.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/worker.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/worker_service.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/core/protobuf/worker_service.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/stream_executor/dnn.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow/stream_executor/dnn.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/classification.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/classification.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/get_model_metadata.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/get_model_metadata.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/get_model_status.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/get_model_status.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/inference.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/inference.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/input.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/input.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/model.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/model.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/model_management.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/model_management.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/model_service.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/model_service.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/predict.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/predict.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/prediction_log.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/prediction_log.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/prediction_service.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/prediction_service.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/regression.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/regression.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/session_service.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/apis/session_service.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/config/log_collector_config.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/config/log_collector_config.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/config/logging_config.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/config/logging_config.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/config/model_server_config.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/config/model_server_config.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/config/monitoring_config.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/config/monitoring_config.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/config/platform_config.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/config/platform_config.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/config/ssl_config.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/config/ssl_config.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/core/logging.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/core/logging.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/sources/storage_path/file_system_storage_path_source.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/sources/storage_path/file_system_storage_path_source.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/sources/storage_path/static_storage_path_source.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/sources/storage_path/static_storage_path_source.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/util/class_registration_test.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/util/class_registration_test.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/util/status.grpc.pb.h"
    "/cpp/src/tmp/../gen/tensorflow_serving/util/status.pb.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/cpp/src/tmp/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
