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

IF (CMAKE_COMPILER_IS_GNUCXX)
	INCLUDE (CheckCXXSourceCompiles)

	CHECK_CXX_SOURCE_COMPILES(
		"int main()
		{
		if(__builtin_expect(true, 0))
		{}
		}"
		MIZUIRO_HAVE_BUILTIN_EXPECT
	)
ENDIF ()

CONFIGURE_FILE(
	${CMAKE_SOURCE_DIR}/config.h.in
	${CMAKE_SOURCE_DIR}/include/mizuiro/config.hpp
)

INSTALL (DIRECTORY include/ DESTINATION include/)

OPTION (BUILD_EXAMPLES "Build the examples" ON)

IF(BUILD_EXAMPLES)
	ADD_SUBDIRECTORY(examples)
ENDIF()
