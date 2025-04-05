add_executable(dll_user main.cpp)
target_link_libraries(dll_user PUBLIC TestDLL)

target_include_directories(dll_user PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/dll_src/"
                          )

message(PROJECT_BINARY_DIR=${PROJECT_BINARY_DIR})

install(TARGETS dll_user
    DESTINATION ${PROJECT_BINARY_DIR}/bin)