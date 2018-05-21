if get_option('BUILD_PHYSICS') and get_option('BUILD_MATHEMATICS')
    subdir('integration_tests')
else
    warning('To enable integration tests, compile both PHYSICS and MATHEMATICS')
endif

gtest = dependency('gtest', main: true,
                   fallback : ['gtest', 'gtest_main_dep'],
                   required: false)

subdir('unit_tests')
