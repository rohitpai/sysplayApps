project('zmq-server.application',
  'cpp',
  default_options : ['cpp_std=c++11','b_ndebug=true'],
  version : '0.1.0'
  )

srcs = [
  'src/zmq-server.cpp',
]

zmq_dep = dependency('libzmq')

all_deps = [
  zmq_dep
 ]

#----------------------------------------

app = executable(
  meson.project_name(),
  sources : srcs,
  dependencies : all_deps,
  install : true
  )



