#include <iostream>

#include "Time/Time.h"

int main() {
    // Creating Time objects using different constructors
    Time t1;  // 00:00:00 by default
    Time t2(2, 30, 45);
    Time t3(1, 45, 30, "Meeting reminder");

    std::cout << "Initial Times:\n";
    t1.display();
    t2.display();
    t3.display();

    // Using custom literals
    Time t4 = 15_sec;
    Time t5 = 2_min + 15_sec;
    Time t6 = 1_hour + 30_min + 45_sec;

    std::cout << "\nTimes created with literals:\n";
    t4.display();
    t5.display();
    t6.display();

    // Demonstration of the operator += and +
    std::cout << "\nAdding times with += operator:\n";
    t2 += t4;
    t2.display();

    std::cout << "\nAdding times with + operator:\n";
    Time t7 = t5 + t6;
    t7.display();

    // Changing the reminder
    t3.setReminder("Updated meeting reminder");
    std::cout << "\nTime with updated reminder:\n";
    t3.display();

    return 0;
}