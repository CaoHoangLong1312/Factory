#include "TourService.h"

// DaLat class implementation

DaLat::DaLat() {
    tourName = "Da Lat 3 Days 3 Nights Tour";
    tourCode = "DL-3D3N";
    departureDate = "Every Thursday and Friday";
    transportation = "Sleeper Bus";
    hotel = "2-3 stars hotels";
    tourPrice = 2400000.0;
    contact = "0917 966 033";
    maxGroup = 40;
    booked = 0;

    itinerary = {
        {"Night 1 (22:00 - 24:05)", {
            "22:00: Pick up guests at meeting points in Ho Chi Minh City (District 12, Tan Binh, District 5, District 1, Thu Duc)",
            "22:35: Pick up at Tan Binh Exhibition Center",
            "22:55: Pick up at Hung Vuong Plaza (District 5)",
            "23:25: Pick up at Youth Cultural House, District 1",
            "Afterwards: Depart for Da Lat, overnight on the bus"
        }},
        {"Day 1 (08:00 - 17:00)", {
            "08:00: Arrive in Da Lat, visit Xuan Huong Lake & Lam Vien Square",
            "Visit Van Thanh Flower Village and Hydrangea Flower Field",
            "Lunch: Local restaurant",
            "Afternoon: Langbiang Mountain or Linh An Pagoda",
            "17:00: Return to hotel, check in, free evening to explore Da Lat"
        }},
        {"Day 2 (07:30 - 17:30)", {
            "07:30: Breakfast at hotel",
            "08:30: Start tour: Clay Tunnel",
            "Next: High-tech Strawberry Garden & Da Lat Market",
            "Lunch: Unlimited vegetable buffet or local restaurant",
            "Afternoon: Datanla Waterfall or Fresh Garden",
            "17:30: Return to hotel, dinner, rest"
        }},
        {"Day 3 (06:30 - 17:00)", {
            "06:30: Breakfast, check out",
            "07:30: Visit Domaine Church & Old French Villa Village",
            "Buy Da Lat specialties (jam, tea, milk, etc.) at local market",
            "Lunch: Local restaurant",
            "12:00: Depart back to Ho Chi Minh City",
            "17:00: Arrive in HCM City, end of tour"
        }}
    };

    includedServices = {
        {"Entrance Tickets", "Tickets to all destinations in the itinerary."},
        {"Hotel", "2 nights at 2-3 star hotels, 2-4 people per room."},
        {"Meals", "3 breakfasts, 5 main meals according to the program."},
        {"Mineral Water", "2 bottles/day/person."},
        {"Tour Guide", "Professional, enthusiastic tour guide."},
        {"Travel Insurance", "Full travel insurance during the tour."}
    };
}

DaLat::~DaLat() {
    
}

DaLat::DaLat(const DaLat& other)
    : TourService(other),
      departureDate(other.departureDate),
      transportation(other.transportation),
      hotel(other.hotel)
{

}

string DaLat::getInfo() const {
    ostringstream oss;
    oss << std::fixed << std::setprecision(0);
    oss << "---- " << tourName << " (" << tourCode << ") ----\n"
        << "Departure date: " << departureDate << "\n"
        << "Transportation: " << transportation << "\n"
        << "Hotel: " << hotel << "\n"
        << "Tour price: " << tourPrice << " VND/person\n"
        << "Contact for booking: " << contact << "\n"
        << "Group size: " << booked << "/" << maxGroup << "\n\n"
        << "=== Itinerary ===\n";
    for (const auto& dayPlan : itinerary) {
        oss << dayPlan.day << ":\n";
        for (const auto& activity : dayPlan.activities) {
            oss << "  - " << activity << "\n";
        }
    }   
    oss << "\n=== Included Services ===\n";
    for (const auto& service : includedServices) {
        oss << "  * " << service.name << ": " << service.description << "\n";
    }
    oss << "\nNote: The price does not include personal expenses, VAT, and services not mentioned in the program.\n";
    return oss.str();
}

bool DaLat::book(int groupSize) {
    if (booked + groupSize <= maxGroup) {
        booked += groupSize;
        return true;
    }
    return false;
}

// SapaHaGiang class implementation

