subdir('integration_tests')

gtest = dependency('gtest', 
                   fallback : ['gtest', 'gtest_main_dep'],
                   required: true)

catch2_dep = dependency('catch2', 
                   fallback : ['catch2', 'catch2_dep'],
                   required: true)


doctest = dependency('doctest', 
                   fallback : ['doctest', 'doctest_dep'],
                   required: true)

subdir('unit_tests')
