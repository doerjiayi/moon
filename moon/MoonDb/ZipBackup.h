#pragma once

//压缩和清理备份文件,现在用的是 7za.exe ,要把 7za.exe 放在 DBEngine.exe 同一目录下

#include "thread/Thread.h"

class CZipBackup :
	public lib::thread::CBaseThread
{
public:
	CZipBackup();
	~CZipBackup();
	typedef lib::thread::CBaseThread Inherited;
	VOID StartZipBackup();
	VOID SetBackupPath(LPCTSTR sBackupPath);
	VOID SetBackupArchiveDuration(int nBackupArchiveDuration);
protected:
	//覆盖线程例行执行函数
	VOID OnRountine();

private:
	TCHAR m_szBackupPath[MAX_PATH];
	int m_nBackupArchiveDuration; //设置备份存档存在时间(到时间删除存档)
#ifdef WINDOWS
	HANDLE m_hZipBackupEvent;
#else
	pthread_cond_t m_hZipBackupEvent;
	pthread_mutex_t m_tx;
#endif
	VOID CleanBackupFiles();
 VOID DoZipBackup();
 bool m_terminated;
};

