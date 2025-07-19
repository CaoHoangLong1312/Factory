#ifndef BE5B627C_638B_4759_83A6_82D00B8614AA
#define BE5B627C_638B_4759_83A6_82D00B8614AA

#include "travelService.h"

// Base class for all tour services
// Stores common information like name, code, price, schedule, included services, etc
class TourService : public TravelService {
protected:
    string tourName;                            // Name of the tour
    string tourCode;                            // Tour code
    double tourPrice;                           // Price of the tour
    int maxGroup;                               // Maximum group size
    int booked;                                 // Number of people already booked
    string contact;                             // Contact information
    vector<Itinerary> itinerary;                // Tour itinerary
    vector<IncludedService> includedServices;   // Services included in the tour

public:
    TourService() = default;
    TourService(const TourService& other)
        : tourName(other.tourName),
          tourCode(other.tourCode),
          tourPrice(other.tourPrice),
          maxGroup(other.maxGroup),
          booked(other.booked),
          contact(other.contact),
          itinerary(other.itinerary),
          includedServices(other.includedServices)
    {}
    virtual ~TourService() {}
};

// Represents the "Da Lat" tour, inherits from TourService
class DaLat : public TourService {
private:
    string departureDate;       // Date of departure
    string transportation;      // Means of transportation
    string hotel;               // Hotel information
public:
    DaLat();
    ~DaLat();
    DaLat(const DaLat& other);
    string getInfo() const override;    // Get Da Lat tour information
    bool book(int groupSize) override;  // Book Da Lat tour
};

// Represents the Sapa - Ha Giang tour
class SapaHaGiang : public TourService {
private:
    string departurePoint;      // Departure location
public:
    SapaHaGiang();
    ~SapaHaGiang();
    SapaHaGiang(const SapaHaGiang& other);
    string getInfo() const override;    // Get Sapa Ha Giang tour information
    bool book(int groupSize) override;  // Book Sapa Ha Giang tour
};

// Represents the Ha Long - Tuan Chau tour.
class HaLongTuanChau : public TourService {
private:
    string departurePoint;      // Departure location
    string accommodation;       // Accommodation details
public:
    HaLongTuanChau();
    ~HaLongTuanChau();
    HaLongTuanChau(const HaLongTuanChau& other);
    string getInfo() const override;    // Get Ha Long Tuan Chau tour information
    bool book(int groupSize) override;  // Book Ha Long Tuan Chau tour
};

// Represents the Da Nang tour.
class DaNang : public TourService {
private:
    string departurePoint;      // Departure location
    string hotel;               // Hotel information
public:
    DaNang();
    ~DaNang();
    DaNang(const DaNang& other);
    string getInfo() const override;    // Get Da Nang tour information
    bool book(int groupSize) override;  // Book Da Nang tour
};

// Represents the Phu Quoc tour.
class PhuQuoc : public TourService {
private:
    string departurePoint;      // Departure location
    string hotel;               // Hotel information
public:
    PhuQuoc();
    ~PhuQuoc();
    PhuQuoc(const PhuQuoc& other);
    string getInfo() const override;    // Get Phu Quoc tour information
    bool book(int groupSize) override;  // Book Phu Quoc tour
};

#endif /* BE5B627C_638B_4759_83A6_82D00B8614AA */
