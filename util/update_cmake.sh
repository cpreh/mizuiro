#!/bin/sh
function update_cmake_file()
{
	local cmakefile="$1"

	update_cmake \
		"${cmakefile}" \
		"${@:2}" \
		|| exit -1

	mv "${cmakefile}".new "${cmakefile}" || exit -1
}

update_cmake_file \
	CMakeLists.txt \
	MIZUIRO_FILES \
	include
