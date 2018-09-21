include(
	CMakeParseArguments
)

function(
	add_mizuiro_test
	PATH_NAME
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
		_NO_CODE
	)
		set(
			NO_CODE
			NO_CODE
		)
	endif()

	fcppt_utils_add_test(
		${FCPPT_UTILS_PROJECT_SOURCE_DIR}/test
		${PATH_NAME}
		${NO_CODE}
		LINK_LIBS
			mizuiro_interface
			${_LINK_LIBS}
	)
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
	view
)
