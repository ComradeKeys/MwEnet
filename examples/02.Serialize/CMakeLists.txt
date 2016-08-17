add_executable(example02_server ${ENet_LIBRARY} src/server.cpp)
add_executable(example02_client ${ENet_LIBRARY} src/client.cpp)

include_directories("${CMAKE_SOURCE_DIR}/thirdparty/cereal-1.2.1/include/")

target_link_libraries(example02_server MwEnet)
target_link_libraries(example02_client MwEnet)
