project('how_to_test_02', 'cpp',
        default_options : ['cpp_std=c++11',
			   'buildtype=debug',
			   'warning_level=3'])

main = files('main.cc')

inc_dirs = include_directories('include')

subdir('src')

exe = executable(meson.project_name(), main,
                 include_directories: inc_dirs,
                 dependencies: [phys_dep, math_dep])

subdir('tests')
