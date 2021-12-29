add_library(example)

target_sources(example
  PRIVATE
    functions.cpp
  PUBLIC
    functions.hpp
    vector.hpp
  )

target_include_directories(example
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

add_executable(main)
target_sources(main PRIVATE main.cpp)
target_link_libraries(main example)

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(example
    PUBLIC
      "--coverage"
    )
  target_link_options(example
    INTERFACE
      "--coverage"
    )
endif()
