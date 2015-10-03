// c51com1Dlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_C51COM1DLG_H__1AE512B4_E336_4B19_8051_DD9C6292A2A8__INCLUDED_)
#define AFX_C51COM1DLG_H__1AE512B4_E336_4B19_8051_DD9C6292A2A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CC51com1Dlg dialog

class CC51com1Dlg : public CDialog
{
// Construction
public:
	CC51com1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CC51com1Dlg)
	enum { IDD = IDD_C51COM1_DIALOG };
	CButton	m_BtnClose;
	CButton	m_BtnOpen;
	CMSComm	m_Comm1;
	CString	m_STATIC2;
	CString	IDC_EditRxData;
	CString	m_EditRxData;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC51com1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CC51com1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnOpen();
	afx_msg void OnOnCommMscomm1();
	afx_msg void OnBtnClose();
	afx_msg void OnButcom1();
	afx_msg void OnButcom2();
	afx_msg void OnButcom3();
	afx_msg void OnButcom4();
	afx_msg void OnButcom5();
	afx_msg void OnButcom6();
	afx_msg void OnButcom7();
	afx_msg void OnButcom8();
	afx_msg void OnBtnAbout();
	afx_msg void OnTimer(UINT nIDEvent);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C51COM1DLG_H__1AE512B4_E336_4B19_8051_DD9C6292A2A8__INCLUDED_)

#include "OScopeCtrl.h" 
