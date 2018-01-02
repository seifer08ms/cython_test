#include "PyGISCore/Rect.h"
#include "Base/ogdcdefs.h"

using namespace OGDC;

Rect::Rect():left(0),top(0),right(0),bottom(0)
{
}

Rect::~Rect()
{
}

Rect::Rect(int nLeft,int nTop,int nRight,int nBottom)
:left(nLeft),top(nTop),right(nRight),bottom(nBottom)
{

}

Rect::Rect(const Point& pnt,const Size& sz)
:left(pnt.x),top(pnt.y),right(pnt.x+sz.cx),bottom(pnt.y+sz.cy)
{

}

Rect::Rect(const Point& pntTL,const Point& pntBR)
:left(pntTL.x),top(pntTL.y),right(pntBR.x),bottom(pntBR.y)
{

}

Rect& Rect::operator=(const Rect& rc)
{
    if( this == &rc)
		return *this;
	left   =rc.left;
	top    =rc.top;
    right  =rc.right;
	bottom =rc.bottom;
    return *this;
}

bool operator==(const Rect& rcStart,const Rect& rcEnd)
{
	return rcStart.left==rcEnd.left && rcStart.top==rcEnd.top &&
		rcStart.right==rcEnd.right && rcStart.bottom==rcEnd.bottom;
}

bool operator!=(const Rect& rcStart,const Rect& rcEnd)
{
	return rcStart.left!=rcEnd.left || rcStart.top!=rcEnd.top ||
		rcStart.right!=rcEnd.right || rcStart.bottom!=rcEnd.bottom;
}

void Rect::SetRect(int nLeft,int nTop,int nRight,int nBottom)
{
	left=nLeft;
	top=nTop;
	right=nRight;
	bottom=nBottom;
}

void Rect::SetRect(const Point& pntTL,const Point& pntBR)
{
	SetRect(pntTL.x,pntTL.y,pntBR.x,pntBR.y);
}

void Rect::SetEmpty()
{
	left=top=right=bottom=0;
}

bool Rect::IsEmpty() const
{
	return left>=right || top>=bottom;
}

bool Rect::IsNull() const
{
	return left==0 && top==0 
		&& right==0 && bottom==0;
}

int Rect::Width() const	
{
	return right-left;
}

int Rect::Height() const
{
	return bottom-top;
}

Point& Rect::TopLeft()
{
	return *((Point*)this);
}

const Point& Rect::TopLeft() const
{
	return *((Point*)this);
}

Point& Rect::BottomRight()
{
	return *((Point*)this+1);
}

const Point& Rect::BottomRight() const
{
	return *((Point*)this+1);
}

Point Rect::CenterPoint() const
{
	return Point((left+right)/2,(top+bottom)/2);
}

Size Rect::GetSize() const
{
	return Size(right-left,bottom-top);
}

void Rect::SwapLeftRight()
{
	int tmp=0;
	OGDCSWAP(left,right,tmp);
}

void Rect::SwapTopBottom()
{
	int tmp=0;
	OGDCSWAP(top,bottom,tmp);
}

bool Rect::PtInRect(const Point& pnt) const
{
	return (pnt.x>=left)	&& (pnt.x<=right)
		&& (pnt.y>=top)	&& (pnt.y<=bottom);
}

bool Rect::Contains(const Rect& rc) const
{
	return left<=rc.left && top<=rc.top &&
		right>=rc.right && bottom>=rc.bottom;
}

bool Rect::Withins(const Rect& rc) const
{
	return left>=rc.left && top>=rc.top &&
		right<=rc.right && bottom<=rc.bottom;
}

bool Rect::Intersects(const Rect& rc) const
{
	return right>=rc.left && left<=rc.right &&
		bottom>=rc.top && top<=rc.bottom;
}

void Rect::Normalize()
{
	int tmp=0;
	if(left>right) OGDCSWAP(left,right,tmp);
	if(top>bottom) OGDCSWAP(top,bottom,tmp);	
}

void Rect::Offset(int x,int y)
{
	left    += x;
	top		+= y;
	right	+= x;
	bottom	+= y;
}

void Rect::Offset(const Size& sz)
{
	Offset(sz.cx,sz.cy);
}

void Rect::Offset(const Point& pnt)
{
	Offset(pnt.x,pnt.y);
}

void Rect::Inflate(int nMargin)
{
	left	    -= nMargin;
	top		-= nMargin;
	right	+= nMargin;
	bottom	+= nMargin;
}

void Rect::Inflate(int nHorMargin,int nVerMargin)
{
	left	    -= nHorMargin;
	top		-= nVerMargin;
	right	+= nHorMargin;
	bottom	+= nVerMargin;
}

void Rect::Inflate(int nLeftMargin,int nTopMargin,int nRightMargin,int nBottomMargin)
{
	left	    -= nLeftMargin;
	top		-= nTopMargin;
	right	+= nRightMargin;
	bottom	+= nBottomMargin;
}

void Rect::Deflate(int nMargin)
{
	Inflate(-nMargin);
}

void Rect::Deflate(int nHorMargin,int nVerMargin)
{
	Inflate(-nHorMargin,-nVerMargin);
}

void Rect::Deflate(int nLeftMargin,int nTopMargin,int nRightMargin,int nBottomMargin)
{
	Inflate(-nLeftMargin,-nTopMargin,-nRightMargin,-nBottomMargin);
}

void Rect::Union(const Rect& rc)
{
	left	= OGDCMIN(left,rc.left);
	top		= OGDCMIN(top,rc.top);
	right	= OGDCMAX(right,rc.right);	
	bottom	= OGDCMAX(bottom,rc.bottom);
}

void Rect::Union(const Point& pnt)
{
	left	= OGDCMIN(left,pnt.x);
	top		= OGDCMIN(top,pnt.y);
	right	= OGDCMAX(right,pnt.x);
	bottom	= OGDCMAX(bottom,pnt.y);
}

void Rect::Intersection(const Rect& rc)
{
	left	= OGDCMAX(left,rc.left);
	top		= OGDCMAX(top,rc.top);
	right	= OGDCMIN(right,rc.right);
	bottom	= OGDCMIN(bottom,rc.bottom);
}