SapaHaGiang::SapaHaGiang() {
    tourName = "Sapa - Ha Giang 4 Days 4 Nights";
    tourCode = "SP-HG-4D4N";
    departurePoint = "Hanoi (morning departure)";
    tourPrice = 4500000.0;  
    contact = "0777.522.622";
    maxGroup = 40;
    booked = 0;

    itinerary = {
        {"Day 1 (06:30 - 19:00)", {
            "06:30 - 07:00: Pickup from hotels in Hanoi Old Quarter",
            "Travel via Noi Bai - Lao Cai expressway with rest stops",
            "13:00 - 13:30: Arrive Sapa, lunch and check-in",
            "Afternoon: Trek Ham Rong Mountain Park - Orchid, Apple, Apple Guava Gardens, Heaven Gate, Stone Turtle, TV Tower, Cloud Yard",
            "18:00: Dinner; evening free to explore Stone Church, Sapa love market (Sat nights), enjoy local BBQ and San Lung wine"
        }},
        {"Day 2 (07:00 - 22:00)", {
            "07:00: Breakfast at hotel",
            "08:00: Transfer to Fansipan cable car station",
            "Ascend to Fansipan summit (3-wire system)",
            "Visit Tien Vien Zen Monastery, A Di Da Buddha statue (21.5m), La Han statues, Kim Son Bao Thang Temple",
            "12:00: Return to Sapa town for lunch",
            "Afternoon: Visit Cat Cat village, Tiensa waterfall, traditional ethnic performance",
            "18:00: Dinner in Sapa, transfer to sleeper bus to Ha Giang, overnight on bus"
        }},
        {"Day 3 (04:00 - 21:00)", {
            "04:00 - 04:30: Arrive Ha Giang, transfer to homestay, freshen up",
            "06:30: Breakfast at homestay",
            "07:00: Start Ha Giang loop: Km0 photo stop, Bac Sum pass, Quan Ba Heaven's Gate, Twin Stone Mountain, Join-Lang weaving village Lung Tam, Solo tree in Quan Ba",
            "Lunch in Yen Minh or Dong Van area",
            "Afternoon: Explore Tham Ma pass, Pho Cao, Doc Chin Khoanh, Sung La village (Stone house), Lung Cu flagpole",
            "18:00: Dinner in Dong Van; free evening walking around Old Quarter"
        }},
        {"Day 4 (08:00 - 03:30 next day)", {
            "Breakfast at hotel; on Sundays join Dong Van Market (optional)",
            "08:00: Checkout and visit Ma Pi Leng Pass (16km Happiness Road)",
            "Scenic stop at Tu San Canyon (1,500m altitude)",
            "Boat cruise on Nho Que River through Tu San Canyon (optional costs 200k-250k VND)",
            "Lunch in Dong Van",
            "16:00: Return to Ha Giang",
            "Option A: Transfer to limousine to Hanoi, arrive 23-24h (+50k VND surcharge)",
            "Option B: Overnight sleeper bus to Hanoi, arrive Noi Bai 03:00, Hanoi 03:30"
        }}
    };

    includedServices = {
        {"Transport", "7-29 seat bus in Ha Giang + Sapa-ha sleeper buses on inter-city segments"},
        {"Accommodation", "02 nights in hotel (Sapa 3*, Dong Van 2*), 01 night homestay + 01 night sleeper bus"},
        {"Meals", "08 main meals, breakfasts as per program"},
        {"Entrance Fees", "All visits except Fansipan cable car (optional)"},
        {"Guide", "Experienced English-Vietnamese tour guide"},
        {"Mineral Water", "1 bottle per person per day"},
        {"Insurance", "Travel insurance during tour"}
    };
}

SapaHaGiang::~SapaHaGiang() {

}

SapaHaGiang::SapaHaGiang(const SapaHaGiang& other)
    : TourService(other),
      departurePoint(other.departurePoint)
{

}

string SapaHaGiang::getInfo() const {
    ostringstream oss;
    oss << std::fixed << std::setprecision(0);
    oss << "---- " << tourName << " (" << tourCode << ") ----\n"
        << "Departure point: " << departurePoint << "\n"
        << "Tour price: " << tourPrice << " VND/person\n"
        << "Contact: " << contact << "\n"
        << "Group size: " << booked << "/" << maxGroup << "\n\n"
        << "=== Itinerary ===\n";
    for (const auto& day : itinerary) {
        oss << day.day << ":\n";
        for (const auto& activity : day.activities) {
            oss << "  - " << activity << "\n";
        }
    }
    oss << "\n=== Included Services ===\n";
    for (const auto& service : includedServices) {
        oss << "  * " << service.name << ": " << service.description << "\n";
    }
    return oss.str();
}

