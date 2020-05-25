#pragma once


// error_no_path 对话框

class error_no_path : public CDialogEx
{
	DECLARE_DYNAMIC(error_no_path)

public:
	error_no_path(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~error_no_path();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
