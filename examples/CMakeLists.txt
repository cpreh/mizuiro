include_directories(
	"${CMAKE_SOURCE_DIR}/include"
)

function(
	BUILD_MIZUIRO_EXAMPLE
	example
)
	set(
		EXAMPLE_NAME
		"mizuiro_example_${example}"
	)

	add_executable(
		${EXAMPLE_NAME}
		"${example}.cpp"
	)

	mizuiro_target_flags(
		${EXAMPLE_NAME}
	)
endfunction()

build_mizuiro_example(adapted_view)
build_mizuiro_example(algorithm)
build_mizuiro_example(convert)
build_mizuiro_example(convert_view)
build_mizuiro_example(dynamic)
build_mizuiro_example(flipped_view)
build_mizuiro_example(format)
build_mizuiro_example(heterogenous)
build_mizuiro_example(hsv)
build_mizuiro_example(gray)
build_mizuiro_example(image)
build_mizuiro_example(init)
build_mizuiro_example(linedraw)
build_mizuiro_example(operators)
build_mizuiro_example(sub_view)
build_mizuiro_example(raw_view)
build_mizuiro_example(raw_sub_view)
