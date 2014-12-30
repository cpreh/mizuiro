function(
	add_mizuiro_test
	PATHNAME
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
		test_${TESTNAME}
	)

	add_executable(
		${MIZUIRO_TEST_NAME}
		${PATHNAME}.cpp
	)

	target_compile_definitions(
		${MIZUIRO_TEST_NAME}
		PRIVATE
		BOOST_TEST_MODULE=${TESTNAME}
	)

	if(
		Boost_USE_STATIC_LIBS
	)
		target_compile_definitions(
			${MIZUIRO_TEST_NAME}
			PRIVATE
			BOOST_TEST_NO_LIB
		)
	else()
		target_compile_definitions(
			${MIZUIRO_TEST_NAME}
			PRIVATE
			BOOST_TEST_DYN_LINK
		)
	endif()

	if(
		ENABLE_FCPPT
	)
		fcppt_utils_set_target_compiler_flags(
			${MIZUIRO_TEST_NAME}
		)
	endif()

	target_include_directories(
		${MIZUIRO_TEST_NAME}
		PRIVATE
		${Boost_INCLUDE_DIR}
	)

	target_link_libraries (
		${MIZUIRO_TEST_NAME}
		PRIVATE
		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	)

	add_test(
		NAME
		${MIZUIRO_TEST_NAME}
		COMMAND
		${MIZUIRO_TEST_NAME}
	)
endfunction()

add_mizuiro_test(algorithm/clone)
add_mizuiro_test(convert/swizzle)
add_mizuiro_test(data)
add_mizuiro_test(dynamic)
add_mizuiro_test(empty_view)
add_mizuiro_test(heterogenous)
add_mizuiro_test(homogenous)
add_mizuiro_test(iterator_position)
add_mizuiro_test(view)
add_mizuiro_test(views_are_compatible)
