project('i2c.application',
  'cpp',
  default_options : ['cpp_std=c++11','b_ndebug=true'],
  version : '0.1.0'
  )

srcs = [
  'src/i2c_app.cpp',
]


inc = include_directories([
  'include'])

all_deps = [

 ]

#----------------------------------------

app = executable(
  meson.project_name(),
  sources : srcs,
  include_directories : inc,
  dependencies : all_deps,
  install : true
  )



