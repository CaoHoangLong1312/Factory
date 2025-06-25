#include "travelService.h"
#include "travelServiceFactory.h"

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

map<string, string> users = {
    {"Dragon", "anh iu em"},
    {"Dat HCMUS", "1234"},
    {"Thien HCMUS", "1234"},
    {"Quang lazy", "1234"},
    {"guest", "1234"}
};

int main() {
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

        map<string, string>::iterator it = users.find(userName);
        if (it != users.end() && it->second == passWord) {
            cout << "Login successful! Welcome, " << userName << ".\n";
            login = true;
            break;
        } else {
            cout << "Login failed! Please try again. (" << tries << " attempts left)\n";
        }
    }
    
    if (! login) {
        cout << "You have exceeded the maximum number of login attempts. The program will now exit.\n";
        return 0;
    }

    int travelChoice = -1;
    do {
        cout << "\n===== TRAVEL SERVICE SYSTEM =====\n";
        cout << "1. Travel tour\n";
        cout << "2. Vehicle ticket\n";
        cout << "3. Car rental\n";
        cout << "0. Exit\n";
        cout << "Enter your choice (number from 0 to 3): ";
        cin >> travelChoice;

        if (travelChoice == 0) {
            cout << "Thank you for using the travel service system!\n";
            break;
        }

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

                string tourType = getTourType(choice);
                if (tourType == "") {
                    cout << "Invalid choice! Please try again.\n";
                    continue;
                }

                TourFactory factory(tourType);
                TravelService* tour = factory.createService();
                if (! tour) {
                    cerr << "Error: creating tour. Please try again.\n";
                    continue;
                }

                cout << "\n" << tour->getInfo() << "\n";

                // Booking
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
                delete tour;
            } while (choice != 0);

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

                string ticketType = getTicketType(choice);
                if (ticketType == "") {
                    cout << "Invalid choice! Please try again.\n";
                    continue;
                }

                TicketFactory factory(ticketType);
                TravelService* ticket = factory.createService();
                if (! ticket) {
                    cerr << "Error: creating ticket. Please try again.\n";
                    continue;
                }

                cout << "\n" << ticket->getInfo() << "\n";

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
                delete ticket;
            } while (choice != 0);

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

                string vehicleType = getVehicleType(choice);
                if (vehicleType == "") {
                    cout << "Invalid choice! Please try again.\n";
                    continue;
                }

                CarRentalFactory factory(vehicleType);
                TravelService* rental = factory.createService();
                if (! rental) {
                    cout << "Error: creating rental. Please try again.\n";
                    continue;
                }

                cout << "\n" << rental->getInfo() << "\n";

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
                delete rental;
            } while (choice != 0);

        } else {
            cout << "Invalid your choice! Please enter again.\n"; 
        }

    } while (travelChoice != 0);
    
    return 0;
}