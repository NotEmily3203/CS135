#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

int main(){
    std::cout<<"minutesSinceMidnight({10, 30}) : "<<minutesSinceMidnight({10, 30})<<std::endl;
    std::cout<<"minutesUntil({10, 30},{13, 40}) : "<<minutesUntil({10, 30},{13, 40})<<std::endl;
    Time sum_time = addMinutes({8, 10}, 75);
    std::cout<<"addMinutes({8, 10}, 75) : "<<sum_time.h<<sum_time.m<<std::endl;
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot afternoon = {movie2, {14, 30}}; 
    TimeSlot evening = {movie2, {16, 45}};
    TimeSlot night = {movie1, {19, 15}};  
    std::cout<<getTimeSlot(morning)<<std::endl;
    /*std::cout<<getTimeSlot(daytime)<<std::endl;
    std::cout<<getTimeSlot(afternoon)<<std::endl;
    std::cout<<getTimeSlot(evening)<<std::endl;
    std::cout<<getTimeSlot(night)<<std::endl;*/
    TimeSlot after;
    after = scheduleAfter(morning, movie2);
    std::cout<<"Scheduled after : "<<getTimeSlot(after)<<std::endl;
    std::cout<<timeOverlap(morning, after)<<std::endl;
    return 0;
}