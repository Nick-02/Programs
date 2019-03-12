// RisovanieDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Risovanie.h"
#include "RisovanieDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	CStatic mpic1;
	CStatic mpic2;
	CStatic mpic3;

	CBitmap PIC;
	CRect Next, Back, Sps;
	CWnd *WndPtr;

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC1, mpic1);
	DDX_Control(pDX, IDC_PIC2, mpic2);
	DDX_Control(pDX, IDC_PIC3, mpic3);

	WndPtr = GetDlgItem(IDC_PIC1);
	WndPtr->GetWindowRect(&Next);
	ScreenToClient(&Next);

	WndPtr = GetDlgItem(IDC_PIC2);
	WndPtr->GetWindowRect(&Back);
	ScreenToClient(&Back);

	WndPtr = GetDlgItem(IDC_PIC3);
	WndPtr->GetWindowRect(&Sps);
	ScreenToClient(&Sps);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// CRisovanieDlg dialog



CRisovanieDlg::CRisovanieDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RISOVANIE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRisovanieDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRisovanieDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CRisovanieDlg message handlers

BOOL CRisovanieDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRisovanieDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRisovanieDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRisovanieDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (PtInRect(&Next, point))
	{
		PIC.LoadBitmapW(IDB_BITMAP28);
		mpic1.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(50);
	}
	else
	{
		PIC.LoadBitmapW(IDB_BITMAP20);
		mpic1.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(50);
	}

	if (PtInRect(&Back, point))
	{
		PIC.LoadBitmapW(IDB_BITMAP18);
		mpic2.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(50);
	}
	else
	{
		PIC.LoadBitmapW(IDB_BITMAP5);
		mpic2.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(50);
	}

	if (PtInRect(&Sps, point))
	{
		PIC.LoadBitmapW(IDB_BITMAP24);
		mpic3.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(50);
	}
	else
	{
		PIC.LoadBitmapW(IDB_BITMAP1);
		mpic3.SetBitmap(PIC);
		PIC.DeleteObject();
		Sleep(50);
	}



	SendMessage(WM_SYSCOMMAND, 0xF012, NULL);
	CDialog::OnMouseMove(nFlags, point);
}


void CAboutDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (PtInRect(&Next, point))
	{
		if (MessageBox(L"Бажаєте вийти з програми?", L"Вікно виходу", MB_YESNO | MB_ICONQUESTION) == IDYES) exit(0);
	}

	if (PtInRect(&Back, point))
	{
		if (MessageBox(L"Повертаємось до головного вікна програми?", L"Вікно -> Повернутись до головної програми", MB_YESNO | MB_ICONQUESTION) == IDYES) OnOK();
	}

	CDialog::OnLButtonDown(nFlags, point);
}


void CAboutDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (PtInRect(&Sps, point))
	{
		MessageBox(L"Натиснуто праву кнопку миші", L"Увага!", MB_OK|MB_ICONASTERISK);
	}


	CDialog::OnRButtonDown(nFlags, point);
}
