import platform

from setuptools import Extension, setup


def get_ext_modules() -> list:
    """
    获取三方模块

    Linux需要编译封装接口
    Windows直接使用预编译的pyd即可
    Mac由于缺乏二进制库支持无法使用
    """
    if platform.system() != "Linux":
        return []

    compiler_flags = [
        "-std=c++17",
        "-O3",
        "-Wno-delete-incomplete", "-Wno-sign-compare",
    ]
    extra_link_args = ["-lstdc++"]
    runtime_library_dirs = ["$ORIGIN"]

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
        libraries=["EsTdAPI", "TapQuoteAPI", "ITapSETdAPI", "ITapTdAPI", "TapDataCollectAPI"],
        extra_compile_args=compiler_flags,
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
        libraries=["EsTdAPI", "TapQuoteAPI", "ITapSETdAPI", "ITapTdAPI", "TapDataCollectAPI"],
        extra_compile_args=compiler_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    return [vnesunnytd, vnesunnymd]


setup(
    ext_modules=get_ext_modules(),
)
