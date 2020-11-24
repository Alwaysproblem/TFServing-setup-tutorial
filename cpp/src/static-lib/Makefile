# source files.
TFDIRS = $(shell find /cpp/src/gen -type d)

TARGET  := libtfserving.a

# compile and lib parameter
CC      := g++
AR      = ar
RANLIB  = ranlib
LIBS    := -lboost_program_options -lprotobuf -pthread -lgrpc++ -lgrpc -lgpr \
		  -laddress_sorting -lgrpc++_alts -lgrpc++_error_details -lgrpc++_reflection \
		  -lgrpc++_unsecure -lgrpc_plugin_support -lgrpc_unsecure -lgrpcpp_channelz -lupb \
		  -labsl_base \
		  -labsl_str_format_internal \
		  -labsl_strings_internal \
		  -labsl_strings \
		  -labsl_dynamic_annotations \
		  -labsl_flags_program_name \
		  -labsl_time \
		  -labsl_int128 \
		  -labsl_flags_usage \
		  -labsl_malloc_internal \
		  -labsl_city \
		  -labsl_random_internal_randen_hwaes \
		  -labsl_raw_logging_internal \
		  -labsl_random_internal_seed_material \
		  -labsl_flags_parse \
		  -labsl_random_distributions \
		  -labsl_failure_signal_handler \
		  -labsl_spinlock_wait \
		  -labsl_random_seed_gen_exception \
		  -labsl_bad_variant_access \
		  -labsl_log_severity \
		  -labsl_examine_stack \
		  -labsl_graphcycles_internal \
		  -labsl_leak_check_disable \
		  -labsl_scoped_set_env \
		  -labsl_debugging_internal \
		  -labsl_cord \
		  -labsl_synchronization \
		  -labsl_periodic_sampler \
		  -labsl_raw_hash_set \
		  -labsl_stacktrace \
		  -labsl_flags_usage_internal \
		  -labsl_flags_internal \
		  -labsl_time_zone \
		  -labsl_exponential_biased \
		  -labsl_throw_delegate \
		  -labsl_bad_optional_access \
		  -labsl_random_internal_pool_urbg \
		  -labsl_symbolize \
		  -labsl_flags_marshalling \
		  -labsl_random_seed_sequences \
		  -labsl_status \
		  -labsl_hash \
		  -labsl_random_internal_randen \
		  -labsl_flags_config \
		  -labsl_random_internal_randen_hwaes_impl \
		  -labsl_random_internal_randen_slow \
		  -labsl_flags_registry \
		  -labsl_demangle_internal \
		  -labsl_flags \
		  -labsl_bad_any_cast_impl \
		  -labsl_leak_check \
		  -labsl_random_internal_distribution_test_util \
		  -labsl_civil_time \
		  -labsl_hashtablez_sampler \
		  -lcares -lz -lssl -lcrypto \
		  -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed \
		  -ldl

LDFLAGS := -L/usr/local/lib -L/grpc/cmake/build -L/usr/lib -L/grpc/cmake/build/third_party/boringssl-with-bazel \
		  -L/grpc/cmake/build/third_party/abseil-cpp/absl/base \
		  -L/grpc/cmake/build/third_party/abseil-cpp/absl/strings \
		  -L/grpc/cmake/build/third_party/abseil-cpp/absl/container \
		  -L/grpc/cmake/build/third_party/abseil-cpp/absl/flags \
		  -L/grpc/cmake/build/third_party/abseil-cpp/absl/synchronization \
		  -L/grpc/cmake/build/third_party/zlib -L/grpc/cmake/build/third_party/abseil-cpp/absl/time \
		  -L/grpc/cmake/build/third_party/abseil-cpp/absl/random \
		  -L/grpc/cmake/build/third_party/abseil-cpp/absl/types -L/grpc/cmake/build/third_party/boringssl-with-bazel \
		  -L/grpc/cmake/build/third_party/abseil-cpp/absl/status -L/grpc/cmake/build/third_party/abseil-cpp/absl/hash \
		  -L/grpc/cmake/build/third_party/abseil-cpp/absl/debugging -L/grpc/cmake/build/third_party/abseil-cpp/absl/numeric \
		  -L/grpc/cmake/build/third_party/cares/cares/lib
DEFINES := -c
INCLUDE := -I/includeh -I/cpp/src/gen
CFLAGS  := -Wall -O3 -std=c++11 $(DEFINES) $(INCLUDE)

SOURCE  := $(foreach dir,$(TFDIRS),$(wildcard $(dir)/**.cc)) $(wildcard *.cc)
OBJ = ./obj
  
OBJS    = $(SOURCE:%.cc=$(OBJ)/%.o)

.PHONY : everything objs clean cleanall rebuild
  
everything : $(TARGET)
  
all : $(TARGET)
  
objs : $(OBJS)

rebuild: cleanall everything

clean :
		rm -rf $(OBJ)

cleanall : clean
		rm -fr $(TARGET)

$(OBJS): $(OBJ)/%.o: %.cc
		@echo Compiling $<
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS) $(LIBS) 

$(TARGET) : $(OBJS)
		$(AR) cruv $(TARGET) $(OBJS)
		$(RANLIB) $(TARGET)
		@echo "Build successful!"