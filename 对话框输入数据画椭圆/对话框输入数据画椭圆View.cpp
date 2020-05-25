
// 对话框输入数据画椭圆View.cpp : C对话框输入数据画椭圆View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "对话框输入数据画椭圆.h"
#endif

#include "对话框输入数据画椭圆Doc.h"
#include "对话框输入数据画椭圆View.h"
#include "diag.h"+
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C对话框输入数据画椭圆View

IMPLEMENT_DYNCREATE(C对话框输入数据画椭圆View, CView)

BEGIN_MESSAGE_MAP(C对话框输入数据画椭圆View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &C对话框输入数据画椭圆View::中点画椭圆)
END_MESSAGE_MAP()

// C对话框输入数据画椭圆View 构造/析构

C对话框输入数据画椭圆View::C对话框输入数据画椭圆View()
{
	// TODO: 在此处添加构造代码

}

C对话框输入数据画椭圆View::~C对话框输入数据画椭圆View()
{
}

BOOL C对话框输入数据画椭圆View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C对话框输入数据画椭圆View 绘制

void C对话框输入数据画椭圆View::OnDraw(CDC* /*pDC*/)
{
	C对话框输入数据画椭圆Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C对话框输入数据画椭圆View 打印

BOOL C对话框输入数据画椭圆View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C对话框输入数据画椭圆View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C对话框输入数据画椭圆View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C对话框输入数据画椭圆View 诊断

#ifdef _DEBUG
void C对话框输入数据画椭圆View::AssertValid() const
{
	CView::AssertValid();
}

void C对话框输入数据画椭圆View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C对话框输入数据画椭圆Doc* C对话框输入数据画椭圆View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C对话框输入数据画椭圆Doc)));
	return (C对话框输入数据画椭圆Doc*)m_pDocument;
}
#endif //_DEBUG


// C对话框输入数据画椭圆View 消息处理程序


void C对话框输入数据画椭圆View::中点画椭圆()
{
	diag dc;
	int result = dc.DoModal();
	if (result == IDOK)
	{
		UpdateData(TRUE);
		绘制椭圆(dc.x, dc.y, dc.a, dc.b);
	}// TODO: 在此添加命令处理程序代码
}
void C对话框输入数据画椭圆View::绘制椭圆(int xc, int yc, int a, int b)
{
	CDC*pDC=GetDC();
	int x, y, c = 0;
	double d1, d2;
	x = 0;
	y = b;
	d1 = b*b + a*a*(-b + 0.25);
	pDC->SetPixel(x + 300, y + 200, c);
	pDC->SetPixel(-x + 300, y + 200, c);
	pDC->SetPixel(x + 300, -y + 200, c);
	pDC->SetPixel(-x + 300, -y + 200, c);
	while (b*b*(x + 1) < a*a*(y - 0.5))
	{
		if (d1 < 0) {
			d1 += b*b*(2 * x + 3);
			x++;

		}
		else
		{

			d1 += b*b*(2 * x + 3) + a*a*(-2 * y + 2);
			x++;
			y--;

		}
		pDC->SetPixel(x + xc, y + yc, c);
		pDC->SetPixel(-x + xc, y + yc, c);
		pDC->SetPixel(x + xc, -y + yc, c);
		pDC->SetPixel(-x + xc, -y + yc, c);

	}
	d2 = sqrt(b*(x + 0.5)) + a*(y - 1) - a*b;
	while (y > 0)
	{

		if (d2 < 0)
		{
			d2 += b*b*(2 * x + 2) + a*a*(-2 * y + 3);
			x++;
			y--;
		}
		else {
			d2 += a*a*(-2 * y + 3);
			y--;
		}
		pDC->SetPixel(x + xc, y + yc, c);
		pDC->SetPixel(-x + xc, y + yc, c);
		pDC->SetPixel(x + xc, -y + yc, c);
		pDC->SetPixel(-x + xc, -y + yc, c);
	}


}