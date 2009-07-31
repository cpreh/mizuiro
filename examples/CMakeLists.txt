INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

IF (CMAKE_COMPILER_IS_GNUCXX)
	ADD_DEFINITIONS ("-std=c++0x -pedantic-errors -Wall -Wextra -Wconversion"
	"-Wfloat-equal -Wredundant-decls -Wstrict-null-sentinel -Winit-self"
	"-Woverloaded-virtual -Wnon-virtual-dtor -Wctor-dtor-privacy"
	"-Wsign-promo -Wold-style-cast")
ENDIF()

MACRO (BUILD_EXAMPLE example)
	ADD_EXECUTABLE (${example} ${example}.cpp)
	TARGET_LINK_LIBRARIES( ${example} sgecore)
ENDMACRO()

BUILD_EXAMPLE(algorithm)
BUILD_EXAMPLE(convert)
BUILD_EXAMPLE(gray)
BUILD_EXAMPLE(image)
BUILD_EXAMPLE(init)
BUILD_EXAMPLE(sub_view)
BUILD_EXAMPLE(raw)
BUILD_EXAMPLE(raw_sub_view)
