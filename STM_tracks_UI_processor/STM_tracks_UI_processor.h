
// STM_tracks_UI_processor.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSTMTracksUIProcessorApp:
// See STM_tracks_UI_processor.cpp for the implementation of this class
//

class CSTMTracksUIProcessorApp : public CWinApp
{
public:
	CSTMTracksUIProcessorApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSTMTracksUIProcessorApp theApp;
