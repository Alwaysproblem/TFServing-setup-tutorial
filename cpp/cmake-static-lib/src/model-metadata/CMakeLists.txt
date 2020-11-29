cmake_minimum_required(VERSION 3.0.0)
project(model-metadata VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(/cpp/src/gen)
include_directories(/usr/local/include)

link_directories(/usr/local/lib)
link_directories(/grpc/cmake/build)
link_directories(/usr/lib/x86_64-linux-gnu)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "./*.cc" "/cpp/src/gen/*.cc")

add_executable(model-metadata ${SOURCES})
target_link_libraries(${PROJECT_NAME} -lboost_program_options -lprotobuf -pthread -lgrpc++ -lgrpc -lgrpc++_reflection)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
