include(
	CMakeParseArguments
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

	if(
		ENABLE_FCPPT
	)
		if(
			_NO_CODE
		)
			set(
				NO_CODE
				NO_CODE
			)
		endif()

		fcppt_utils_add_test(
			${FCPPT_UTILS_PROJECT_SOURCE_DIR}/test
			${PATHNAME}
			${NO_CODE}
			INCLUDE_DIRS
				${MIZUIRO_SOURCE_DIR}/include
				${CMAKE_CURRENT_SOURCE_DIR}/include
		)
	else()
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

		mizuiro_target_flags(
			${MIZUIRO_TEST_NAME}
		)

		target_include_directories(
			${MIZUIRO_TEST_NAME}
			PRIVATE
			include
		)

		if(
			NOT ${_NO_CODE}
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

			target_include_directories(
				${MIZUIRO_TEST_NAME}
				SYSTEM
				PRIVATE
				${Boost_INCLUDE_DIR}
			)

			target_link_libraries(
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
		endif()
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
	convert/swizzle
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
