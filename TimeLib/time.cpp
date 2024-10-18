#include <iostream>
#include <vector>
#include "time.hpp"

Time::Time(bool flag):flag(flag){
    if (flag){
        count += 1;
        std::cout << "I create new time! current count = " << count << "\n";
    }
}
Time::Time(int h, int m, int s, bool flag): hours(h), minutes(m), seconds(s), flag(flag) {
    if (flag){
        count += 1;
        std::cout << "I create new time! current count = " << count << "\n";
    }
}
Time::~Time(){
    if (this->flag){
        count -= 1;
        std::cout << "I delete time! current count = " << count << "\n";
    }
}
Time::Time(const Time& t): Time(t.hours, t.minutes, t.seconds, true) {}


void Time::PrintTime(){
    std::cout << hours << ":" \
    << minutes << ":" << seconds << std::endl;
}

void Time::SetHours(int hours){this->hours = hours; };
void Time::SetMinutes(int minutes){this->minutes = minutes; };
void Time::SetSeconds(int seconds){this->seconds = seconds; };

int Time::GetHours() const { return hours; }
int Time::GetMinutes() const { return minutes; }
int Time::GetSeconds() const { return seconds; }

int Time::ToSeconds(){ return (24 * 3600 + this->GetHours() * 3600 + this->GetMinutes() * 60 + this->GetSeconds()) % (24 * 3600); }
Time Time::Normalize () { 
    int seconds = this->ToSeconds();
    return Time(this->hours = seconds / 3600, this->minutes = (seconds % 3600) / 60, this->seconds = seconds%60); 
}

Time& Time::operator= (const Time& other){
    this->hours = other.hours; 
    this->minutes = other.minutes; // для примера
    this->seconds = other.seconds;
    this->flag = true;
    return *this;
}
Time& Time::operator += (int s) {
    seconds += s;
    this->Normalize();
    return *this;
}
Time& Time::operator -= (int s) {
    seconds += -s;
    this->Normalize();
    return *this;
}
int Time::operator == (const Time other){
    if (this->seconds == other.seconds && this->minutes == other.minutes && this->hours == other.hours)
        return 1;
    return 0;
}

Time operator+ (const Time& t, int s) {
   return Time(t.GetHours(), t.GetMinutes(), t.GetSeconds() + s).Normalize();
}
Time operator- (const Time& t, int s) {
   return Time(t.GetHours(), t.GetMinutes(), t.GetSeconds() - s).Normalize();
}

unsigned Time::count = 0 ;
