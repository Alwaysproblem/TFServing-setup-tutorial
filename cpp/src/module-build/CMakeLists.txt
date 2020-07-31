cmake_minimum_required(VERSION 3.0.0)
project(tfclient VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(/cpp/src/gen)
include_directories(/usr/local/include)

link_directories(/usr/local/lib)
link_directories(/grpc/cmake/build)
link_directories(/usr/lib/x86_64-linux-gnu)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "/cpp/src/gen/*.cc")
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "/cpp/src/gen/*.h")

add_library(tfclient STATIC ${SOURCES})

set_target_properties(tfclient PROPERTIES OUTPUT_NAME "tfclient")

target_link_libraries(${PROJECT_NAME} -lboost_program_options -lprotobuf -pthread -lgrpc++ -lgrpc -lgrpc++_reflection)

INSTALL(TARGETS tfclient
    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
    ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib)

# # set(BASE /cpp/src/gen/)
# foreach ( file ${HEADERS} )
#     get_filename_component( dir ${file} ABSOLUTE)
#     file(RELATIVE_PATH ITEM "/cpp/src/gen" dir)
#     # string(REPLACE "" "/cpp/src/gen/" ITEM_PATH ${dir})
#     # message(${ITEM_PATH})
#     install( FILES ${file} DESTINATION ${PROJECT_SOURCE_DIR}/include/${ITEM} )
# endforeach()

INSTALL(FILES ${HEADERS}  DESTINATION ${PROJECT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include(CPack)
