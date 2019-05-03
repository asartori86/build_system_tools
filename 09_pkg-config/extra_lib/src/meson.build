min = files('min.cpp')
max = files('max.cpp')

src = [min, max]

libextra = both_libraries('extra',
                          src,
		    	  name_suffix: [],
		    	  cpp_args: ['-O3', '-Wall'],
			  include_directories: inc,
			  install: true)