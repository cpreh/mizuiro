INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

IF (CMAKE_COMPILER_IS_GNUCXX)
	ADD_DEFINITIONS ("-std=c++0x -pedantic-errors -Wall -Wextra -Wconversion"
	"-Wfloat-equal -Wredundant-decls -Wstrict-null-sentinel -Winit-self"
	"-Woverloaded-virtual -Wnon-virtual-dtor -Wctor-dtor-privacy"
	"-Wsign-promo -Wold-style-cast")
ENDIF()

MACRO (BUILD_EXAMPLE example)
	ADD_EXECUTABLE (${example} ${example}.cpp)
ENDMACRO()

BUILD_EXAMPLE(image)
