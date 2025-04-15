#include <iostream>
#include <string>
#include <algorithm> // For transform
using namespace std;

const int NUM_HEROES = 10;

// Parallel arrays
string names[NUM_HEROES] = {
    "Squirrel Girl", "Arm-Fall-Off-Boy", "The Tick", "Matter-Eater Lad",
    "Zan", "Bouncing Boy", "Doorman", "Color Kid", "Dogwelder", "Razorback"
};

string superpowers[NUM_HEROES] = {
    "Control Squirrels", "Detachable Limbs", "Super Strength", "Eat Anything",
    "Water Manipulation", "Inflation", "Teleportation", "Color Manipulation", "Welding Dogs", "Driving Anything"
};

string weaknesses[NUM_HEROES] = {
    "Time Limits", "Heavy Objects", "Poor Judgment", "Indigestion",
    "Heat", "Deflation", "Doors Only", "Limited Spectrum", "Morality", "Low Fuel"
};

// Multidimensional array: [Year][Universe]
string otherData[NUM_HEROES][2] = {
    {"1992", "Marvel"}, {"1989", "DC"}, {"1986", "Other"}, {"1962", "DC"},
    {"1977", "DC"}, {"1963", "DC"}, {"1989", "Marvel"}, {"1966", "DC"},
    {"1996", "DC"}, {"1977", "Marvel"}
};

// Function prototypes
void displayMenu();
void searchByName();
void searchByPower();
void sortHeroes();
void displayFormatted(bool toUpper);

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: searchByName(); break;
            case 2: searchByPower(); break;
            case 3: sortHeroes(); break;
            case 4: displayFormatted(true); break;
            case 5: displayFormatted(false); break;
            case 6: cout << "Exiting program. Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n"; break;
        }

    } while (choice != 6);

    return 0;
}

void displayMenu() {
    cout << "\n===== Obscure Superhero Database =====\n";
    cout << "1. Search by Name\n";
    cout << "2. Search by Superpower\n";
    cout << "3. Sort Alphabetically\n";
    cout << "4. Display All in UPPERCASE\n";
    cout << "5. Display All in lowercase\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

void searchByName() {
    string input;
    cout << "Enter superhero name to search: ";
    getline(cin, input);

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    bool found = false;
    for (int i = 0; i < NUM_HEROES; i++) {
        string nameLower = names[i];
        transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
        if (nameLower.find(input) != string::npos) {
            cout << "\nFound: " << names[i] << "\nSuperpower: " << superpowers[i]
                 << "\nWeakness: " << weaknesses[i] << "\nYear: " << otherData[i][0]
                 << "\nUniverse: " << otherData[i][1] << "\n";
            found = true;
        }
    }
    if (!found) cout << "No superhero found with that name.\n";
}

void searchByPower() {
    string input;
    cout << "Enter superpower to search: ";
    getline(cin, input);

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    bool found = false;
    for (int i = 0; i < NUM_HEROES; i++) {
        string powerLower = superpowers[i];
        transform(powerLower.begin(), powerLower.end(), powerLower.begin(), ::tolower);
        if (powerLower.find(input) != string::npos) {
            cout << "\nFound: " << names[i] << "\nSuperpower: " << superpowers[i]
                 << "\nWeakness: " << weaknesses[i] << "\nYear: " << otherData[i][0]
                 << "\nUniverse: " << otherData[i][1] << "\n";
            found = true;
        }
    }
    if (!found) cout << "No superhero found with that superpower.\n";
}

void sortHeroes() {
    for (int i = 0; i < NUM_HEROES - 1; i++) {
        for (int j = i + 1; j < NUM_HEROES; j++) {
            if (names[i] > names[j]) {
                swap(names[i], names[j]);
                swap(superpowers[i], superpowers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(otherData[i][0], otherData[j][0]); // Year
                swap(otherData[i][1], otherData[j][1]); // Universe
            }
        }
    }
    cout << "Heroes sorted alphabetically.\n";
}

void displayFormatted(bool toUpper) {
    for (int i = 0; i < NUM_HEROES; i++) {
        string name = names[i], power = superpowers[i], weak = weaknesses[i], year = otherData[i][0], universe = otherData[i][1];

        if (toUpper) {
            transform(name.begin(), name.end(), name.begin(), ::toupper);
            transform(power.begin(), power.end(), power.begin(), ::toupper);
            transform(weak.begin(), weak.end(), weak.begin(), ::toupper);
            transform(universe.begin(), universe.end(), universe.begin(), ::toupper);
        } else {
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            transform(power.begin(), power.end(), power.begin(), ::tolower);
            transform(weak.begin(), weak.end(), weak.begin(), ::tolower);
            transform(universe.begin(), universe.end(), universe.begin(), ::tolower);
        }

        cout << "\n" << name << "\nSuperpower: " << power
             << "\nWeakness: " << weak << "\nYear: " << year
             << "\nUniverse: " << universe << "\n";
    }
}
