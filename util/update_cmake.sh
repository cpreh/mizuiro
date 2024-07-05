#!/bin/sh

set -e -u

update_cmake.sh \
	files.txt \
	include

update_cmake.sh \
	doc/all_files.txt \
	include \
	examples

FIND_PATTERN="*.*" update_cmake.sh doc/doc_files.txt doc
