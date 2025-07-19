#include "TicketService.h"

// BusTicketService class implementation

BusTicketService::BusTicketService() {
    code = "BS-123";
    departure = "Ho Chi Minh City";
    destination = "Can Tho";
    departureTime = { 7, 30 };
    departureDate = { 25, 6, 2025 };
    ticketPrice = 180000;
    remainingTickets = 35;
    licensePlate = "51F-678.99";
    stops = {
        {"Long An", {8, 15}, 10},
        {"Tien Giang", {9, 0}, 15}
    };
    baggagePolicy = "One small bag per person. Extra charge for oversized luggage.";
    cancellationPolicy = "No refund within 6 hours before departure.";
    contactInfo = "0283 456 789";
}

BusTicketService::BusTicketService(const BusTicketService& other)
    : TicketService(other),
      licensePlate(other.licensePlate)
{

}

BusTicketService::~BusTicketService() {}

string BusTicketService::getInfo() const {
    ostringstream oss;
    oss << fixed << setprecision(0);
    oss << "=== Bus Ticket Information ===\n";
    oss << "Trip Code: " << code << "\n";
    oss << "Departure: " << departure << "\n";
    oss << "Destination: " << destination << "\n";
    oss << "Departure Time: " << departureTime.hour << ":" << setw(2) << setfill('0') << departureTime.min << "\n";
    oss << "Departure Date: " << departureDate.day << "/" << departureDate.month << "/" << departureDate.year << "\n";
    oss << "Ticket Price: " << ticketPrice << " VND\n";
    oss << "Remaining Tickets: " << remainingTickets << "\n";
    oss << "License Plate: " << licensePlate << "\n\n";
    oss << "Stop Schedule:\n";
    for (int i = 0; i < stops.size(); ++i) {
        oss << "Stop #" << (i + 1) << ": " << get<0>(stops[i])
            << ", Time: " << get<1>(stops[i]).hour << ":" << setw(2) << setfill('0') << get<1>(stops[i]).min
            << ", Duration: " << get<2>(stops[i]) << " minutes\n";
    }
    oss << "Baggage Policy: " << baggagePolicy << "\n";
    oss << "Cancellation Policy: " << cancellationPolicy << "\n";
    oss << "Contact Info: " << contactInfo << "\n";
    return oss.str();
}

bool BusTicketService::book(int groupSize) {
    if (groupSize <= remainingTickets) {
        remainingTickets -= groupSize;
        return true;
    }
    return false;
}

// FlightTicketService class implementation

FlightTicketService::FlightTicketService() {
    code = "VN-888";
    departure = "Hanoi";
    destination = "Da Nang";
    departureTime = { 14, 0 };
    departureDate = { 10, 7, 2025 };
    ticketPrice = 1200000;
    remainingTickets = 20;
    airplaneCode = "Airbus A321";
    stops = {};
    baggagePolicy = "20kg checked + 7kg carry-on.";
    cancellationPolicy = "Refund 50% if canceled before 24 hours.";
    contactInfo = "1900 1100";
}

FlightTicketService::FlightTicketService(const FlightTicketService& other)
    : TicketService(other),
      airplaneCode(other.airplaneCode)
{

}

FlightTicketService::~FlightTicketService() {}

string FlightTicketService::getInfo() const {
    ostringstream oss;
    oss << fixed << setprecision(0);
    oss << "=== Flight Ticket Information ===\n";
    oss << "Flight Code: " << code << "\n";
    oss << "Departure: " << departure << "\n";
    oss << "Destination: " << destination << "\n";
    oss << "Departure Time: " << departureTime.hour << ":" << setw(2) << setfill('0') << departureTime.min << "\n";
    oss << "Departure Date: " << departureDate.day << "/" << departureDate.month << "/" << departureDate.year << "\n";
    oss << "Ticket Price: " << ticketPrice << " VND\n";
    oss << "Remaining Tickets: " << remainingTickets << "\n";
    oss << "Airplane Code: " << airplaneCode << "\n\n";
    oss << "Stop Schedule:\n";
    for (int i = 0; i < stops.size(); ++i) {
        oss << "Stop #" << (i + 1) << ": " << get<0>(stops[i])
            << ", Time: " << get<1>(stops[i]).hour << ":" << setw(2) << setfill('0') << get<1>(stops[i]).min
            << ", Duration: " << get<2>(stops[i]) << " minutes\n";
    }
    oss << "Baggage Policy: " << baggagePolicy << "\n";
    oss << "Cancellation Policy: " << cancellationPolicy << "\n";
    oss << "Contact Info: " << contactInfo << "\n";
    return oss.str();
}

bool FlightTicketService::book(int groupSize) {
    if (groupSize <= remainingTickets) {
        remainingTickets -= groupSize;
        return true;
    }
    return false;
}

// TrainTicketService class implementation

TrainTicketService::TrainTicketService() {
    code = "SE5";
    departure = "Ho Chi Minh City";
    destination = "Nha Trang";
    departureTime = { 6, 0 };
    departureDate = { 5, 7, 2025 };
    ticketPrice = 450000;
    remainingTickets = 50;
    trainID = "D19E-955";
    stops = {
        {"Bien Hoa", {6, 45}, 5},
        {"Binh Thuan", {8, 30}, 10}
    };
    baggagePolicy = "No weight limit but must be manageable.";
    cancellationPolicy = "Full refund 48h prior to departure.";
    contactInfo = "1900 1520";
}

TrainTicketService::TrainTicketService(const TrainTicketService& other) 
    : TicketService(other),
      trainID(other.trainID)
{

}

TrainTicketService::~TrainTicketService() {}

string TrainTicketService::getInfo() const {
    ostringstream oss;
    oss << fixed << setprecision(0);
    oss << "=== Train Ticket Information ===\n";
    oss << "Train Code: " << code << "\n";
    oss << "Departure Station: " << departure << "\n";
    oss << "Arrival Station: " << destination << "\n";
    oss << "Departure Time: " << departureTime.hour << ":" << setw(2) << setfill('0') << departureTime.min << "\n";
    oss << "Departure Date: " << departureDate.day << "/" << departureDate.month << "/" << departureDate.year << "\n";
    oss << "Ticket Price: " << ticketPrice << " VND\n";
    oss << "Remaining Tickets: " << remainingTickets << "\n";
    oss << "Train ID: " << trainID << "\n\n";
    oss << "Stop Schedule:\n";
    for (int i = 0; i < stops.size(); ++i) {
        oss << "Stop #" << (i + 1) << ": " << get<0>(stops[i])
            << ", Time: " << get<1>(stops[i]).hour << ":" << setw(2) << setfill('0') << get<1>(stops[i]).min
            << ", Duration: " << get<2>(stops[i]) << " minutes\n";
    }
    oss << "Baggage Policy: " << baggagePolicy << "\n";
    oss << "Cancellation Policy: " << cancellationPolicy << "\n";
    oss << "Contact Info: " << contactInfo << "\n";
    return oss.str();
}

bool TrainTicketService::book(int groupSize) {
    if (groupSize <= remainingTickets) {
        remainingTickets -= groupSize;
        return true;
    }
    return false;
}