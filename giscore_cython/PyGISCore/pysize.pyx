# cdef extern from "PyGISCore/Size.h":
#     cdef cppclass Size:
#         int cx,cy
#         Size() except +
#         Size(int,int ) except +
#         # Size& opiadd "operator+="(const Size&)
#         # Size& opiadd "operator-="(const Size&)
#         # Size opneg "operator-"() const 
#         # Size operator==(const Size&)
#         # Size operator!=(const Size&)
#         # Size operator+(const Size&)
#         # Size operator-(const Size&)

cdef class PySize:
    # cdef Size *csize
    def __cinit__(self,int x=0,int y=0):
        self.csize =  new  Size(x,y)
    def __dealloc__(self):
        del self.csize
    # def __add__(PySize left,PySize right):
    #     cdef Size si = left.csize[0] + right.csize[0]
    #     cdef PySize pys = PySize(si.cx,si.cy)
    #     return pys
    def __add__(left,right):
        cdef Size sz
        cdef Point pt
        cdef PySize pys
        cdef PyPoint ppt
        if isinstance(left,PySize):
            if isinstance(right,PySize):
                sz = (<PySize>left).csize[0] + (<PySize>right).csize[0] 
                pys = PySize(sz.cx,sz.cy)
                return pys
            elif isinstance(right,PyPoint):
                pt = pypoint.opadd_sp((<PySize>left).csize[0],(<PyPoint>right).cpoint[0])
                ppt = PyPoint(pt.x,pt.y)
                return ppt
        else:
            return NotImplemented

    def __sub__(left,right):
        cdef Size sz
        cdef Point pt
        cdef PySize pys
        cdef PyPoint ppt
        if isinstance(left,PySize):
            if isinstance(right,PySize):
                sz = (<PySize>left).csize[0] - (<PySize>right).csize[0] 
                pys = PySize(sz.cx,sz.cy)
                return pys
            elif isinstance(right,PyPoint):
                pt = pypoint.opsub_sp((<PySize>left).csize[0],(<PyPoint>right).cpoint[0])
                ppt = PyPoint(pt.x,pt.y)
                return ppt
        else:
            return NotImplemented

    # def __sub__(PySize left,PySize right):
    #     cdef Size si = left.csize[0] - right.csize[0]
    #     cdef PySize pys = PySize(si.cx,si.cy)
    #     return pys
    def __iadd__(self,PySize right):
        cdef Size si = self.csize.opiadd(right.csize[0])
        cdef PySize pys = PySize(si.cx,si.cy)
        return pys
    def __isub__(self,PySize right):
        cdef Size si = self.csize.opisub(right.csize[0])
        cdef PySize pys = PySize(si.cx,si.cy)
        return pys
    def __neg__(self):
        cdef Size si = -self.csize[0]
        cdef PySize pys = PySize(si.cx,si.cy)
        return pys 
    def __eq__(PySize left , PySize right):
        return left.csize[0] == right.csize[0]
    def __ne__(PySize left , PySize right):
        return left.csize[0] != right.csize[0]
    def __repr__(self):
        return "PySize[%s,%s]" % (
                self.csize.cx,
                self.csize.cy
                )

