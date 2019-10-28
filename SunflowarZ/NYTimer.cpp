#include "pch.h"
#include "NYTimer.h"

#ifndef __NY_TIMER__
#define __NY_TIMER__



NYTimer::NYTimer()
{
	QueryPerformanceCounter(&lastUpdateTime);
	LARGE_INTEGER li_freq;
	QueryPerformanceFrequency(&li_freq);
	freq = li_freq.QuadPart;
	freq /= 1000;
}

void NYTimer::start()
{
	QueryPerformanceCounter(&lastUpdateTime);
}

float NYTimer::getElapsedSeconds(bool restart)
{
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	float elapsed = (float)((float)elapsedLong / (float)freq);
	elapsed /= 1000.0f;

	if (restart)
		lastUpdateTime = timeNow;

	return elapsed;
}

unsigned long NYTimer::getElapsedMs(bool restart)
{
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	unsigned long elapsed = (unsigned long)((float)elapsedLong / (float)freq);
	return elapsed;
}
#endif
