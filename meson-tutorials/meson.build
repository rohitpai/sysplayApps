project('hello-world.application',
  'cpp',
  default_options : ['cpp_std=c++11','b_ndebug=true'],
  version : '0.1.0'
  )

srcs = [
  'src/main.cpp',
]

inc = include_directories([
  'include'])

hello_dep = dependency('hello-lib')

all_deps = [
hello_dep ]

#----------------------------------------

app = executable(
  meson.project_name(),
  sources : srcs,
  include_directories : inc,
  dependencies : all_deps,
  install : true
  )



