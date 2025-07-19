#include "CarRentalService.h"

// ===== CarRentalService IMPLEMENTATION =====

bool CarRentalService::book(int rentalHours) {
    if (rentalHours <= 0)
        return false;

    endTime.hour = startTime.hour + rentalHours;

    if (endTime.hour >= 24)
        endTime.hour %= 24;

    totalCost = rentalHours * hourlyRate;

    return true;
}

string CarRentalService::getInfo() const {
    stringstream ss;

    ss << "Rental ID: " << rentalID << "\n";
    ss << "Vehicle Type: " << getVehicleType() << "\n";
    ss << "License Plate: " << licensePlate << "\n";
    ss << "Rental Date: " << rentalDate.day << "/" << rentalDate.month << "/" << rentalDate.year << "\n";
    ss << "Time: " << startTime.hour << ":" << (startTime.min < 10 ? "0" : "") << startTime.min
        << " - " << endTime.hour << ":" << (endTime.min < 10 ? "0" : "") << endTime.min << "\n";
    ss << "City: " << rentalCity << "\n";
    ss << "Hourly Rate: " << hourlyRate << "\n";
    ss << "Total Cost: " << totalCost << "\n";
    ss << "Contact: " << contactInfo;

    return ss.str();
}

// ===== BikeRental IMPLEMENTATION =====

BikeRental::BikeRental() {
    rentalID = "B001";
    licensePlate = "29Y3-002.34";           
    rentalDate = { 1, 1, 2024 };
    startTime = { 8, 0 };
    endTime = { 0, 0 };
    rentalCity = "Hanoi";
    hourlyRate = 15000;
    totalCost = 0.0;
    contactInfo = "bike@rental.vn";
}

BikeRental::BikeRental(const BikeRental& other) : CarRentalService(other) {}

string BikeRental::getInfo() const {
    return CarRentalService::getInfo();
}

// ===== MotorbikeRental IMPLEMENTATION =====

MotorbikeRental::MotorbikeRental() {
    rentalID = "M001";
    licensePlate = "51F-178.12";            
    rentalDate = { 1, 1, 2024 };
    startTime = { 9, 0 };
    endTime = { 0, 0 };
    rentalCity = "HCM City";
    hourlyRate = 30000;
    totalCost = 0.0;
    contactInfo = "motorbike@rental.vn";
}

MotorbikeRental::MotorbikeRental(const MotorbikeRental& other) : CarRentalService(other) {}

string MotorbikeRental::getInfo() const {
    return CarRentalService::getInfo();
}

// ===== CarRental IMPLEMENTATION =====

CarRental::CarRental() {
    rentalID = "C001";
    licensePlate = "51G-743.72";           
    rentalDate = { 1, 1, 2024 };
    startTime = { 10, 0 };
    endTime = { 0, 0 };
    rentalCity = "Da Nang";
    hourlyRate = 70000;
    totalCost = 0.0;
    contactInfo = "car@rental.vn";
}

CarRental::CarRental(const CarRental& other) : CarRentalService(other) {}

string CarRental::getInfo() const {
    return CarRentalService::getInfo();
}