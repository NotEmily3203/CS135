#include <iostream>
#include "movie.h"

std::string getTimeSlot(TimeSlot ts){
    std::string result = ts.movie.title;
    std::string g;
    switch (ts.movie.genre) {
        case ACTION   : g = " ACTION"; break;
        case COMEDY   : g = " COMEDY"; break;
        case DRAMA    : g = " DRAMA";  break;
        case ROMANCE  : g = " ROMANCE"; break;
        case THRILLER : g = " THRILLER"; break;
    }
    result += g; // adds genre to string
    result += " (" + std::to_string(ts.movie.duration); // adds movie duration to string
    result += " min)";
    result += " [starts at " + std::to_string(ts.startTime.h); // adds start time to string
    result += ":" + std::to_string(ts.startTime.m);
    Time end_time = addMinutes(ts.startTime,ts.movie.duration);
    result += ", ends by " + std::to_string(end_time.h);
    result += ":" + std::to_string(end_time.m);
    result += "]";
    return result;
}