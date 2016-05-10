#ifndef SELECT_MODULE_H__
#define SELECT_MODULE_H__


#ifdef WINDOWS
 
class CSelectReactor:public CBaseReactor
{
public:
	CSelectReactor();
	virtual ~CSelectReactor();
protected:
	virtual void runRector();
	static DWORD WINAPI SelectThread(LPVOID lpThreadParameter);//接受数据线程
	static DWORD WINAPI runThread(LPVOID lpThreadParameter);//接受连接线程
private:
	CRITICAL_SECTION m_selectCriticalSection;
	int selectSocketNumber;
	SOCKET selectClientSockets[FD_SETSIZE];
};
#endif




#endif
