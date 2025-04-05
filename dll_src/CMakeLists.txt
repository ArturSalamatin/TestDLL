# Add the source files to the project
set(SOURCE_FILES
    src/Operator.cpp
    src/Manager.cpp
    Wrapper.cpp
)

# Add the header files to the project
set(HEADER_FILES
    src/Operator.h
    src/Manager.h
    Wrapper.h
)

# Create the shared library (DLL)
add_library(TestDLL SHARED ${HEADER_FILES} 
                            ${SOURCE_FILES})
set_target_properties(TestDLL PROPERTIES 
                        VERSION ${PROJECT_VERSION}
                        PUBLIC_HEADER Wrapper.h)
target_compile_definitions(TestDLL PRIVATE MYLIBRARY_EXPORT)
target_include_directories(TestDLL PRIVATE
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/dll_src"
                          "${PROJECT_SOURCE_DIR}/dll_src/src"
                          )

message(PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR})

install(TARGETS TestDLL
    # copy *.dll file
    RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin
    # copy public header(s)
    PUBLIC_HEADER DESTINATION ${PROJECT_BINARY_DIR}/bin)
install(FILES ${PROJECT_BINARY_DIR}/dll_src/Debug/TestDLL.lib
    # copy *.lib file
    DESTINATION ${PROJECT_BINARY_DIR}/bin)