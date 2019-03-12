project('fctlog', 'cpp', 'c', default_options : ['c_std=c11', 'cpp_std=c++11', 'warning_level=2'])

config = configuration_data()
cppc = meson.get_compiler('cpp')
if cppc.has_header('cxxabi.h')
    config.set('CONFIG_FCTLOG_DEMANGLE', 1)
endif

subdir('src')
subdir('samples')
subdir('test')
