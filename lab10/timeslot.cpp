#include <iostream>
#include "timeslot.h"
#include "time.h"

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot next_slot;
    next_slot.movie = nextMovie;
    next_slot.startTime = addMinutes(ts.startTime, ts.movie.duration);
    return next_slot;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    bool overlap = false;
    Time movie1Ends;
    //if start time of ts2 is greater than the end time of ts1
    movie1Ends = addMinutes(ts1.startTime,ts1.movie.duration);
    if(ts2.startTime.h>movie1Ends.h || ts2.startTime.m>movie1Ends.m){
        //then there is an overlap
        overlap = true;
    }
    return overlap;
}