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
	set(CMAKE_CXX_FLAGS "-std=c++11")
endif (MSVC)

# Source files.
set(SOURCES_MW
	src/mw/enetclient.cpp
	src/mw/enetclient.h
	src/mw/enetnetwork.cpp
	src/mw/enetnetwork.h
	src/mw/network.h
	src/mw/packet.h
	src/mw/enetserver.cpp
	src/mw/enetserver.h
	src/mw/localnetwork.cpp
	src/mw/localnetwork.h
	src/mw/server.h
)
# End of source files.

find_package(ENet)

if(ENet_NOT_FOUND)
  add_subdirectory(Enet)
  include_directories(Enet/src)
  add_library(MwEnet Enet ${SOURCES_MW})

else() # ENet is FOUND
  message("-- ENet was found!")
  include_directories(SYSTEM ${ENet_INCLUDE_DIRS})  
  add_library(MwEnet Enet ${SOURCES_MW})
  target_link_libraries(${CMAKE_PROJECT_NAME} ${ENet_LIBRARY})

endif()







