project(
  'vnpy_esunny',
  'cpp',
  version: '9.0.3.16.0',
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
compiler_id = cpp.get_id()

# 输出构建目标系统信息
message('构建目标系统: ' + host_machine.system())

# 仅 Windows 编译扩展（与 setup.py 一致，Linux 不编译）
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

  # 定义库
  TapQuoteAPI_lib = cpp.find_library('TapQuoteAPI',
                                       dirs: [lib_dir, api_dir],
                                       required: true)
  TapTradeAPI_lib = cpp.find_library('TapTradeAPI',
                                       dirs: [lib_dir, api_dir],
                                       required: true)

  # 创建MD模块扩展
  md_module = py.extension_module(
    'vnesunnymd',
    sources: ['vnpy_esunny/api/vnesunny/vnesunnymd/vnesunnymd.cpp'],
    include_directories: include_dirs,
    dependencies: [py_dep],
    cpp_args: [],
    link_args: [
      '-L' + lib_dir,
      '-lTapQuoteAPI',
      '-Wl,-rpath,$ORIGIN'
    ],
    install: true,
    install_rpath: '$ORIGIN',
    subdir: 'vnpy_esunny/api'
  )

  # 创建TD模块扩展
  td_module = py.extension_module(
    'vnesunnytd',
    sources: ['vnpy_esunny/api/vnesunny/vnesunnytd/vnesunnytd.cpp'],
    include_directories: include_dirs,
    dependencies: [py_dep],
    cpp_args: [],
    link_args: [
      '-L' + lib_dir,
      '-lTapTradeAPI',
      '-Wl,-rpath,$ORIGIN'
    ],
    install: true,
    install_rpath: '$ORIGIN',
    subdir: 'vnpy_esunny/api'
  )

  # 安装API动态库文件
  api_libs = [
    'vnpy_esunny/api/TapQuoteAPI.dll',
    'vnpy_esunny/api/TapTradeAPI.dll',
  ]
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_esunny/api'
  )
endif

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
