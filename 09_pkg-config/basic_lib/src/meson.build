sum_range = files('sum_range.cpp')
mult_range = files('mult_range.cpp')
dot = files('dot.cpp')
abs = files('abs.cpp')

src = [sum_range, mult_range, dot, abs]

libbasic = build_target('basic',
                        src,
		    	name_suffix: [],
		    	cpp_args: ['-O3', '-Wall'],
			include_directories: inc,
			target_type: libtype,
			install: true)

pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries: libbasic,
                 version: '0.1.0',
                 name: 'basic',
                 filebase: 'basic',
                 description: 'Library for very basic math.')
