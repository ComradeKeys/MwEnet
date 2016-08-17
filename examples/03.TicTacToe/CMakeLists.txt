add_executable(example03_server ${ENet_LIBRARY} src/server.cpp)
add_executable(example03_client ${ENet_LIBRARY} src/client.cpp)

target_link_libraries(example03_server MwEnet)
target_link_libraries(example03_client MwEnet)
