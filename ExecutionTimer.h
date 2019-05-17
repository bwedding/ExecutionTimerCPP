// ExecutionTimer.h
// original code by Code Blacksmith on Youtube
// https://www.youtube.com/watch?v=GV0JMHOpoEw
#pragma once

#include "stdafx.h"  // remove if not needed
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;

class ExecutionTimer
{
public:
	// Use the best steady clock available
	using Clock = std::conditional_t<high_resolution_clock::is_steady,
		high_resolution_clock,
		steady_clock>;

	ExecutionTimer() = default;
	inline ~ExecutionTimer()
	{
		std::string units = " microSeconds";
		// Determine whether to print uSecs or mSecs or Secs
		double count = duration_cast<microseconds>(Clock::now() - mStart).count();
		if (count > 1000)
		{
			// Convert to milliseconds
			units = " milliSeconds";
			count /= 1000.0f;
			if (count > 1000)
			{
				// Convert to seconds
				units = " Seconds";
				count /= 1000.0f;
			}
		}

		std::cout
			<< "Elapsed: " << count << units.data() << std::endl;
	}
private:
	Clock::time_point mStart = Clock::now();
};