bool SapaHaGiang::book(int groupSize) {
    if (booked + groupSize <= maxGroup) {
        booked += groupSize;
        return true;
    }
    return false;
}

// HaLongTuanChau class implementation

HaLongTuanChau::HaLongTuanChau() {
    tourName = "Ha Long - Tuan Chau - Bai Chay 3 Days 2 Nights";
    tourCode = "HL-3D2N";
    departurePoint = "Pick-up from Hanoi or Ha Long";
    accommodation = "1 Night 3-star Cruise + 1 Night 3-star Hotel";
    tourPrice = 3550000.0;
    contact = "Hotline SinhCafe Travel";
    maxGroup = 40;
    booked = 0;

    itinerary = {
        {"Day 1 (08:30 - 12:15)", {
            "08:30: Pick-up from Hanoi (Old Quarter) or Ha Long",
            "12:00: Arrive at Tuan Chau Marina",
            "12:15: Board cruise - welcome drink & safety briefing",
            "13:00: Lunch while cruising past islets (Chicken, Finger, Frog)",
            "15:00: Kayak/rowboat at Dark & Bright Lagoon",
            "16:30: Free swim or sun-deck spa",
            "17:30: Sunset cooking demo, 19:00: Dinner on board",
            "21:00: Evening activities: movie, squid fishing or bar"
        }},
        {"Day 2 (06:15 - 10:30)", {
            "06:15: Tai Chi on sundeck",
            "07:00: Light breakfast",
            "07:45: Visit Sung Sot (Surprise) Cave",
            "09:00: Check-out cabin",
            "09:30: Brunch on board returning to port",
            "10:30: Disembark at Tuan Chau, transfer to hotel at Bai Chay",
            "Afternoon free time: explore Bai Chay or Tuan Chau Night Market",
            "18:00: Dinner at hotel restaurant"
        }},
        {"Day 3", {
            "07:00: Breakfast at hotel, free time",
            "11:00: Check-out hotel, lunch",
            "12:00: Depart back to Hanoi",
            "16:00 - 16:30: Mid-afternoon arrive back in Hanoi"
        }}
    };

    includedServices = {
        {"Cruise Accommodation", "1 night on a 3-star cruise cabin, AC, private bathroom"},
        {"Hotel", "1 night in 3-star hotel at Bai Chay / Tuan Chau, AC room"},
        {"Meals", "2 breakfasts, 3 lunches, 2 dinners according to program"},
        {"Insurance", "Travel insurance throughout tour"},
        {"Kayak & Bamboo Boat", "Session on bay and caves"},
        {"Entrance Fees", "Sung Sot Cave, Titop Island, pearl farm, boat to cave"},
        {"Transfers", "Pick-up/drop-off by van/bus from Hanoi or Ha Long"},
    };
}

HaLongTuanChau::~HaLongTuanChau() {}

HaLongTuanChau::HaLongTuanChau(const HaLongTuanChau& other)
    : TourService(other),
      departurePoint(other.departurePoint),
      accommodation(other.accommodation)
{

}

string HaLongTuanChau::getInfo() const {
    ostringstream oss;
    oss << std::fixed << std::setprecision(0);
    oss << "---- " << tourName << " (" << tourCode << ") ----\n"
        << "Departure point: " << departurePoint << "\n"
        << "Accommodation: " << accommodation << "\n"
        << "Tour price: " << tourPrice << " VND/person\n"
        << "Contact: " << contact << "\n"
        << "Group size: " << booked << "/" << maxGroup << "\n\n"
        << "=== Itinerary ===\n";
    for (const auto& day : itinerary) {
        oss << day.day << ":\n";
        for (const auto& act : day.activities) {
            oss << "  - " << act << "\n";
        }
    }
    oss << "\n=== Included Services ===\n";
    for (const auto& service : includedServices) {
        oss << "  * " << service.name << ": " << service.description << "\n";
    }
    oss << "\nNote: Price excludes personal expenses, VAT, and optional activities.\n";
    return oss.str();
}

bool HaLongTuanChau::book(int groupSize) {
    if (booked + groupSize <= maxGroup) {
        booked += groupSize;
        return true;
    }
    return false;
}

