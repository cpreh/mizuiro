CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET (CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)
SET (CMAKE_VERBOSE_MAKEFILE ON)

PROJECT (mizuiro)

IF(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
	message(
		FATAL_ERROR
		"In-source builds are not permitted. "
		"Make a separate folder for building:\n"
		"mkdir build; cd build; cmake ..\n"
		"Before that, remove the files that cmake"
		"just created:\nrm -rf CMakeCache.txt CMakeFiles")
ENDIF()

FIND_PACKAGE(Boost 1.35.0)

IF(NOT Boost_FOUND)
	MESSAGE(STATUS "Boost not found!")
ENDIF()

IF(Boost_INCLUDE_DIR)
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ELSE()
	MESSAGE(
		STATUS
		"Boost headers not found. You will have to specify them"
		"in your build environment or you can use"
		"-DBOOST_ROOT= to tell cmake where your boost installation is.")
ENDIF()

MACRO (INSTALL_HEADERS subpath)
	FILE (GLOB headers include/${subpath}/*.hpp)
	INSTALL (FILES ${headers} DESTINATION ${CMAKE_INSTALL_PREFX}include/${subpath})
ENDMACRO ()

INSTALL_HEADERS(mizuiro)
INSTALL_HEADERS(mizuiro/detail)
INSTALL_HEADERS(mizuiro/color)
INSTALL_HEADERS(mizuiro/color/channel)
INSTALL_HEADERS(mizuiro/color/layout)
INSTALL_HEADERS(mizuiro/image)
INSTALL_HEADERS(mizuiro/image/detail)

OPTION (BUILD_EXAMPLES "Build the examples" ON)

IF(BUILD_EXAMPLES)
	ADD_SUBDIRECTORY(examples)
ENDIF()
