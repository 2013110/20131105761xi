
// compareDlg.h : 头文件
//

#pragma once


// CcompareDlg 对话框
class CcompareDlg : public CDialogEx
{
// 构造
public:
	CcompareDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_COMPARE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	IStream* m_stream;
	IPicture *m_picture;
	OLE_XSIZE_HIMETRIC m_width;
    OLE_YSIZE_HIMETRIC m_height;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClicked2();
};
