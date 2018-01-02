# Cython compile instructions

from distutils.core import setup
from distutils.extension import Extension
# from Cython.Distutils import build_ext
from Cython.Build import cythonize
import platform
import os

# Use python setup.py build_ext --inplace
# to compile
IS_WINDOWS = (platform.system() == 'Windows')
IS_DARWIN = (platform.system() == 'Darwin')
IS_LINUX = (platform.system() == 'Linux')


def make_relative_rpath(path):
    if IS_DARWIN:
        return '-Wl,-rpath,@loader_path/' + path
    elif IS_WINDOWS:
        return ''
    else:
        return '-Wl,-rpath,$ORIGIN/' + path


ext_options = {
    'language': 'c++',
    'include_dirs': ['.', './include'],
    'library_dirs': ['lib'],
    'extra_link_args': [make_relative_rpath('lib')],
    'libraries': ['gdal']}

if not os.name == "nt":
    # These options fail on Windows if using Visual Studio
    ext_options['extra_compile_args'] = ['-Wno-unused-parameter',
                                         '-Wno-unused-function']

ext_modules = [Extension("readtif",
                         ["readtif.pyx", "gdal_readintif.cpp"],
                         **ext_options)
               ]

setup(
    name="readtif_gdal",
    ext_modules=cythonize(ext_modules))
