#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct City {
    string name;
    int distance;
    int mileage;
};

void printCities(const vector<City>& cities) {
    for (size_t i = 0; i < cities.size(); ++i) {
        cout << i + 1 << ". " << cities[i].name << "\n";
    }
}

int getDistance(const vector<City>& beginningCities, const vector<City>& destinationCities,
                const string& beginCityName, const string& destCityName) {
    for (const auto& beginCity : beginningCities) {
        if (beginCity.name == beginCityName) {
            for (const auto& destCity : destinationCities) {
                if (destCity.name == destCityName) {
                    return destCity.distance;
                }
            }
        }
    }
    return -1;
}
void processPayment(double price, const string& userEmail) {
    
    cout << "Processing payment...\n";
    
    
    string cardNumber;
    cout << "Enter your 8-digit card number: ";
    cin >> cardNumber;

    
    if (cardNumber.length() == 8 && all_of(cardNumber.begin(), cardNumber.end(), ::isdigit)) {
        cout << "Payment successful!\n";
        cout << "Check your email for your ticket.\n";
    } else {
        cout << "Invalid card number. Please enter a valid 8-digit card number.\n";
    }
}

int main() {
    ofstream ticket;

    string userName, userEmail;

    cout << "Enter your name: ";
    getline(cin, userName);

    cout << "Enter your email: ";
    getline(cin, userEmail);

    vector<City> beginningCities = {
        {"megenaga", 0, 0},
        {"tulu dimtu", 0, 0},
        {"wollo sefer", 0, 0},
        {"bisrate gabriel", 0, 0},
        {"mexico", 0, 0}
    };

     vector<City> destinationCities = {
        {"Mekele", 504, 313},
        {"Jijiga", 446, 277},
        {"Harar", 371, 231},
        {"Bahir Dar", 322, 200},
        {"Hawassa", 220, 137},
        {"Asosa", 476, 296},
        {"Afar", 388, 241},
        {"Amhara", 272, 169},
        {"Binshangul Gumuz", 399, 248},
        {"Dire Dawa", 346, 215},
        {"Gambela", 466, 290},
        {"Harari", 380, 236},
        {"Oromiya", 265, 165},
        {"Somali", 615, 382},
        {"Tigray", 559, 347},
        {"Southern Nations, Nationalities, and People's Reg", 342, 213}
    };

    cout << "Choose your beginning city:\n";
    printCities(beginningCities);

    int beginCityChoice;
    cout << "\nEnter the number for your beginning city: ";
    cin >> beginCityChoice;

    if (beginCityChoice >= 1 && static_cast<size_t>(beginCityChoice) <= beginningCities.size()) {
        string beginCity = beginningCities[beginCityChoice - 1].name;

        cout << "\nDestination Cities:\n";
        printCities(destinationCities);

        int destCityChoice;
        cout << "\nEnter the number for the destination city: ";
        cin >> destCityChoice;

        if (destCityChoice >= 1 && static_cast<size_t>(destCityChoice) <= destinationCities.size()) {
            string destCity = destinationCities[destCityChoice - 1].name;

            int distance = getDistance(beginningCities, destinationCities, beginCity, destCity);
            if (distance != -1) {
                double price = 15 * distance;
                cout << "Distance from " << beginCity << " to " << destCity << ": " << distance << " km\n";
                cout << "Price: " << price << " birr\n";
                processPayment(price, userEmail);
                ticket.open("emailfile.txt");
                ticket << "Hi, " << userName << ". Your ticket is ready\n" <<  "Starting point: " << beginCity << "\nDestination: " << destCity;
                system("try.py");
            } else {
                cout << "Cities not found. Please enter valid cities.\n";
            }
        } else {
            cout << "Invalid destination city choice. Please enter a valid number.\n";
        }
    } else {
        cout << "Invalid beginning city choice. Please enter a valid number.\n";
    }

    return 0;
}
