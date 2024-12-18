#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

class Patient {
    int id;
    std::string name;
    int age;
    std::string disease;

public:
    Patient(int id = 0, std::string name = "", int age = 0, std::string disease = "")
        : id(id), name(name), age(age), disease(disease) {}

    void inputPatientDetails() {
        std::cout << "Enter Patient ID: ";
        std::cin >> id;
        std::cin.ignore();
        std::cout << "Enter Patient Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Age: ";
        std::cin >> age;
        std::cin.ignore();
        std::cout << "Enter Disease: ";
        std::getline(std::cin, disease);
    }

    void displayPatientDetails() const {
        std::cout << "\nID: " << id
                  << "\nName: " << name
                  << "\nAge: " << age
                  << "\nDisease: " << disease << "\n";
    }

    int getId() const { return id; }

    void saveToFile(std::ofstream &outFile) const {
        outFile << id << "," << name << "," << age << "," << disease << "\n";
    }

    void loadFromFile(std::ifstream &inFile) {
        char delimiter;
        inFile >> id >> delimiter;
        std::getline(inFile, name, ',');
        inFile >> age >> delimiter;
        std::getline(inFile, disease);
    }
};

class Doctor {
    int id;
    std::string name;
    std::string specialization;

public:
    Doctor(int id = 0, std::string name = "", std::string specialization = "")
        : id(id), name(name), specialization(specialization) {}

    void inputDoctorDetails() {
        std::cout << "Enter Doctor ID: ";
        std::cin >> id;
        std::cin.ignore();
        std::cout << "Enter Doctor Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Specialization: ";
        std::getline(std::cin, specialization);
    }

    void displayDoctorDetails() const {
        std::cout << "\nID: " << id
                  << "\nName: " << name
                  << "\nSpecialization: " << specialization << "\n";
    }

    int getId() const { return id; }

    void saveToFile(std::ofstream &outFile) const {
        outFile << id << "," << name << "," << specialization << "\n";
    }

    void loadFromFile(std::ifstream &inFile) {
        char delimiter;
        inFile >> id >> delimiter;
        std::getline(inFile, name, ',');
        std::getline(inFile, specialization);
    }
};

class Appointment {
    int appointmentId;
    int patientId;
    int doctorId;
    std::string date;

public:
    Appointment(int appointmentId = 0, int patientId = 0, int doctorId = 0, std::string date = "")
        : appointmentId(appointmentId), patientId(patientId), doctorId(doctorId), date(date) {}

    void inputAppointmentDetails() {
        std::cout << "Enter Appointment ID: ";
        std::cin >> appointmentId;
        std::cout << "Enter Patient ID: ";
        std::cin >> patientId;
        std::cout << "Enter Doctor ID: ";
        std::cin >> doctorId;
        std::cin.ignore();
        std::cout << "Enter Appointment Date (YYYY-MM-DD): ";
        std::getline(std::cin, date);
    }

    void displayAppointmentDetails() const {
        std::cout << "\nAppointment ID: " << appointmentId
                  << "\nPatient ID: " << patientId
                  << "\nDoctor ID: " << doctorId
                  << "\nDate: " << date << "\n";
    }

    void saveToFile(std::ofstream &outFile) const {
        outFile << appointmentId << "," << patientId << "," << doctorId << "," << date << "\n";
    }

    void loadFromFile(std::ifstream &inFile) {
        char delimiter;
        inFile >> appointmentId >> delimiter;
        inFile >> patientId >> delimiter;
        inFile >> doctorId >> delimiter;
        std::getline(inFile, date);
    }
};

std::vector<Patient> patientRecords;
std::vector<Doctor> doctorRecords;
std::vector<Appointment> appointmentRecords;

void addPatient() {
    Patient p;
    p.inputPatientDetails();
    patientRecords.push_back(p);
    std::cout << "Patient record added successfully!\n";
}

void viewPatients() {
    if (patientRecords.empty()) {
        std::cout << "No patient records found.\n";
        return;
    }

    for (const auto &p : patientRecords) {
        p.displayPatientDetails();
    }
}

