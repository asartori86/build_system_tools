project('shared_libs', 'cpp',
        default_options : ['cpp_std=c++11',
			   'buildtype=debug',
			   'warning_level=3'])

main = files('main.cc')

inc_dirs = include_directories('include')

libmath = shared_library('mathematics', ['src/mathematics.cc'],
                         include_directories : inc_dirs)

libphys = shared_library('physics', ['src/physics.cc'],
                         include_directories: inc_dirs)

executable(meson.project_name(), main,
           include_directories: inc_dirs,
           link_with: [libmath, libphys])

