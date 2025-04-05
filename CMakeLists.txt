# useful links
# https://cgold.readthedocs.io/en/latest/tutorials/libraries/static-shared.html
# https://cgold.readthedocs.io/en/latest/overview/cmake-can.html
# https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake


cmake_minimum_required(VERSION 3.14)

project(DLLtester VERSION 1.0 LANGUAGES C CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory(dll_src)
add_subdirectory(dll_user)

# install section
# to copy generated binaries
install(TARGETS dll_user
    # copy *.exe file
    DESTINATION ${PROJECT_BINARY_DIR}/bin)
install(TARGETS TestDLL
    # copy *.dll file
    RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin
    # copy public header(s)
    PUBLIC_HEADER DESTINATION ${PROJECT_BINARY_DIR}/bin)
# install(FILES ${PROJECT_BINARY_DIR}/dll_src/Debug/TestDLL.lib
#     # copy *.lib file
#     DESTINATION ${PROJECT_BINARY_DIR}/bin)