CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET (CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

PROJECT (mizuiro)

IF(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
	message(
		FATAL_ERROR
		"In-source builds are not permitted. "
		"Make a separate folder for building:\n"
		"mkdir build; cd build; cmake ..\n"
		"Before that, remove the files that cmake"
		"just created:\nrm -rf CMakeCache.txt CMakeFiles"
	)
ENDIF()

SET (Boost_ADDITIONAL_VERSIONS "1.41" "1.41.0" "1.42" "1.42.0" "1.43" "1.43.0")

FIND_PACKAGE(
	Boost 1.41.0 REQUIRED COMPONENTS
)

INCLUDE_DIRECTORIES(SYSTEM ${Boost_INCLUDE_DIR})

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

INSTALL (DIRECTORY include/ DESTINATION include)

OPTION (BUILD_EXAMPLES "Build the examples" ON)

IF(BUILD_EXAMPLES)
	ADD_SUBDIRECTORY(examples)
ENDIF()
