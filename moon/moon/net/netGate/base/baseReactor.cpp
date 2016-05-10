#include "StdAfx.h"

CBaseReactor::CBaseReactor()
{
	m_port = 0;
	memset(m_address,0,MAX_ADDRESS);
}


void CBaseReactor::init( int port,const char *address)
{
	m_port = port;
	strncpy(m_address,address,MAX_ADDRESS -1);
}

