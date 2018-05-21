_i = [include_directories('.'), inc_dirs]

_l = shared_library('mathematics',
                    files(['mathematics.cc', 'mathematics.h']),
                    include_directories: _i)

math_dep = declare_dependency(include_directories: _i,
                              link_with: _l)

_deps += [math_dep]

