_i = [include_directories('.'), inc_dirs]

_l = shared_library('mathematics',
                    files(['mathematics.cc', 'mathematics.h']),
                    include_directories: _i,
                    install:true)

math_dep = declare_dependency(include_directories: _i,
                              link_with: _l)

