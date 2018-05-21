add_test(NAME "01_just_run"
  COMMAND ${name} 01.input
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )

set(_prefix ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_MATHEMATICS AND BUILD_PHYSICS)

  set (_tests 01 02)

  foreach(_t ${_tests})
    add_test(NAME ${_t}_run_and_diff
      COMMAND ${_prefix}/compare.sh ${CMAKE_BINARY_DIR}/${name}
      ${_prefix}/${_t}.output ${_prefix}/${_t}.input
      WORKDIR ${CMAKE_BINARY_DIR}
      )
  endforeach()
else()
  message(WARNING "\n\nTo enable integration tests, please enable both MATHEMATICS and PHYSICS")
endif()
