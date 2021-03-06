cmake_minimum_required(VERSION 2.8)
project(MwEnet)

set(CMAKE_MODULE_PATH
	${CMAKE_MODULE_PATH}
	${CMAKE_SOURCE_DIR}/CMake
	${CMAKE_SOURCE_DIR}/CMake/Dependencies
	${CMAKE_SOURCE_DIR}/CMake/Compiler
	${CMAKE_SOURCE_DIR}/CMake/OperatingSystems
	${CMAKE_SOURCE_DIR}/CMake/Options
	${CMAKE_SOURCE_DIR}/CMake/Packages
)

if (MSVC)
	# Exception handler model.
	add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS -DWIN32)
	
	set(WINDOWS_ENET_DEPENDENCIES "ws2_32;winmm")
else (MSVC)
	set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")
endif (MSVC)


option(BUILD_EXAMPLES "Compile examples using MwENet" ON)

# Source files.
set(SOURCES_MW
	src/mw/enetclient.cpp
	src/mw/enetnetwork.cpp
	src/mw/enetserver.cpp
	src/mw/localnetwork.cpp
)
# End of source files.

find_package(ENet)

if(ENet_NOT_FOUND)
  add_subdirectory(third/partyEnet)
  include_directories(thirdparty/Enet/src)
  set(${ENet_LIBRARY} Enet)
  add_library(MwEnet Enet ${SOURCES_MW})
else() # ENet is FOUND
  message("-- ENet was found!")
  include_directories(SYSTEM
    "${CMAKE_SOURCE_DIR}/include/"
    ${ENet_INCLUDE_DIRS}
    )
  add_library(${CMAKE_PROJECT_NAME} ${ENet_LIBRARY} ${SOURCES_MW})
endif()

  target_link_libraries(${CMAKE_PROJECT_NAME} ${ENet_LIBRARY})

if(BUILD_EXAMPLES)
  add_subdirectory("${CMAKE_SOURCE_DIR}/examples/")
endif()

