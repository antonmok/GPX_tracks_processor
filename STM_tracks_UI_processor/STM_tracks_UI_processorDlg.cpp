
// STM_tracks_UI_processorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "STM_tracks_UI_processor.h"
#include "STM_tracks_UI_processorDlg.h"
#include "afxdialogex.h"
#include "GpxReader.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSTMtracksUIprocessorDlg dialog



CSTMtracksUIprocessorDlg::CSTMtracksUIprocessorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STM_TRACKS_UI_PROCESSOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSTMtracksUIprocessorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_STATIC_PATH, gpxPathLabel_);
}

BEGIN_MESSAGE_MAP(CSTMtracksUIprocessorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SET_GPX_PATH, &CSTMtracksUIprocessorDlg::OnBnClickedButtonSetGpxPath)
	ON_BN_CLICKED(IDC_BUTTON_START, &CSTMtracksUIprocessorDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CSTMtracksUIprocessorDlg::OnBnClickedButtonStop)
END_MESSAGE_MAP()


// CSTMtracksUIprocessorDlg message handlers

BOOL CSTMtracksUIprocessorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSTMtracksUIprocessorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSTMtracksUIprocessorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSTMtracksUIprocessorDlg::OnBnClickedButtonSetGpxPath()
{
	CFolderPickerDialog dirPickdlg;

	if (dirPickdlg.DoModal() != IDCANCEL) {
		gpxPath_ = dirPickdlg.GetPathName().GetString();
		gpxPathLabel_.SetWindowText(gpxPath_);
	}
}


void CSTMtracksUIprocessorDlg::OnBnClickedButtonStart()
{
	if (gpxPath_.GetLength() == 0)
		AfxMessageBox(_T("Select GPX path first"));
	else
		CGpxReader::Instance().Run(gpxPath_.GetBuffer());
}


void CSTMtracksUIprocessorDlg::OnBnClickedButtonStop()
{
	CGpxReader::Instance().Stop();
}
