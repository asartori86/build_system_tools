project('customization', 'cpp',
        default_options : ['cpp_std=c++11',
			   'buildtype=debug',
			   'warning_level=3'],
        version: '1.0')

main = files('main.cc')

inc_dirs = include_directories('include')

_deps = []

subdir('src')

exe = executable(meson.project_name(), main,
                 include_directories: inc_dirs,
                 dependencies: _deps)

if get_option('ENABLE_TESTING')
    subdir('tests')
endif

_cdata = configuration_data()

_cdata.set_quoted('version', meson.project_version() )

_cdata.set('BUILD_PHYSICS', get_option('BUILD_PHYSICS'))
_cdata.set('BUILD_MATHEMATICS', get_option('BUILD_MATHEMATICS'))

configure_file(output: 'my_project_config.h',
               input: 'include/my_project_config_meson.h.in',
               configuration: _cdata)

message('\n\n'+
        '###\n'+
        '#\n'+
        '# Library name:\t\t' + meson.project_name() +'\n'+
	'# Library version:\t\t' + meson.project_version() +'\n'+
        '#\n'+
	'# Build options:\n'+
        '#   BUILD_MATHEMATICS:\t\t' + get_option('BUILD_MATHEMATICS').to_string() + '\n'+
        '#   BUILD_PHYSICS:\t\t' + get_option('BUILD_PHYSICS').to_string() + '\n'+
        '#\n'+
	'# Project options:\n'+
        '#   ENABLE_TESTING:\t\t' + get_option('ENABLE_TESTING').to_string() + '\n'+
        '#\n'+
        '###\n'
	)
