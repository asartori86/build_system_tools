add_test(NAME "01_just_run"
  COMMAND ${name} 01.input
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )

set(_prefix ${CMAKE_CURRENT_SOURCE_DIR})

# add_test(NAME "01_run_and_diff"
#   COMMAND ${_prefix}/compare.sh ${CMAKE_BINARY_DIR}/how_to_test_01
#   ${_prefix}/01.output ${_prefix}/01.input
#   WORKDIR ${CMAKE_BINARY_DIR}
#   )

# add_test(NAME "02_run_and_diff"
#   COMMAND ${_prefix}/compare.sh ${CMAKE_BINARY_DIR}/how_to_test_01
#   ${_prefix}/02.output ${_prefix}/02.input
#   WORKDIR ${CMAKE_BINARY_DIR}
#   )


set (_tests 01 02)

foreach(_t ${_tests})
  add_test(NAME ${_t}_run_and_diff
    COMMAND ${_prefix}/compare.sh ${CMAKE_BINARY_DIR}/${name}
    ${_prefix}/${_t}.output ${_prefix}/${_t}.input
    WORKDIR ${CMAKE_BINARY_DIR}
    )
endforeach()
