#!/bin/sh

set -e -u

update_cmake \
	CMakeLists.txt \
	MIZUIRO_FILES \
	include

update_cmake \
	doc/CMakeLists.txt \
	MIZUIRO_DOC_FILES \
	include \
	examples \
	-e ".*" \
	doc
