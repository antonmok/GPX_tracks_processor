#pragma once

class CGpxDrawer
{
public:
	static CGpxDrawer& Instance();

	void DrawTracks(HDC dc) const;

private:

	CGpxDrawer() {};
	~CGpxDrawer() {};
	CGpxDrawer(CGpxDrawer const&) = delete;
	CGpxDrawer& operator= (CGpxDrawer const&) = delete;
};
