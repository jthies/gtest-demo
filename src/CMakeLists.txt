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

