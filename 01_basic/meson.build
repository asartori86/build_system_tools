project('basic', 'cpp',
        default_options : ['cpp_std=c++11',
			   'buildtype=debug',
			   'warning_level=3' ])

inc = include_directories('include')

executable('basic', ['main.cc','src/physics.cc',
                     'src/mathematics.cc'], 
           include_directories: inc)

