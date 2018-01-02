# distutils: language = c++
# distutils: sources = Rectangle.cpp

# Cython interface file for wrapping the object
#
#

from libcpp.vector cimport vector
from cython.operator cimport dereference as deref 

# c++ interface to cython
cdef extern from "Rectangle.h" namespace "shapes":
    cdef cppclass Rectangle:
        Rectangle() except +
        Rectangle(int, int, int, int) except +
        int x0, y0, x1, y1
        int getLength()
        Rectangle operator+(Rectangle right)
        Rectangle& opiadd "operator+="(Rectangle right)
        Rectangle operator-(Rectangle right)

####  nonmember operator can also work
# cdef extern from "Rectangle.h" namespace "shapes":
    # cdef Rectangle operator-(Rectangle left ,Rectangle right) 

# creating a cython wrapper class
cdef class PyRectangle:
    cdef Rectangle *thisptr      # hold a C++ instance which we're wrapping
    def __cinit__(self, int x0=0, int y0=0, int x1=0, int y1=0):
        self.thisptr = new Rectangle(x0, y0, x1, y1)
    def __dealloc__(self):
        del self.thisptr
    def getLength(self):
        return self.thisptr.getLength()
    def __add__(PyRectangle left,PyRectangle right):
        cdef Rectangle rect = left.thisptr[0] + right.thisptr[0]
        cdef PyRectangle sum = PyRectangle(rect.x0,rect.y0,rect.x1,rect.y1)
        return sum
    def __iadd__(self, PyRectangle right):
        self.thisptr[0] = self.thisptr.opiadd(right.thisptr[0])
        cdef PyRectangle iad = PyRectangle(self.thisptr[0].x0,self.thisptr[0].y0,
                self.thisptr[0].x1,self.thisptr[0].y1)
        return iad
    def __sub__(PyRectangle left,PyRectangle right):
        cdef Rectangle rect = left.thisptr[0] - right.thisptr[0]
        # cdef Rectangle rect = opsub(left.thisptr[0],right.thisptr[0])
        cdef PyRectangle sub = PyRectangle(rect.x0,rect.y0,rect.x1,rect.y1)
        return sub
    def __repr__(self):
        return "PyRectangle[%s,%s,%s,%s]" % (
                self.thisptr.x0,
                self.thisptr.y0,
                self.thisptr.x1,
                self.thisptr.y1)
