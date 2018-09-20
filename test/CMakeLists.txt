include(
	CMakeParseArguments
)

option(
	MIZUIRO_CATCH_LINK_STATIC
	"Link to catch statically"
	OFF
)

if(
	MIZUIRO_CATCH_LINK_STATIC
)
	set(
		MIZUIRO_CATCH_LIB_TYPE
		"STATIC"
	)
else()
	set(
		MIZUIRO_CATCH_LIB_TYPE
		"SHARED"
	)
endif()

add_library(
	mizuiro_catch_main
	${MIZUIRO_CATCH_LIB_TYPE}
	catch_main.cpp
)

set_target_properties(
	mizuiro_catch_main
	PROPERTIES
	FOLDER
	mizuiro
)

target_link_libraries(
	mizuiro_catch_main
	PRIVATE
	Catch2::Catch2
)

function(
	add_mizuiro_test
	PATHNAME
)
	set(
		OPTION_ARGS
		NO_CODE
	)

	cmake_parse_arguments(
		""
		"${OPTION_ARGS}"
		""
		""
		${ARGN}
	)

	string(
		REGEX
		REPLACE
		"\\/"
		"_"
		TESTNAME
		${PATHNAME}
	)

	set(
		MIZUIRO_TEST_NAME
		mizuiro_test_${TESTNAME}
	)

	add_executable(
		${MIZUIRO_TEST_NAME}
		${PATHNAME}.cpp
	)

	fcppt_utils_set_target_compiler_flags(
		${MIZUIRO_TEST_NAME}
	)

	fcppt_utils_set_target_folder(
		${MIZUIRO_TEST_NAME}
		tests
		${PATHNAME}
	)

	target_link_libraries(
		${MIZUIRO_TEST_NAME}
		PRIVATE
		mizuiro_interface
	)

	target_include_directories(
		${MIZUIRO_TEST_NAME}
		PRIVATE
		include
	)

	if(
		NOT ${_NO_CODE}
	)
		target_link_libraries(
			${MIZUIRO_TEST_NAME}
			PRIVATE
			mizuiro_catch_main
			Catch2::Catch2
		)

		add_test(
			NAME
			${MIZUIRO_TEST_NAME}
			COMMAND
			${MIZUIRO_TEST_NAME}
		)
	endif()
endfunction()

add_mizuiro_test(
	algorithm/clone
)

add_mizuiro_test(
	can_copy
	NO_CODE
)

add_mizuiro_test(
	convert/rgb_srgb
)

add_mizuiro_test(
	convert/shuffle
)

add_mizuiro_test(
	dynamic
)

add_mizuiro_test(
	empty_view
)

add_mizuiro_test(
	heterogenous
)

add_mizuiro_test(
	homogenous
)

add_mizuiro_test(
	image
)

add_mizuiro_test(
	iterator_position
)

add_mizuiro_test(
	prepare_store
)

add_mizuiro_test(
	range
)

add_mizuiro_test(
	view
)
