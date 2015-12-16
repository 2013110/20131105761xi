
// compareDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "compare.h"
#include "compareDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcompareDlg �Ի���




CcompareDlg::CcompareDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcompareDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcompareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcompareDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CcompareDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcompareDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_2, &CcompareDlg::OnBnClicked2)
END_MESSAGE_MAP()


// CcompareDlg ��Ϣ�������

BOOL CcompareDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcompareDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcompareDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcompareDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcompareDlg::OnBnClickedButton1()
{
	IStream* m_stream;
	
	CString m_filename("e:\\1.jpg");
	CFileDialog Dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,L"JPG Files(*.JPG)|*.JPG|ALL Files(*.*)|*.*");
	if(Dlg.DoModal()==IDOK)
	{
		m_filename = Dlg.GetPathName();
	}
	else
	{
		MessageBox(L"��ʧ��",NULL,MB_OK);
	}
	CFile m_file(m_filename,CFile::modeRead);
	DWORD m_filelen=m_file.GetLength();
	HGLOBAL m_hglobal=GlobalAlloc(GMEM_MOVEABLE,m_filelen);
	LPVOID pvdata=NULL;
	pvdata=GlobalLock(m_hglobal);
	m_file.Read(pvdata,m_filelen);
	GlobalUnlock(m_hglobal);
	CreateStreamOnHGlobal(m_hglobal,TRUE,&m_stream);
	OleLoadPicture(m_stream,m_filelen,TRUE,IID_IPicture,(LPVOID*)&m_picture);
	m_picture->get_Width(&m_width);
	m_picture->get_Height(&m_height);
	CDC* dc=GetDC();
	
    CRect rect;
    GetClientRect(rect);
    SetScrollRange(SB_VERT,0,(int)(m_height/70)-rect.Height());
    SetScrollRange(SB_HORZ,0,(int)(m_width/100)-rect.Width());

    m_picture->Render(*dc,20,1,(int)(m_width/100),(int)(m_height/70),0,m_height,m_width,-m_height,NULL);

	ReleaseDC(dc);


}


void CcompareDlg::OnBnClickedButton2()
{
	CDC* dc=GetDC();
	
    CRect rect;
    GetClientRect(rect);
    SetScrollRange(SB_VERT,0,(int)(m_height/70)-rect.Height());
    SetScrollRange(SB_HORZ,0,(int)(m_width/100)-rect.Width());

    m_picture->Render(*dc,200,1,(int)(m_width/100),(int)(m_height/70),0,m_height,m_width,-m_height,NULL);

	ReleaseDC(dc);
}

void CcompareDlg::OnBnClicked2()
{
	CDC* pDC=GetDC();
	CRect rcC1(200,0,400,200); 
    pDC->FillSolidRect(rcC1,RGB(0,0,255)); 
    pDC->SetMapMode(MM_ANISOTROPIC ); 
    CSize sizeO; 
    sizeO=pDC->SetWindowExt(5,5); 
    TRACE("winExt %d %d\n",sizeO.cx,sizeO.cy); 
    sizeO=pDC->SetViewportExt(5,10); 
    TRACE("ViewExt %d %d\n",sizeO.cx,sizeO.cy); 
    CRect rcC(100,0,100,200); 
    pDC->FillSolidRect(rcC,RGB(0,128,0)); 

// TODO: �ڴ���ӿؼ�֪ͨ����������
}
