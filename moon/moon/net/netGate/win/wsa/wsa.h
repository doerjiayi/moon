#ifndef WSA_H__
#define WSA_H__

#if defined(WINDOWS)

class WsaData
{
public:
	WsaData();
	~WsaData();

	bool initWsaData();
	void dastroyWsaData();
};


extern bool InitWinNet();

#endif

#endif//WSA_H__
