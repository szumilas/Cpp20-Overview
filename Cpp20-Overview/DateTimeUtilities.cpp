#include <chrono>
#include <iostream>

namespace DateTimeUtilities
{
	void foo()
	{
        // Get a local time_point with system_clock::duration precision
        auto now = std::chrono::zoned_time{ std::chrono::current_zone(), std::chrono::system_clock::now() }.get_local_time();

        // Get a local time_point with days precision
        auto ld = std::chrono::floor<std::chrono::days>(now);

        // Convert local days-precision time_point to a local {y, m, d} calendar
        std::chrono::year_month_day ymd{ ld };

        // Split time since local midnight into {h, m, s, subseconds}
        std::chrono::hh_mm_ss hms{ now - ld };

        // This part not recommended.  Stay within the chrono type system.
        std::cout << "Year: " << ymd.year() << " ";
        std::cout << "Month: " << static_cast<unsigned int>(ymd.month()) << " ";
        std::cout << "Day: " << static_cast<unsigned int>(ymd.day()) << " ";
        std::cout << "Hour: " << hms.hours().count() << " ";
        std::cout << "Minutes: " << hms.minutes().count() << " ";
        std::cout << "Seconds: " << hms.seconds().count() << " ";
	}
}

// Output:
// Year: 2022 Month: 7 Day: 24 Hour: 11 Minutes: 47 Seconds: 29