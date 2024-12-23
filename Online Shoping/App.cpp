#include <iostream>
using namespace std;

float onlineShopping()
{
    char choice;
    int item;
    int quantity;
    float billAmount = 0;
    cout << "************* Welcome to Online Shopping ***************" << endl;
    cout << "-------------------- Follow the Instructions ------------" << endl;
    cout << "1. Enter 'm' to order Mobile Phone" << endl;
    cout << "2. Enter 'l' to order Laptop" << endl;
    cout << "3. Enter 's' to order Speaker" << endl;
    cout << "4. Enter 'e' to order Earbuds" << endl;
    cout << "5. Enter 'p' to order PlayStation" << endl;
    cout << "6. Enter 'd' to order Desktop" << endl;
    cin >> choice;

    if (choice == 'm' || choice == 'M')
    {
    mobileLevel:
        cout << "Mobile Information" << endl;
        cout << "1. Apple -> Price: 50,000" << endl;
        cout << "2. OnePlus -> Price: 40,000" << endl;
        cout << "3. Samsung -> Price: 30,000" << endl;
        cout << "4. Vivo -> Price: 10,000" << endl;

        cin >> item;
        if (item == 1)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 50000;
        }
        else if (item == 2)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 40000;
        }
        else if (item == 3)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 30000;
        }
        else if (item == 4)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 10000;
        }
        else
        {
            cout << "Please enter a correct choice." << endl;
            goto mobileLevel;
        }
    }
    else if (choice == 'l' || choice == 'L')
    {
    laptopLevel:
        cout << "Laptop Information" << endl;
        cout << "1. Dell -> Price: 70,000" << endl;
        cout << "2. HP -> Price: 65,000" << endl;
        cout << "3. Lenovo -> Price: 60,000" << endl;

        cin >> item;
        if (item == 1)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 70000;
        }
        else if (item == 2)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 65000;
        }
        else if (item == 3)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 60000;
        }
        else
        {
            cout << "Please enter a correct choice." << endl;
            goto laptopLevel;
        }
    }
    else if (choice == 's' || choice == 'S')
    {
    speakerLevel:
        cout << "Speaker Information" << endl;
        cout << "1. Bose -> Price: 20,000" << endl;
        cout << "2. JBL -> Price: 15,000" << endl;

        cin >> item;
        if (item == 1)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 20000;
        }
        else if (item == 2)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 15000;
        }
        else
        {
            cout << "Please enter a correct choice." << endl;
            goto speakerLevel;
        }
    }
    else if (choice == 'e' || choice == 'E')
    {
    earbudsLevel:
        cout << "Earbuds Information" << endl;
        cout << "1. Apple -> Price: 10,000" << endl;
        cout << "2. Sony -> Price: 8,000" << endl;

        cin >> item;
        if (item == 1)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 10000;
        }
        else if (item == 2)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 8000;
        }
        else
        {
            cout << "Please enter a correct choice." << endl;
            goto earbudsLevel;
        }
    }
    else if (choice == 'p' || choice == 'P')
    {
    playstationLevel:
        cout << "PlayStation Information" << endl;
        cout << "1. PS5 -> Price: 50,000" << endl;
        cout << "2. PS4 -> Price: 30,000" << endl;

        cin >> item;
        if (item == 1)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 50000;
        }
        else if (item == 2)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 30000;
        }
        else
        {
            cout << "Please enter a correct choice." << endl;
            goto playstationLevel;
        }
    }
    else if (choice == 'd' || choice == 'D')
    {
    desktopLevel:
        cout << "Desktop Information" << endl;
        cout << "1. Dell -> Price: 40,000" << endl;
        cout << "2. HP -> Price: 35,000" << endl;

        cin >> item;
        if (item == 1)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 40000;
        }
        else if (item == 2)
        {
            cout << "Enter Quantity: ";
            cin >> quantity;
            billAmount += quantity * 35000;
        }
        else
        {
            cout << "Please enter a correct choice." << endl;
            goto desktopLevel;
        }
    }
    else
    {
        cout << "Invalid choice. Please restart the program." << endl;
    }
    return billAmount;
}

int main()
{
    char startValue;
    char choiceAgain;

    cout << "Press 'S' to start shopping: ";
Start:
    cin >> startValue;

    if (startValue == 's' || startValue == 'S')
    {
        float totalAmount = onlineShopping();
        cout << "Total Bill Amount: " << totalAmount << endl;
        cout << "Would you like to shop again? (Y/N): ";
    shopAgain:
        cin >> choiceAgain;

        if (choiceAgain == 'y' || choiceAgain == 'Y')
        {
            goto Start;
        }
        else if (choiceAgain == 'n' || choiceAgain == 'N')
        {
            cout << "Thanks for shopping with us!" << endl;
        }
        else
        {
            cout << "Invalid choice. Please enter 'Y' or 'N': ";
            goto shopAgain;
        }
    }
    else
    {
        cout << "Invalid choice. Please enter 'S' to start shopping." << endl;
        goto Start;
    }

    return 0;
}
