if(
	NOT
	MIZUIRO_DONT_EXPORT
)
	get_filename_component(
		MIZUIRO_EXPORT_DIR
		"${CMAKE_CURRENT_LIST_FILE}"
		PATH
	)

	include(
		"${MIZUIRO_EXPORT_DIR}/mizuiroTargets.cmake"
	)

	unset(
		MIZUIRO_EXPORT_DIR
	)
endif()
