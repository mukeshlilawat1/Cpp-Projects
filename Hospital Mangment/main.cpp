#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <ctime>
#include <iomanip>

using namespace std;

class Patient
{
    int patientId;
    string name;
    int age;
    string gender;
    string contact;
    string address;
    string disease;
    string email; // Added email

public:
    Patient(int patientId = 0, string name = "", int age = 0, string gender = "", string contact = "", string address = "", string disease = "", string email = "")
        : patientId(patientId), name(name), age(age), gender(gender), contact(contact), address(address), disease(disease), email(email) {}

    int getPatientId() const { return patientId; }

    void inputPatientDetails()
    {
        cout << "Enter Patient ID: ";
        cin >> patientId;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Gender: ";
        getline(cin, gender);
        cout << "Enter Contact: ";
        getline(cin, contact);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Disease: ";
        getline(cin, disease);
        cout << "Enter Email: "; // Added email input
        getline(cin, email);
    }

    void displayPatientDetails() const
    {
        cout << "\nPatient ID: " << patientId
             << "\nName: " << name
             << "\nAge: " << age
             << "\nGender: " << gender
             << "\nContact: " << contact
             << "\nAddress: " << address
             << "\nDisease: " << disease
             << "\nEmail: " << email << "\n"; // Added email display
    }

    void saveToFile(ofstream &outFile) const
    {
        outFile << patientId << "," << name << "," << age << "," << gender << "," << contact << "," << address << "," << disease << "," << email << "\n";
    }

    void loadFromFile(ifstream &inFile)
    {
        char delimiter;
        inFile >> patientId >> delimiter;
        getline(inFile, name, ',');
        inFile >> age >> delimiter;
        getline(inFile, gender, ',');
        getline(inFile, contact, ',');
        getline(inFile, address, ',');
        getline(inFile, disease, ',');
        getline(inFile, email); // Added loading email
    }
};

class Doctor
{
    int doctorId;
    string name;
    string specialization;
    string contact;
    string email; // Added email

public:
    Doctor(int doctorId = 0, string name = "", string specialization = "", string contact = "", string email = "")
        : doctorId(doctorId), name(name), specialization(specialization), contact(contact), email(email) {}

    int getDoctorId() const { return doctorId; }

    void inputDoctorDetails()
    {
        cout << "Enter Doctor ID: ";
        cin >> doctorId;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Specialization: ";
        getline(cin, specialization);
        cout << "Enter Contact: ";
        getline(cin, contact);
        cout << "Enter Email: "; // Added email input
        getline(cin, email);
    }

    void displayDoctorDetails() const
    {
        cout << "\nDoctor ID: " << doctorId
             << "\nName: " << name
             << "\nSpecialization: " << specialization
             << "\nContact: " << contact
             << "\nEmail: " << email << "\n"; // Added email display
    }

    void saveToFile(ofstream &outFile) const
    {
        outFile << doctorId << "," << name << "," << specialization << "," << contact << "," << email << "\n";
    }

    void loadFromFile(ifstream &inFile)
    {
        char delimiter;
        inFile >> doctorId >> delimiter;
        getline(inFile, name, ',');
        getline(inFile, specialization, ',');
        getline(inFile, contact, ',');
        getline(inFile, email); // Added loading email
    }
};

class Appointment
{
    int appointmentId;
    int patientId;
    int doctorId;
    string date;
    string time;
    string reason;

public:
    Appointment(int appointmentId = 0, int patientId = 0, int doctorId = 0, string date = "", string time = "", string reason = "")
        : appointmentId(appointmentId), patientId(patientId), doctorId(doctorId), date(date), time(time), reason(reason) {}

    int getAppointmentId() const { return appointmentId; }

