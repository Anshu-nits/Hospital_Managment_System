#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

// Base Class: Person
class Person {
protected:
    string Name, Address;

public:
    Person(): Name(""), Address("") {}

    void setName(string name) {
        Name = name;
    }

    void setAddress(string address) {
        Address = address;
    }

    string getName() {
        return Name;
    }

    string getAddress() {
        return Address;
    }
};

// Derived Class: NormalPatient
class NormalPatient : public Person {
private:
    string BGroup;

public:
    NormalPatient(): Person(), BGroup("") {}

    void setBGroup(string group) {
        BGroup = group;
    }

    string getBGroup() {
        return BGroup;
    }

    void admit() {
        system("cls");
        string name, address, group;

        cout << "\tEnter Name of Patient: ";
        cin >> name;
        setName(name);

        cout << "\tEnter Address of Patient: ";
        cin >> address;
        setAddress(address);

        cout << "\tEnter Blood Group of Patient: ";
        cin >> group;
        setBGroup(group);

        ofstream outfile("Hospital.txt", ios::app);
        if (!outfile) {
            cout << "\tError: File Can't Open!" << endl;
        } else {
            outfile << "\t" << getName() << " : " << getAddress() << " : " << getBGroup() << endl << endl;
            cout << "\tNormal Patient Admitted!" << endl;
        }
        outfile.close();
        Sleep(3000);
    }
};

// Derived Class: EmergencyPatient
class EmergencyPatient : public Person {
private:
    string BGroup;
    string contactNumber;

public:
    EmergencyPatient(): Person(), BGroup(""), contactNumber("") {}

    void setBGroup(string group) {
        BGroup = group;
    }

    string getBGroup() {
        return BGroup;
    }

    void setContactNumber(string number) {
        contactNumber = number;
    }

    string getContactNumber() {
        return contactNumber;
    }

    void admit() {
        system("cls");
        string name, address, group, contact;

        cout << "\tEnter Name of Patient: ";
        cin >> name;
        setName(name);

        cout << "\tEnter Address of Patient: ";
        cin >> address;
        setAddress(address);

        cout << "\tEnter Blood Group of Patient: ";
        cin >> group;
        setBGroup(group);

        cout << "\tEnter Contact Number for Emergency: ";
        cin >> contact;
        setContactNumber(contact);

        ofstream outfile("Hospital.txt", ios::app);
        if (!outfile) {
            cout << "\tError: File Can't Open!" << endl;
        } else {
            outfile << "\t" << getName() << " : " << getAddress() << " : " << getBGroup() << " : " << getContactNumber() << endl << endl;
            cout << "\tEmergency Patient Admitted!" << endl;
        }
        outfile.close();
        Sleep(3000);
    }
};

// Function to discharge a patient
void discharge() {
    system("cls");
    string name;
    cout << "\tEnter Name of Patient: ";
    cin >> name;

    ifstream infile("Hospital.txt");
    ofstream outfile("Hospital Temp.txt");
    if (!infile || !outfile) {
        cout << "\tError: File Can't Open!" << endl;
    } else {
        string line;
        bool found = false;

        while (getline(infile, line)) {
            stringstream ss;
            ss << line;
            string patientName;
            ss >> patientName;
            if (name == patientName) {
                found = true;
                cout << "\tPatient Discharged!" << endl;
            } else {
                outfile << line << endl;
            }
        }
        if (!found) {
            cout << "\tIncorrect Name!" << endl;
        }
    }
    outfile.close();
    infile.close();
    remove("Hospital.txt");
    rename("Hospital Temp.txt", "Hospital.txt");
    Sleep(3000);
}

// Main function
int main() {
    bool exit = false;
    while (!exit) {
        system("cls");
        int val;
        cout << "\tHospital Management System" << endl;
        cout << "\t**********" << endl;
        cout << "\t1. Admit Normal Patient." << endl;
        cout << "\t2. Admit Emergency Patient." << endl;
        cout << "\t3. Discharge Patient." << endl;
        cout << "\t4. Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            NormalPatient normalPatient;
            normalPatient.admit();  // Admit a normal patient
        } else if (val == 2) {
            EmergencyPatient emergencyPatient;
            emergencyPatient.admit();  // Admit an emergency patient
        } else if (val == 3) {
            discharge();  // Discharge a patient
        } else if (val == 4) {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(3000);
        }
        Sleep(5000);
    }
}
