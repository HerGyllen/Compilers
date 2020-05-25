#pragma once


// error_wrong_token 对话框

class error_wrong_token : public CDialogEx
{
	DECLARE_DYNAMIC(error_wrong_token)

public:
	error_wrong_token(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~error_wrong_token();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
