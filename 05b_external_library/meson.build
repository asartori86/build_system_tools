project('hello','c')

libm = meson.get_compiler('c').find_library('m')

executable('hello', 'hello.c', dependencies: libm)
