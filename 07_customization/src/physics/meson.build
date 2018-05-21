
_i = [include_directories('.'), inc_dirs]

_l = shared_library('physics',
                    files(['physics.cc', 'physics.h']),
                    include_directories: _i)

phys_dep = declare_dependency(include_directories: _i,
                              link_with: _l)

_deps += [phys_dep]
