_tests_math = ['mathematics_01_catch.cpp']

catch2 = declare_dependency(sources:'catch.cpp',dependencies:[catch2_dep])

foreach _t : _tests_math
  _exe_name = _t
  _src_file = _t
  _test_name = _t
  _e = executable(_exe_name, _src_file, dependencies: [catch2,math_dep] )
  test(_test_name, _e, suite:['unit_tests', 'math', 'catch2'])

endforeach


_tests_phys = ['physics_01_catch.cpp']

foreach _t : _tests_phys
  _exe_name = _t
  _src_file = _t
  _test_name = _t
  _e = executable(_exe_name, _src_file, dependencies: [catch2,phys_dep] )
  test(_test_name, _e, suite:['unit_tests', 'phys', 'catch2'])
endforeach
