#include "RoutePlanner.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    RoutePlanner planner;

    planner.loadRoutesFromFile("locations.txt");

    int choice;

    do
    {
        cout << "\n===== C++ Route Planner =====\n";
        cout << "1. Display locations\n";
        cout << "2. Add location\n";
        cout << "3. Add route\n";
        cout << "4. Find shortest path\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (choice == 1)
        {
            planner.displayLocations();
        }
        else if (choice == 2)
        {
            string location;

            cout << "Enter location name: ";
            cin >> location;

            planner.addLocation(location);

            cout << "Location added.\n";
        }
        else if (choice == 3)
        {
            string from;
            string to;
            double distance;

            cout << "Enter starting location: ";
            cin >> from;

            cout << "Enter destination: ";
            cin >> to;

            cout << "Enter distance in km: ";
            cin >> distance;

            planner.addRoute(from, to, distance);

            cout << "Route added.\n";
        }
        else if (choice == 4)
        {
            string start;
            string destination;

            cout << "Enter starting location: ";
            cin >> start;

            cout << "Enter destination: ";
            cin >> destination;

            planner.findShortestPath(start, destination);
        }
        else if (choice == 5)
        {
            cout << "Exiting route planner.\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}