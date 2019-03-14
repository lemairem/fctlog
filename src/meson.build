config = configuration_data()
cppc = meson.get_compiler('cpp')
if cppc.has_header('cxxabi.h')
    config.set('CONFIG_FCTLOG_DEMANGLE', 1)
endif
if cppc.has_header('boost/exception/all.hpp')
    config.set('CONFIG_FCTLOG_BOOST_EXCEPTION', 1)
endif

subdir('include')
fctlog_dep = declare_dependency(include_directories: fctlog_inc)
