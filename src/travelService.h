#ifndef F6B5D65E_852A_4768_845D_BB9968DC2DCA
#define F6B5D65E_852A_4768_845D_BB9968DC2DCA
#include "main.h"

// Abstract base class for all travel-related services
// All specific services will inherit from this class
class TravelService {
public:
    // Get information about the service
    virtual string getInfo() const = 0;
    // Book the service for a group of people
    virtual bool book(int groupSize) = 0;
    virtual ~TravelService() {}
};

// Represents a day's itinerary, including the date and activities
class Itinerary {
public:
    string day;                 // Date of the itinerary
    vector<string> activities;  // List of activities for this day
};

// Represents a service included in a tour (e.g., breakfast, insurance)
class IncludedService {
public:
    string name;                // Service name
    string description;         // Service description

};

// Represents a specific time (hour, minute)
class Time {
public:
    int hour = 0;
    int min = 0;
};

// Represents a specific date (day, month, year)
class Date {
public:
    int day = 0;
    int month = 0;
    int year = 0;
};

#endif /* F6B5D65E_852A_4768_845D_BB9968DC2DCA */
