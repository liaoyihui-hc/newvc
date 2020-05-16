
// rect1View.cpp : Crect1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "rect1.h"
#endif

#include "rect1Doc.h"
#include "rect1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int a = 0, b = 0, c = 0;

// Crect1View

IMPLEMENT_DYNCREATE(Crect1View, CView)

BEGIN_MESSAGE_MAP(Crect1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Crect1View 构造/析构

Crect1View::Crect1View()
{
	rect.SetSize(256);
	for (int i = 0; i < 4; i++)
	{
		rect[i].bottom = 150;
		rect[i].left = 0;
		rect[i].top = 0;
		rect[i].right = 150;
	}


	// TODO: 在此处添加构造代码

}

Crect1View::~Crect1View()
{
}

BOOL Crect1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Crect1View 绘制

void Crect1View::OnDraw(CDC* pDC)
{
	Crect1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(rect[0]);
	for (int i = 1; i < 4; i++)
	{
		
		rect[i].left= rect[i-1].left+200;

		rect[i].right = rect[i-1].right+200;
		pDC->Rectangle(rect[i]);
		
	}
		

	
	// TODO: 在此处为本机数据添加绘制代码
}


// Crect1View 打印

BOOL Crect1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Crect1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Crect1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Crect1View 诊断

#ifdef _DEBUG
void Crect1View::AssertValid() const
{
	CView::AssertValid();
}

void Crect1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Crect1Doc* Crect1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Crect1Doc)));
	return (Crect1Doc*)m_pDocument;
}
#endif //_DEBUG


// Crect1View 消息处理程序


void Crect1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC*pDC = GetDC();
	
	CString s;

	
	

	CView::OnLButtonDown(nFlags, point);
	if (point.x > rect[0].left&&point.x<rect[0].right&&point.y>rect[0].top&&point.y < rect[0].bottom)
	{
		a = rand() % 50;
		s.Format(_T("%d"), a);
		pDC->TextOutW(50, 50, s);
	}
	else	if (point.x > rect[1].left&&point.x<rect[1].right&&point.y>rect[1].top&&point.y < rect[1].bottom)

	{
		b = rand() % 50;
		s.Format(_T("%d"), b);
		pDC->TextOutW(250, 50, s);

	}
	else	if (point.x > rect[2].left&&point.x<rect[2].right&&point.y>rect[2].top&&point.y < rect[2].bottom)

	{
		c = a + b;
		s.Format(_T("%d"), c);
		pDC->TextOutW(450, 50, s);

	}
	else
	{
		MessageBox(_T("点击无效"));
	}
}
