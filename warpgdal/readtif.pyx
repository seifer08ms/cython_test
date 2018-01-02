cdef extern from "gdal_readintif.h" namespace "gdaltest":
    cdef cppclass Readtif:
        ctypedef const char* tif_path
        Readtif(const char* path) except +


cdef class PyReadtif:
    cdef Readtif *thisptr 
    def __cinit__(self,object path):
        cdef const char *fname = NULL
        path = path.encode('utf-8')
        fname = path
        self.thisptr = new Readtif(fname)
    def __dealloc__(self):
        del self.thisptr
