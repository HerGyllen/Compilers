#pragma once


// error_no_token 对话框

class error_no_token : public CDialogEx
{
	DECLARE_DYNAMIC(error_no_token)

public:
	error_no_token(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~error_no_token();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
