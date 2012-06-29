include_directories(
	${CMAKE_SOURCE_DIR}/include
)

macro(
	BUILD_FCPPT_EXAMPLE
	example
)
	add_executable(
		mizuiro${example}example
		${example}.cpp
	)
endmacro()

build_fcppt_example(adapted_view)
build_fcppt_example(algorithm)
build_fcppt_example(convert)
build_fcppt_example(convert_view)
build_fcppt_example(dynamic)
build_fcppt_example(flipped_view)
build_fcppt_example(hsv)
build_fcppt_example(gray)
build_fcppt_example(image)
build_fcppt_example(init)
build_fcppt_example(operators)
build_fcppt_example(sub_view)
build_fcppt_example(raw_view)
build_fcppt_example(raw_sub_view)
