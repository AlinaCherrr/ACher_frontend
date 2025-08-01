add_library(robocalc robocalc.cpp robocalc.hpp)
set_property(TARGET robocalc PROPERTY CXX_STANDARD 20)
target_include_directories(robocalc PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

add_executable(main "main.cpp")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)
target_link_libraries(main robocalc)
