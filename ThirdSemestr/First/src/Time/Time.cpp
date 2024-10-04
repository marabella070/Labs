#include "Time.h"

#include <cstring>
#include <iomanip>
#include <iostream>

/* ----------------------- Class Time Implementation ----------------------- */
// Constructors
Time::Time() : hours(0), minutes(0), seconds(0), reminder(nullptr) {
    reminder = new char[1];
    reminder[0] = '\0';
}

Time::Time(int h, int m, int s)
    : hours(h), minutes(m), seconds(s), reminder(nullptr) {
    reminder = new char[1];
    reminder[0] = '\0';
}

Time::Time(int h, int m, int s, const char* rem)
    : hours(h), minutes(m), seconds(s), reminder(nullptr) {
    reminder = new char[strlen(rem) + 1];
    strcpy(reminder, rem);
}

Time::Time(const Time& other)
    : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {
    reminder = new char[strlen(other.reminder) + 1];
    strcpy(reminder, other.reminder);
}

Time::~Time() { delete[] reminder; }

// Setters
Time& Time::setHours(int h) {
    hours = h;
    return *this;
}
Time& Time::setMinutes(int m) {
    minutes = m;
    return *this;
}
Time& Time::setSeconds(int s) {
    seconds = s;
    return *this;
}

void Time::setReminder(const char* rem) {
    delete[] reminder;
    reminder = new char[strlen(rem) + 1];
    strcpy(reminder, rem);
}

void Time::setTime(int h, int m, int s) {
    this->setHours(h).setMinutes(m).setSeconds(s);
}

// Getters
int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }
const char* Time::getReminder() const { return reminder; }

Time& Time::operator+=(const Time& other) {
    int total_seconds = (hours + other.hours) * 3600 +
                        (minutes + other.minutes) * 60 +
                        (seconds + other.seconds);
    hours = total_seconds / 3600;
    minutes = (total_seconds % 3600) / 60;
    seconds = total_seconds % 60;
    return *this;
}

Time Time::operator+(const Time& other) const {
    Time result = *this;
    return result += other;
}

void Time::display() const {
    std::cout << "Time: " << std::setfill('0') << std::setw(2) << hours << ":"
              << std::setfill('0') << std::setw(2) << minutes << ":"
              << std::setfill('0') << std::setw(2) << seconds << "\n";
    std::cout << "Reminder: " << (strlen(reminder) ? reminder : "None") << "\n";
}

// Defining custom literals for seconds, minutes, and hours
Time operator"" _sec(unsigned long long s) {
    return Time(0, 0, static_cast<int>(s));
}

Time operator"" _min(unsigned long long m) {
    return Time(0, static_cast<int>(m), 0);
}

Time operator"" _hour(unsigned long long h) {
    return Time(static_cast<int>(h), 0, 0);
}