
# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")
set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/btree.hpp"
                "${PROJECT_SOURCE_DIR}/include/loader.hpp")

# Add all the src cpp files with the headers
add_executable(btree.o main.cpp ${HEADER_LIST})

# Ensure everything in `include` is included.
target_include_directories(btree.o PUBLIC ../include)

# C++11
target_compile_features(btree.o PUBLIC cxx_std_11)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
