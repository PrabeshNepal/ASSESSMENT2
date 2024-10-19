// Assessment2ReadingFilesCreatingObjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


using namespace std;
#include <vector>
#include <string>
#include <iostream>  // For std::cout
#include <fstream>   // For file input/output operations
#include "Vehicle.h" // Custom class for Vehicle objects
#include "Constant.h" // Custom class for Vehicle objects


// ---------------------------------------------------------------------------------------------------------------------  //
// Task 1
class DemandGenerator {
public:


};

class ChargingStation {
public:
    int cityId = 1;
    string cityName = "Sydney";            // Declare string and initialize it 
    int distanceToLastCity = 1;
    int numberOfChargers = 1;
    int distance_to_syd = 0;
    // Constructor to initialize city details
    ChargingStation(int Stationid) {
        if (Stationid >= 0 && Stationid < NUM_CITIES) {
            cityId = Stationid;
            cityName = nameMap[Stationid];  // Correctly reference nameMap from Constant.h
            distanceToLastCity = distanceMap[Stationid];
            numberOfChargers = chargersMap[Stationid];
            

        }
        else {
            // Handle invalid city ID
            cout << "Invalid City ID!" << endl;
        }
    }
    // Display city information
    void displayCityID() const {
        cout << "City ID: " << cityId << endl;
    }
    void displayDistanceToLastCity() const {
        cout << "Distance to Last City: " << distanceToLastCity << " km" << endl;
    }
    void displayNumberOfChargers() const {
        cout << "Number of Chargers: " << numberOfChargers << endl;
    }
    void displayCityName() const {
        cout << "City Name: " << cityName << endl;
    }

    
    // Task 3
    static int displayDistanceToSydney(int cityid_temp) {
        //cityid_temp;
        int distance_to_syd = 0;
        int current_cityId = 0;
        for (int i = current_cityId; i <= cityid_temp; i++) {
            distance_to_syd += distanceMap[i];
        }
        //cout << distance_to_syd;
        return distance_to_syd;
    }


};
// ---------------------------------------------------------------------------------------------------------------------  //


// ---------------------------------------------------------------------------------------------------------------------  //
// Task 2
Vehicle::Vehicle(int vId, int destId, int capRange, int remRange) : vehicleId(vId), destinationId(destId), capacityRange(capRange), remainingRange(remRange) {}// constructor

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle) {
    os << "[" << vehicle.vehicleId << "," << vehicle.destinationId << "," << vehicle.capacityRange << "," << vehicle.remainingRange << "]" << endl;
    return os;  // Return the output stream
}





int Vehicle::getVehicleId() const { return vehicleId; }
int Vehicle::getCurrentCityId() const { return currentCityId; }
int Vehicle::getDestinationId() const { return destinationId; }
int Vehicle::getCapacityRange() const { return capacityRange; }
int Vehicle::getRemainingRange() const { return remainingRange; }

// Setters
void Vehicle::setVehicleId(int vId) { vehicleId = vId; }
void Vehicle::setCurrentCityId(int currCityId) { currentCityId = currCityId; }
void Vehicle::setDestinationId(int destId) { destinationId = destId; }
void Vehicle::setCapacityRange(int capRange) { capacityRange = capRange; }
void Vehicle::setRemainingRange(int remRange) { remainingRange = remRange; }

// Display vehicle information
void Vehicle::displayVehicleInfo() const {

    cout << "[" << vehicleId << "," << destinationId << "," << capacityRange << "," << remainingRange << "]" << "endl";
}



int Vehicle::farCity(int rem) {
   
    int current_city_id = 0;
    int fd_city = 0;
    const int arr[12] = { 0, 57, 117, 200, 286, 385, 500, 562, 636, 723, 829, 891 };

    for (int i = 0; i < 12; i++)
    {
        if (rem > arr[i])
        {
            fd_city = i;
        }
        else if(rem == arr[i])
        {
            fd_city = i;
            break;
        }
        else
        {
            fd_city = i-1;
            break;
        }
        
    }
    return fd_city;
    //cout << fd_city;
}


// ---------------------------------------------------------------------------------------------------------------------  //

// ---------------------------------------------------------------------------------------------------------------------  //
// Task 3






int main()
{
    // this shows the distance to sydney from a cityid 
    //ChargingStation::displayDistanceToSydney(12);

    // storing value of distance to syd test
    //int sdf = ChargingStation::displayDistanceToSydney(3);
    //cout << "sdf: " << sdf << endl;
 
    cout << endl;
    ifstream infile;
    infile.open("Chargingdemands.txt");
    if (infile.fail()) {
        cout << "This file could not be opened";
        exit(1);
    }

    //std::cout << "Hello World!\n";
    vector<Vehicle> demands;
    while (!infile.eof()) 
    {
        char c;
        infile >> c;
        if (c == '[') 
        {
            int values[4];
            for (int i = 0; i < 4; i++) 
            {
                infile >> values[i];
                infile >> c;
            }
            if (c != ']') 
            {
                cout << "Problem of reading file" << endl;
                break;
            }
            Vehicle demand(values[0], values[1], values[2], values[3]);
            //demand.setLatestCharging();
            demands.push_back(demand);
        }
    }
    // works with 156 as limit for charging demands
    for (int i = 0; i < 156; i++)
    {
        cout << demands[i];
        
        int remains = demands[i].getRemainingRange();
        cout << "Remaining Range on EV Battery: " << remains;
        cout << endl;
        cout << "farthest city can travel: " << Vehicle::farCity(remains) << endl << endl;
        //Vehicle::furthest_city(demands[i].getRemainingRange);
         
    }
    

    
    /*
    * // Already implemented in the above for loop to display furthest distance an ev can go with current remaining range
    int rr = 117;
    cout << "very far city " << Vehicle::farCity(rr) << endl;
    */
    
 
}

