import platform

from setuptools import Extension, setup


def get_ext_modules() -> list:
    """
    获取三方模块
    Linux和Windows需要编译封装接口
    Mac由于缺乏二进制库支持无法使用
    """
    if platform.system() == "Linux":
        extra_compile_flags = [
            "-std=c++17",
            "-O3",
            "-Wno-delete-incomplete",
            "-Wno-sign-compare",
        ]
        extra_link_args = ["-lstdc++"]
        runtime_library_dirs = ["$ORIGIN"]
        td_libraries = ["EsTdAPI", "TapTdAPI", "ITapSETdAPI", "ITapTdAPI", "TapDataCollectAPI"]

    elif platform.system() == "Windows":
        extra_compile_flags = ["-O2"]
        extra_link_args = []
        runtime_library_dirs = []
        td_libraries = ["EsTdAPI", "TapDataCollectAPI"]

    else:
        return []

    vnesunnymd = Extension(
        "vnpy_esunny.api.vnesunnymd",
        [
            "vnpy_esunny/api/vnesunny/vnesunnymd/vnesunnymd.cpp",
        ],
        include_dirs=["vnpy_esunny/api/include",
                      "vnpy_esunny/api/vnesunny"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_esunny/api/libs", "vnpy_esunny/api"],
        libraries=["TapQuoteAPI"],
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    vnesunnytd = Extension(
        "vnpy_esunny.api.vnesunnytd",
        [
            "vnpy_esunny/api/vnesunny/vnesunnytd/vnesunnytd.cpp",
        ],
        include_dirs=["vnpy_esunny/api/include",
                      "vnpy_esunny/api/vnesunny"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_esunny/api/libs", "vnpy_esunny/api"],
        libraries=td_libraries,
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    return [vnesunnytd, vnesunnymd]


setup(
    ext_modules=get_ext_modules(),
)
