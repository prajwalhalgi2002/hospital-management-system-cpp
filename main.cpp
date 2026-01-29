#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

class Patient {
    string name, address, bloodGroup;
public:
    void input() {
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Address: "; cin >> address;
        cout << "Enter Blood Group: "; cin >> bloodGroup;
    }
    void save() {
        ofstream file("patients.txt", ios::app);
        file << name << "," << address << "," << bloodGroup << endl;
    }
};

class Doctor {
    string name, specialization;
public:
    void input() {
        cout << "Enter Doctor Name: "; cin >> name;
        cout << "Enter Specialization: "; cin >> specialization;
    }
    void save() {
        ofstream file("doctors.txt", ios::app);
        file << name << "," << specialization << endl;
    }
};

map<string, string> appointments;

void bookAppointment() {
    string patient, doctor, date;
    cout << "Patient Name: "; cin >> patient;
    cout << "Doctor Name: "; cin >> doctor;
    cout << "Date (YYYY-MM-DD): "; cin >> date;
    string key = doctor + "_" + date;
    if (appointments[key].empty()) {
        appointments[key] = patient;
        cout << "Appointment Booked!\n";
    } else {
        cout << "Doctor already booked!\n";
    }
}

int main() {
    int choice;
    Patient p;
    Doctor d;

    while (true) {
        cout << "\nHospital Management System\n";
        cout << "1. Add Patient\n2. Add Doctor\n3. Book Appointment\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            p.input();
            p.save();
        }
        else if (choice == 2) {
            d.input();
            d.save();
        }
        else if (choice == 3) {
            bookAppointment();
        }
        else if (choice == 4) break;
    }
    return 0;
}
