project(
  'vnpy_esunny',
  'cpp',
  version: '1.0.2.2.6',
  license: 'MIT',
  meson_version: '>=1.7.0',
  default_options: [
    'buildtype=release',
    'cpp_std=c++17',
    'warning_level=2',
  ],
)

# 导入文件系统和Python模块
fs = import('fs')
py = import('python').find_installation(pure: false)
py_dep = py.dependency()

# 获取pybind11路径
python_cmd = host_machine.system() == 'windows' ? 'python' : 'python3'
pybind11_include_dir = run_command(python_cmd, '-c', 'import pybind11; print(pybind11.get_include())', check: true).stdout().strip()
message('使用pybind11路径: ' + pybind11_include_dir)

# 获取编译器信息
cpp = meson.get_compiler('cpp')

# 输出构建目标系统信息
message('构建目标系统: ' + host_machine.system())

# 初始化变量
extra_cpp_args = []
extra_link_args = []

# 设置Windows特定编译选项
if host_machine.system() == 'windows'
  # Windows编译器设置
  add_project_arguments('/MT', language : 'cpp')
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_esunny/api/libs'
  api_dir = meson.current_source_dir() / 'vnpy_esunny/api'
  
  # 设置include目录
  include_dirs = include_directories(
    'vnpy_esunny/api/include',
    'vnpy_esunny/api/vnesunny',
    pybind11_include_dir,
  )
  
  # 定义MD库
  tapquoteapi_lib = cpp.find_library('TapQuoteAPI', 
                                     dirs: [lib_dir, api_dir],
                                     required: true)
  
  # 定义TD库
  estdapi_lib = cpp.find_library('EsTdAPI', 
                                 dirs: [lib_dir, api_dir],
                                 required: true)
  tapdatacollectapi_lib = cpp.find_library('TapDataCollectAPI', 
                                           dirs: [lib_dir, api_dir],
                                           required: true)

# 设置Linux特定编译选项
else  # Linux
  # Linux编译器设置
  extra_cpp_args = [
    '-std=c++17',
    '-O3',
    '-Wno-delete-incomplete',
    '-Wno-sign-compare',
  ]
  
  extra_link_args = [
    '-lstdc++',
  ]
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_esunny/api'
  api_dir = meson.current_source_dir() / 'vnpy_esunny/api'
  
  # 设置include目录
  include_dirs = include_directories(
    'vnpy_esunny/api/include',
    'vnpy_esunny/api/vnesunny',
    pybind11_include_dir,
  )
  
  # 定义MD库
  tapquoteapi_lib = cpp.find_library('TapQuoteAPI', 
                                     dirs: [lib_dir],
                                     required: true)
  
  # 定义TD库
  estdapi_lib = cpp.find_library('EsTdAPI', 
                                 dirs: [lib_dir],
                                 required: true)
  taptdapi_lib = cpp.find_library('TapTdAPI', 
                                  dirs: [lib_dir],
                                  required: true)
  itapsetdapi_lib = cpp.find_library('ITapSETdAPI', 
                                     dirs: [lib_dir],
                                     required: true)
  itaptdapi_lib = cpp.find_library('ITapTdAPI', 
                                   dirs: [lib_dir],
                                   required: true)
  tapdatacollectapi_lib = cpp.find_library('TapDataCollectAPI', 
                                           dirs: [lib_dir],
                                           required: true)
endif

# 创建MD模块扩展
md_module = py.extension_module(
  'vnesunnymd',
  sources: ['vnpy_esunny/api/vnesunny/vnesunnymd/vnesunnymd.cpp'],
  include_directories: include_dirs,
  dependencies: [py_dep, tapquoteapi_lib],
  cpp_args: extra_cpp_args,
  link_args: extra_link_args,
  install: true,
  install_rpath: '$ORIGIN',
  subdir: 'vnpy_esunny/api'
)

# 创建TD模块扩展
if host_machine.system() == 'windows'
  td_deps = [py_dep, estdapi_lib, tapdatacollectapi_lib]
else
  td_deps = [py_dep, estdapi_lib, taptdapi_lib, itapsetdapi_lib, itaptdapi_lib, tapdatacollectapi_lib]
endif

td_module = py.extension_module(
  'vnesunnytd',
  sources: ['vnpy_esunny/api/vnesunny/vnesunnytd/vnesunnytd.cpp'],
  include_directories: include_dirs,
  dependencies: td_deps,
  cpp_args: extra_cpp_args,
  link_args: extra_link_args,
  install: true,
  install_rpath: '$ORIGIN',
  subdir: 'vnpy_esunny/api'
)

# 安装Python源代码
python_files = [
  ['vnpy_esunny/__init__.py', 'vnpy_esunny'],
  ['vnpy_esunny/api/__init__.py', 'vnpy_esunny/api'],
  ['vnpy_esunny/api/esunny_constant.py', 'vnpy_esunny/api'],
  ['vnpy_esunny/gateway/__init__.py', 'vnpy_esunny/gateway'],
  ['vnpy_esunny/gateway/esunny_gateway.py', 'vnpy_esunny/gateway'],
]

foreach file : python_files
  py.install_sources(
    [file[0]],
    pure: false,
    subdir: file[1]
  )
endforeach

# 安装API动态库文件
if host_machine.system() == 'windows'
  api_libs = [
    'vnpy_esunny/api/TapQuoteAPI.dll',
    'vnpy_esunny/api/TapDataCollectAPI.dll',
    'vnpy_esunny/api/EsTdAPI.dll',
    'vnpy_esunny/api/ITapTdAPI.dll',
    'vnpy_esunny/api/ITapSETdAPI.dll',
    'vnpy_esunny/api/TapTdAPI.dll',
  ]
  
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_esunny/api'
  )
else  # Linux
  api_libs = [
    'vnpy_esunny/api/libTapQuoteAPI.so',
    'vnpy_esunny/api/libTapDataCollectAPI.so',
    'vnpy_esunny/api/libEsTdAPI.so',
    'vnpy_esunny/api/libITapTdAPI.so',
    'vnpy_esunny/api/libITapSETdAPI.so',
    'vnpy_esunny/api/libTapTdAPI.so',
  ]
  
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_esunny/api'
  )
endif
