project('hello-mpi', 'cpp',
        default_options : ['cpp_std=c++11',
			   'buildtype=debug',
			   'warning_level=3'],
        version: '1.0')

main = files('hello.cc')

exe = executable(meson.project_name(), main)
