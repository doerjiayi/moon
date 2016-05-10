#ifndef EPOLL_REACTOR_H__
#define EPOLL_REACTOR_H__

#if 0

class CEpollReactor: public CBaseReactor
{
public:
	CEpollReactor():m_pos(0){};
	virtual ~CEpollReactor(){};

	virtual void runRector(int port,int address);

#define MAX_BUFFER 4086
	BYTE m_buf[MAX_BUFFER];
	unsigned int m_pos; 
};


#endif
#endif
