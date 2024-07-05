cmake_minimum_required(VERSION 3.27.0)

project(mizuiro)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(MIZUIRO_SOURCE_DIR "${${PROJECT_NAME}_SOURCE_DIR}")

set(MIZUIRO_BINARY_DIR "${${PROJECT_NAME}_BINARY_DIR}")

find_package(fcppt REQUIRED)

# TODO: Remove default arguments eventually.
list(
  APPEND
  FCPPT_UTILS_CLANG_TIDY_ADDITIONAL_CHECKS
  "-cppcoreguidelines-avoid-const-or-ref-data-members"
  "-fuchsia-default-arguments-calls"
  "-fuchsia-default-arguments-declarations"
  "-misc-misplaced-const")

set(FCPPT_UTILS_CLANG_TIDY_WHITELIST "fcppt" "mizuiro")

include(FcpptCMakeUtils)

option(ENABLE_DOC "Build the documentation" OFF)

if(ENABLE_DOC)
  add_subdirectory(doc)
endif()

option(ENABLE_EXAMPLES "Build the examples" ON)

if(ENABLE_EXAMPLES)
  add_subdirectory(examples)
endif()

find_package(Catch2)

option(ENABLE_TEST "Build the tests" ${Catch2_FOUND})

if(ENABLE_TEST)
  fcppt_utils_setup_tests()

  enable_testing()

  add_subdirectory(test)
endif()

fcppt_utils_load_source_files(files.txt MIZUIRO_FILES)

fcppt_utils_add_source_groups("${MIZUIRO_FILES}")

fcppt_utils_add_dummy_target(mizuiro "${MIZUIRO_FILES}")

set_target_properties(mizuiro_dummy PROPERTIES FOLDER mizuiro)

target_link_libraries(mizuiro_dummy PRIVATE fcppt_core_interface)

target_include_directories(mizuiro_dummy PRIVATE ${MIZUIRO_SOURCE_DIR}/include)

fcppt_utils_set_target_compiler_flags(mizuiro_dummy)

include(GNUInstallDirs)

add_library(mizuiro_interface INTERFACE)

target_link_libraries(mizuiro_interface INTERFACE fcppt_core_interface)

target_include_directories(
  mizuiro_interface
  INTERFACE "$<BUILD_INTERFACE:${MIZUIRO_SOURCE_DIR}/include>"
            "$<INSTALL_INTERFACE:${CMAKE_INSTALL_FULL_INCLUDEDIR}>")

set(MIZUIRO_EXPORT_NAME mizuiroExport)

set(MIZUIRO_BUILD_CONFIG ${MIZUIRO_BINARY_DIR}/config)

set(MIZUIRO_TARGETS_FILE_NAME mizuiroTargets.cmake)

install(
  TARGETS mizuiro_interface
  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  EXPORT ${MIZUIRO_EXPORT_NAME})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

export(EXPORT ${MIZUIRO_EXPORT_NAME}
       FILE ${MIZUIRO_BUILD_CONFIG}/${MIZUIRO_TARGETS_FILE_NAME})

set(INSTALL_CMAKECONFIG_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/mizuiro)

install(
  EXPORT ${MIZUIRO_EXPORT_NAME}
  FILE ${MIZUIRO_TARGETS_FILE_NAME}
  DESTINATION ${INSTALL_CMAKECONFIG_DIR})

set(CONFIG_OUT_FILE ${MIZUIRO_BUILD_CONFIG}/mizuiro-config.cmake)

configure_file(${MIZUIRO_SOURCE_DIR}/mizuiro-config.cmake ${CONFIG_OUT_FILE}
               COPYONLY)

install(FILES ${CONFIG_OUT_FILE} DESTINATION ${INSTALL_CMAKECONFIG_DIR})
