#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

TEST_CASE("minutes since midnight"){
    CHECK(minutesSinceMidnight({10, 30}) == 630);
}

TEST_CASE("minute until"){
    CHECK(minutesUntil({10, 30},{13, 40}) == 190);
}

TEST_CASE("add minutes"){
    Time sum_time = addMinutes({8, 10}, 75);
    CHECK(sum_time.h == 9);
    CHECK(sum_time.m == 25);
}

Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};
TimeSlot morning = {movie1, {9, 15}};

TEST_CASE("time slot"){
    CHECK(getTimeSlot(morning) == "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]");
}

TimeSlot after = scheduleAfter(morning, movie2);

TEST_CASE("schedule after movie"){
    CHECK(after.startTime.h == 11);
    CHECK(after.startTime.h == 11);
}

TEST_CASE("timeslot overlap"){
    CHECK(timeOverlap(morning, after)==false);
}