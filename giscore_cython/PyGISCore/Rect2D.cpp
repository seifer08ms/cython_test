#include "PyGISCore/Rect2D.h"
#include "Base/ogdcdefs.h"

using namespace OGDC;

#include <float.h>

Rect2D::Rect2D()
{
	left =	top = right = bottom = 0;
}

Rect2D::Rect2D(const Rect2D& rc)
{
	left=rc.left;
	bottom=rc.bottom;
	right=rc.right;
	top=rc.top;
}

Rect2D::~Rect2D()
{
}

Rect2D::Rect2D(double dLeft,double dTop,double dRight,double dBottom)
:left(dLeft),top(dTop),right(dRight),bottom(dBottom)
{

}

Rect2D::Rect2D(const Point2D& pnt,const Size2D& sz)
:left(pnt.x),top(pnt.y+sz.cy),right(pnt.x+sz.cx),bottom(pnt.y)
{

}

Rect2D::Rect2D(const Point2D& pntTL,const Point2D& pntBR)
:left(pntTL.x),top(pntTL.y),right(pntBR.x),bottom(pntBR.y)
{

}

Rect2D& Rect2D::operator=(const Rect2D& rc)
{
	if( this == &rc)
		return *this;
	left=rc.left;
	bottom=rc.bottom;
	right=rc.right;
	top=rc.top;
	return *this;
}


bool operator==(const Rect2D& rcStart,const Rect2D& rcEnd)
{
	return OGDCEQUAL(rcStart.left, rcEnd.left) && OGDCEQUAL(rcStart.right, rcEnd.right) 
		&& OGDCEQUAL(rcStart.bottom, rcEnd.bottom) && OGDCEQUAL(rcStart.top, rcEnd.top);
}

bool operator!=(const Rect2D& rcStart,const Rect2D& rcEnd)
{
	return !OGDCEQUAL(rcStart.left, rcEnd.left) || !OGDCEQUAL(rcStart.right, rcEnd.right) 
		|| !OGDCEQUAL(rcStart.bottom, rcEnd.bottom) || !OGDCEQUAL(rcStart.top, rcEnd.top);
}

void Rect2D::SetRect(double dLeft,double dTop,double dRight,double dBottom)
{
	left=dLeft;
	top=dTop;
	right=dRight;
	bottom=dBottom;
}

void Rect2D::SetRect(const Point2D& pntTL,const Point2D& pntBR)
{
	SetRect(pntTL.x,pntTL.y,pntBR.x,pntBR.y);
}

void Rect2D::SetEmpty()
{
	left=top=right=bottom=0;
}

bool Rect2D::IsEmpty() const
{
	if(!this->IsValid())
	{
		return true;
	}

	return OGDCIS0(right - left) || OGDCIS0(bottom - top);
}

bool Rect2D::IsNull() const
{
	if(!this->IsValid())
	{
		return true;
	}
	return OGDCIS0(left) && OGDCIS0(right) 
		&& OGDCIS0(bottom) && OGDCIS0(top) ;
}

double Rect2D::Width() const	
{
	return right-left;
}

double Rect2D::Height() const
{
	return top-bottom;
}

Point2D& Rect2D::TopLeft()
{
	return *((Point2D*)this);
}

const Point2D& Rect2D::TopLeft() const
{
	return *((Point2D*)this);
}

Point2D Rect2D::TopRight() const
{
	return Point2D(right, top);
}

Point2D& Rect2D::BottomRight()
{
	return *((Point2D*)this+1);
}

const Point2D& Rect2D::BottomRight() const
{
	return *((Point2D*)this+1);
}

Point2D Rect2D::BottomLeft() const
{
	return Point2D(left, bottom);
}

Point2D Rect2D::CenterPoint() const
{
	return Point2D((left+right)/2,(top+bottom)/2);
}

Size2D Rect2D::Size() const
{
	return Size2D(right-left,top-bottom);
}

void Rect2D::SwapLeftRight()
{
	double tmp=0;
	OGDCSWAP(left,right,tmp);
}

void Rect2D::SwapTopBottom()
{
	double tmp=0;
	OGDCSWAP(top,bottom,tmp);
}

bool Rect2D::PtInRect(const Point2D& pnt) const
{
	return (pnt.x>left || OGDCIS0(pnt.x-left) )	&& (pnt.x<right|| OGDCIS0(pnt.x-right))
		&& (pnt.y<top|| OGDCIS0(pnt.y-top))	&& (pnt.y>bottom|| OGDCIS0(pnt.y-bottom));
}

bool Rect2D::Contains(const Rect2D& rc) const
{
	return (rc.left > left || OGDCIS0(rc.left-left))
		&& (rc.top < top || OGDCIS0(rc.top-top))
		&& (rc.right < right || OGDCIS0(rc.right -right))
		&& (rc.bottom > bottom || OGDCIS0(rc.bottom-bottom));
}

bool Rect2D::Withins(const Rect2D& rc) const
{
	return (rc.left < left || OGDCIS0(rc.left-left))
		&& (rc.top > top || OGDCIS0(rc.top-top))
		&& (rc.right > right || OGDCIS0(rc.right -right))
		&& (rc.bottom < bottom || OGDCIS0(rc.bottom-bottom));
}

bool Rect2D::IsIntersect(const Rect2D& rc) const
{
	if(!this->IsValid() || !rc.IsValid())
	{
		return false;
	}
	return (right>rc.left || OGDCEQUAL(right,rc.left)) 
		&& (left<rc.right || OGDCEQUAL(left,rc.right))
		&& (top>rc.bottom|| OGDCEQUAL(top,rc.bottom))
		&& (bottom<rc.top|| OGDCEQUAL(bottom,rc.top));
}

