// ExecutionTimerTest.cpp
// original code by Code Blacksmith on Youtube
// https://www.youtube.com/watch?v=GV0JMHOpoEw

#include "stdafx.h"  // remove if not needed
#include "executiontimer.h"

int main()
{
	volatile double x = 2.0;
	{
		// test uSec output
		ExecutionTimer timer;
		for (int i = 1; i < 1000; i++)
			for (int j = 1; j < 10; j++)
			x *= j;
	}
	{
		// test mSec output
		ExecutionTimer timer;
		for (int i = 1; i < 200000; i++)
			for (int j = 1; j < 100; j++)
				x *= j;
	}
	{
		// test seconds output
		ExecutionTimer timer;
		for (int i = 1; i < 1000000; i++)
			for (int j = 1; j < 1000; j++)
				x *= j;
	}

    return 0;
}
