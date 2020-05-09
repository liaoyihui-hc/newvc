
// MFCApplication1View.cpp : CMFCApplication1View 类的实现
//
#include<math.h>
#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFCApplication1View::数值微分)
	ON_COMMAND(ID_32772, &CMFCApplication1View::中点画线)
	ON_COMMAND(ID_32773, &CMFCApplication1View::Bresenham算法)
	ON_COMMAND(ID_32775, &CMFCApplication1View::On32775)
END_MESSAGE_MAP()

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 绘制

void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication1View 打印

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 消息处理程序


void CMFCApplication1View::数值微分()
{  

	int xa = 100, ya = 300, xb = 300, yb = 200;
		
	数值微分画线(xa, ya, xb, yb);
	
	
	// TODO: 在此添加命令处理程序代码
}
void CMFCApplication1View::数值微分画线(int xa,int ya,int xb,int yb)
{
	CDC*pDC = GetDC();
	int x, y, c = RGB(80, 255, 30);
	float dx, dy, k;
	dx = (float)(xb - xa),
		dy = (float)(yb - ya);
	k = dy / dx;
	y = ya;
	if (fabs(k) < 1)
	{
		for (x = xa; x <= xb; x++)
		{
			pDC->SetPixel(x, int(y + 0.5), c);
		
		}
	}
	if (fabs(k) >= 1)
	{
		for (y = ya; y <= yb; y++)
		{
			pDC->SetPixel(int(x + 0.5), y, c);
			x = x + 1 / k;
			c += 80;
		}

		ReleaseDC(pDC);
	}
}
void CMFCApplication1View::中点画线()
{
	
	int xa = 300, ya = 200, xb = 450, yb= 300;

	for (int i = 0; i <4; i++)
	{
		中点画线代码(xa, ya, xb, yb);
		ya -= 10;
		yb += 10;
		
	}

}


void CMFCApplication1View::Bresenham算法()
{
// TODO: 在此添加命令处理程序代码
}
void CMFCApplication1View::中点画线代码(int xa, int ya, int xb, int yb)
{
	CDC*pDC = GetDC();
	int c = RGB(0, 255, 0);
	float a, b, d1, d2, d, dx, x, y;
	a = ya - yb, b = xb - xa, d = 2 * a + b;
	d1 = 2 * a, d2 = 2 * (a + b);
	x = xa, y = ya;
	pDC->SetPixel(x, y, c);
	while (x < xb)
	{

		if (d < 0)
		{
			x++,
				y++,
				d += d2;

		}
		else {
			x++, d += d1;
		}
		c = c + 10;
		pDC->SetPixel(x, y, c);
	}
	ReleaseDC(pDC);// TODO: 在此添加命令处理程序代码
}

void CMFCApplication1View::On32775()
{
	CDC*pDC = GetDC();
	int x1 = 100, y1 = 200, x2 = 350, y2 = 100, c = RGB(0, 0, 255);
	int i, s1, s2, interchange;
	float x, y, deltax, deltay, e, temp, f;
	x = x1;
	y = y1;
	deltax = abs(x2 - x1);
	deltay = abs(y2 - y1);
	if (x2 - x1 >= 0)
		s1 = 1;
	else
		s1 = -1;
	if (y2 - y1 >= 0)
		s2 = 1;
	else
		s2 = -1;
	if (deltay > deltax)
	{
		temp = deltax;
		deltay = temp;
		interchange = 1;
	}
	else
		interchange = 0;
	f = 2 * deltay - deltax;
	pDC->SetPixel(x, y, c);
	for (i = 1; i <= deltax; i++)
	{
		if (f >= 0)
		{
			if (interchange == 1)
				x += s1;
			else
				y += s2;
			pDC->SetPixel(x, y, c);

		}
		else
		{
			if (interchange == 1)
				y += s2;
			else
				x += s1;
			f = f + 2 * deltay;
		}
	}// TODO: 在此添加命令处理程序代码
}
