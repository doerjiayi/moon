/*
 * RunDataSendThread.h
 *
 *  Created on: 2013-1-24
 *      Author: root
 */
#pragma once

using namespace common::time;
using namespace lib::container;

class CGateSendPacket;
class CGateSendPacketPool;
class ExecSockDataMgr;

//数据发送线程
typedef struct structExecDataSendThread
{
#ifdef WINDOWS
	HANDLE				hThread;
#else
	pthread_t 			hThread;
#endif
	int					nThreadIdx;
	DWORD				dwThreadId;
	TICKCOUNT			dwProcTick;
	TICKCOUNT			dwSleepTick;
	bool				boSendEWouldBlock;
	bool				boSendFewBuffer;
	BYTE				btRcvs[2];
	ExecSockDataMgr	*pRunData;
	CRITICAL_SECTION	SendQueueLock;
	CBList<CGateSendPacket*>	*pSendAppendList;
	CBList<CGateSendPacket*>	*pSendProcList;
	CGateSendPacketPool *pSendPacketPool;
}EXECDATASENDTHREAD, *PEXECDATASENDTHREAD;
