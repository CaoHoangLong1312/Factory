#ifndef B30E3E30_C990_4479_8D08_C74F72DDDFCB
#define B30E3E30_C990_4479_8D08_C74F72DDDFCB

#include "travelService.h"

// Base class for all types of vehicle rental services
// Stores common info: rental ID, vehicle info, date, city, rates, etc.
class CarRentalService : public TravelService {
protected:
    string rentalID;        // Rental contract ID
    string licensePlate;    // Vehicle license plate
    Date rentalDate;        // Rental date
    Time startTime;         // Rental start time
    Time endTime;           // Rental end time
    string rentalCity;      // City of rental
    double hourlyRate;      // Hourly rental rate
    double totalCost;       // Total cost for rental
    string contactInfo;     // Contact information

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
    string getInfo() const override;            // Get rental information
    bool book(int rentalHours) override;        // Book a rental
    virtual string getVehicleType() const = 0;  // Get vehicle type (bike, motorbike, car)
};

// Represents a bike rental service
class BikeRental : public CarRentalService {
public:
    BikeRental();
    BikeRental(const BikeRental& other);
    string getInfo() const override;
    string getVehicleType() const override { return "Bike"; }
};

// Represents a motorbike rental service.
class MotorbikeRental : public CarRentalService {
public:
    MotorbikeRental();
    MotorbikeRental(const MotorbikeRental& other);
    string getInfo() const override;
    string getVehicleType() const override { return "Motorbike"; }
};

// Represents a car rental service.
class CarRental : public CarRentalService {
public:
    CarRental();
    CarRental(const CarRental& other);
    string getInfo() const override;
    string getVehicleType() const override { return "Car"; }
};

#endif /* B30E3E30_C990_4479_8D08_C74F72DDDFCB */
