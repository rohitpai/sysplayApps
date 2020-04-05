project('hello-lib',
  'cpp',
  default_options : ['cpp_std=c++11'],
  version : '0.1.0'
  )

srcs = [
  'src/Hello.cpp'
]

all_deps = [ ]

#----------------------------------------

inc = include_directories('include')
sh = shared_library(
  meson.project_name(),
  sources : srcs,
  version : meson.project_version(),
  soversion : 0,
  include_directories : inc,
  dependencies: all_deps,
  install : true,
  )

install_subdir('include', install_dir : get_option('includedir'), strip_directory : true)


pkg = import('pkgconfig')

pkg.generate(
  name : meson.project_name(),
  description : 'hello lib',
  version : meson.project_version(),
  libraries : [sh] + all_deps
)

hello_lib_dep = declare_dependency(include_directories : inc, 
  link_with : sh, 
  dependencies: all_deps)