//压缩和清理备份文件,现在用的是 7za.exe ,要把 7za.exe 放在 DBEngine.exe 同一目录下
#include "StdAfx.h"
#include <os/Platform.h>


using namespace moon::OS;


void MiniDtToStr(int nMiniDateTime, TCHAR* strDateTimeString)
{
	if (NULL == strDateTimeString)
		return;
	CMiniDateTime mdt((unsigned int)nMiniDateTime);
	SYSTEMTIME st;
	mdt.decode(st);
	TCHAR dtFmt[] = _T("%04d%02d%02d%02d%02d");
	sprintf(strDateTimeString, dtFmt, st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute);
}

#ifdef WINDOWS
unsigned __int64 FileTimeToInt64(FILETIME ft) 
{ 
	ULARGE_INTEGER uliTime;
	uliTime.LowPart = ft.dwLowDateTime;
	uliTime.HighPart = ft.dwHighDateTime;
	return uliTime.QuadPart;
}
#endif

#ifdef LINUX
long int FileTimeToInt64(time_t t)
{
	return t;
}
#endif

CZipBackup::CZipBackup():Inherited(TRUE)
{
#ifdef WINDOWS
	m_hZipBackupEvent = NULL;
	resume();
#endif
}

VOID CZipBackup::SetBackupPath(LPCTSTR sBackupPath)
{
	_tcscpy(m_szBackupPath, sBackupPath);
}

VOID CZipBackup::SetBackupArchiveDuration(int nBackupArchiveDuration)
{
	m_nBackupArchiveDuration = nBackupArchiveDuration * 3600 * 1000;//时->毫秒
}

VOID CZipBackup::OnRountine()
{
#ifdef WINDOWS
	m_hZipBackupEvent = ::CreateEvent(NULL, FALSE, FALSE, NULL);
#else
	pthread_cond_init(&m_hZipBackupEvent, NULL);
#endif
	while (!terminated())
	{
#ifdef WINDOWS
		::WaitForSingleObject(m_hZipBackupEvent, INFINITE);
#else
		pthread_mutex_lock( &m_tx );
		pthread_cond_wait( &m_hZipBackupEvent , &m_tx );
		pthread_mutex_unlock( &m_tx );
#endif
		if (terminated())
			break;
		DoZipBackup();
		CleanBackupFiles();
		osSleep(10);
	}
#ifdef WINDOWS
	::CloseHandle(m_hZipBackupEvent);
	m_hZipBackupEvent = NULL;
#else
	pthread_cond_destroy(&m_hZipBackupEvent);
#endif
}

VOID CZipBackup::StartZipBackup()
{
#ifdef WINDOWS
	if (m_hZipBackupEvent != NULL)
		::SetEvent(m_hZipBackupEvent);
#endif
}

CZipBackup::~CZipBackup()
{
	terminate();
#ifdef WINDOWS
	if (m_hZipBackupEvent != NULL)
		::SetEvent(m_hZipBackupEvent);
#else
	pthread_cond_signal(&m_hZipBackupEvent);
#endif
}
#ifdef WINDOWS
VOID CZipBackup::CleanBackupFiles()
{

	SYSTEMTIME st;
	//不要用 GetLocalTime(),因为下面文件的 FILETIME 用的是 UTC 时间,不是本地时间
	GetSystemTime(&st);
	FILETIME ft;
	::SystemTimeToFileTime(&st, &ft);

	TCHAR szFullPath[MAX_PATH];

	WIN32_FIND_DATA fd;
    ZeroMemory(&fd, sizeof(WIN32_FIND_DATA));

	TCHAR szFindFile[MAX_PATH];

	strcpy(szFindFile, m_szBackupPath);
	strcat(szFindFile, _T("/*.zip"));

	HANDLE hFind  = ::FindFirstFile(szFindFile, &fd);

	if (hFind == INVALID_HANDLE_VALUE)
		return;

	do
	{
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			continue;

		unsigned __int64 i1, i2;
		i1 = FileTimeToInt64(ft);
		i2 = FileTimeToInt64(fd.ftCreationTime);
		unsigned __int64 nTimeDiff = (i1 - i2) / 10000; //时间差(毫秒)
		//__int64 nTimeDiff = ((FileTimeToInt64(ft) - FileTimeToInt64(fd.ftLastWriteTime)) / 10000; //时间差(毫秒)
		//时间差值大于备份清除间隔
		if (nTimeDiff >= m_nBackupArchiveDuration)
		{
			strcpy(szFullPath, m_szBackupPath);
			strcat(szFullPath, _T("/"));
			strcat(szFullPath, fd.cFileName);

			::DeleteFile(szFullPath);
		}
	}
	while (::FindNextFile(hFind, &fd));

	if (hFind != INVALID_HANDLE_VALUE)
		FindClose(hFind);
}
#endif

#ifdef LINUX
VOID CZipBackup::CleanBackupFiles()
{
//#pragma message("Linux 待实现!")
}
#endif

VOID CZipBackup::DoZipBackup()
{
#ifdef WINDOWS
	//判断 7za.exe 是否存在
	DWORD dwAttr = ::GetFileAttributes(_T(".\\7za.exe"));
    if ((dwAttr == INVALID_FILE_ATTRIBUTES) || (FILE_ATTRIBUTE_DIRECTORY & dwAttr))
	{
		logError("7za.exe 不存在！");
		return;
	}

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );
#endif
	TCHAR strDateTime[20];
	MiniDtToStr(CMiniDateTime::now(),  strDateTime);
	TCHAR szBackupFDBPath[MAX_PATH];
	strcpy(szBackupFDBPath, m_szBackupPath);
	strcat(szBackupFDBPath, _T("/FDB/*"));

	//压缩命令，以当前日期做文件名
	TCHAR strCmdLn[MAX_PATH];
	//zip 格式 快速压缩
#ifdef WINDOWS
	_stprintf(strCmdLn, _T("./7za.exe a -tzip %s/%s %s -mx1"), m_szBackupPath, strDateTime, szBackupFDBPath);
	try
	{
		if (::CreateProcess( NULL,   // No module name (use command line). 
			strCmdLn, // Command line. 
			NULL,             // Process handle not inheritable. 
			NULL,             // Thread handle not inheritable. 
			FALSE,            // Set handle inheritance to FALSE. 
			0,                // No creation flags. 
			NULL,             // Use parent's environment block. 
			NULL,             // Use parent's starting directory. 
			&si,              // Pointer to STARTUPINFO structure.
			&pi ))             // Pointer to PROCESS_INFORMATION structure.
		{
			::WaitForSingleObject( pi.hProcess, INFINITE );
			// Close process and thread handles. 
			::CloseHandle( pi.hProcess );
			::CloseHandle( pi.hThread );
		}
		else
			logError("运行 7za.exe 失败！");
	}
	catch (...)
	{

	}
#else
	pid_t pid;
	pid = fork();
	if(!pid)
	{
		//子进程
		//要安装p7zip
		sprintf(strCmdLn, _T("./7z a -tzip %s/%s %s -mx1"), m_szBackupPath, strDateTime, szBackupFDBPath);
		system(strCmdLn);
	}
	else if (pid < 0)
		logError("fork fail ");
#endif
}



