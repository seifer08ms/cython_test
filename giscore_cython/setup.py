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


# def make_relative_rpath(path):
#     if IS_DARWIN:
#         return '-Wl,-rpath,@loader_path/' + path
#     elif IS_WINDOWS:
#         return ''
#     else:
#         return '-Wl,-rpath,$ORIGIN/' + path

ext_options = {
    'language': 'c++',
    'include_dirs': ['.', 'Include']  # ,
    # library_dirs=['lib'],
    # extra_link_args=[make_relative_rpath('lib')],
    # libraries=['Rect']
}

ext_modules = [
    Extension("pysize", ["PyGISCore/pysize.pyx",
                         "PyGISCore/Size.cpp"], **ext_options),
    Extension("pypoint", ["PyGISCore/pypoint.pyx",
                          "PyGISCore/Point.cpp", "PyGISCore/Size.cpp"],
              **ext_options)
    # Extension("cytest",
    # ["PyGISCore/cysize.pyx",
    #  "PyGISCore/cypoint.pyx",
    #  "PyGISCore/Size.cpp",
    #  "PyGISCore/Point.cpp"],
    # **ext_options)

]

setup(
    name="PyGISCore",
    cmdclass={'build_ext': build_ext},
    ext_modules=(ext_modules))
