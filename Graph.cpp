#include "Graph.h"
#include <iostream>

using namespace std;

void Graph::addLocation(const string& location)
{
    if (!hasLocation(location))
    {
        adjacencyList[location] = {};
    }
}

void Graph::addRoute(const string& from,
                     const string& to,
                     double distance)
{
    addLocation(from);
    addLocation(to);

    adjacencyList[from].push_back({to, distance});
    adjacencyList[to].push_back({from, distance});
}

bool Graph::hasLocation(const string& location) const
{
    return adjacencyList.find(location) != adjacencyList.end();
}

const vector<pair<string, double>>&
Graph::getNeighbors(const string& location) const
{
    return adjacencyList.at(location);
}

vector<string> Graph::getLocations() const
{
    vector<string> locations;

    for (const auto& entry : adjacencyList)
    {
        locations.push_back(entry.first);
    }

    return locations;
}

void Graph::displayLocations() const
{
    cout << "\nAvailable Locations:\n";

    for (const auto& entry : adjacencyList)
    {
        cout << "- " << entry.first << '\n';
    }
}