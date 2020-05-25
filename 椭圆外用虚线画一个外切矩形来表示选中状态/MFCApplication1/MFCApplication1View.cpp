
// MFCApplication1View.cpp : CMFCApplication1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#include "diag.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int color=RGB(255, 255, 255);

// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONUP()

	ON_COMMAND(ID_32771, &CMFCApplication1View::On32771)
END_MESSAGE_MAP()

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View()
{
	rc.top = 50;
	rc.bottom = 300;
	rc.left = 100;
	rc.right = 500;// TODO: 在此处添加构造代码

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

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	pDC->Ellipse(rc);
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


void CMFCApplication1View::OnMButtonDown(UINT nFlags, CPoint point)
{


	CView::OnMButtonDown(nFlags, point);
}


void CMFCApplication1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	CDC*pDC = GetDC();
	CClientDC dc(this);
	
	// TODO: 在此添加消息处理程序代码和/或调用默认值


	if (point.x >=rc.left&&point.x <=rc.right&&point.y <= rc.bottom&&point.y >=rc.top)
	{
		CPen newPen(PS_DOT, 1, color);
	CPen*oldPen = dc.SelectObject(&newPen);
	
		dc.Rectangle(rc);
		dc.SelectObject(oldPen);
		Sleep(100);
		CBrush newBrush(color);
		CBrush*oldBrush = dc.SelectObject(&newBrush);
		dc.Ellipse(rc);
	
	
		
	
	
	
	}// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CView::OnLButtonUp(nFlags, point);
}





void CMFCApplication1View::On32771()
{
	
		



		diag dc;
		int result = dc.DoModal();
		if (result == IDOK)
		{
			UpdateData(true);
		color = RGB(dc.R, dc.G, dc.Y);


		}// TODO: 在此添加命令处理程序代码
	
}
