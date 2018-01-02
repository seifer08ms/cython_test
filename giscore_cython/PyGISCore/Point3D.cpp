#include "PyGISCore/Point3D.h"
#include "Base/ogdcdefs.h"

using namespace OGDC;

Point3D::Point3D():x(0),y(0),z(0)
{

}

Point3D::~Point3D()
{

}

Point3D::Point3D(double xx,double yy,double zz):x(xx),y(yy),z(zz)
{

}

bool operator==(const Point3D& p,const Point3D& q)
{
	return OGDCEQUAL(p.x, q.x) && OGDCEQUAL(p.y, q.y) && OGDCEQUAL(p.z, q.z);
}

bool operator!=(const Point3D& p,const Point3D& q)
{
	return !OGDCEQUAL(p.x, q.x) || !OGDCEQUAL(p.y, q.y) || !OGDCEQUAL(p.z, q.z);
}

Point3D& Point3D::operator=(const Point3D& s)
{
	if(this == &s)
		return *this;
	x=s.x;
	y=s.y;
	z=s.z; 
	return *this;
}

Point3D& Point3D::operator+=(const Point3D& p)
{
	x+=p.x;
	y+=p.y;
	z+=p.z;
	return *this;
}

Point3D& Point3D::operator-=(const Point3D& p)
{
	x-=p.x;
	y-=p.y;
	z-=p.z;
	return *this;
}

Point3D& Point3D::operator*=(double c)
{
	x*=c;
	y*=c;
	z*=c;
	return *this;
}

Point3D& Point3D::operator/=(double c)
{
	if (OGDCIS0(c))
	{
		x/=c;
		y/=c;
		z/=c;
	}
	
	return *this;
}

Point3D Point3D::operator-() const
{
	return Point3D(-x,-y,-z);
}