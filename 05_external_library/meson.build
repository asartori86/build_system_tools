project('external_lib', 'cpp')

main = files('main.cc')

inc_dirs = include_directories('include')


boost_dep = dependency('boost', modules : 'program_options')


# cxx = meson.get_compiler('cpp')
# boost_dep = cxx.find_library('boost_program_options', dirs: ['/wherever'])

# if not cxx.has_header('boost/program_options.hpp')
#   found = false
#   foreach _i : ['/usr/local/include', '/usr/include','/whatever/']
#     _iarg = '-I'+_i
#     if not found and cxx.has_header('boost/program_options.hpp', args: [_iarg])
#       add_global_arguments(_iarg, language: 'cpp')
#       found = true
#     endif
#   endforeach
# endif


subdir('src')

exe = executable(meson.project_name(), main,
                 include_directories: inc_dirs,
                 dependencies: [phys_dep, math_dep, boost_dep])

