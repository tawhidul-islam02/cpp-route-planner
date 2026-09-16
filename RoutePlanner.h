#ifndef ROUTEPLANNER_H
#define ROUTEPLANNER_H

#include "Graph.h"
#include <string>
#include <vector>

using namespace std;

class RoutePlanner
{
private:
    Graph graph;

public:
    void addLocation(const string& location);

    void addRoute(const string& from,
                  const string& to,
                  double distance);

    void displayLocations() const;

    void findShortestPath(const string& start,
                          const string& destination) const;

    void loadRoutesFromFile(const string& filename);
};

#endif