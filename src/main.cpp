#include "travelServiceFactory.h"

/*
    Travel Service System (Factory Method Pattern Demo)
    - User can login, select travel services, and make bookings.
    - Services (tour, ticket, rental) are managed with maps to preserve booking status (not reset after each booking).
    - Uses Factory Method pattern for service creation.
    - Demonstrates good memory management in C++ (freeing all objects before exit).
*/


// Helper functions to map menu choices to service types
// Used to select the type of tour, ticket, or vehicle rental based on user input.

string getTourType(int choice) {
    switch (choice) {
        case 1: return "DaLat";
        case 2: return "SapaHaGiang";
        case 3: return "HaLongTuanChau";
        case 4: return "DaNang";
        case 5: return "PhuQuoc";
        default: return ""; 
    }
}

string getTicketType(int choice) {
    switch (choice) {
        case 1: return "FlightTicketService";
        case 2: return "BusTicketService";
        case 3: return "TrainTicketService";
        default: return "";
    } 
}

string getVehicleType(int choice) {
    switch (choice) {
        case 1: return "Bike";
        case 2: return "Motorbike";
        case 3: return "Car";
        default: return "";
    }
}

// Simple user database for login simulation.
map<string, string> users = {
    {"Dragon", "anh iu em"},
    {"Dat HCMUS", "1234"},
    {"Thien HCMUS", "1234"},
    {"Quang lazy", "1234"},
    {"guest", "1234"}
};