    void inputAppointmentDetails()
    {
        cout << "Enter Appointment ID: ";
        cin >> appointmentId;
        cin.ignore();
        cout << "Enter Patient ID: ";
        cin >> patientId;
        cout << "Enter Doctor ID: ";
        cin >> doctorId;
        cin.ignore();
        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, date);
        cout << "Enter Time (HH:MM): ";
        getline(cin, time);
        cout << "Enter Reason for Visit: ";
        getline(cin, reason);
    }

    void displayAppointmentDetails() const
    {
        cout << "\nAppointment ID: " << appointmentId
             << "\nPatient ID: " << patientId
             << "\nDoctor ID: " << doctorId
             << "\nDate: " << date
             << "\nTime: " << time
             << "\nReason: " << reason << "\n";
    }

    void saveToFile(ofstream &outFile) const
    {
        outFile << appointmentId << "," << patientId << "," << doctorId << "," << date << "," << time << "," << reason << "\n";
    }

    void loadFromFile(ifstream &inFile)
    {
        char delimiter;
        inFile >> appointmentId >> delimiter;
        inFile >> patientId >> delimiter;
        inFile >> doctorId >> delimiter;
        getline(inFile, date, ',');
        getline(inFile, time, ',');
        getline(inFile, reason);
    }
};

// Function to update patient details
void updatePatientDetails(vector<Patient> &patients)
{
    int id;
    cout << "Enter Patient ID to update: ";
    cin >> id;
    cin.ignore();

    auto it = find_if(patients.begin(), patients.end(), [id](const Patient &p)
                      { return p.getPatientId() == id; });

    if (it != patients.end())
    {
        cout << "Patient found! Updating details...\n";
        it->inputPatientDetails();
    }
    else
    {
        cout << "Patient not found.\n";
    }
}

// Function to update doctor details
void updateDoctorDetails(vector<Doctor> &doctors)
{
    int id;
    cout << "Enter Doctor ID to update: ";
    cin >> id;
    cin.ignore();

    auto it = find_if(doctors.begin(), doctors.end(), [id](const Doctor &d)
                      { return d.getDoctorId() == id; });

    if (it != doctors.end())
    {
        cout << "Doctor found! Updating details...\n";
        it->inputDoctorDetails();
    }
    else
    {
        cout << "Doctor not found.\n";
    }
}

// Function to update appointment details
void updateAppointmentDetails(vector<Appointment> &appointments)
{
    int id;
    cout << "Enter Appointment ID to update: ";
    cin >> id;
    cin.ignore();

    auto it = find_if(appointments.begin(), appointments.end(), [id](const Appointment &a)
                      { return a.getAppointmentId() == id; });

    if (it != appointments.end())
    {
        cout << "Appointment found! Updating details...\n";
        it->inputAppointmentDetails();
    }
    else
    {
        cout << "Appointment not found.\n";
    }
}

// Function to delete patient by ID
void deletePatient(vector<Patient> &patients, int id)
{
    auto it = remove_if(patients.begin(), patients.end(), [id](const Patient &p)
                        { return p.getPatientId() == id; });
    if (it != patients.end())
    {
        patients.erase(it, patients.end());
        cout << "Patient deleted successfully.\n";
    }
    else
    {
        cout << "Patient not found.\n";
    }
}

// Function to delete doctor by ID
void deleteDoctor(vector<Doctor> &doctors, int id)
{
    auto it = remove_if(doctors.begin(), doctors.end(), [id](const Doctor &d)
                        { return d.getDoctorId() == id; });
    if (it != doctors.end())
    {
        doctors.erase(it, doctors.end());
        cout << "Doctor deleted successfully.\n";
    }
    else
    {
        cout << "Doctor not found.\n";
    }
}

// Function to delete appointment by ID
void deleteAppointment(vector<Appointment> &appointments, int id)
{
    auto it = remove_if(appointments.begin(), appointments.end(), [id](const Appointment &a)
                        { return a.getAppointmentId() == id; });
    if (it != appointments.end())
    {
        appointments.erase(it, appointments.end());
        cout << "Appointment deleted successfully.\n";
    }
    else
    {
        cout << "Appointment not found.\n";
    }
}

