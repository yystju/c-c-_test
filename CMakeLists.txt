cmake_minimum_required(VERSION 3.9.2)

project(OpenSSLTest VERSION 1.0)

set(CMAKE_C_FLAGS "-std=c99")
set(CMAKE_C_FLAGS "-D_DEFAULT_SOURCE")

configure_file(version.h.in version.h)

# openssl...
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

#boost...
find_package(Boost REQUIRED COMPONENTS system thread program_options regex python)
include_directories(${Boost_INCLUDE_DIRS})

#libuv...
find_package(libuv REQUIRED)
include_directories(${libuv_INCLUDE_DIRS})

add_executable(server server.c)
target_link_libraries(server ${OPENSSL_LIBRARIES})
target_include_directories(server PUBLIC "${PROJECT_BINARY_DIR}")

add_executable(client client.c trojan_header.c)
target_link_libraries(client ${OPENSSL_LIBRARIES})
target_include_directories(client PUBLIC "${PROJECT_BINARY_DIR}")

add_custom_command(TARGET server POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/cert $<TARGET_FILE_DIR:server>)

add_executable(trojan_test trojan_header.c trojan_header_test.c)
target_link_libraries(trojan_test ${OPENSSL_LIBRARIES})
target_include_directories(trojan_test PUBLIC "${PROJECT_BINARY_DIR}")

add_executable(epoll_test epoll_test.c)
target_include_directories(trojan_test PUBLIC "${PROJECT_BINARY_DIR}")

add_executable(hello hello.cpp)
target_link_libraries(hello ${Boost_LIBRARIES})
target_include_directories(trojan_test PUBLIC "${PROJECT_BINARY_DIR}")


# add_library(py_hello py_hello.cpp)
# target_link_libraries(hello ${Boost_LIBRARIES})
# target_include_directories(trojan_test PUBLIC "${PROJECT_BINARY_DIR}")
