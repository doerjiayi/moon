#ifndef BASE_REACTOR_H__
#define BASE_REACTOR_H__


//网络处理反应器

class CBaseReactor
{
public:
	CBaseReactor();
	virtual ~CBaseReactor(){};
	virtual void runRector() = 0;
	virtual void init(int port,const char *address = "0.0.0.0");
	int m_port;
#define  MAX_ADDRESS 32
	char m_address[MAX_ADDRESS];
};


#endif