void savePatientsToFile() {
    std::ofstream outFile("patients.txt");
    for (const auto &p : patientRecords) {
        p.saveToFile(outFile);
    }
    outFile.close();
    std::cout << "Patient records saved to file successfully!\n";
}

void loadPatientsFromFile() {
    std::ifstream inFile("patients.txt");
    if (!inFile) {
        std::cout << "No existing patient records file found.\n";
        return;
    }

    patientRecords.clear();
    while (inFile.peek() != EOF) {
        Patient p;
        p.loadFromFile(inFile);
        patientRecords.push_back(p);
    }
    inFile.close();
    std::cout << "Patient records loaded from file successfully!\n";
}

void addDoctor() {
    Doctor d;
    d.inputDoctorDetails();
    doctorRecords.push_back(d);
    std::cout << "Doctor record added successfully!\n";
}

void viewDoctors() {
    if (doctorRecords.empty()) {
        std::cout << "No doctor records found.\n";
        return;
    }

    for (const auto &d : doctorRecords) {
        d.displayDoctorDetails();
    }
}

void saveDoctorsToFile() {
    std::ofstream outFile("doctors.txt");
    for (const auto &d : doctorRecords) {
        d.saveToFile(outFile);
    }
    outFile.close();
    std::cout << "Doctor records saved to file successfully!\n";
}

void loadDoctorsFromFile() {
    std::ifstream inFile("doctors.txt");
    if (!inFile) {
        std::cout << "No existing doctor records file found.\n";
        return;
    }

    doctorRecords.clear();
    while (inFile.peek() != EOF) {
        Doctor d;
        d.loadFromFile(inFile);
        doctorRecords.push_back(d);
    }
    inFile.close();
    std::cout << "Doctor records loaded from file successfully!\n";
}

void addAppointment() {
    Appointment a;
    a.inputAppointmentDetails();
    appointmentRecords.push_back(a);
    std::cout << "Appointment record added successfully!\n";
}

void viewAppointments() {
    if (appointmentRecords.empty()) {
        std::cout << "No appointment records found.\n";
        return;
    }

    for (const auto &a : appointmentRecords) {
        a.displayAppointmentDetails();
    }
}

void saveAppointmentsToFile() {
    std::ofstream outFile("appointments.txt");
    for (const auto &a : appointmentRecords) {
        a.saveToFile(outFile);
    }
    outFile.close();
    std::cout << "Appointment records saved to file successfully!\n";
}

void loadAppointmentsFromFile() {
    std::ifstream inFile("appointments.txt");
    if (!inFile) {
        std::cout << "No existing appointment records file found.\n";
        return;
    }

    appointmentRecords.clear();
    while (inFile.peek() != EOF) {
        Appointment a;
        a.loadFromFile(inFile);
        appointmentRecords.push_back(a);
    }
    inFile.close();
    std::cout << "Appointment records loaded from file successfully!\n";
}

void showMainMenu() {
    std::cout << "\n--- Hospital Management System ---\n";
    std::cout << "1. Add Patient\n";
    std::cout << "2. View Patients\n";
    std::cout << "3. Save Patients to File\n";
    std::cout << "4. Load Patients from File\n";
    std::cout << "5. Add Doctor\n";
    std::cout << "6. View Doctors\n";
    std::cout << "7. Save Doctors to File\n";
    std::cout << "8. Load Doctors from File\n";
    std::cout << "9. Add Appointment\n";
    std::cout << "10. View Appointments\n";
    std::cout << "11. Save Appointments to File\n";
    std::cout << "12. Load Appointments from File\n";
    std::cout << "13. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        showMainMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            addPatient();
            break;
        case 2:
            viewPatients();
            break;
        case 3:
            savePatientsToFile();
            break;
        case 4:
            loadPatientsFromFile();
            break;
        case 5:
            addDoctor();
            break;
        case 6:
            viewDoctors();
            break;
        case 7:
            saveDoctorsToFile();
            break;
        case 8:
            loadDoctorsFromFile();
            break;
        case 9:
            addAppointment();
            break;
        case 10:
            viewAppointments();
            break;
        case 11:
            saveAppointmentsToFile();
            break;
        case 12:
            loadAppointmentsFromFile();
            break;
        case 13:
            std::cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 13);

    return 0;
}
