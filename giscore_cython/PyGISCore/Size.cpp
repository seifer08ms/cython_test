#include "PyGISCore/Size.h"

Size::Size():cx(0),cy(0)
{	
}

Size::~Size()
{	
}

Size::Size(int nX,int nY):cx(nX),cy(nY)
{

}

bool operator==(const Size& szSrc,const Size& szTag)
{
	return szSrc.cx==szTag.cx && szSrc.cy==szTag.cy;
}

bool operator!=(const Size& szSrc,const Size& szTag)
{
	return szSrc.cx!=szTag.cx || szSrc.cy!=szTag.cy; 
}

Size& Size::operator+=(const Size& sz)
{
	cx+=sz.cx;
	cy+=sz.cy;
	return *this;
}

Size& Size::operator-=(const Size& sz)
{
	cx-=sz.cx; 
	cy-=sz.cy;
	return *this; 
}

Size Size::operator-() const
{
	return Size(-cx,-cy);
}

Size operator+(const Size& szSrc,const Size& szTag)
{
	return Size(szSrc.cx+szTag.cx,szSrc.cy+szTag.cy); 
}

Size operator-(const Size& szSrc,const Size& szTag)
{
	return Size(szSrc.cx-szTag.cx,szSrc.cy-szTag.cy);
}