#include <iostream>
#include <vector>
#include "time.hpp"

Time::Time(bool flag):hours(0), minutes(0), seconds(0), flag(flag){
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
    if (this->hours > 23 || this->hours < 0 || this->minutes > 59 || this->minutes < 0 || this->seconds > 59 || this->seconds < 0 )
        this->Normalize();
}
Time::~Time(){
    if (this->flag){
        count -= 1;
        std::cout << "I delete time! current count = " << count << " " << *this << "\n";
    }
}
Time::Time(const Time& t): Time(t.hours, t.minutes, t.seconds, true) {}

void Time::PrintTime(){
    std::cout << hours << ":" \
    << minutes << ":" << seconds << std::endl;
}

void Time::SetHours(int hours){this->hours = hours; this->Normalize();};
void Time::SetMinutes(int minutes){this->minutes = minutes; this->Normalize(); };
void Time::SetSeconds(int seconds){this->seconds = seconds; this->Normalize(); };

int Time::GetHours() const { return hours; }
int Time::GetMinutes() const { return minutes; }
int Time::GetSeconds() const { return seconds; }

int Time::ToSeconds() const{ return (24 * 3600 + this->GetHours() * 3600 + this->GetMinutes() * 60 + this->GetSeconds()) % (24 * 3600); }
Time Time::Normalize () { 
    if (this->hours > 23 || this->hours < 0 ||\
        this->minutes > 59 || this->minutes < 0 || \
        this->seconds > 59 || this->seconds < 0 ){    
    int seconds = this->ToSeconds();
    return Time(this->hours = seconds / 3600, this->minutes = (seconds % 3600) / 60, this->seconds = seconds%60, false); 
    }
    return Time(this->hours, this->minutes, this->seconds,false);
}

Time& Time::operator= (const Time& other){
    this->hours = other.hours; 
    this->minutes = other.minutes; // для примера
    this->seconds = other.seconds;
    this->flag = other.flag;
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
Time& Time::operator += (const Time& a){
    *this += a.ToSeconds();
    return *this;
}
Time& Time::operator -= (const Time& a){
    *this -= a.ToSeconds();
    return *this;

}
bool Time::operator == (const Time& other){
    if (this->seconds == other.seconds && this->minutes == other.minutes && this->hours == other.hours)
        return true;
    return false;
}

Time operator+ (const Time& t, int s) {
   return Time(t.GetHours(), t.GetMinutes(), t.GetSeconds() + s, false).Normalize();
}
Time operator- (const Time& t, int s) {
   return Time(t.GetHours(), t.GetMinutes(), t.GetSeconds() - s, false).Normalize();
}

std::ostream& operator<<(std::ostream& os, const Time& time){
    os  << time.GetHours() << ":"\
        << time.GetMinutes() << ":"\
        << time.GetSeconds();
    return os;
}
std::string TimeNameSpace::to_string(const Time& a) {
    return std::to_string(a.GetHours()) + ":" + std::to_string(a.GetMinutes()) + ":" + std::to_string(a.GetSeconds());
}

unsigned Time::count = 0 ;
