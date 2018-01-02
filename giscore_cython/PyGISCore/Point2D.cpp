#include "PyGISCore/Point2D.h"
#include "Base/ogdcdefs.h"

Point2D::Point2D():x(0),y(0)
{

}

Point2D::~Point2D()
{
	
}

Point2D::Point2D(double dX,double dY):x(dX),y(dY)
{
	
}

Point2D::Point2D(const Size2D& sz):x(sz.cx),y(sz.cy)
{
	
}

Point2D::Point2D(const Point2D& pnt):x(pnt.x),y(pnt.y)
{
	
}

bool operator==(const Point2D& pntStart,const Point2D& pntEnd)
{
	return (OGDCIS0(pntStart.x-pntEnd.x) && OGDCIS0(pntStart.y-pntEnd.y));
}

bool operator!=(const Point2D& pntStart,const Point2D& pntEnd)
{
	return ((!OGDCIS0(pntStart.x-pntEnd.x)) || (!OGDCIS0(pntStart.y-pntEnd.y)));
}

void Point2D::Offset(const Size2D &szValue)
{
	x += szValue.cx;
	y += szValue.cy;
}

void Point2D::Offset(double dOffsetX, double dOffsetY)
{
	x += dOffsetX;
	y += dOffsetY;
}

void Point2D::Rotate(const Point2D &pntAnchor, double dCos, double dSin)
{
    double xx = x - pntAnchor.x;
    double yy = y - pntAnchor.y;
    
	x = xx * dCos - yy * dSin + pntAnchor.x;
    y = xx * dSin + yy * dCos + pntAnchor.y;
}

void Point2D::Rotate(const Point2D &pntAnchor, double dRadian)
{
	double dCos = cos(dRadian), dSin = sin(dRadian);
    double xx = x - pntAnchor.x;
    double yy = y - pntAnchor.y;
    
	x = xx * dCos - yy * dSin + pntAnchor.x;
    y = xx * dSin + yy * dCos + pntAnchor.y;
}

bool Point2D::EQ(const Point2D &pntTest, double dTolerance)const
{
	if (!OGDCEQ(x,pntTest.x,dTolerance) || !OGDCEQ(y,pntTest.y,dTolerance))
	{
		return false;
	}

	double dDistance2 = (x-pntTest.x)*(x-pntTest.x) + (y-pntTest.y)*(y-pntTest.y);
	double dTolerance2 = dTolerance*dTolerance;

	return dDistance2 <= dTolerance2;
}

Point2D& Point2D::operator=(const Size2D& sz)
{
	x=sz.cx;
	y=sz.cy;
	return *this;
}

Point2D& Point2D::operator=(const Point2D& pnt2)
{
	if( this == &pnt2)
		return *this;
	x=pnt2.x;
	y=pnt2.y;
	return *this;
}

Point2D& Point2D::operator=(const Point& pnt)
{
	x=pnt.x;
	y=pnt.y;
	return *this;
}

Point2D& Point2D::operator+=(const Point2D& pnt)
{
	x+=pnt.x;
	y+=pnt.y;
	return *this;
}

Point2D& Point2D::operator+=(const Size2D& sz)
{
	x+=sz.cx;
	y+=sz.cy;
	return *this;
}

Point2D& Point2D::operator-=(const Point2D& pnt)
{
	x-=pnt.x;
	y-=pnt.y;
	return *this;
}

Point2D& Point2D::operator-=(const Size2D& sz)
{
	x-=sz.cx;
	y-=sz.cy;
	return *this;
}

Point2D Point2D::operator-() const
{
	return Point2D(-x,-y);
}

Point2D operator+(const Point2D& pntStart,const Point2D& pntEnd)
{
	return Point2D(pntStart.x+pntEnd.x,pntStart.y+pntEnd.y);
}

Point2D operator+(const Point2D& pnt,const Size2D& sz)
{
	return Point2D(pnt.x+sz.cx,pnt.y+sz.cy);
}

Point2D operator+(const Size2D& sz,const Point2D& pnt)
{
	return Point2D(sz.cx+pnt.x,sz.cy+pnt.y);
}

Point2D operator-(const Point2D& pntStart,const Point2D& pntEnd)
{
	return Point2D(pntStart.x-pntEnd.x,pntStart.y-pntEnd.y);
}

Point2D operator-(const Point2D& pnt,const Size2D& sz)
{
	return Point2D(pnt.x-sz.cx,pnt.y-sz.cy);
}

Point2D operator-(const Size2D& sz,const Point2D& pnt)
{
	return Point2D(sz.cx-pnt.x,sz.cy-pnt.y);
}

bool operator<(const Point2D& pnt,const Point2D& sz)
{
	if(pnt.x < sz.x - EP)
	{
		return true;
	}
	else if(pnt.x > sz.x + EP)
	{
		return false;
	}
	else 
	{
		if(pnt.y < sz.y - EP)
		{
			return true;
		}
	}

	return false;
}