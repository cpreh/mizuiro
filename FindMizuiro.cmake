# - Try to find the mizuiro library
#
# This module defines the following variables
#
#	MIZUIRO_FOUND        - True when mizuiro was found
#	MIZUIRO_INCLUDE_DIRS - The path to the MIZUIRO header files
#

FIND_PATH(
	MIZUIRO_INCLUDE_DIRS
	NAMES mizuiro/config.hpp
)

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(
	MIZUIRO
	DEFAULT_MSG
	MIZUIRO_INCLUDE_DIRS
)

MARK_AS_ADVANCED(
	MIZUIRO_INCLUDE_DIRS
)
