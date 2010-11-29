CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET (CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

SET (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

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

SET (Boost_ADDITIONAL_VERSIONS "1.41" "1.41.0" "1.42" "1.42.0" "1.43" "1.43.0" "1.44" "1.44.0")

IF(MSVC)
	SET(Boost_USE_STATIC_LIBS ON)
ENDIF()

FIND_PACKAGE(
	Boost 1.40.0 REQUIRED 
)

OPTION(
	ENABLE_FCPPT "Use fcppt's variant. Required for ternary visitation." OFF
)

IF(ENABLE_FCPPT)
	FIND_PACKAGE(
		Fcppt
		REQUIRED
	)
ENDIF()

SET(MIZUIRO_HAVE_FCPPT ${FCPPT_FOUND})

INCLUDE_DIRECTORIES(include)

INCLUDE_DIRECTORIES(SYSTEM ${Boost_INCLUDE_DIR})

IF(FCPPT_FOUND)
	INCLUDE_DIRECTORIES(${FCPPT_INCLUDE_DIRS})
ENDIF()

INCLUDE (CheckCXXSourceRuns)

CHECK_CXX_SOURCE_RUNS(
	"#include <cstdlib>
	int main()
	{
	#ifdef __clang__
		return EXIT_SUCCESS;
	#else
		return EXIT_FAILURE;
	#endif
	}
	"
	COMPILER_IS_CLANGPP
)

IF (CMAKE_COMPILER_IS_GNUCXX OR COMPILER_IS_CLANGPP)
	INCLUDE (CheckCXXSourceCompiles)

	CHECK_CXX_SOURCE_COMPILES(
		"int main()
		{
		if(__builtin_expect(true, 0))
		{}
		}"
		MIZUIRO_HAVE_BUILTIN_EXPECT
	)

	ADD_DEFINITIONS (
		"-ansi -pedantic-errors -Wall -Wextra -Wconversion"
		"-Wfloat-equal -Wredundant-decls -Winit-self -Wshadow"
		"-Woverloaded-virtual -Wnon-virtual-dtor -Wctor-dtor-privacy"
		"-Wsign-promo -Wold-style-cast -Wno-long-long"
	)
ELSEIF (MSVC)
	ADD_DEFINITIONS ("/W4 /wd4996 /EHa /D_BIND_TO_CURRENT_VCLIBS_VERSION=1")
	#4996 - unsafe standard C++ functions
ENDIF ()

CONFIGURE_FILE(
	${CMAKE_SOURCE_DIR}/config.hpp.in
	${CMAKE_SOURCE_DIR}/include/mizuiro/config.hpp
)

INSTALL (DIRECTORY include/ DESTINATION include)

OPTION(ENABLE_DOC "Build the documentation" OFF)

IF (ENABLE_DOC)
	ADD_SUBDIRECTORY (doc)
ENDIF ()

OPTION (ENABLE_EXAMPLES "Build the examples" ON)

IF(ENABLE_EXAMPLES)
	ADD_SUBDIRECTORY(examples)
ENDIF()

OPTION (ENABLE_TEST "Build the tests" ON)

IF(ENABLE_TEST)
	ENABLE_TESTING()
	ADD_SUBDIRECTORY(test)
ENDIF()
