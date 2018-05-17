set(_tests_math mathematics_01.cc)
set(_tests_phys physics_01.cc)


foreach (_t ${_tests_math})
  add_executable(${_t} ${_t} ${GTEST_LIB_SOURCES} ${GTEST_MAIN_SOURCES} )
  target_include_directories(${_t} PRIVATE ${GTEST_INCLUDE_DIRS})
  target_link_libraries(${_t} mathematics  
   ${CMAKE_THREAD_LIBS_INIT}
    )
  add_test(${_t} ${_t})
endforeach()

foreach (_t ${_tests_phys})
  add_executable(${_t} ${_t} ${GTEST_LIB_SOURCES} ${GTEST_MAIN_SOURCES} )
  target_include_directories(${_t} PRIVATE ${GTEST_INCLUDE_DIRS})
  target_link_libraries(${_t} physics
    ${CMAKE_THREAD_LIBS_INIT}
    )
  add_test(${_t} ${_t})
endforeach()
