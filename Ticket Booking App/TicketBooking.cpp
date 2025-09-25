#include <iostream>
#include <mysql.h>          // Assuming the MySQL C API header is mysql.h in your include path
#include <mysql_error.h>
#include <Windows.h>
#include <sstream>

using namespace std;

const char *Host = "localhost";
const char *User = "root";
const char *Password = "12150";
const char *Database = "mydb";

class Theater
{
private:
    int Seat[10][10];

public:
    Theater()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                Seat[i][j] = 1;
            }
        }
    }

    int GetSeatStatus(int row, int Seat_Number)
    {
        if (row < 1 || row > 10 || Seat_Number < 1 || Seat_Number > 10)
        {
            return -1;
        }
        return Seat[row - 1][Seat_Number - 1];
    }

    void ReserveSeat(int row, int Seat_Number)
    {
        if (row < 1 || row > 10 || Seat_Number < 1 || Seat_Number > 10)
        {
            return;
        }
        Seat[row - 1][Seat_Number - 1] = 0;
    }

    void display()
    {
        cout << "  ";
        for (int i = 0; i < 10; i++)
        {
            cout << " " << i + 1;
        }
        cout << endl;

        for (int rows = 0; rows < 10; rows++)
        {
            cout << rows + 1 << " ";
            for (int columns = 0; columns < 10; columns++)
            {
                if (Seat[rows][columns] == 1)
                {
                    cout << "- ";
                }
                else
                {
                    cout << "X ";
                }
            }
            cout << " |" << endl;
        }
        cout << "----------------------" << endl;
    }
};

int main(int argc, char const *argv[])
{
    MYSQL *connection;
    connection = mysql_init(NULL);

    if (!mysql_real_connect(connection, Host, User, Password, Database, 3306, NULL, 0))
    {
        cout << "Error : " << mysql_error(connection) << endl;
    }
    else
    {
        cout << "Logged In Database !" << endl;
    }

    Sleep(3000);

    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS Ticket(RowNumber INT, SeatNumber INT, Seat INT)")) {
        cout << "Error : " << mysql_error(conn) << endl;
    }

    for(int row=1; row <= 10; row++) {
        for(int seatNumber = 1; seatNumber <= 10; seatNumber++) {
            stringstream s;
            s <<"INSERT INTO Ticket (RowNumber, SeatNumber, Seat)" <<
             " SELECT '"<< row << " ', '"<<seatNumber
             <<"', '1'" << "WHERE NOT EXISTS (SELECT * FROM Ticket WHERE RowNumber = '"
             << row"' AND SeatNumber = '"<<seatNumber<<"')";
        }
    }
    

    return 0;
}
