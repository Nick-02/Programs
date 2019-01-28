// ProgramDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgramDlg dialog



CProgramDlg::CProgramDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	fg = true;

	SetWindowTextW(L"Program");

	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CProgramDlg message handlers

BOOL CProgramDlg::OnInitDialog()
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

void CProgramDlg::OnPaint()
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

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 4, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);

		cx = RH / 2;
		cy = RW / 2;

		dx = cx / 8;
		dy = cy / 6;

		x1 = w.left = cx;
		y1 = w.top = cy - 4 * dy;

		for (x2 = x2 + 100; x2 >= -500; x2 += 50)
		{
			Sleep(mtime - 150);
			dc.FillSolidRect(&rc, RGB(255, 255, 255));
			x1 = w.left = x2;
			y2 = w.bottom = y1 + 8 * dy;


			CorpusShip(x1, y1, x2, y2, dx, dy);


			ElluminateShip(x1, y1, dx, dy);


			Ship(x1, y1, x2, y2, dx, dy);
		}



		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);


		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CProgramDlg::CorpusShip(int X1, int Y1, int X2, int Y2, int DX, int DY)
{
	CClientDC dc(this);
	GetClientRect(&rc);
	/*
	cf = RGB(0, 0, 0);
	hPenOxy = CreatePen(PS_SOLID, 4, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);
	dc.MoveTo(X1, Y1);
	dc.LineTo(X1 + DX, Y1 + 3 * DY);
	dc.LineTo(X1 + DX, Y1 + 8 * DY);
	dc.LineTo(X2, Y2);
	dc.MoveTo(X1, Y1);
	dc.LineTo(X1 - DX, Y1 + 3 * DY);
	dc.LineTo(X1 - DX, Y1 + 8 * DY);
	dc.LineTo(X2, Y2);
	*/
	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);

}

void CProgramDlg::ElluminateShip(int X1, int Y1, int DX, int DY)
{
	CClientDC dc(this);
	GetClientRect(&rc);

	cf = RGB(0, 0, 0);
	hPenOxy = CreatePen(PS_SOLID, 4, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	int r1;

	r1 = DX / 3;
	int x = X1 + DX;
	int y = Y1 + 8 * DY;
	dc.Ellipse(x - r1, y - r1, x + r1, y + r1);

	x = x + DX;
	dc.Ellipse(x - r1, y - r1, x + r1, y + r1);

	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);

}


void CProgramDlg::Ship(int X1, int Y1, int X2, int Y2, int DX, int DY)
{
	CClientDC dc(this);
	GetClientRect(&rc);

	cf = RGB(0, 0, 0);
	hPenOxy = CreatePen(PS_SOLID, 4, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	dc.MoveTo(X1 - 5 * DX, Y1 + 9 * DY);
	dc.LineTo(X1 - 5 * DX, Y1 + 8 * DY - DX / 3);
	dc.LineTo(X1 + DX / 3, Y1 + 8 * DY - DX / 3);
	dc.LineTo(X1 + 2 * (DX / 3), Y1 + 7 * DY);
	dc.LineTo(X1 + 4 * DX, Y1 + 7 * DY);
	dc.LineTo(X1 + 2 * DX + DX / 3, Y1 + 9 * DY);
	dc.LineTo(X1 - 5 * DX, Y1 + 9 * DY);

	dc.MoveTo(X1 - 4 * DX + DX / 3 + DX / 3, Y1 + 8 * DY - DX / 3);
	dc.LineTo(X1 - 3 * DX, Y1 + 7 * DY);
	dc.LineTo(X1 - 3 * DX, Y1 + 6 * DY);
	dc.LineTo(X1 + 2 * DX + DX / 3, Y1 + 6 * DY);
	dc.LineTo(X1 + 2 * DX + DX / 3, Y1 + 7 * DY);

	dc.MoveTo(X1 - DX - DX / 3, Y1 + 6 * DY);
	dc.LineTo(X1 - DX - DX / 3, Y1 + 4 * DY);
	dc.LineTo(X1 - DX + DX / 3, Y1 + 4 * DY);
	dc.LineTo(X1 - DX + DX / 3, Y1 + 6 * DY);
	dc.LineTo(X1 - DX + DX / 3, Y1 + 6 * DY);


	dc.MoveTo(X1 - DX + DX / 3, Y1 + 4 * DY + DX);
	dc.LineTo(X1 + DX / 3 + DX / 3, Y1 + 4 * DY + DX);
	dc.LineTo(X1 + DX / 3 + DX / 3, Y1 + 4 * DY + DX + DX / 2);

	dc.MoveTo(X1 + DX / 3, Y1 + 4 * DY + DX);
	dc.LineTo(X1 + DX / 3, Y1 + DY);
	dc.MoveTo(X1 + DX / 3, Y1);
	dc.LineTo(X1 - 5 * DX, Y1 + 8 * DY - DX / 3);
	dc.MoveTo(X1 + DX / 3, Y1);
	dc.LineTo(X1 + 4 * DX, Y1 + 7 * DY);




	dc.MoveTo(X1 - 2 * DX - DX / 3, Y1 + 7 * DY);
	dc.LineTo(X1 - DX / 3, Y1 + 7 * DY);

	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);


}
