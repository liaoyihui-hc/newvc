
// MFCApplication2View.h : CMFCApplication2View ��Ľӿ�
//

#pragma once

class CMFCApplication2Set;

class CMFCApplication2View : public CRecordView
{
protected: // �������л�����
	CMFCApplication2View();
	DECLARE_DYNCREATE(CMFCApplication2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION2_FORM };
#endif
	CMFCApplication2Set* m_pSet;

// ����
public:
	CMFCApplication2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCApplication2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString s1;
	CString s2;
	CString s3;
	CString s4;
	CString s5;
};

#ifndef _DEBUG  // MFCApplication2View.cpp �еĵ��԰汾
inline CMFCApplication2Doc* CMFCApplication2View::GetDocument() const
   { return reinterpret_cast<CMFCApplication2Doc*>(m_pDocument); }
#endif

