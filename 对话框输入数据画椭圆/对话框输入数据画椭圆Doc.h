
// �Ի����������ݻ���ԲDoc.h : C�Ի����������ݻ���ԲDoc ��Ľӿ�
//


#pragma once


class C�Ի����������ݻ���ԲDoc : public CDocument
{
protected: // �������л�����
	C�Ի����������ݻ���ԲDoc();
	DECLARE_DYNCREATE(C�Ի����������ݻ���ԲDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~C�Ի����������ݻ���ԲDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
