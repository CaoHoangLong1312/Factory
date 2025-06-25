#ifndef F6B5D65E_852A_4768_845D_BB9968DC2DCA
#define F6B5D65E_852A_4768_845D_BB9968DC2DCA
#include "main.h"

class TravelService {
public:
    virtual string getInfo() const = 0;
    virtual bool book(int groupSize) = 0;
    virtual ~TravelService() {}
};

// Tour service

class Itinerary {
public:
    string day;
    vector<string> activities;
};

class IncludedService {
public:
    string name;
    string description;
};

class TourService : public TravelService {
protected:
    string tourName;
    string tourCode;
    double tourPrice;
    int maxGroup;
    int booked;
    string contact;
    vector<Itinerary> itinerary;
    vector<IncludedService> includedServices;

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

class DaLat : public TourService {
private:
    string departureDate;
    string transportation;
    string hotel;
public:
    DaLat();
    ~DaLat();
    DaLat(const DaLat& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class SapaHaGiang : public TourService {
private:
    string departurePoint;
public:
    SapaHaGiang();
    ~SapaHaGiang();
    SapaHaGiang(const SapaHaGiang& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class HaLongTuanChau : public TourService {
private:
    string departurePoint;
    string accommodation;
public:
    HaLongTuanChau();
    ~HaLongTuanChau();
    HaLongTuanChau(const HaLongTuanChau& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class DaNang : public TourService {
private:
    string departurePoint;
    string hotel;
public:
    DaNang();
    ~DaNang();
    DaNang(const DaNang& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class PhuQuoc : public TourService {
private:
    string departurePoint;
    string hotel;
public:
    PhuQuoc();
    ~PhuQuoc();
    PhuQuoc(const PhuQuoc& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

// Ticket Service
class Time {
public:
    int hour = 0;
    int min = 0;
};

class Date {
public:
    int day = 0;
    int month = 0;
    int year = 0;
};

class TicketService : public TravelService {
protected:
    string code;
    string departure;
    string destination;
    Time departureTime;
    Date departureDate;
    int ticketPrice;
    int remainingTickets;
    vector<tuple<string, Time, int>> stops;
    string baggagePolicy;
    string cancellationPolicy;
    string contactInfo;
public:
    TicketService() = default;
    TicketService(const TicketService& other)
        : code(other.code),
          departure(other.departure),
          destination(other.destination),
          departureTime(other.departureTime),
          departureDate(other.departureDate),
          ticketPrice(other.ticketPrice),
          remainingTickets(other.remainingTickets),
          stops(other.stops),
          baggagePolicy(other.baggagePolicy),
          cancellationPolicy(other.cancellationPolicy),
          contactInfo(other.contactInfo)
    {}
    virtual ~TicketService() {}
};

class BusTicketService : public TicketService {
private:
    string licensePlate;

public:
    BusTicketService();
    BusTicketService(const BusTicketService& other);
    ~BusTicketService();
    string getInfo() const override;
    bool book(int groupSize) override;  
};

class FlightTicketService : public TicketService {
private:
    string airplaneCode;

public:
    FlightTicketService();
    FlightTicketService(const FlightTicketService& other);
    ~FlightTicketService();
    string getInfo() const override;
    bool book(int groupSize) override;  
};

class TrainTicketService : public TicketService {
private:
    string trainID;

public:
    TrainTicketService();
    TrainTicketService(const TrainTicketService& other);
    ~TrainTicketService();
    string getInfo() const override;
    bool book(int groupSize) override;  
};

// Car rental service
class CarRentalService : public TravelService {
protected:
    string rentalID;
    string licensePlate;
    Date rentalDate;
    Time startTime;
    Time endTime;
    string rentalCity;
    double hourlyRate;
    double totalCost;
    string contactInfo;

public:
    CarRentalService() = default;
    CarRentalService(const CarRentalService& other)
        : rentalID(other.rentalID),
          licensePlate(other.licensePlate),
          rentalDate(other.rentalDate),
          startTime(other.startTime),
          endTime(other.endTime),
          rentalCity(other.rentalCity),
          hourlyRate(other.hourlyRate),
          totalCost(other.totalCost),
          contactInfo(other.contactInfo)
    {}
    virtual ~CarRentalService() {}
    string getInfo() const override;
    bool book(int rentalHours) override;
    virtual string getVehicleType() const = 0; 
};

class BikeRental : public CarRentalService {
public:
    BikeRental();
    BikeRental(const BikeRental& other);
    string getInfo() const override;
    string getVehicleType() const override { return "Bike"; }
};

class MotorbikeRental : public CarRentalService {
public:
    MotorbikeRental();
    MotorbikeRental(const MotorbikeRental& other);
    string getInfo() const override;
    string getVehicleType() const override { return "Motorbike"; }
};

class CarRental : public CarRentalService {
public:
    CarRental();
    CarRental(const CarRental& other);
    string getInfo() const override;
    string getVehicleType() const override { return "Car"; }
};

#endif /* F6B5D65E_852A_4768_845D_BB9968DC2DCA */
