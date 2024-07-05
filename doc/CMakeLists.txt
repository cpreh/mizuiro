find_package(Doxygen REQUIRED)

set(DOC_OUTPUT "${MIZUIRO_BINARY_DIR}/doc_generated")

configure_file(Doxyfile.in "${DOC_OUTPUT}/Doxyfile")

file(COPY footer.html header.html layout.xml stylesheet.css
     DESTINATION "${DOC_OUTPUT}")

fcppt_utils_load_source_files(doc/doc_files.txt MIZUIRO_DOC_FILES)
fcppt_utils_load_source_files(doc/all_files.txt MIZUIRO_ALL_FILES)
list(APPEND MIZUIRO_DOC_FILES ${MIZUIRO_ALL_FILES})

fcppt_utils_append_source_dir(MIZUIRO_DOC_FILES_ABS "${MIZUIRO_DOC_FILES}")

set(HTML_INDEX_OUTPUT ${DOC_OUTPUT}/html/index.html)

add_custom_command(
  OUTPUT "${HTML_INDEX_OUTPUT}"
  COMMAND ${DOXYGEN_EXECUTABLE}
  DEPENDS ${MIZUIRO_DOC_FILES_ABS}
  WORKING_DIRECTORY "${DOC_OUTPUT}"
  COMMENT "Generating HTML documentation.")

add_custom_target(doc ALL SOURCES ${HTML_INDEX_OUTPUT})

install(DIRECTORY "${DOC_OUTPUT}/html" DESTINATION ${CMAKE_INSTALL_DOCDIR})
