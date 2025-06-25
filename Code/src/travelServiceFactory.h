#ifndef A6C762EE_8BD5_434F_95A2_B0FA1BBEE309
#define A6C762EE_8BD5_434F_95A2_B0FA1BBEE309
#include "travelService.h"

class TravelServiceFactory {
public:
    virtual TravelService* createService() const = 0;
    virtual ~TravelServiceFactory() {}
};

class TourFactory : public TravelServiceFactory {
private: 
    string tourType;
public:
    TourFactory(const string& tourType);
    virtual ~TourFactory() {}
    TourFactory(const TourFactory& other);
    TravelService* createService() const override;
};

class TicketFactory : public TravelServiceFactory {
private:
    string ticketType;
public:
    TicketFactory(const string& ticketType);
    virtual ~TicketFactory() {}
    TicketFactory(const TicketFactory& other);
    TravelService* createService() const override;
};

class CarRentalFactory : public TravelServiceFactory {
private:    
    string vehicleType;
public:
    CarRentalFactory(const string& vehicleType);
    virtual ~CarRentalFactory() {}
    CarRentalFactory(const CarRentalFactory& other);
    TravelService* createService() const override;
};

class HotelBookingFactory : public TravelServiceFactory {
public:
    TravelService* createService() const override;
};

#endif /* A6C762EE_8BD5_434F_95A2_B0FA1BBEE309 */
