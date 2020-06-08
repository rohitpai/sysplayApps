project('process2.application',
  'cpp',
  default_options : ['cpp_std=c++11','b_ndebug=true'],
  version : '0.1.0'
  )

srcs = [
  'src/main.cpp',
]


inc = include_directories([
  'include'])

thread_dep = dependency('threads')
systemd_dep = dependency('libsystemd')

all_deps = [
  thread_dep, 
  systemd_dep
 ]

#----------------------------------------

app = executable(
  meson.project_name(),
  sources : srcs,
  include_directories : inc,
  dependencies : all_deps,
  install : true
  )



