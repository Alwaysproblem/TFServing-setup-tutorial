import tensorflow as tf
from tensorflow.python.compiler.tensorrt import trt_convert as trt


output_saved_model_dir = "./save/CTR_tensorRT/1"

input_saved_model_dir="./save/CTR_tensorRT/1"


# A template RewriterConfig proto used to create a TRT-enabled
# RewriterConfig. If None, it will use a default one.
# "rewriter_config_template",

# The maximum GPU temporary memory which the TRT engine can use at
# execution time. This corresponds to the 'workspaceSize' parameter of
# nvinfer1::IBuilder::setMaxWorkspaceSize().
# "max_workspace_size_bytes",

# One of TrtPrecisionMode.supported_precision_modes().
# "precision_mode",

# The minimum number of nodes required for a subgraph to be replaced by
# TRTEngineOp.
# "minimum_segment_size",

# Whether to generate dynamic TRT ops which will build the TRT network
# and engine at run time.
# This option should be set to True in TF 2.0.
# "is_dynamic_op",

# Max number of cached TRT engines in dynamic TRT ops. If the number of
# cached engines is already at max but none of them can serve the input,
# the TRTEngineOp will fall back to run the TF function based on which
# the TRTEngineOp is created.
# "maximum_cached_engines",

# This argument is ignored if precision_mode is not INT8. If set to
# True, a calibration graph will be created to calibrate the missing
# ranges. The calibration graph must be converted to an inference graph
# by running calibration with calibrate(). If set to False, quantization
# nodes will be expected for every tensor in the graph (exlcuding those
# which will be fused). If a range is missing, an error will occur.
# Please note that accuracy may be negatively affected if there is a
# mismatch between which tensors TRT quantizes and which tensors were
# trained with fake quantization.
# "use_calibration",

# Max size for the input batch.
# This option is deprecated in TF 2.0.
# "max_batch_size",


# DEFAULT_TRT_CONVERSION_PARAMS = TrtConversionParams(
#     rewriter_config_template=None,
#     max_workspace_size_bytes=DEFAULT_TRT_MAX_WORKSPACE_SIZE_BYTES,
#     precision_mode=TrtPrecisionMode.FP32,
#     minimum_segment_size=3,
#     is_dynamic_op=True,
#     maximum_cached_engines=1,
#     use_calibration=True,
#     max_batch_size=1)

conversion_params = trt.DEFAULT_TRT_CONVERSION_PARAMS._replace(
    precision_mode = "FP32",
    max_batch_size = 100
    )

converter = tf.experimental.tensorrt.Converter(
   input_saved_model_dir=input_saved_model_dir, conversion_params=conversion_params)

converter.convert()
converter.save(output_saved_model_dir)