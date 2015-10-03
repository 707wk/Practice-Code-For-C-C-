// c51com1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "c51com1.h"
#include "c51com1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define TIMER_START 707
#define INTERVAL 1000

int comnum=1;
double temp[3];

COScopeCtrl m_Osc;
COScopeCtrl m_Osc1;
COScopeCtrl m_Osc2;

//CComboBox m_COMBO1;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC51com1Dlg dialog

CC51com1Dlg::CC51com1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CC51com1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC51com1Dlg)
	m_STATIC2 = _T("");
	IDC_EditRxData = _T("");
	m_EditRxData = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CC51com1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC51com1Dlg)
	DDX_Control(pDX, IDC_BtnClose, m_BtnClose);
	DDX_Control(pDX, IDC_BtnOpen, m_BtnOpen);
	DDX_Control(pDX, IDC_MSCOMM1, m_Comm1);
	DDX_Text(pDX, IDC_STATIC2, m_STATIC2);
	DDX_Text(pDX, IDC_STATIC3, m_EditRxData);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CC51com1Dlg, CDialog)
	//{{AFX_MSG_MAP(CC51com1Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BtnOpen, OnBtnOpen)
	ON_BN_CLICKED(IDC_BtnClose, OnBtnClose)
	ON_BN_CLICKED(IDC_BUTCOM1, OnButcom1)
	ON_BN_CLICKED(IDC_BUTCOM2, OnButcom2)
	ON_BN_CLICKED(IDC_BUTCOM3, OnButcom3)
	ON_BN_CLICKED(IDC_BUTCOM4, OnButcom4)
	ON_BN_CLICKED(IDC_BUTCOM5, OnButcom5)
	ON_BN_CLICKED(IDC_BUTCOM6, OnButcom6)
	ON_BN_CLICKED(IDC_BUTCOM7, OnButcom7)
	ON_BN_CLICKED(IDC_BUTCOM8, OnButcom8)
	ON_BN_CLICKED(IDC_BtnAbout, OnBtnAbout)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC51com1Dlg message handlers

BOOL CC51com1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	//初始化温度曲线控件  
    CRect rt;  
    GetDlgItem(IDC_OSC)->GetWindowRect(rt);  
    ScreenToClient(rt);  
    m_Osc.Create(WS_VISIBLE | WS_CHILD,rt,this);  
    m_Osc.SetRange(0.0, 50.0, 1) ;  
    m_Osc.SetYUnits("温度") ;  
    m_Osc.SetXUnits("采样频率: 1000ms") ;  
    m_Osc.SetBackgroundColor(RGB(0, 0, 64)) ;  
    m_Osc.SetGridColor(RGB(192, 192, 255)) ;  
    m_Osc.SetPlotColor(RGB(0, 255, 255)) ;  

	//初始化电压曲线控件  
    GetDlgItem(IDC_OSC2)->GetWindowRect(rt);  
    ScreenToClient(rt);  
    m_Osc1.Create(WS_VISIBLE | WS_CHILD,rt,this);  
    m_Osc1.SetRange(-10.0, 10.0, 1) ;  
    m_Osc1.SetYUnits("电压") ;  
    m_Osc1.SetXUnits("采样频率: 1000ms") ;  
    m_Osc1.SetBackgroundColor(RGB(0, 0, 64)) ;  
    m_Osc1.SetGridColor(RGB(192, 192, 255)) ;  
    m_Osc1.SetPlotColor(RGB(255, 0, 255)) ;  

	//初始化电流曲线控件  
    GetDlgItem(IDC_OSC3)->GetWindowRect(rt);  
    ScreenToClient(rt);  
    m_Osc2.Create(WS_VISIBLE | WS_CHILD,rt,this);  
    m_Osc2.SetRange(-10.0, 10.0, 1) ;  
    m_Osc2.SetYUnits("电流") ;  
    m_Osc2.SetXUnits("采样频率: 1000ms") ;  
    m_Osc2.SetBackgroundColor(RGB(0, 0, 64)) ;  
    m_Osc2.SetGridColor(RGB(192, 192, 255)) ;  
    m_Osc2.SetPlotColor(RGB(255, 255, 0)) ;  

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetDlgItemText(IDC_STATIC2,"COM1");
	GetDlgItem(IDC_BtnClose)->EnableWindow(FALSE);
	SetDlgItemText(IDC_STATIC3,"00.0");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CC51com1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CC51com1Dlg::OnPaint() 
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
HCURSOR CC51com1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CC51com1Dlg :: OnBtnOpen()
{
    // TODO: Add your control notification handler code here
    if(m_Comm1.GetPortOpen())
    m_Comm1.SetPortOpen(FALSE);
    
    m_Comm1.SetCommPort(comnum);
    m_Comm1.SetInBufferSize(4096);
    m_Comm1.SetOutBufferSize(2048);
    m_Comm1.SetSettings("9600,n,8,1");
    m_Comm1.SetInputMode(1);
    m_Comm1.SetRThreshold(1);
    m_Comm1.SetInputLen(0);
    if(!m_Comm1.GetPortOpen())
	{
		m_Comm1.SetPortOpen(TRUE);
		GetDlgItem(IDC_BUTCOM1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTCOM2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTCOM3)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTCOM4)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTCOM5)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTCOM6)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTCOM7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTCOM8)->EnableWindow(FALSE);
		GetDlgItem(IDC_BtnOpen)->EnableWindow(FALSE);
		GetDlgItem(IDC_BtnClose)->EnableWindow(TRUE);
	}
    else 
		AfxMessageBox("cannot open serial port");
    m_Comm1.GetInput();
	SetDlgItemText(IDC_STATIC1,"已连接");
	SetTimer(TIMER_START,INTERVAL,NULL);
}

