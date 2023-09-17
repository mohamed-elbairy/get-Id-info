#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IDParser {
private:
    string id;

    // A map for governorate codes
    static const vector<pair<string, string>> governorateMap;

    // Function to validate the ID length and check for valid characters
    bool isValidID() const {
        if (id.length() != 14) {
            return false;
        }
        for (char c : id) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    // Function to extract the birth city from the ID
    string extractCity() const {
        string index = id.substr(7, 2);
        for (const auto& entry : governorateMap) {
            if (entry.second == index) {
                return entry.first;
            }
        }
        return "Unknown City";
    }

    // Function to extract the birthdate from the ID
    string extractBirthdate() const {
        string yearIndex = id.substr(1, 2);
        string monthIndex = id.substr(3, 2);
        string dayIndex = id.substr(5, 2);
        return "Birth Date: " + dayIndex + "/" + monthIndex + "/" + yearIndex;
    }

    // Function to extract gender from the ID
    string extractGender() const {
        int genderDigit = id[12] - '0'; // Convert the character to an integer
        return (genderDigit % 2 == 1) ? "Male" : "Female";
    }

public:
    IDParser(const string& inputID) : id(inputID) {}

    // Function to display the parsed information based on user choice
    void displayInfo(int choice) {
        if (!isValidID()) {
            cout << "Invalid ID" << endl;
            return;
        }

        switch (choice) {
        case 1:
            cout << extractBirthdate() << endl;
            break;
        case 2:
            cout << "Birth City: " << extractCity() << endl;
            break;
        case 3:
            cout << "Gender: " << extractGender() << endl;
            break;
        case 4:
            cout << extractBirthdate() << endl;
            cout << "Birth City: " << extractCity() << endl;
            cout << "Gender: " << extractGender() << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
};

// Initialize the governorate code map
const vector<pair<string, string>> IDParser::governorateMap = {

          {"Cairo","01"}
         ,{"Alex","02"}
         ,{"Portsaid","03"}
         ,{"Suaze","04"}
         ,{"Domiata","11"}
         ,{"Dakahlia","12"}
         ,{"Sharkia","13"}
         ,{"Qaliubbia","14"}
         ,{"kafr Elshaikh","15"}
         ,{"Gharbia","16"}
         ,{"Monofia","17"}
         ,{"AL Bahaira","18"}
         ,{"Ismalia","19"}
         ,{"Giza","21"}
         ,{"Bani Swif","22"}
         ,{"Fayom","23"}
         ,{"Minia","24"}
         ,{"Assiut","25"}
         ,{"Sohag","26"}
         ,{"Qina","27"}
         ,{"Aswan","28"}
         ,{"Aqsor","29"}
         ,{"Read Sea","31"}
         ,{"New Vally","32"}
         ,{"Nourth Of Sina","33"}
         ,{"South Of Sina","35"}
         ,{"Born abroad","88"} };

int main() {
    string inputID;
    cout << "Enter Your ID Number: ";
    cin >> inputID;

    IDParser parser(inputID);

    int choice;
    cout << "Choose an option:" << endl;
    cout << "1) Birth Date" << endl;
    cout << "2) Birth City" << endl;
    cout << "3) Gender" << endl;
    cout << "4) All" << endl;
    cin >> choice;

    parser.displayInfo(choice);

    return 0;
}
