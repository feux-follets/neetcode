add_library(pch INTERFACE)
target_precompile_headers(pch INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/stdc++.h")

file(GLOB NEETCODE_SRC CONFIGURE_DEPENDS
		"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach (src ${NEETCODE_SRC})
	get_filename_component(name "${src}" NAME_WE)

	add_library(${name} OBJECT ${src})
	target_link_libraries(${name} PRIVATE pch)
endforeach ()