BEGIN_EVENTSINK_MAP(CC51com1Dlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CC51com1Dlg)
	ON_EVENT(CC51com1Dlg, IDC_MSCOMM1, 1 /* OnComm */, OnOnCommMscomm1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CC51com1Dlg :: OnOnCommMscomm1()
{
    VARIANT variant_inp ;
    COleSafeArray safearray_inp ;
    LONG len;
    LONG k ;
    BYTE rxdata[2048];
    CString strtemp ;
    if(m_Comm1.GetCommEvent()==2)
    {
        variant_inp=m_Comm1.GetInput();
        safearray_inp=variant_inp ;
        len=safearray_inp.GetOneDimSize();
		//if(len<10)return ;
        for(k=0;k<len;k++)
			safearray_inp.GetElement(&k,rxdata+k);
		rxdata[k]='\0';
		//MessageBox((char*)rxdata);
		SetDlgItemText(IDC_EDIT1,(char*)rxdata);
		sscanf((char*)rxdata,"%lf:%lf:%lf",temp,temp+1,temp+2);
    }
	
}

void CC51com1Dlg::OnBtnClose() 
{
    m_Comm1.SetPortOpen(FALSE);
	SetDlgItemText(IDC_STATIC1,"已关闭");
	GetDlgItem(IDC_BUTCOM1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTCOM2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTCOM3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTCOM4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTCOM5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTCOM6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTCOM7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTCOM8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BtnOpen)->EnableWindow(TRUE);
	GetDlgItem(IDC_BtnClose)->EnableWindow(FALSE);
	KillTimer(TIMER_START);
}

void CC51com1Dlg::OnButcom1() 
{
	comnum=1;
	SetDlgItemText(IDC_STATIC2,"COM1");
}

void CC51com1Dlg::OnButcom2() 
{
	comnum=2;
	SetDlgItemText(IDC_STATIC2,"COM2");
}

void CC51com1Dlg::OnButcom3() 
{
	comnum=3;
	SetDlgItemText(IDC_STATIC2,"COM3");
}

void CC51com1Dlg::OnButcom4() 
{
	comnum=4;
	SetDlgItemText(IDC_STATIC2,"COM4");
}

void CC51com1Dlg::OnButcom5() 
{
	comnum=5;
	SetDlgItemText(IDC_STATIC2,"COM5");
}

void CC51com1Dlg::OnButcom6() 
{
	comnum=6;
	SetDlgItemText(IDC_STATIC2,"COM6");
}

void CC51com1Dlg::OnButcom7() 
{
	comnum=7;
	SetDlgItemText(IDC_STATIC2,"COM7");
}

void CC51com1Dlg::OnButcom8() 
{
	comnum=8;
	SetDlgItemText(IDC_STATIC2,"COM8");
}

void CC51com1Dlg::OnBtnAbout() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CC51com1Dlg::OnTimer(UINT nIDEvent) 
{
	CString strtemp ;
	switch(nIDEvent)
	{
		case TIMER_START:
			{
				m_Osc.AppendPoint(temp[0]);
				m_Osc1.AppendPoint(temp[1]);
				m_Osc2.AppendPoint(temp[2]);

				strtemp.Format("%0.2lf",temp[0]);
				SetDlgItemText(IDC_STATIC3,strtemp);
				strtemp.Format("%0.2lf",temp[1]);
				SetDlgItemText(IDC_STATIC4,strtemp);
				strtemp.Format("%0.2lf",temp[2]);
				SetDlgItemText(IDC_STATIC5,strtemp);
			}
	}
	CDialog::OnTimer(nIDEvent);
}
