#ifndef F6B5D65E_852A_4768_845D_BB9968DC2DCA
#define F6B5D65E_852A_4768_845D_BB9968DC2DCA
#include "main.h"

struct Time {
    int h = 0;
    int min = 0;
};

struct Date {
    int d = 0;
    int m = 0;
    int y = 0;
};

class TravelService {
public:
    virtual string getInfo() const = 0;
    virtual bool book(int groupSize) = 0;
    virtual ~TravelService() {}
};

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

class DaLat : public TravelService {
private:
    string tourName;
    string tourCode;
    string departureDate;
    string transportation;
    string hotel;
    double tourPrice;
    vector<Itinerary> itinerary;
    vector<IncludedService> includedServices;
    string contact;

    int maxGroup;
    int booked;
public:
    DaLat();
    ~DaLat();
    DaLat(const DaLat& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class SapaHaGiang : public TravelService {
private:
    string tourName;
    string tourCode;
    string departurePoint;
    double tourPrice;
    vector<Itinerary> itinerary;
    vector<IncludedService> includedServices;
    string contact;

    int maxGroup;
    int booked;
public:
    SapaHaGiang();
    ~SapaHaGiang();
    SapaHaGiang(const SapaHaGiang& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class HaLongTuanChau : public TravelService {
private:
    string tourName;
    string tourCode;
    string departurePoint;
    string accommodation;
    double tourPrice;
    vector<Itinerary> itinerary;
    vector<IncludedService> includedServices;
    string contact;
    
    int maxGroup;
    int booked;
public:
    HaLongTuanChau();
    ~HaLongTuanChau();
    HaLongTuanChau(const HaLongTuanChau& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class DaNang : public TravelService {
private:
    string tourName;
    string tourCode;
    string departurePoint;
    string hotel;
    double tourPrice;
    vector<Itinerary> itinerary;
    vector<IncludedService> includedServices;
    string contact;

    int maxGroup;
    int booked;
public:
    DaNang();
    ~DaNang();
    DaNang(const DaNang& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class PhuQuoc : public TravelService {
private:
    string tourName;
    string tourCode;
    string departurePoint;
    string hotel;
    double tourPrice;
    vector<Itinerary> itinerary;
    vector<IncludedService> includedServices;
    string contact;

    int maxGroup;
    int booked;
public:
    PhuQuoc();
    ~PhuQuoc();
    PhuQuoc(const PhuQuoc& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

/*----------------------Bus--------------------*/
class BusTicketService : public TravelService {
private:
    string tripCode;
    string departure;
    string destination;
    Time departureTime;
    Date departureDate;
    int ticketPrice;
    int remainingTickets;
    string licensePlate;
    vector<tuple<string, Time, int>> stops;
    string baggagePolicy;
    string cancellationPolicy;
    string contactInfo;

public:
    BusTicketService();
    BusTicketService(const BusTicketService& other);
    ~BusTicketService();
    string getInfo() const override;
    bool book(int groupSize) override;  
};

/*----------------------Flight--------------------*/
class FlightTicketService : public TravelService {
private:
    string flightCode;
    string departure;
    string destination;
    Time departureTime;
    Date departureDate;
    int ticketPrice;
    int remainingTickets;
    string airplaneCode;
    vector<tuple<string, Time, int>> stops;
    string baggagePolicy;
    string cancellationPolicy;
    string contactInfo;

public:
    FlightTicketService();
    FlightTicketService(const FlightTicketService& other);
    ~FlightTicketService();
    string getInfo() const override;
    bool book(int groupSize) override;  
};

/*----------------------Train--------------------*/
class TrainTicketService : public TravelService {
private:
    string trainCode;
    string stationDeparture;
    string stationArrival;
    Time departureTime;
    Date departureDate;
    int ticketPrice;
    int remainingTickets;
    string trainID;
    vector<tuple<string, Time, int>> stops;
    string baggagePolicy;
    string cancellationPolicy;
    string contactInfo;

public:
    TrainTicketService();
    TrainTicketService(const TrainTicketService& other);
    ~TrainTicketService();
    string getInfo() const override;
    bool book(int groupSize) override;  
};


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
    CarRentalService();
    CarRentalService(const CarRentalService& other);
    virtual ~CarRentalService();
    virtual string getVehicleType() const = 0;  
    virtual string getInfo() const;
    virtual bool book(int rentalHours);
};

class BikeRental : public CarRentalService {
public:
    BikeRental();
    BikeRental(const BikeRental& other);
    string getVehicleType() const override { return "Bike"; }
    string getInfo() const override;
};

class MotorbikeRental : public CarRentalService {
public:
    MotorbikeRental();
    MotorbikeRental(const MotorbikeRental& other);
    string getVehicleType() const override { return "Motorbike"; }
    string getInfo() const override;
};

class CarRental : public CarRentalService {
public:
    CarRental();
    CarRental(const CarRental& other);
    string getVehicleType() const override { return "Car"; }
    string getInfo() const override;
};


#endif /* F6B5D65E_852A_4768_845D_BB9968DC2DCA */
