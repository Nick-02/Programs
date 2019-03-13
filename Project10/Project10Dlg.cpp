// Project10Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Project10.h"
#include "Project10Dlg.h"
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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CProject10Dlg dialog



CProject10Dlg::CProject10Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PROJECT10_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProject10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	SetWindowTextW(L"Прикладне програмування: Дидактична картка №10.");
}

BEGIN_MESSAGE_MAP(CProject10Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CProject10Dlg message handlers

BOOL CProject10Dlg::OnInitDialog()
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

void CProject10Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProject10Dlg::OnPaint()
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
		CClientDC dc(this);
		GetClientRect(&rc);

		hNew = CreateFont(32, 0, 0, 0, FW_NORMAL, 0, 0, 0,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"Trebuchet Ms");
		hold = (HFONT)SelectObject(dc, hNew);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		cx = RH / 2;
		cy = RW / 2;

		
		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		// TODO

		dc.SetTextColor(RGB(72, 61, 139));
		ms = "Складіть формулу для обчислення площі даної фігури:";
		dc.TextOutW(cx-320, cy - 270, ms, ms.GetLength());


		pen = CreatePen(PS_SOLID, 4, RGB(72, 61, 139));
		SelectObject(dc, pen);

		// TODO KORPUS
		x1 = cx - 340;
		y1 = cy - 130;
		x2 = x1 + 280;
		y2 = y1 + 280;
		dc.Rectangle(x1, y1, x2, y2);
		x3 = x1 + 45;
		y3 = y1 + 45;
		x4 = x2 - 45;
		y4 = y2 - 45;
		dc.Rectangle(x3, y3, x4, y4);
		dc.MoveTo(x3, y2);
		dc.LineTo(x1, y2 + 45);
		dc.LineTo(x2, y2 + 45);
		dc.LineTo(x4, y2);

		// TODO S-BLOCK
		x = x1 + 380;
		y = y1;
		dc.Rectangle(x, y, x + 140, y + 325);
		dc.Ellipse(x + 80, y + 110, x + 105, y + 135);
		
		DeleteObject(pen);

		pen = CreatePen(PS_SOLID, 2, RGB(72, 61, 139));
		SelectObject(dc, pen);

		// TODO STRELKI
		// c
		dc.MoveTo(x1, y1);
		dc.LineTo(x1, y1 - 50);
		dc.MoveTo(x2, y1);
		dc.LineTo(x2, y1 - 50);
		dc.MoveTo(x1, y1 - 25);
		dc.LineTo(x2, y1 - 25);

		dc.MoveTo(x1, y1 - 25);
		dc.LineTo(x1 + 15, y1 - 30);
		dc.MoveTo(x1, y1 - 25);
		dc.LineTo(x1 + 15, y1 - 20);

		dc.MoveTo(x2, y1 - 25);
		dc.LineTo(x2 - 15, y1 - 30);
		dc.MoveTo(x2, y1 - 25);
		dc.LineTo(x2 - 15, y1 - 20);

		// b
		dc.MoveTo(x3, (y3 + y4) / 2);
		dc.LineTo(x4, (y3 + y4) / 2);

		dc.MoveTo(x3, (y3 + y4) / 2);
		dc.LineTo(x3 + 15, (y3 + y4) / 2 - 5);
		dc.MoveTo(x3, (y3 + y4) / 2);
		dc.LineTo(x3 + 15, (y3 + y4) / 2 + 5);

		dc.MoveTo(x4, (y3 + y4) / 2);
		dc.LineTo(x4 - 15, (y3 + y4) / 2 - 5);
		dc.MoveTo(x4, (y3 + y4) / 2);
		dc.LineTo(x4 - 15, (y3 + y4) / 2 + 5);

		//a
		dc.MoveTo(x1, y2 + 45);
		dc.LineTo(x1 - 50, y2 + 45);
		dc.MoveTo(x1, y4 + 45);
		dc.LineTo(x1 - 50, y4 + 45);
		dc.MoveTo(x1 - 25, y2 + 45);
		dc.LineTo(x1 - 25, y4 + 45);

		dc.MoveTo(x1 - 25, y2);
		dc.LineTo(x1 - 28, y2 + 10);
		dc.MoveTo(x1 - 25, y2);
		dc.LineTo(x1 - 22, y2 + 10);

		dc.MoveTo(x1 - 25, y2 + 45);
		dc.LineTo(x1 - 28, y2 + 35);
		dc.MoveTo(x1 - 25, y2 + 45);
		dc.LineTo(x1 - 22, y2 + 35);


		//e
		dc.MoveTo(x, y);
		dc.LineTo(x - 50, y);
		dc.MoveTo(x, y + 325);
		dc.LineTo(x - 50, y + 325);
		dc.MoveTo(x - 25, y);
		dc.LineTo(x - 25, y + 325);

		dc.MoveTo(x - 25, y);
		dc.LineTo(x - 28, y + 10);
		dc.MoveTo(x - 25, y);
		dc.LineTo(x - 22, y + 10);

		dc.MoveTo(x - 25, y + 325);
		dc.LineTo(x - 28, y + 315);
		dc.MoveTo(x - 25, y + 325);
		dc.LineTo(x - 22, y + 315);

		//f
		dc.MoveTo(x, y);
		dc.LineTo(x, y - 50);
		dc.MoveTo(x + 140, y);
		dc.LineTo(x + 140, y - 50);
		dc.MoveTo(x, y - 25);
		dc.LineTo(x + 140, y - 25);

		dc.MoveTo(x, y - 25);
		dc.LineTo(x + 15, y - 30);
		dc.MoveTo(x, y - 25);
		dc.LineTo(x + 15, y - 20);

		dc.MoveTo(x + 140, y - 25);
		dc.LineTo(x + 125, y - 30);
		dc.MoveTo(x + 140, y - 25);
		dc.LineTo(x + 125, y - 20);

		//d
		dc.MoveTo(x + 70, y + 150);
		dc.LineTo(x + 160, y + 35);
		dc.LineTo(x + 210, y + 35);

		dc.MoveTo(x + 78, y + 140);
		dc.LineTo(x + 76, y + 150);

		dc.MoveTo(x + 78, y + 140);
		dc.LineTo(x + 68, y + 144);

		DeleteObject(pen);

		// AZBUKA

		DeleteObject(hNew);
		hold = (HFONT)SelectObject(dc, hbk);

		hNew = CreateFont(28, 0, 0, 0, FW_BOLD, 0, 0, 0,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"Trebuchet Ms");
		hold = (HFONT)SelectObject(dc, hNew);

		ms = "c";
		dc.TextOutW((x1 + x2) / 2, y1 - 60, ms, ms.GetLength());
		ms = "b";
		dc.TextOutW((x3 + x4) / 2, (y4 + y3) / 2 - 40, ms, ms.GetLength());
		ms = "a";
		dc.TextOutW(x1 - 50, y4 + 50, ms, ms.GetLength());
		ms = "e";
		dc.TextOutW(x - 50, y + 150, ms, ms.GetLength());
		ms = "f";
		dc.TextOutW(x + 70, y - 60, ms, ms.GetLength());
		ms = "d";
		dc.TextOutW(x + 180, y + 5, ms, ms.GetLength());

		y -= 40;
		ms = ", де";
		dc.TextOutW(x + 250, y, ms, ms.GetLength());
		ms = "a=2;";
		dc.TextOutW(x + 250, y + 40, ms, ms.GetLength());
		ms = "b=6;";
		dc.TextOutW(x + 250, y + 80, ms, ms.GetLength());
		ms = "c=10;";
		dc.TextOutW(x + 250, y + 120, ms, ms.GetLength());
		ms = "d=1;";
		dc.TextOutW(x + 250, y + 160, ms, ms.GetLength());
		ms = "e=12";
		dc.TextOutW(x + 250, y + 200, ms, ms.GetLength());
		ms = "f=5";
		dc.TextOutW(x + 250, y + 240, ms, ms.GetLength());


		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);
		hold = (HFONT)SelectObject(dc, hbk);
	
		
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProject10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
