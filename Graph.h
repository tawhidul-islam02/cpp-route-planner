#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph
{
private:
    unordered_map<string, vector<pair<string, double>>> adjacencyList;

public:
    void addLocation(const string& location);

    void addRoute(const string& from,
                  const string& to,
                  double distance);

    bool hasLocation(const string& location) const;

    const vector<pair<string, double>>&
    getNeighbors(const string& location) const;

    vector<string> getLocations() const;

    void displayLocations() const;
};

#endif