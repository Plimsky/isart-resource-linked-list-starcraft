#ifdef __linux__
#include <unistd.h>
#endif
#ifdef _WIN32
#include <windows.h>
#endif

#include <utils/sleep.h>

void my_sleep(int sleepMs)
{
#ifdef __linux__
	usleep(sleepMs * 1000);   // usleep takes sleep time in us (1 millionth of a second)
#endif
#ifdef _WIN32
	Sleep((DWORD) sleepMs);
#endif
}
