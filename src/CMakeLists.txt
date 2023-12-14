if (!MSVC)
add_compile_options(-Wno-deprecated -Wno-write-strings -Wno-unused-result)
endif()
add_definitions(-DNDEBUG )

include_directories(../LASzip/src)
include_directories(../LASlib/inc)

set(GEOPROJECTION_TARGETS
	laszip
	lasinfo
	lasprecision
	txt2las
	las2las
	lasmerge
)
set(STANDALONE_TARGETS
	las2txt
	lasdiff
	lasindex
	# txt2las
)
set(ALL_TARGETS ${GEOPROJECTION_TARGETS} ${STANDALONE_TARGETS})

foreach(TARGET ${GEOPROJECTION_TARGETS})
	add_library(${TARGET} ${TARGET}.cpp ${TARGET}lib.cpp geoprojectionconverter.cpp)
endforeach(TARGET)

foreach(TARGET ${STANDALONE_TARGETS})
	add_library(${TARGET} ${TARGET}.cpp ${TARGET}lib.cpp)
endforeach(TARGET)

foreach(TARGET ${ALL_TARGETS})
	target_link_libraries(${TARGET} LASlib)
	target_include_directories(${TARGET} PUBLIC ${CMAKE_SOURCE_DIR}/include)
	set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin64)
	set_target_properties(${TARGET} PROPERTIES OUTPUT_NAME ${TARGET}64)
	install(TARGETS ${TARGET} RUNTIME DESTINATION bin)
endforeach(TARGET)
