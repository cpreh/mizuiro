#!/bin/sh

set -e -u

update_cmake \
	CMakeLists.txt \
	MIZUIRO_FILES \
	include
