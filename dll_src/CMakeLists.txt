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
                       PUBLIC_HEADER dll_src/Wrapper.h
                    )
target_compile_definitions(TestDLL PRIVATE MYLIBRARY_EXPORT)
target_include_directories(TestDLL INTERFACE
                          "${PROJECT_SOURCE_DIR}/dll_src"
                          )
target_include_directories(TestDLL PRIVATE
                          "${PROJECT_SOURCE_DIR}/dll_src"
                          "${PROJECT_SOURCE_DIR}/dll_src/src"
                          )

message(PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR})
