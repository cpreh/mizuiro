function(add_mizuiro_example example)
  fcppt_utils_add_example(${FCPPT_UTILS_PROJECT_SOURCE_DIR}/examples ${example}
                          LINK_LIBS mizuiro_interface)
endfunction()

add_mizuiro_example(adapted_view)
add_mizuiro_example(algorithm)
add_mizuiro_example(canonical)
add_mizuiro_example(convert)
add_mizuiro_example(convert_view)
add_mizuiro_example(dynamic)
add_mizuiro_example(flipped_view)
add_mizuiro_example(format)
add_mizuiro_example(heterogenous)
add_mizuiro_example(hsv)
add_mizuiro_example(gray)
add_mizuiro_example(image)
add_mizuiro_example(init)
add_mizuiro_example(operators)
add_mizuiro_example(planar)
add_mizuiro_example(sub_view)
add_mizuiro_example(raw_view)
add_mizuiro_example(raw_sub_view)
