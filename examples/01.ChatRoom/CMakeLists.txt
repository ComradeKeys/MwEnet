

add_executable(example01_server ${ENet_LIBRARY} src/server.cpp)
add_executable(example01_client ${ENet_LIBRARY} src/client.cpp)

target_link_libraries(example01_server MwEnet)
target_link_libraries(example01_client MwEnet)