void Rect2D::Normalize()
{
	if(!IsValid())
	{
		return;
	}
	double tmp=0;
	if(left>right) OGDCSWAP(left,right,tmp);
	if(bottom>top) OGDCSWAP(top,bottom,tmp);	
}

void Rect2D::Offset(double dX,double dY)
{
	left+=dX;
	top+=dY;
	right+=dX;
	bottom+=dY;
}

void Rect2D::Offset(const Size2D& sz)
{
	Offset(sz.cx,sz.cy);
}

void Rect2D::Offset(const Point2D& pnt)
{
	Offset(pnt.x,pnt.y);
}

void Rect2D::Inflate(double dMargin)
{
	left-=dMargin;
	top+=dMargin;
	right+=dMargin;
	bottom-=dMargin;
}

void Rect2D::Inflate(double dHorMargin,double dVerMargin)
{
	left-=dHorMargin;
	top+=dVerMargin;
	right+=dHorMargin;
	bottom-=dVerMargin;
}

void Rect2D::Inflate(double nLeftMargin,double nTopMargin,double nRightMargin,double nBottomMargin)
{
	left-=nLeftMargin;
	top+=nTopMargin;
	right+=nRightMargin;
	bottom-=nBottomMargin;
}

void Rect2D::Deflate(double dMargin)
{
	Inflate(-dMargin);
}

void Rect2D::Deflate(double mHorMargin,double mVerMargin)
{
	Inflate(-mHorMargin,-mVerMargin);
}

void Rect2D::Deflate(double dLeftMargin,double dTopMargin,double dRightMargin,double dBottomMargin)
{
	Inflate(-dLeftMargin,-dTopMargin,-dRightMargin,-dBottomMargin);
}

void Rect2D::Union(const Rect2D& rc)
{
	if(!((Rect2D)rc).IsValid()) return;
	if(!IsValid())    //如果自己是isvalid是false，那么就用传入的rc既可
	{
		*this = rc;
		return;
	}
	left   = OGDCMIN(left,rc.left);
	top    = OGDCMAX(top,rc.top);
	right  = OGDCMAX(right,rc.right);	
	bottom = OGDCMIN(bottom,rc.bottom);
}

void Rect2D::Union(const Point2D& pnt)
{
	left   = OGDCMIN(left,pnt.x);
	top    = OGDCMAX(top,pnt.y);
	right  = OGDCMAX(right,pnt.x);
	bottom = OGDCMIN(bottom,pnt.y);
}

void Rect2D::UnionRotate(const Point2D &pntOrg, double dbAngle)
{
	double dCosAngle = cos(dbAngle);
    double dSinAngle = sin(dbAngle);
	
	Point2D pntResults[4];
	pntResults[0].x = left;    pntResults[0].y = top;
    pntResults[1].x = left;    pntResults[1].y = bottom;
    pntResults[2].x = right;   pntResults[2].y = bottom;
    pntResults[3].x = right;   pntResults[3].y = top;
	
	for (int j=0; j<4; j++)
	{
		double xx = pntResults[j].x - pntOrg.x;
		double yy = pntResults[j].y - pntOrg.y;
		pntResults[j].x = xx * dCosAngle - yy * dSinAngle + pntOrg.x;
		pntResults[j].y = xx * dSinAngle + yy * dCosAngle + pntOrg.y;
	}
	
	left	= pntResults[0].x;
	right	= pntResults[0].x;
	top		= pntResults[0].y;
	bottom	= pntResults[0].y;
	
	for (int i=1; i<4; i++)
	{
		if (pntResults[i].y > top)
		{
			top = pntResults[i].y;
		}
		else if (pntResults[i].y < bottom)
		{
			bottom = pntResults[i].y;
		}

		if (pntResults[i].x < left)
		{
			left = pntResults[i].x;
		}
		else if (pntResults[i].x > right)
		{
			right = pntResults[i].x;
		}
	}	
}

bool Rect2D::IntersectRect(const Rect2D& rc)
{
	if (this->IsIntersect(rc))
	{
		left   = OGDCMAX(left,rc.left);
		top    = OGDCMIN(top,rc.top);
		right  = OGDCMIN(right,rc.right);
		bottom = OGDCMAX(bottom,rc.bottom);
		
		return true;
	}
	
	return false;
}

bool Rect2D::IntersectRect(const Rect2D& rc1,const Rect2D& rc2)
{
	if (rc1.IsIntersect(rc2))
	{
		left   = OGDCMAX(rc1.left,rc2.left);
		top    = OGDCMIN(rc1.top,rc2.top);
		right  = OGDCMIN(rc1.right,rc2.right);
		bottom = OGDCMAX(rc1.bottom,rc2.bottom);
		
		return true;
	}
	else
	{
		//和sfc保持一致，而且也合理
		SetEmpty();
	}
	
	return false;
}

bool Rect2D::IsValid() const
{
#ifdef WIN32
	#define FINITE(v) _finite(v)
#else
#ifdef SYMBIAN60
	#define FINITE(v) (Math::IsFinite(v))?1:0
#else
	#define FINITE(v) finite(v)
#endif
#endif
#if !defined IOS
 	if(FINITE(left)!=0 && FINITE(right)!=0
		&& FINITE(top)!=0 && FINITE(bottom)!=0)
	{
		return true;
	}
#else
    return true;
#endif
	return false;
}

void Rect2D::InflateRect(double x, double y)
{
	if(x<0) x = -x;
	if(y<0) y = -y;

	left -= x;
	top += y;
	right += x;
	bottom -= y;
}