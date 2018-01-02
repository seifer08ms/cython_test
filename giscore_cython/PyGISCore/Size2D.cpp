#include "PyGISCore/Size2D.h"
#include "Base/ogdcdefs.h"

using namespace OGDC;

Size2D::Size2D():cx(0.0),cy(0.0)
{
}

Size2D::~Size2D()
{
}

Size2D::Size2D(double dX,double dY):cx(dX),cy(dY)
{

}

bool operator==(const Size2D& szSrc,const Size2D& sztag)
{
	return OGDCEQUAL(szSrc.cx,sztag.cx) && OGDCEQUAL(szSrc.cy,sztag.cy);
}

bool operator!=(const Size2D& szSrc,const Size2D& sztag)
{
	return !OGDCEQUAL(szSrc.cx,sztag.cx) || !OGDCEQUAL(szSrc.cy,sztag.cy);
}

Size2D& Size2D::operator+=(const Size2D& sz)
{
	cx+=sz.cx;
	cy+=sz.cy;
	return *this;
}

Size2D& Size2D::operator-=(const Size2D& sz)
{
	cx-=sz.cx;
	cy-=sz.cy;
	return *this;
}

Size2D Size2D::operator-() const
{
	return Size2D(-cx,-cy);
}

Size2D operator+(const Size2D& szSrc,const Size2D& sztag)
{
	return Size2D(szSrc.cx+sztag.cx,szSrc.cy+sztag.cy);
}

Size2D operator-(const Size2D& szSrc,const Size2D& sztag)
{
	return Size2D(szSrc.cx-sztag.cx,szSrc.cy-sztag.cy);
}