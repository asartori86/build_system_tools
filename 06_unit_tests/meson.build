project('how_to_test_02', 'cpp')

main = files('main.cc')

inc_dirs = include_directories('include')

subdir('src')

exe = executable(meson.project_name(), main,
                 include_directories: inc_dirs,
                 dependencies: [phys_dep, math_dep])

subdir('tests')