int main() {
    // Step 1: Login Section
    // User has 3 attempts to login
    string userName = "";
    string passWord = "";
    int tries = 3;

    bool login = false;
    while (tries--) {
        cout << "\n===== LOGIN =====\n";
        cout << "Enter username: ";
        getline(cin, userName);
        cout << "Enter password: ";
        getline(cin, passWord);

        // Check if username and password match
        map<string, string>::iterator it = users.find(userName);
        if (it != users.end() && it->second == passWord) {
            cout << "Login successful! Welcome, " << userName << ".\n";
            login = true;
            break;
        } else {
            cout << "Login failed! Please try again. (" << tries << " attempts left)\n";
        }
    }
    
    // Exit program if login failed after 3 tries
    if (! login) {
        cout << "You have exceeded the maximum number of login attempts. The program will now exit.\n";
        return 0;
    }

    // Step 2: Create maps to store and reuse each service object (so state is preserved)
    map<string, TravelService*> tourServices;
    map<string, TravelService*> ticketServices;
    map<string, TravelService*> carRentalServices;

    // Step 3: Main menu loop for choosing service and booking
    int travelChoice = -1;
    do {
        cout << "\n===== TRAVEL SERVICE SYSTEM =====\n";
        cout << "1. Travel tour\n";
        cout << "2. Vehicle ticket\n";
        cout << "3. Car rental\n";
        cout << "0. Exit\n";
        cout << "Enter your choice (number from 0 to 3): ";
        cin >> travelChoice;

        // Exit the program
        if (travelChoice == 0) {
            cout << "Thank you for using the travel service system!\n";
            break;
        }

        // Book a tour
        if (travelChoice == 1) {
            int choice = -1;
            do {
                cout << "\n====== TOUR BOOKING SYSTEM =====\n";
                cout << "1. Da Lat\n";
                cout << "2. Sapa - Ha Giang\n";
                cout << "3. Ha Long - Tuan Chau\n";
                cout << "4. Da Nang\n";
                cout << "5. Phu Quoc\n";
                cout << "0. Exit\n";
                cout << "Enter your choice (number from 0 to 5): ";
                cin >> choice;

                if (choice == 0) {
                    cout << "Thank you for using the tour booking system!\n";
                    break;
                }

                // Get type of tour based on user choice
                string tourType = getTourType(choice);
                if (tourType == "") {
                    cout << "Invalid choice! Please try again.\n";
                    continue;
                }

                // Create the chosen tour using the Factory
                TravelService* tour = nullptr;
                if (tourServices.find(tourType) == tourServices.end()) {
                    TourFactory factory(tourType);
                    tour = factory.createService();
                    tourServices[tourType] = tour;
                } else {
                    tour = tourServices[tourType];
                }

                // Display tour information
                cout << "\n" << tour->getInfo() << "\n";

                // Ask if user wants to book the tour
                char bookingChoice;
                cout << "Do you want to book this tour? (y/n): ";
                cin >> bookingChoice;

                if (bookingChoice == 'y' || bookingChoice == 'Y') {
                    int groupSize;
                    cout << "Enter number of people to book: ";
                    cin >> groupSize;
                    if (groupSize <= 0) {
                        cout << "Invalid group size!\n";
                    } else if (tour->book(groupSize)) {
                        cout << "Booking successful for group of " << groupSize << ".\n";
                        cout << "Current group size: " << tour->getInfo() << "\n"; 
                    } else {
                        cout << "Booking failed! Not enough slots remaining.\n";
                    }
                } else {
                    continue;
                }
                cout << "---------------------------------------------\n";
            } while (choice != 0);

            // Book a vehicle ticket (flight, bus, train)
        } else if (travelChoice == 2) {
            int choice = -1;
            do {
                cout << "\n===== VEHICLE TICKET BOOKING SYSTEM =====\n";
                cout << "1. Flight Ticket\n";
                cout << "2. Bus Ticket\n";
                cout << "3. Train Ticket\n";
                cout << "0. Exit\n";
                cout << "Enter your choice (number from 0 to 3): ";
                cin >> choice;

                if (choice == 0) {
                    cout << "Thank you for using the vehicle ticket booking system!\n";
                    break;
                }

                // Get ticket type based on user choice
                string ticketType = getTicketType(choice);
                if (ticketType == "") {
                    cout << "Invalid choice! Please try again.\n";
                    continue;
                }

                // Create the chosen ticket using the Factory
                TravelService* ticket = nullptr;
                if (ticketServices.find(ticketType) == ticketServices.end()) {
                    TicketFactory factory(ticketType);
                    ticket = factory.createService();
                    ticketServices[ticketType] = ticket;
                } else {
                    ticket = ticketServices[ticketType];
                }

                // Display ticket information
                cout << "\n" << ticket->getInfo() << "\n";

                // Ask if user wants to book the ticket
                char bookingChoice;
                cout << "Do you want to book this ticket? (y/n): ";
                cin >> bookingChoice;

                if (bookingChoice == 'y' || bookingChoice == 'Y') {
                    int groupSize;
                    cout << "Enter number of tickets to book: ";
                    cin >> groupSize;

                    if (groupSize <= 0) {
                        cout << "Invalid ticket count!\n";
                    } else if (ticket->book(groupSize)) {
                        cout << "Booking successful for " << groupSize << " tickets.\n";
                        cout << "Current ticket info:\n" << ticket->getInfo() << "\n";
                    } else {
                        cout << "Booking failed! Not enough tickets remaining.\n";
                    }
                } else {
                    continue;
                }

                cout << "---------------------------------------------\n";
            } while (choice != 0);

            // Book a car or vehicle rental (bike, motorbike, car)
        } else if (travelChoice == 3) {
            int choice = -1;
            do {
                cout << "\n===== CAR RENTAL SERVICE SYSTEM =====\n";
                cout << "1. Bike rental\n";
                cout << "2. Motorbike rental\n";
                cout << "3. Car rental\n";
                cout << "0. Exit\n";
                cout << "Enter your choice (number from 0 to 3): ";
                cin >> choice;

                if (choice == 0) {
                    cout << "Thank you for using the car rental service system!\n";
                    break;
                }

                // Get vehicle type based on user choice
                string vehicleType = getVehicleType(choice);
                if (vehicleType == "") {
                    cout << "Invalid choice! Please try again.\n";
                    continue;
                }

                // Create the chosen rental service using the Factory
                TravelService* rental = nullptr;
                if (carRentalServices.find(vehicleType) == carRentalServices.end()) {
                    CarRentalFactory factory(vehicleType);
                    rental = factory.createService();
                    carRentalServices[vehicleType] = rental;
                } else {
                    rental = carRentalServices[vehicleType];
                }

                // Display rental information
                cout << "\n" << rental->getInfo() << "\n";

                // Ask if user wants to rent the vehicle
                char bookingChoice;
                cout << "Do you want to rent this vehicle? (y/n): ";
                cin >> bookingChoice;
                
                if (bookingChoice =='y' || bookingChoice == 'Y') {
                    int rentalHours;
                    cout << "Enter number of rental hours: ";
                    cin >> rentalHours;
                    if (rentalHours <= 0) {
                        cout << "Invalid rental hours!\n";
                    } else if (rental->book(rentalHours)) {
                        cout << "Booking successful for " << rentalHours << " hours.\n";
                        cout << "Current rental info:\n" << rental->getInfo() << "\n";
                    } else {
                        cout << "Booking failed! Cannot book this rental duration.\n";
                    }
                } else {
                    continue;
                }
                cout << "---------------------------------------------\n";
            } while (choice != 0);

        } else {
            // If user enters an invalid menu choice
            cout << "Invalid your choice! Please enter again.\n"; 
        }

    } while (travelChoice != 0);

    // Step 4: Free all allocated objects before program exit
    // .second: value (pointer points to object by new)
    // .first: key (Ex: "DaLat", "BusTicketService", "Bike")
    for (auto& p : tourServices) delete p.second;
    for (auto& p : ticketServices) delete p.second;
    for (auto& p : carRentalServices) delete p.second;
    
    return 0;
}