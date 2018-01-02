# Cython compile instructions

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
# from Cython.Build import cythonize
import platform

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


ext_modules = [Extension("rect",
                         ["rect.pyx"],
                         language='c++',
                         include_dirs=['.'],
                         library_dirs=['lib'],
                         extra_link_args=[make_relative_rpath('lib')],
                         libraries=['Rect']
                         )]

setup(
    name="rectangleapp",
    cmdclass={'build_ext': build_ext},
    ext_modules=(ext_modules))
