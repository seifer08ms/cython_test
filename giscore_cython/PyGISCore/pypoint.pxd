# from libc.stdlib cimport free

cdef class PyPoint:
    cdef Point *cpoint
    # cdef void * _inst
    cdef public bint _free_inst

    _pt_0_argtypes= frozenset()
    _pt_1_argtypes= frozenset(((0 ,PySize),("sz",PySize)))
    _pt_2_argtypes= frozenset(((0,int),(1,int),("x",int),("y",int)))

    def _init_int(self,int x ,int y ):
        self.cpoint = new Point(x,y)

    def _init_size(self ,PySize sz):
        self.cpoint = new Point(sz.csize[0])

    def __cinit__(self,*args,**kwargs):
        self.cpoint = NULL
        self._free_inst = True

    def __init__(self,*args,**kwargs):
        types = set([(i,type(a)) for i,a in enumerate(args)])
        types.update([(k,type(v)) for k, v in kwargs.items()])
        # print(types)

        if types <= self._pt_0_argtypes:
            self.cpoint = new Point()
            return 
        if types <= self._pt_1_argtypes:
            self._init_size(*args,**kwargs)
            return 
        if types <= self._pt_2_argtypes:
            self._init_int(*args,**kwargs)
            return 
        try:
            self.cpoint = new Point()
            return 
        except (RuntimeError,TypeError,NameError):
            pass
        try:
            self._init_size(*args,**kwargs)
            return 
        except (RuntimeError,TypeError,NameError):
            pass
        try:
            self._init_int(*args,**kwargs)
            return 
        except (RuntimeError,TypeError,NameError):
            pass

    def __dealloc__(self):
        if self._free_inst:
            del self.cpoint
            # free(self.cpoint)
    def Rotate(self,PyPoint pz,double drad=0):
        self.cpoint.Rotate(pz.cpoint[0],drad)

    def Rotate(self,PyPoint pz,double dcos=0,double dsin=0):
        self.cpoint.Rotate(pz.cpoint[0],dcos,dsin)

    def Offset(self,PySize szvalue):
        self.cpoint.Offset(szvalue.csize[0])

    def Offset(self,int offsetx=0,int offsety=0):
        self.cpoint.Offset(offsetx,offsety)

    def __eq__(PyPoint left , PyPoint right):
        return left.cpoint[0] == right.cpoint[0]

    def __ne__(PyPoint left , PyPoint right):
        return left.cpoint[0] != right.cpoint[0]

    # def _from(self,PyPoint pz):
    #     self.cpoint.opassign(pz.cpoint[0])
    #     return self

    # def _from(self,PySize sz):
    #     self.cpoint.opassign(sz.csize[0])
    #     return self
    def __iadd__(self,PyPoint right):
        cdef Point pt = self.cpoint.opiadd(right.cpoint[0])
        cdef PyPoint pypt = PyPoint(pt.x,pt.y)
        return pypt

    def __iadd__(self,PySize right):
        cdef PyPoint pright = PyPoint(right)
        cdef Point pt = self.cpoint.opiadd(pright.cpoint[0])
        cdef PyPoint pypt = PyPoint(pt.x,pt.y)
        return pypt

    def __isub__(self,PyPoint right):
        cdef Point pt = self.cpoint.opisub(right.cpoint[0])
        cdef PyPoint pypt = PyPoint(pt.x,pt.y)
        return pypt

    def __isub__(self,PySize right):
        cdef PyPoint pright = PyPoint(right)
        cdef Point pt = self.cpoint.opisub(pright.cpoint[0])
        cdef PyPoint pypt = PyPoint(pt.x,pt.y)
        return pypt

    def __sub__(PyPoint left,PySize right):
        cdef PyPoint pright = PyPoint(right)
        cdef Point pt = left.cpoint[0] - pright.cpoint[0]
        cdef PyPoint pypt = PyPoint(pt.x,pt.y)
        return pypt

    def __neg__(self):
        cdef Point pt = -self.cpoint[0]
        cdef PyPoint pypt = PyPoint(pt.x,pt.y)
        return pypt

    def __lt__(PyPoint left,PyPoint right):
        return left.cpoint[0] < right.cpoint[0]

    # def __add__(PyPoint left,PyPoint right):
    #     cdef Point pt = left.cpoint[0] + right.cpoint[0]
    #     cdef PyPoint pypt = PyPoint(pt.x,pt.y)
    #     return pypt

    # def __add__(PyPoint left,PySize right):
    #     cdef PyPoint pright = PyPoint(right)
    #     cdef Point pt = left.cpoint[0] + pright.cpoint[0]
    #     cdef PyPoint pypt = PyPoint(pt.x,pt.y)
    #     return pypt

    def __sub__(PyPoint left,PyPoint right):
        cdef Point pt = left.cpoint[0] - right.cpoint[0]
        cdef PyPoint pypt = PyPoint(pt.x,pt.y)
        return pypt

    def __sub__(PyPoint left,PySize right):
        cdef PyPoint pright = PyPoint(right)
        cdef Point pt = left.cpoint[0] -  pright.cpoint[0]
        cdef PyPoint pypt = PyPoint(pt.x,pt.y)
        return pypt

    # def __add__(PySize left,PyPoint right):
    #     cdef Size sz = left.csize[0]
    #     cdef Point pt = opadd(sz, right.cpoint[0])
    #     cdef PyPoint pypt = PyPoint(pt.x,pt.y)
    #     return pypt

    def __add__(left,right):
        cdef PyPoint pypt
        cdef Point pt
        if isinstance(left,PyPoint):
            if isinstance(right,PyPoint):
                pt = left.cpoint[0] + right.cpoint[0]
                pypt = PyPoint(pt.x,pt.y)
                return pypt
            elif isinstance(right,PySize):
                pt = left.cpoint[0] + right.csize[0] 
                pypt = PyPoint(pt.x,pt.y)
                return pypt
        # elif isinstance(left,PySize):
        #     if isinstance(right,PyPoint):
        #         pt = left.csize[0] + right.cpoint[0]
        #         pypt = PyPoint(pt.x,pt.y)
        #         return pypt
        #     elif isinstance(right,PySize):
        #         pt = left.csize[0] + right.csize[0] 
        #         pypt = PyPoint(pt.x,pt.y)
        #         return pypt

    def __repr__(self):
        return "PyPoint[%s,%s]" % (
                self.cpoint.x,
                self.cpoint.y
                )

