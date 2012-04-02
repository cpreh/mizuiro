cmake_minimum_required(VERSION 2.6)

project (mizuiro)

find_package(
	Boost 1.40.0 REQUIRED
)

option(
	ENABLE_FCPPT "Use fcppt's variant. Required for ternary visitation." OFF
)

if(ENABLE_FCPPT)
	find_package(
		Fcppt
		REQUIRED
	)
endif()

set(
	MIZUIRO_HAVE_FCPPT
	${FCPPT_FOUND}
)

include_directories(
	include
)

if(
	MIZUIRO_HAVE_FCPPT
)
	include(FcpptCMakeUtils)

	include_directories(
		${FCPPT_UTILS_INCLUDE_SYSTEM}
		${Boost_INCLUDE_DIR}
	)
else()
	include_directories(
		SYSTEM
		${Boost_INCLUDE_DIR}
	)
endif()

if(FCPPT_FOUND)
	include_directories(
		${Fcppt_INCLUDE_DIRS}
	)
endif()

if (CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP)
	include (CheckCXXSourceCompiles)

	check_cxx_source_compiles(
		"int main()
		{
		if(__builtin_expect(true, 0))
		{}
		}"
		MIZUIRO_HAVE_BUILTIN_EXPECT
	)
endif ()

configure_file(
	${CMAKE_SOURCE_DIR}/config.hpp.in
	${CMAKE_BINARY_DIR}/include/mizuiro/config.hpp
)

include_directories(
	${CMAKE_BINARY_DIR}/include
)

install(
	DIRECTORY
	include/
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)

install(
	FILES
	${CMAKE_BINARY_DIR}/include/mizuiro/config.hpp
	DESTINATION
	${INSTALL_INCLUDE_DIR}/mizuiro
)

install(
	FILES
	${CMAKE_SOURCE_DIR}/CMakeModules/FindMizuiro.cmake
	DESTINATION
	${INSTALL_CMAKEMODULES_DIR}
)

option(ENABLE_DOC "Build the documentation" OFF)

if (ENABLE_DOC)
	add_subdirectory (doc)
endif ()

option (ENABLE_EXAMPLES "Build the examples" ON)

if(ENABLE_EXAMPLES)
	add_subdirectory(examples)
endif()

option (ENABLE_TEST "Build the tests" ON)

if(ENABLE_TEST)
	enable_testing()
	add_subdirectory(test)
endif()
