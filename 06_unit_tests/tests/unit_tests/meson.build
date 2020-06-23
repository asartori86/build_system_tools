_tests_math = ['mathematics_01.cc']

catch2 = declare_dependency(sources:'catch.cpp',dependencies:[catch2_dep])

foreach _t : _tests_math
  _exe_name = _t
  _src_file = _t
  _test_name = _t
  _e = executable(_exe_name, _src_file, dependencies: [gtest,math_dep] ) # link agains the whole mathematics library

  test(_test_name, _e, suite:['unit_tests', 'math'])

endforeach


_tests_phys = ['physics_01.cc']
foreach _t : _tests_phys
  _e = executable(_t, _t, dependencies: [gtest, phys_dep] ) 
  test(_t, _e, suite:['unit_tests', 'phys'])
endforeach


tests_catch = ['mathematics_01_catch.cpp',
               'physics_01_catch.cpp'
               ]

test('catch-test', executable('test_catch', tests_catch,
                              dependencies:[math_dep,
                                            phys_dep,
                                            catch2]),
     suite:'catch'
     )


tests_doc = ['doctest.cpp',
             'mathematics_01_doctest.cpp',
             'physics_01_doctest.cpp'
             ]


test('doctest-test', executable('doctest-test', tests_doc,
                                dependencies: [math_dep,
                                               phys_dep,
                                               doctest]),
     suite:'doctest'
     )