// DaNang class implementation

DaNang::DaNang() {
    tourName = "Da Nang - Hoi An - Ba Na - Cu Lao Cham 3 Days 2 Nights";
    tourCode = "DN-3D2N";
    departurePoint = "Pick up at Da Nang airport or hotels";
    hotel = "3-star hotel in Da Nang";
    tourPrice = 3200000.0;
    contact = "Tuan Nguyen Travel Hotline: 1900 63 68 22";
    maxGroup = 40;
    booked = 0;

    itinerary = {
        {"Day 1", {
            "08:00 - 12:00: Pick up at Da Nang airport, transfer to hotel, check-in",
            "12:00: Lunch at restaurant",
            "14:00: Visit Son Tra Peninsula - Linh Ung Pagoda (the tallest Lady Buddha in Vietnam)",
            "16:00: Swim at My Khe Beach (one of the most beautiful beaches in the world)",
            "18:30: Dinner at restaurant, free evening: explore Da Nang, Dragon Bridge, Han River"
        }},
        {"Day 2", {
            "06:30: Breakfast at hotel",
            "07:30: Depart for Ba Na Hills - Golden Bridge (World famous 'Hand Bridge')",
            "Take cable car, visit Le Jardin d'Amour, Debay Wine Cellar, French Village",
            "12:00: Buffet lunch at Ba Na Hills",
            "Afternoon: Free to enjoy Fantasy Park (indoor amusement park), Alpine Coaster",
            "15:00: Return to Da Nang",
            "16:30: Visit Marble Mountains (Ngu Hanh Son) and Non Nuoc stone carving village",
            "18:30: Dinner in Hoi An, walk and admire lantern street, ancient houses, Japanese Covered Bridge, release flower lanterns on Hoai River",
            "21:00: Return to Da Nang"
        }},
        {"Day 3", {
            "06:30: Breakfast, check-out hotel",
            "07:30: Transfer to Cua Dai Port, speedboat to Cu Lao Cham Island",
            "08:00: Visit local fishing village, Hai Tang Pagoda, Cham well",
            "09:30: Swim, snorkel to see coral, relax on Bai On g beach",
            "11:30: Lunch with fresh seafood on island",
            "13:30: Return to Da Nang, drop off at airport or hotel",
            "End of tour"
        }}
    };

    includedServices = {
        {"Accommodation", "2 nights in 3-star hotel (2-3 pax/room)"},
        {"Meals", "Breakfasts at hotel, main meals at local restaurants or buffet (as program)"},
        {"Tickets", "All sightseeing and entrance tickets according to itinerary (Ba Na cable car, Cu Lao Cham speedboat, etc.)"},
        {"Transport", "Modern air-conditioned coach during tour"},
        {"Guide", "Experienced local guide"},
        {"Travel Insurance", "According to tour regulations"},
        {"Water", "1 bottle/day/person"}
    };
}
    
DaNang::~DaNang() {

}

DaNang::DaNang(const DaNang& other)
    : TourService(other),
      departurePoint(other.departurePoint),
      hotel(other.hotel)
{

}

string DaNang::getInfo() const {
    ostringstream oss;
    oss << std::fixed << std::setprecision(0);
    oss << "---- " << tourName << " (" << tourCode << ") ----\n"
        << "Departure point: " << departurePoint << "\n"
        << "Hotel: " << hotel << "\n"
        << "Tour price: " << tourPrice << " VND/person" << "\n"
        << "Contact: " << contact << "\n"
        << "Group size: " << booked << "/" << maxGroup << "\n\n"
        << "=== Itinerary ===\n";
    for (const auto& day : itinerary) {
        oss << day.day << "\n";
        for (const auto& activity : day.activities) {
            oss << "  - " << activity << "\n";
        }
    }
    oss << "\n=== Included Services ===\n";
    for (const auto& service : includedServices) {
        oss << "  * " << service.name << ": " << service.description << "\n"; 
    }
    return oss.str();
}

bool DaNang::book(int groupSize) {
    if (booked + groupSize <= maxGroup) {
        booked += groupSize;
        return true;
    }
    return false;
}

// PhuQuoc class implementation

