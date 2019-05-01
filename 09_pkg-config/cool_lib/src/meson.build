strange_sum = files('strange_sum.cpp')
strange_mult = files('strange_mult.cpp')
min_vec = files('min_vec.cpp')
max_vec = files('max_vec.cpp')

src = [strange_sum, strange_mult, min_vec, max_vec]

basic_dep = dependency('basic')

cxx = meson.get_compiler('cpp')
extra_prefix = '/tmp/extra/'
extra_dep = cxx.find_library('extra',
			     required: true, 
			     dirs: [extra_prefix + 'lib'],
			     has_headers: [extra_prefix + 'include/max.hpp', extra_prefix + 'include/min.hpp'])

libcool = both_libraries('cool',
			 src,
		    	 name_suffix: [],
			 cpp_args: ['-O3', '-Wall', '-I'+extra_prefix+'include'],
		     	 include_directories: inc,
		     	 dependencies: [basic_dep, extra_dep],
		     	 install: true)

pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries: libcool,
                 version: '0.1.1',
                 name: 'cool',
                 filebase: 'cool',
                 description: 'Library for very cool math.',
		 extra_cflags: ['-O3', '-Wall', '-I'+extra_prefix+'include'],
		 variables: ['other_name=my_lib', 'author=someone'])
