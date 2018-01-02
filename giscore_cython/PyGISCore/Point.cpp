#include "PyGISCore/Point.h"
#include "Base/ogdcdefs.h"

using namespace OGDC;

Point::Point() :x(0),y(0)
{

}	

Point::~Point()
{

}

Point::Point(int nX,int nY):x(nX),y(nY) 
{

}

Point::Point(const Size& sz):x(sz.cx),y(sz.cy) 
{
	
}

bool operator==(const Point& pntStart,const Point& pntEnd)
{
	return ((pntStart.x==pntEnd.x) && (pntStart.y==pntEnd.y)); 
}

bool operator!=(const Point& pntStart,const Point& pntEnd)
{
	return pntStart.x!=pntEnd.x || pntStart.y!=pntEnd.y;
}

Point& Point::operator=(const Size& sz)
{ 
	x=sz.cx; 
	y=sz.cy; 
	return *this; 
}

Point& Point::operator=(const Point& pnt)
{
	x=pnt.x; 
	y=pnt.y; 
	return *this; 
}

void Point::Offset(const Size &szValue)
{
	x += szValue.cx;
	y += szValue.cy;
}

void Point::Offset(int nOffsetX, int nOffsetY) 
{
	x += nOffsetX;
	y += nOffsetY;
}

void Point::Rotate(const Point &pntAnchor, double dCos, double dSin)
{
    double xx = x - pntAnchor.x;
    double yy = y - pntAnchor.y;
    x = OGDCROUND(xx * dCos - yy * dSin)  + pntAnchor.x;
    y = OGDCROUND(xx * dSin + yy * dCos)  + pntAnchor.y;
}

void Point::Rotate(const Point &pntAnchor, double dRadian)
{
	double dCos = cos(dRadian), dSin = sin(dRadian);
    double xx = x - pntAnchor.x;
    double yy = y - pntAnchor.y;
    
	x = OGDCROUND(xx * dCos - yy * dSin)  + pntAnchor.x;
    y = OGDCROUND(xx * dSin + yy * dCos)  + pntAnchor.y;
}

Point& Point::operator+=(const Point& pnt)
{
	x+=pnt.x; 
	y+=pnt.y; 
	return *this; 
}

Point& Point::operator+=(const Size& sz)
{
	x+=sz.cx; 
	y+=sz.cy; 
	return *this; 
}

Point& Point::operator-=(const Point& pnt)
{
	x-=pnt.x;
	y-=pnt.y; 
	return *this; 
}

Point& Point::operator-=(const Size& sz)
{
	x-=sz.cx; 
	y-=sz.cy; 
	return *this; 
}

Point Point::operator-() const
{
	return Point(-x,-y); 
}

bool Point::operator<(const Point& pt) const
{
	return x<pt.x || (x==pt.x && y<pt.y);
}

Point operator+(const Point& pntStart,const Point& pntEnd)
{
	return Point(pntStart.x+pntEnd.x,pntStart.y+pntEnd.y); 
}

Point operator+(const Point& pnt,const Size& sz)
{
	return Point(pnt.x+sz.cx,pnt.y+sz.cy); 
}

Point operator+(const Size& sz,const Point& pnt)
{
	return Point(sz.cx+pnt.x,sz.cy+pnt.y); 
}

Point operator-(const Point& pntStart,const Point& pntEnd)
{
	return Point(pntStart.x-pntEnd.x,pntStart.y-pntEnd.y); 
}

Point operator-(const Point& pnt,const Size& sz)
{
	return Point(pnt.x-sz.cx,pnt.y-sz.cy); 
}

Point operator-(const Size& sz,const Point& pnt)
{
	return Point(sz.cx-pnt.x,sz.cy-pnt.y); 
}