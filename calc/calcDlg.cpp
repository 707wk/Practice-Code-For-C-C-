// calcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "calc.h"
#include "calcDlg.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CComboBox m_cbExamble;

CString m_a;
CString m_b;

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg dialog

CCalcDlg::CCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalcDlg)
	m_a = _T("");
	m_b = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalcDlg)
	DDX_Control(pDX, IDC_COMBO1, m_cbExamble);
	DDX_Text(pDX, IDC_EDIT1, m_a);
	DDX_Text(pDX, IDC_EDIT2, m_b);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialog)
	//{{AFX_MSG_MAP(CCalcDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg message handlers

BOOL CCalcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_cbExamble.AddString("+");
	m_cbExamble.AddString("-");
	m_cbExamble.AddString("*");
	m_cbExamble.AddString("/");

	CEdit* pEdit = (CEdit*)m_cbExamble.GetWindow(GW_CHILD);
	// 将输入框色设置为只读
	pEdit->SetReadOnly(TRUE);

	CComboBox *pBox = (CComboBox *)GetDlgItem( IDC_COMBO1 );
	//设置默认显示
	pBox->SetCurSel( 0 );

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalcDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCalcDlg::OnOK() 
{
	// TODO: Add extra validation here
	int nIndex = m_cbExamble.GetCurSel();
	int a;
	int b;
	double c;
	CString str;

	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	a=_ttoi(str);
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	b=_ttoi(str);

	switch(nIndex)
	{
	case 0:
		c=a+b;
		break;
	case 1:
		c=a-b;
		break;
	case 2:
		c=a*b;
		break;
	case 3:
		if(b==0)
		{
			GetDlgItem(IDC_EDIT3)->SetWindowText("error!"); 
			return ;
		}
		c=a*1.0/b;
		break;
	}

	str.Format(_T("%g"),c);  
	GetDlgItem(IDC_EDIT3)->SetWindowText(str); 

	//CDialog::OnOK();
}
