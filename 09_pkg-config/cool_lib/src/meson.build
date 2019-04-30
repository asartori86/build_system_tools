strange_sum = files('strange_sum.cpp')
strange_mult = files('strange_mult.cpp')

src = [strange_sum, strange_mult]

basic_dep = dependency('basic')

# libcool = build_target('cool',
#                        src,
# 		       name_suffix: [],
# 		       cpp_args: ['-O3', '-Wall'],
# 		       include_directories: inc,
# 		       dependencies: basic_dep,
# 		       target_type: libtype,
# 		       install: true)

libcool = both_libraries('cool',
			 src,
		    	 name_suffix: [],
			 cpp_args: ['-O3', '-Wall'],
		     	 include_directories: inc,
		     	 dependencies: basic_dep,
		     	 install: true)

pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries: libcool,
                 version: '0.1.1',
                 name: 'cool',
                 filebase: 'cool',
                 description: 'Library for very cool math.',
		 extra_cflags: ['-O3', '-Wall'],
		 variables: ['other_name=my_lib', 'author=someone'])
		 #requires: 'basic >= 0.1')
