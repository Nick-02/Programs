// AnimaciaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Animacia.h"
#include "AnimaciaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAnimaciaDlg dialog



CAnimaciaDlg::CAnimaciaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ANIMACIA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnimaciaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);


	SetWindowTextW(L"Програма демонстрації пересування об'єктів");

}

BEGIN_MESSAGE_MAP(CAnimaciaDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CAnimaciaDlg message handlers

BOOL CAnimaciaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

void CAnimaciaDlg::OnPaint()
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

		hNew = CreateFont(44, 0, 0, 0, FW_BOLD, 0, 0, 0,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"Trebuchet Ms");
		hold = (HFONT)SelectObject(dc, hNew);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		SetTextColor(dc, RGB(0, 0, 139));
		ms = "Зона переміщення об'єктів";
		dc.TextOutW(35, 40, ms, ms.GetLength());


		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		cx = RH / 2;
		cy = RW / 2;

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);


		// TODO
		int minx, maxx, miny, maxy;
		double xx, yy, a, b;

		minx = rc.left; miny = rc.top;
		maxx = rc.right; maxy = rc.bottom;
		a = -2 * PI; b = 2 * PI;

		w.left = minx; w.right = maxx;
		w.top = miny + 110; w.bottom = maxy;
		dc.FillSolidRect(&w, RGB(0, 0, 0));


		for (x1 = minx; x1 < maxx; x1 += 5)
		{
			xx = a + x1*(b - a) / maxx;
			yy = 1.5*sinf(xx);
			y1 = (int)(yy*maxx / (b - a));
			y1 = maxy / 2 - y1 + 50;

			pen = CreatePen(PS_SOLID, 4, RGB(255, 255, 0));
			brush = CreateSolidBrush(RGB(255, 100, 0));
			SelectObject(dc, pen);
			SelectObject(dc, brush);

			dc.Ellipse(x1, y1, x1 + 30, y1 + 30);

			Sleep(15);

			xx = a + x1*(b - a) / maxx;
			yy = -0.75*cosf(xx*1.2);
			y1 = (int)(yy*maxx / (b - a));
			y1 = maxy / 2 - y1 + 50;

			pen = CreatePen(PS_SOLID, 4, RGB(255, 20, 147));
			brush = CreateSolidBrush(RGB(148, 0, 211));
			SelectObject(dc, pen);
			SelectObject(dc, brush);

			dc.Ellipse(x1, y1, x1 + 30, y1 + 30);

			Sleep(15);



		}




		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);
		hold = (HFONT)SelectObject(dc, hbk);
		
		
		
		
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAnimaciaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
