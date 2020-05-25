#pragma once


// error_repeat 对话框

class error_repeat : public CDialogEx
{
	DECLARE_DYNAMIC(error_repeat)

public:
	error_repeat(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~error_repeat();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
