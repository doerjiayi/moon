#ifndef IOCP_H__
#define IOCP_H__
#if defined (WINDOWS)

typedef struct _PER_HANDLE_DATA		// per-handle数据
{
	SOCKET socket;			// 对应的套节字句柄
	sockaddr_in addr;	// 客户方地址
} PER_HANDLE_DATA, *PPER_HANDLE_DATA;


typedef struct _PER_IO_DATA			// per-I/O数据
{
	OVERLAPPED ol;			// 重叠结构
	WSABUF	   wbuf;	// 数据缓冲区
	int nOperationType;		// 操作类型
#define OP_READ   1
#define OP_WRITE  2
#define OP_ACCEPT 3
#define BUFFER_SIZE 1024
} PER_IO_DATA, *PPER_IO_DATA;



class CIocp
{
public:
	CIocp(void);
	CIocp(const char* address,int port);
	~CIocp(void);

	void runRector( int port,int address );
public:
	//iocp reactor 接口
	bool iocpConnect(void);
	int iocpSend(const char *buf,int len);
	bool iocpListen(void);
protected:
	bool init(const char* address,int port);
	static DWORD CALLBACK WorkThread(LPVOID Param);
	static DWORD CALLBACK AcceptThread(LPVOID Param);

private:
	HANDLE	m_wThread;		//工作线程句柄
	DWORD	m_wthreadID;
	HANDLE  m_aThread;		//连接线程句柄
	DWORD	m_athreadID;
public:
#define  START_CIOCP (1)
#define  END_CIOCP (0)
#define  ADDRESS_LEN (32)
	unsigned char m_started;
	HANDLE	m_hIocp;		//完成端口句柄
	SOCKET	m_sSocket;
	unsigned int m_coreNumber;
	unsigned short m_port;
	char	 m_address[ADDRESS_LEN];
};


#endif


#endif
