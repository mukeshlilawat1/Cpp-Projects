#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <vector>

using namespace std;

class Airline
{
private:
    string Flight;
    string Destination;
    string Dep;
    int seats;

public:
    Airline(string Flight, string Destination, string Dep, int seats)
    {
        this->Flight = Flight;
        this->Destination = Destination;
        this->Dep = Dep;
        this->seats = seats;
    }

    string GetFlight()
    {
        return Flight;
    }

    string GetDestination()
    {
        return Destination;
    }

    string GetDep()
    {
        return Dep;
    }

    int GetSeats()
    {
        return seats;
    }

    void update(string Flight)
    {
        ifstream in("flight.txt");
        ofstream out("flight_temp.txt");

        string line;

        while (getline(in, line))
        {
            int pos = line.find(Flight);
            if (pos != string::npos)
            {
                int current = seats - 1;
                seats = current;
                stringstream code;
                code << current;
                string strCurrent = code.str();

                int seatPosition = line.find_last_of(':');
                line.replace(seatPosition + 2, string::npos, strCurrent);
            }
            out << line << endl;
        }
        out.close();
        in.close();
        remove("flight.txt");
        rename("flight_temp.txt", "flight.txt");
        cout << "Seat is Reserved Successfully" << endl;
    }

    void cancel(string Flight)
    {
        ifstream in("flight.txt");
        ofstream out("flight_temp.txt");

        string line;

        while (getline(in, line))
        {
            int pos = line.find(Flight);
            if (pos != string::npos)
            {
                int current = seats + 1;
                seats = current;
                stringstream code;
                code << current;
                string strCurrent = code.str();

                int seatPosition = line.find_last_of(':');
                line.replace(seatPosition + 2, string::npos, strCurrent);
            }
            out << line << endl;
        }
        out.close();
        in.close();
        remove("flight.txt");
        rename("flight_temp.txt", "flight.txt");
        cout << "Reservation Cancelled Successfully" << endl;
    }
};

void display()
{
    ifstream in("flight.txt");
    if (!in)
    {
        cout << "Error : File Not Opened " << endl;
    }
    else
    {
        string line;
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
}

void searchByDestination()
{
    string dest;
    cout << "Enter Destination to Search Flights: ";
    cin >> dest;

    ifstream in("flight.txt");
    if (!in)
    {
        cout << "Error : File Not Opened " << endl;
    }
    else
    {
        string line;
        bool found = false;
        while (getline(in, line))
        {
            if (line.find(dest) != string::npos)
            {
                cout << line << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No Flights Found for Destination: " << dest << endl;
        }
    }
}

void addFlight()
{
    string flight, destination, departure;
    int seats;

    cout << "Enter Flight Number: ";
    cin >> flight;
    cout << "Enter Destination: ";
    cin >> destination;
    cout << "Enter Departure: ";
    cin >> departure;
    cout << "Enter Number of Seats: ";
    cin >> seats;

    ofstream out("flight.txt", ios::app);
    if (!out)
    {
        cout << "Error : Unable to Open File!" << endl;
    }
    else
    {
        out << flight << " : " << destination << " : " << departure << " : " << seats << endl;
        cout << "Flight Added Successfully!" << endl;
    }
    out.close();
}

int main()
{
    Airline Indigo("F10201", "USA", "UK", 50);
    Airline Indigo1("F102091", "UAE", "Israel", 60);
    Airline Indigo2("F102081", "UK", "Russia", 70);

    ofstream out("flight.txt");

    if (!out)
    {
        cout << "Error : this file does Not open!" << endl;
    }
    else
    {
        out << Indigo.GetFlight() << " : " << Indigo.GetDestination() << " : " << Indigo.GetDep() << " : " << Indigo.GetSeats() << endl;
        out << Indigo1.GetFlight() << " : " << Indigo1.GetDestination() << " : " << Indigo1.GetDep() << " : " << Indigo1.GetSeats() << endl;
        out << Indigo2.GetFlight() << " : " << Indigo2.GetDestination() << " : " << Indigo2.GetDep() << " : " << Indigo2.GetSeats() << endl;

        cout << "Data IS Successfully Saved ;) " << endl;
        out.close();
    }

    bool exit = false;
    while (!exit)
    {
        system("Cls");
        cout << "Welcome TO Airline Management System : " << endl;
        cout << "------------*************------------- " << endl;
        cout << "1. Reserve a Seat : " << endl;
        cout << "2. Cancel Reservation : " << endl;
        cout << "3. Search Flights by Destination : " << endl;
        cout << "4. Add a New Flight (Admin): " << endl;
        cout << "5. Display All Flights : " << endl;
        cout << "6. Exit " << endl;
        cout << "Enter Your Choice : ";

        int val;
        cin >> val;

        if (val == 1)
        {
            system("cls");
            display();

            string flight;
            cout << "Enter Your Flight Number : ";
            cin >> flight;

            if (flight == Indigo.GetFlight() && Indigo.GetSeats() > 0)
            {
                Indigo.update(flight);
            }
            else if (flight == Indigo1.GetFlight() && Indigo1.GetSeats() > 0)
            {
                Indigo1.update(flight);
            }
            else if (flight == Indigo2.GetFlight() && Indigo2.GetSeats() > 0)
            {
                Indigo2.update(flight);
            }
            else
            {
                cout << "Sorry, Seats are Not Available or Invalid Flight Number!" << endl;
            }
            Sleep(3000);
        }
        else if (val == 2)
        {
            system("cls");
            display();

            string flight;
            cout << "Enter Your Flight Number to Cancel Reservation: ";
            cin >> flight;

            if (flight == Indigo.GetFlight())
            {
                Indigo.cancel(flight);
            }
            else if (flight == Indigo1.GetFlight())
            {
                Indigo1.cancel(flight);
            }
            else if (flight == Indigo2.GetFlight())
            {
                Indigo2.cancel(flight);
            }
            else
            {
                cout << "Invalid Flight Number!" << endl;
            }
            Sleep(3000);
        }
        else if (val == 3)
        {
            system("cls");
            searchByDestination();
            Sleep(3000);
        }
        else if (val == 4)
        {
            system("cls");
            addFlight();
            Sleep(3000);
        }
        else if (val == 5)
        {
            system("cls");
            display();
            Sleep(3000);
        }
        else if (val == 6)
        {
            system("cls");
            exit = true;
            cout << "Good Luck!" << endl;
            Sleep(3000);
        }
        else
        {
            cout << "Invalid Choice! Please try again." << endl;
            Sleep(2000);
        }
    }
    return 0;
}
