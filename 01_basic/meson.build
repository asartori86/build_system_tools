project('basic', 'cpp',
        default_options : ['cpp_std=c++11',
			   'buildtype=debug',
			   'warning_level=3' ])


main = files('main.cc')

srcs = files(['src/physics.cc',
              'src/mathematics.cc'])

inc = include_directories('include')

executable('basic', main, srcs,
           include_directories: inc)

