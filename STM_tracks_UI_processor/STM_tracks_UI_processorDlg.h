
// STM_tracks_UI_processorDlg.h : header file
//

#pragma once


// CSTMtracksUIprocessorDlg dialog
class CSTMtracksUIprocessorDlg : public CDialogEx
{
// Construction
public:
	CSTMtracksUIprocessorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STM_TRACKS_UI_PROCESSOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSetGpxPath();

private:
	CString gpxPath_;
	CStatic gpxPathLabel_;
public:
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
};
