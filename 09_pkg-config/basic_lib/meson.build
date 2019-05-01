project('libbasic', 'cpp', default_options: ['cpp_std=c++17', 'libdir=lib'], version: '0.1.0')

add_project_arguments(language: 'cpp')

conf_data = configuration_data()
conf_data.set_quoted('version', meson.project_version())
conf_data.set('shared_lib', get_option('shared_lib'))
conf_data.set('static_lib', get_option('static_lib'))

configure_file(input: './my_project_config.h.in',
	       output: 'meson_config.h',
	       configuration: conf_data)

inc = include_directories('.', './include')

if get_option('shared_lib') == true
   libtype = 'shared_library'
else
   libtype = 'static_library'
endif

subdir('./include')
subdir('./src')