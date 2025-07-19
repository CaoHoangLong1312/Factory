#ifndef D1D8A43F_E740_4665_8251_647AD3E1EA87
#define D1D8A43F_E740_4665_8251_647AD3E1EA87

#include "travelService.h"

// Base class for all ticketing services (bus, flight, train)
// Stores ticket information and policies
class TicketService : public TravelService {
protected:
    string code;                                // Ticket code
    string departure;                           // Departure location
    string destination;                         // Destination location
    Time departureTime;                         // Time of departure
    Date departureDate;                         // Date of departure
    int ticketPrice;                            // Price of the ticket
    int remainingTickets;                       // Number of tickets remaining
    vector<tuple<string, Time, int>> stops;     // List of stops, times, and durations
    string baggagePolicy;                       // Baggage policy
    string cancellationPolicy;                  // Cancellation policy
    string contactInfo;                         // Contact information
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

// Represents a bus ticket service
class BusTicketService : public TicketService {
private:
    string licensePlate;    // Bus license plate

public:
    BusTicketService();
    BusTicketService(const BusTicketService& other);
    ~BusTicketService();
    string getInfo() const override;    // Get bus ticket information
    bool book(int groupSize) override;  // Book bus tickets
};

// Represents a flight ticket service
class FlightTicketService : public TicketService {
private:
    string airplaneCode;    // Airplane code

public:
    FlightTicketService();
    FlightTicketService(const FlightTicketService& other);
    ~FlightTicketService();
    string getInfo() const override;        // Get flight ticket information
    bool book(int groupSize) override;      // Book flight tickets
};

// Represents a train ticket service
class TrainTicketService : public TicketService {
private:
    string trainID;     // Train identifier

public:
    TrainTicketService();
    TrainTicketService(const TrainTicketService& other);
    ~TrainTicketService();
    string getInfo() const override;        // Get train ticket information
    bool book(int groupSize) override;      // Book train tickets
};

#endif /* D1D8A43F_E740_4665_8251_647AD3E1EA87 */
