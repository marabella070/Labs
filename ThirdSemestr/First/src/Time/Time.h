#pragma once

class Time {
public:
    // Constructors
    Time();
    Time(int h, int m, int s);
    Time(int h, int m, int s, const char* rem);
    Time(const Time& other);
    ~Time();

    // Setters
    Time& setHours(int h);
    Time& setMinutes(int m);
    Time& setSeconds(int s);
    void setReminder(const char* rem);
    void setTime(int h, int m, int s);

    // Getters
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    const char* getReminder() const;

    Time& operator+=(const Time& other);
    Time operator+(const Time& other) const;

    void display() const;

private:
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    char* reminder;
};

// Defining custom literals for seconds, minutes, and hours
Time operator"" _sec(unsigned long long s);
Time operator"" _min(unsigned long long m);
Time operator"" _hour(unsigned long long h);