cmake_minimum_required(VERSION 3.9.2)

project(C_CPP_TEST VERSION 1.0)

set(CMAKE_C_FLAGS "-std=c99")
set(CMAKE_C_FLAGS "-D_DEFAULT_SOURCE")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_MAJOR_VERSION 0)
set(PROJECT_MINOR_VERSION 1)
set(PROJECT_PATCH_VERSION 0)
set(PROJECT_VERSION ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION}.${PROJECT_PATCH_VERSION})

configure_file(version.h.in version.h)

# openssl...
# find_package(OpenSSL REQUIRED)
# message("OPENSSL_INCLUDE_DIR : ${OPENSSL_INCLUDE_DIR}")
# include_directories(${OPENSSL_INCLUDE_DIR})

#boost...
# find_package(Boost REQUIRED COMPONENTS system thread program_options regex python)
# find_package(Boost REQUIRED COMPONENTS system thread program_options regex)
# include_directories(${Boost_INCLUDE_DIRS})

#libco...
# set(libco_DIR "${PROJECT_SOURCE_DIR}")
# find_package(libco REQUIRED)
# include_directories(${LIBCO_INCLUDE_DIRS})

# add_executable(libco_test_server libco_test_server.cpp)
# target_link_libraries(libco_test_server ${LIBCO_LIBRARIES} pthread dl)
# target_include_directories(libco_test_server PUBLIC "${PROJECT_BINARY_DIR}")
# set_property(TARGET libco_test_server PROPERTY CXX_STANDARD 17)

# add_executable(libco_test_client libco_test_client.cpp)
# target_link_libraries(libco_test_client ${LIBCO_LIBRARIES} pthread dl)
# target_include_directories(libco_test_client PUBLIC "${PROJECT_BINARY_DIR}")
# set_property(TARGET libco_test_client PROPERTY CXX_STANDARD 17)

# add_executable(server server.c)
# target_link_libraries(server ${OPENSSL_LIBRARIES})
# target_include_directories(server PUBLIC "${PROJECT_BINARY_DIR}")

# add_executable(client client.c trojan_header.c)
# target_link_libraries(client ${OPENSSL_LIBRARIES})
# target_include_directories(client PUBLIC "${PROJECT_BINARY_DIR}")

# export(TARGETS server client FILE "${PROJECT_BINARY_DIR}/CPPTestTargets.cmake")

# add_custom_command(TARGET server POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/cert $<TARGET_FILE_DIR:server>)

# add_executable(trojan_test trojan_header.c trojan_header_test.c)
# target_link_libraries(trojan_test ${OPENSSL_LIBRARIES})
# target_include_directories(trojan_test PUBLIC "${PROJECT_BINARY_DIR}")

# add_executable(epoll_test epoll_test.c)
# target_include_directories(trojan_test PUBLIC "${PROJECT_BINARY_DIR}")

add_executable(hello hello.cpp)
target_link_libraries(hello ${Boost_LIBRARIES})
target_include_directories(hello PUBLIC "${PROJECT_BINARY_DIR}")
set_property(TARGET hello PROPERTY CXX_STANDARD 17)

# add_library(py_hello py_hello.cpp)
# target_link_libraries(hello ${Boost_LIBRARIES})
# target_include_directories(py_hello PUBLIC "${PROJECT_BINARY_DIR}")
# set_property(TARGET py_hello PROPERTY CXX_STANDARD 17)
