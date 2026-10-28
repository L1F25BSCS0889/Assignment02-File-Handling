
/*
 * Name       : Momina
 * Reg No     : L1f25bscs0889
 * Assignment : 02 - File Handling
 * Question   : Q2 - Parking Report
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream inFile("parking.txt");
    if (!inFile.is_open()) {
        cout << "parking.txt not found!";
        return 0;
    }
    int d, m, y;
    char slash;
    inFile >> d >> slash >> m >> slash >> y;
    inFile.ignore(100, '\n');
    inFile.ignore(100, '\n');
    cout << "Parking report for " << d << "/" << m << "/" << y << endl;
    ofstream outFile("receipts.txt");
    outFile << "Receipts for " << d << "/" << m << "/" << y << endl;
    char plate[15];
    char longestPlate[15];
    char type;
    char inTime[6], outTime[6];
    int vehicles = 0;
    int cars = 0;
    int bikes = 0;
    int totalCollected = 0;
    int longestMinutes = -1;
    while (inFile >> plate >> type >> inTime >> outTime) {
        int inHour = (inTime[0] - '0') * 10
            + (inTime[1] - '0');
        int inMin = (inTime[3] - '0') * 10
            + (inTime[4] - '0');

        int outHour = (outTime[0] - '0') * 10
            + (outTime[1] - '0');
        int outMin = (outTime[3] - '0') * 10
            + (outTime[4] - '0');
        int start = inHour * 60 + inMin;
        int finish = outHour * 60 + outMin;
        int minutes = finish - start;
        int hoursCharged = (minutes + 59) / 60;
        if (hoursCharged == 0){
            hoursCharged = 1;
        }
        int fee;
        if (type == 'C') {
            fee = hoursCharged * 100;
            cars++;
        }
        else {
            fee = hoursCharged * 40;
            bikes++;
        }
        int actualHours = minutes / 60;
        int actualMinutes = minutes % 60;
        cout << plate << " ";

        if (type == 'C')
        {
            cout << "Car ";
        }
        else
        {
            cout << "Bike ";
        }
        cout << actualHours << " h "
            << actualMinutes << " min Fee: "
            << fee << endl;
        outFile << plate << " " << fee << endl;
        vehicles++;
        totalCollected += fee;
        if (minutes > longestMinutes) {
            longestMinutes = minutes;
            int i = 0;
            while (plate[i] != '\0') {
                longestPlate[i] = plate[i];
                i++;
            }
            longestPlate[i] = '\0';
        }
    }
    if (vehicles == 0){
        cout << "No vehicles found!";
        inFile.close();
        outFile.close();
        return 0;
    }
    cout << "Vehicles: " << vehicles << endl;
    cout << "Cars: " << cars << " Bikes: " << bikes << endl;
    cout << "Total collected: " << totalCollected << endl;
    cout << "Longest stay: " << longestPlate << " ("
        << longestMinutes / 60 << " h "
        << longestMinutes % 60 << " min)" << endl;
    inFile.close();
    outFile.close();
    return 0;
}