// Save all data to files
void saveAllData(const vector<Patient> &patients, const vector<Doctor> &doctors, const vector<Appointment> &appointments)
{
    ofstream patientFile("patients.txt");
    ofstream doctorFile("doctors.txt");
    ofstream appointmentFile("appointments.txt");

    if (patientFile.is_open() && doctorFile.is_open() && appointmentFile.is_open())
    {
        for (const auto &patient : patients)
        {
            patient.saveToFile(patientFile);
        }
        for (const auto &doctor : doctors)
        {
            doctor.saveToFile(doctorFile);
        }
        for (const auto &appointment : appointments)
        {
            appointment.saveToFile(appointmentFile);
        }
    }
    else
    {
        cout << "Error opening file for saving data.\n";
    }

    patientFile.close();
    doctorFile.close();
    appointmentFile.close();
}

// Load all data from files
void loadAllData(vector<Patient> &patients, vector<Doctor> &doctors, vector<Appointment> &appointments)
{
    ifstream patientFile("patients.txt");
    ifstream doctorFile("doctors.txt");
    ifstream appointmentFile("appointments.txt");

    if (patientFile.is_open() && doctorFile.is_open() && appointmentFile.is_open())
    {
        Patient patient;
        while (patientFile)
        {
            patient.loadFromFile(patientFile);
            if (patientFile)
                patients.push_back(patient);
        }

        Doctor doctor;
        while (doctorFile)
        {
            doctor.loadFromFile(doctorFile);
            if (doctorFile)
                doctors.push_back(doctor);
        }

        Appointment appointment;
        while (appointmentFile)
        {
            appointment.loadFromFile(appointmentFile);
            if (appointmentFile)
                appointments.push_back(appointment);
        }
    }
    else
    {
        cout << "Error opening file for loading data.\n";
    }

    patientFile.close();
    doctorFile.close();
    appointmentFile.close();
}

// Display all data
void displayAllData(const vector<Patient> &patients, const vector<Doctor> &doctors, const vector<Appointment> &appointments)
{
    cout << "\nLilawat Hospital Management System\n";

    cout << "\nPatients:\n";
    for (const auto &patient : patients)
    {
        patient.displayPatientDetails();
    }

    cout << "\nDoctors:\n";
    for (const auto &doctor : doctors)
    {
        doctor.displayDoctorDetails();
    }

    cout << "\nAppointments:\n";
    for (const auto &appointment : appointments)
    {
        appointment.displayAppointmentDetails();
    }
}

// Main menu for the hospital system
int main()
{
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

    loadAllData(patients, doctors, appointments);

    int choice;
    while (true)
    {
        cout << "\nLilawat Hospital Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Add Appointment\n";
        cout << "4. Update Patient Details\n";
        cout << "5. Update Doctor Details\n";
        cout << "6. Update Appointment Details\n";
        cout << "7. Display All Data\n";
        cout << "8. Save All Data\n";
        cout << "9. Delete Patient\n";
        cout << "10. Delete Doctor\n";
        cout << "11. Delete Appointment\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            Patient p;
            p.inputPatientDetails();
            patients.push_back(p);
            break;
        }
        case 2:
        {
            Doctor d;
            d.inputDoctorDetails();
            doctors.push_back(d);
            break;
        }
        case 3:
        {
            Appointment a;
            a.inputAppointmentDetails();
            appointments.push_back(a);
            break;
        }
        case 4:
            updatePatientDetails(patients);
            break;
        case 5:
            updateDoctorDetails(doctors);
            break;
        case 6:
            updateAppointmentDetails(appointments);
            break;
        case 7:
            displayAllData(patients, doctors, appointments);
            break;
        case 8:
            saveAllData(patients, doctors, appointments);
            cout << "Data saved successfully.\n";
            break;
        case 9:
        {
            int id;
            cout << "Enter Patient ID to delete: ";
            cin >> id;
            deletePatient(patients, id);
            break;
        }
        case 10:
        {
            int id;
            cout << "Enter Doctor ID to delete: ";
            cin >> id;
            deleteDoctor(doctors, id);
            break;
        }
        case 11:
        {
            int id;
            cout << "Enter Appointment ID to delete: ";
            cin >> id;
            deleteAppointment(appointments, id);
            break;
        }
        case 12:
            cout << "Exiting system...\n";
            return 0;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }
}
