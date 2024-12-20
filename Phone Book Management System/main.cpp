#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class PhoneBook
{
private:
    string Name;
    string Phone_Number;
    string Address;

public:
    // Default constructor
    PhoneBook() : Name(""), Phone_Number(""), Address("") {}

    // Setters and Getters
    void setName(string Name)
    {
        this->Name = Name;
    }

    string getName()
    {
        return Name;
    }

    void setPhoneNumber(string Phone_Number)
    {
        this->Phone_Number = Phone_Number;
    }

    string getPhoneNumber()
    {
        return Phone_Number;
    }

    void setAddress(string Address)
    {
        this->Address = Address;
    }

    string getAddress()
    {
        return Address;
    }
};

// Add a new contact to the phonebook
void add_Number(PhoneBook &phone)
{
    system("cls");
    string Name;
    string Phone_Number;
    string Address;

    cout << "Enter Name of User: " << endl;
    cin.ignore(); // To clear the buffer
    getline(cin, Name);
    phone.setName(Name);

    cout << "Enter Phone Number: " << endl;
    getline(cin, Phone_Number);
    phone.setPhoneNumber(Phone_Number);

    cout << "Enter Address of User: " << endl;
    getline(cin, Address);
    phone.setAddress(Address);

    ofstream outfile("PhoneBook.txt", ios::app);
    if (!outfile)
    {
        cout << "Error: File can't open." << endl;
    }
    else
    {
        outfile << phone.getName() << " : " << phone.getPhoneNumber() << " : " << phone.getAddress() << endl;
        cout << "Contact added successfully!" << endl;
    }
    outfile.close();
    Sleep(3000); // Pause for 3 seconds
}

Search_Number()
{
    system("cls");
    string name;
    cout << "Enter Your Name" << endl;
    cin >> name;

    ifstream infile("PhoneBook.txt");

    if (!infile)
    {
        cout << "Error : File Can't Open" << endl;
    }
    else
    {
        string line;
        bool found = false;

        while (getline(infile, line))
        {
            stringstream lilawat;
            lilawat << line;
            string userName;
            string UserPhoneNumber;
            string UserAddress;

            char delimiter;
            lilawat >> userName >> delimiter >> UserPhoneNumber >> delimiter >> UserAddress >> delimiter;

            if (name == userName)
            {
               found = true;
               cout <<"\t" << userName << " " << UserPhoneNumber << UserAddress << endl;
            }
            
        }
        if (!found)
        {
           cout << "User not found : " << endl;
        }

        
    }
    infile.close();
    Sleep(5000);
}

int main()
{
    PhoneBook phone;

    bool exit = false;
    while (!exit)
    {
        system("cls");
        int val;

        cout << "Welcome to Phone Book Management System" << endl;
        cout << "*****************************************" << endl;
        cout << "1. Add a Number" << endl;
        cout << "2. Search a Number" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Your Choice: " << endl;
        cin >> val;

        if (val == 1)
        {
            add_Number(phone);
        }
        else if (val == 2)
        {
Search_Number();
            // Placeholder for Search functionality
            // cout << "Search functionality not implemented yet." << endl;
            Sleep(3000);
        }
        else if (val == 3)
        {

            exit = true;
            cout << "Exiting the program. Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid choice. Try again!" << endl;
            Sleep(2000);
        }
    }

    return 0;
}
