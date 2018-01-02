/*************************************************************************
	> File Name: gdal_readintif.h
	> Author: Chenliang-Wang
	> Mail: chenliangwang08ms@gmail.com
	> Created Time: Sun 17 Dec 2017 10:38:41 PM CST
 ************************************************************************/

#ifndef _GDAL_READINTIF_H
#define _GDAL_READINTIF_H
#include <string.h>

namespace gdaltest {
class Readtif {
  public:
    const char*  tif_path;
    Readtif(const char* path);
    ~Readtif();
};
}
#endif
