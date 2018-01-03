from libcpp cimport bool

cdef extern from "PyGISCore/Size.h":
    cdef cppclass Size:
        int cx,cy
        Size() except +
        Size(int,int ) except +
        Size& opiadd "operator+="(const Size&)
        Size& opisub "operator-="(const Size&)
        Size operator-() const 
        bool operator==(const Size&)
        bool operator!=(const Size&)
        Size operator+(const Size&)
        Size operator-(const Size&)

cdef class PySize:
    cdef Size *csize