PhuQuoc::PhuQuoc() {
    tourName = "Phu Quoc Island 3 Days 3 Nights Tour";
    tourCode = "PQ-3D3N";
    departurePoint = "Pick-up at Ho Chi Minh City (sleeper bus and speedboat to Phu Quoc)";
    hotel = "3-star hotel in Phu Quoc";
    tourPrice = 2790000.0;
    contact = "Top Travels Hotline: 0917 966 033";
    maxGroup = 40;
    booked = 0;

    itinerary = {
        {"Night 1", {
            "19:30 - 21:00: Pick up at meeting points in Ho Chi Minh City (districts 1, 5, 10, Tan Binh, Binh Tan, Thu Duc, etc.)",
            "21:00: Depart for Rach Gia by sleeper bus (overnight on bus)"
        }},
        {"Day 1", {
            "06:00: Arrive in Rach Gia, breakfast at restaurant",
            "07:30: Take speedboat to Phu Quoc Island",
            "09:30: Arrive in Phu Quoc, visit Ham Ninh Fishing Village (famous for crabs, seafood)",
            "11:00: Visit Suoi Tranh Waterfall (July-Oct: strong water!)",
            "12:00: Lunch at local restaurant",
            "14:00: Check in hotel, rest",
            "15:00: Visit Ho Quoc Pagoda (temple facing the sea, beautiful check-in spot)",
            "16:30: Swim at Sao Beach (the most beautiful beach on the island)",
            "18:00: Dinner with local seafood",
            "Evening: Free to explore Dinh Cau Night Market"
        }},
        {"Day 2", {
            "07:00: Breakfast at hotel",
            "08:00: Board boat for southern island-hopping tour: fishing, snorkeling coral at May Rut and Mong Tay islets",
            "12:00: Lunch on boat or islet",
            "14:30: Return to mainland, visit pearl farm",
            "16:00: Visit Phu Quoc Prison (historic site), Fish Sauce Factory",
            "17:30: Back to hotel, rest, swim at pool or beach",
            "18:30: Dinner at restaurant",
            "Evening: Free time"
        }},
        {"Day 3", {
            "06:30: Breakfast, check-out",
            "07:30: Visit pepper farm, Sim wine factory (Phu Quoc specialties)",
            "09:00: Relax or shop at Phu Quoc Center (Grand World, Safari - optional, own cost)",
            "11:00: Lunch at local restaurant",
            "12:30: Transfer to speedboat back to Rach Gia",
            "15:30: Arrive Rach Gia, board sleeper bus to Ho Chi Minh City (overnight on bus)",
            "04:00 - 05:00 (next day): Arrive HCMC, end of tour"
        }}
    };

    includedServices = {
        {"Transportation", "High-quality sleeper bus HCM City -> Rach Gia, speedboat Rach Gia -> Phu Quoc"},
        {"Accommodation", "2 nights in 3-star hotel in Phu Quoc (2-4 people/room)"},
        {"Meals", "According to program (2 breakfasts, 3 lunches, 2 dinners)"},
        {"Sightseeing", "Entrance tickets to all destinations in itinerary"},
        {"Tour Guide", "Professional, enthusiastic guide throughout the tour"},
        {"Travel Insurance", "Package tour insurance"},
        {"Water", "2 bottles/day/person"}
    };
}

PhuQuoc::~PhuQuoc() {

}

PhuQuoc::PhuQuoc(const PhuQuoc& other)
    : TourService(other),
      departurePoint(other.departurePoint),
      hotel(other.hotel)
{

}

string PhuQuoc::getInfo() const {
    ostringstream oss;
    oss << std::fixed << std::setprecision(0);
    oss << "---- " << tourName << " (" << tourCode << ") ----\n"
        << "Departure Point: " << departurePoint << "\n"
        << "Hotel: " << hotel << "\n"
        << "Tour Price: " << tourPrice << " VND/person\n"
        << "Contact: " << contact << "\n"
        << "Group size: " << booked << "/" << maxGroup << "\n\n"
        << "=== Itinerary ===\n";
    for (const auto& day : itinerary) {
        oss << day.day << ":\n";
        for (const auto& activity : day.activities) {
            oss << "  - " << activity << "\n";
        }
    }
    oss << "\n=== Included Services ===\n";
    for (const auto& service : includedServices) {
        oss << "  * " << service.name << ": " << service.description << "\n";
    }
    return oss.str();
}

bool PhuQuoc::book(int groupSize) {
    if (booked + groupSize <= maxGroup) {
        booked += groupSize;
        return true;
    }
    return false;
}