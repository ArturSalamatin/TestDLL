cmake_minimum_required(VERSION 3.14)

project(DLLtester VERSION 1.0 LANGUAGES C CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory(dll_src)

add_executable(dll_user main.cpp)
target_link_libraries(dll_user PUBLIC TestDLL)

target_include_directories(dll_user PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/dll_src/"
                          )
                          
message(PROJECT_BINARY_DIR=${PROJECT_BINARY_DIR})

install(TARGETS dll_user
    RUNTIME DESTINATION "${PROJECT_BINARY_DIR}/bin")
install(TARGETS TestDLL
    RUNTIME DESTINATION "${PROJECT_BINARY_DIR}/bin")