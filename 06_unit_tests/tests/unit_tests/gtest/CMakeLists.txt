set(GTEST_DIR "" CACHE PATH "google test dir")

find_path(GTEST_INC_DIR "gtest/gtest.h"
  HINTS
  ${GTEST_DIR}/include
  ${GTEST_DIR}/googletest/include)

if(NOT GTEST_INC_DIR)
  message(FATAL_ERROR "Couldn't find gtest/gtest.h under folder GTEST_DIR=" ${GTEST_DIR})
endif()

find_path(GTEST_SOURCE_DIR gtest-all.cc
  ${GTEST_DIR}/src
  ${GTEST_DIR}/googletest/src
)
if(NOT GTEST_SOURCE_DIR)
  message(FATAL_ERROR "Couldn't find gtest-all.cc under folder GTEST_DIR=" ${GTEST_DIR})
endif()

set(GTEST_LIB_SOURCES ${GTEST_SOURCE_DIR}/gtest-all.cc)
set(GTEST_MAIN_SOURCES ${GTEST_SOURCE_DIR}/gtest_main.cc)
set(GTEST_INCLUDE_DIRS ${GTEST_INC_DIR}
  ${GTEST_SOURCE_DIR} ${GTEST_SOURCE_DIR}/..)

find_package(Threads REQUIRED)




set(_tests_math mathematics_01.cc)
set(_tests_phys physics_01.cc)


foreach (_t ${_tests_math})
  add_executable(${_t}_exe ${_t} ${GTEST_LIB_SOURCES} ${GTEST_MAIN_SOURCES} )
  target_include_directories(${_t}_exe PRIVATE ${GTEST_INCLUDE_DIRS})
  target_link_libraries(${_t}_exe mathematics  
   ${CMAKE_THREAD_LIBS_INIT}
    )
  add_test(${_t} ${_t}_exe)
endforeach()

foreach (_t ${_tests_phys})
  add_executable(${_t}_exe ${_t} ${GTEST_LIB_SOURCES} ${GTEST_MAIN_SOURCES} )
  target_include_directories(${_t}_exe PRIVATE ${GTEST_INCLUDE_DIRS})
  target_link_libraries(${_t}_exe physics
    ${CMAKE_THREAD_LIBS_INIT}
    )
  add_test(${_t} ${_t}_exe)
endforeach()
