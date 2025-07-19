#ifndef A6C762EE_8BD5_434F_95A2_B0FA1BBEE309
#define A6C762EE_8BD5_434F_95A2_B0FA1BBEE309

#include "travelService.h"
#include "TourService.h"
#include "TicketService.h"
#include "CarRentalService.h"

// TravelServiceFactory is the abstract "Factory" in Factory Method Pattern
// It defines the interface to create a travel service,
// but does NOT specify what type of service
class TravelServiceFactory {
public:
    // Creates and returns a pointer to a new TravelService object
    virtual TravelService* createService() const = 0;
    
    // Virtual destructor for proper cleanup in inheritance
    virtual ~TravelServiceFactory() {}
};

// TourFactory is a "Concrete Factory"
// It is used to create different types of tour services (for example: DaLat, SapaHaGiang, ...)
class TourFactory : public TravelServiceFactory {
private: 
    string tourType;    // The specific type of tour (e.g. "DaLat", "SapaHaGiang", ...)
public:
    TourFactory(const string& tourType);
    virtual ~TourFactory() {}
    TourFactory(const TourFactory& other);

    // This function creates a new TourService object of the type specified by tourType
    TravelService* createService() const override;
};

// TicketFactory is a "Concrete Factory"
// It is used to create different types of ticket services (bus, flight, train, ...)
class TicketFactory : public TravelServiceFactory {
private:
    string ticketType;  // The specific type of ticket (e.g. "Bus", "Flight", "Train")
public:
    TicketFactory(const string& ticketType);
    virtual ~TicketFactory() {}
    TicketFactory(const TicketFactory& other);

    // This function creates a new TicketService object based on ticketType
    TravelService* createService() const override;
};

// CarRentalFactory is a "Concrete Factory"
// It is used to create different types of car rental services (bike, motorbike, car, ...)
class CarRentalFactory : public TravelServiceFactory {
private:    
    string vehicleType;     // The specific type of vehicle (e.g. "Bike", "Motorbike", "Car")
public:
    CarRentalFactory(const string& vehicleType);
    virtual ~CarRentalFactory() {}
    CarRentalFactory(const CarRentalFactory& other);

    // This function creates a new CarRentalService object based on vehicleType
    TravelService* createService() const override;
};

#endif /* A6C762EE_8BD5_434F_95A2_B0FA1BBEE309 */
