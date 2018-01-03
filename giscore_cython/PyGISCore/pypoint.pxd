from pysize cimport Size
from pysize cimport PySize
from libcpp cimport vector
from libcpp cimport bool

cdef extern from "PyGISCore/Point.h":
    cdef cppclass Point:
        int x,y
        Point() except +
        Point(int,int ) except +
        Point(const Size& ) except +
        void Rotate(const Point& , double )
        void Rotate(const Point& , double , double )
        void Offset(const Size &)
        void Offset(int , int )
        bool operator==(const Point& )
        bool operator!=(const Point& )
        Point& operator=(const Size& )
        Point& operator=(const Point& )
        Point& opiadd "operator+="(const Point&)
        Point& opiadd "operator+="(const Size&)
        Point& opisub "operator-="(const Point&)
        Point& opisub "operator-="(const Size&)
        Point operator-() const 
        bool operator<(const Point& ) const

        Point operator+(const Point&)
        Point operator+(const Size&)
        Point operator-(const Point&)
        Point operator-(const Size&)
    cdef Point operator+(const Size& sz,const Point& pnt)
    cdef Point operator-(const Size& sz,const Point& pnt)

cdef class PyPoint:
    cdef Point *cpoint
    cdef void * _inst
    cdef public bint _free_inst
