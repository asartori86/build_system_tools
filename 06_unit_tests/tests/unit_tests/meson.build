_tests_math = ['mathematics_01.cc']

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
