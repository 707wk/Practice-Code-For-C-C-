// c51com1.h : main header file for the C51COM1 application
//

#if !defined(AFX_C51COM1_H__91B0210C_0DE5_42F3_84DC_93A98287B614__INCLUDED_)
#define AFX_C51COM1_H__91B0210C_0DE5_42F3_84DC_93A98287B614__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CC51com1App:
// See c51com1.cpp for the implementation of this class
//

class CC51com1App : public CWinApp
{
public:
	CC51com1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC51com1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CC51com1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C51COM1_H__91B0210C_0DE5_42F3_84DC_93A98287B614__INCLUDED_)
