#include <iostream>
#include "time.h"
int minutesSinceMidnight(Time time){ // converts time to minutes
    int result = time.h * 60 + time.m;
    return result;
}
int minutesUntil(Time earlier, Time later){
    int result = ((later.h - earlier.h) * 60) + (later.m - earlier.m);
    return result;
}
Time addMinutes(Time time0, int min){
    int minutes = minutesSinceMidnight(time0); // converts time to minutes
    minutes += min;
    int hours = 0;
    while(minutes >= 60){ // converts minutes back to h:m time format
        minutes -= 60;
        hours ++;
    }
    Time result;
    result.h = hours;
    result.m = minutes;
    return result;
}