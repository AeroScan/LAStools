cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_SUPPRESS_REGENERATION true)
project("LAStools")

if (!MSVC)
	add_compile_options(-O3 -Wall -Wno-strict-aliasing)
else()
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

option(BUILD_SHARED_LIBS "Build LASlib as DLL" OFF)

if (BUILD_SHARED_LIBS AND UNIX AND NOT APPLE)
	set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib/LASlib")
endif()

add_subdirectory(LASlib/src)
add_subdirectory(src)
if (EXISTS src_full)
	add_subdirectory(src_full)
endif()

enable_testing()

add_executable(lasinfo_test ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_lasinfo.cpp)
target_link_libraries(lasinfo_test lasinfo)

add_test(lasinfo_gtest lasinfo_test)

add_executable(txt2las_test ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_txt2las.cpp)
target_link_libraries(txt2las_test txt2las)

add_test(txt2las_gtest txt2las_test)

add_executable(lasmerge_test ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_lasmerge.cpp)
target_link_libraries(lasmerge_test lasmerge)

add_test(lasmerge_gtest lasmerge_test)