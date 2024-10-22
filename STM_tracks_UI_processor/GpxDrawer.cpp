#include "pch.h"
#include "GpxDrawer.h"
#include "DataModel.h"

CGpxDrawer& CGpxDrawer::Instance()
{
	static CGpxDrawer singletonInstance;
	return singletonInstance;
}

void CGpxDrawer::DrawTracks(HDC dc) const
{

}
