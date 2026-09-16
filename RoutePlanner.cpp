#include "RoutePlanner.h"

#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

void RoutePlanner::addLocation(const string& location)
{
    graph.addLocation(location);
}

void RoutePlanner::addRoute(const string& from,
                            const string& to,
                            double distance)
{
    graph.addRoute(from, to, distance);
}

void RoutePlanner::displayLocations() const
{
    graph.displayLocations();
}

void RoutePlanner::findShortestPath(const string& start,
                                    const string& destination) const
{
    if (!graph.hasLocation(start) || !graph.hasLocation(destination))
    {
        cout << "One or both locations do not exist.\n";
        return;
    }

    unordered_map<string, double> distance;
    unordered_map<string, string> previous;

    for (const string& location : graph.getLocations())
    {
        distance[location] = numeric_limits<double>::infinity();
    }

    distance[start] = 0;

    using Pair = pair<double, string>;

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        double currentDistance = pq.top().first;
        string currentLocation = pq.top().second;
        pq.pop();

        if (currentDistance > distance[currentLocation])
        {
            continue;
        }

        if (currentLocation == destination)
        {
            break;
        }

        for (const auto& edge : graph.getNeighbors(currentLocation))
        {
            const string& neighbor = edge.first;
            double weight = edge.second;

            double newDistance = currentDistance + weight;

            if (newDistance < distance[neighbor])
            {
                distance[neighbor] = newDistance;
                previous[neighbor] = currentLocation;
                pq.push({newDistance, neighbor});
            }
        }
    }

    if (distance[destination] == numeric_limits<double>::infinity())
    {
        cout << "No route found.\n";
        return;
    }

    vector<string> path;

    string current = destination;

    while (current != start)
    {
        path.push_back(current);
        current = previous[current];
    }

    path.push_back(start);

    reverse(path.begin(), path.end());

    cout << "\nShortest path: ";

    for (size_t i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i < path.size() - 1)
        {
            cout << " -> ";
        }
    }

    cout << "\nTotal distance: "
         << distance[destination]
         << " km\n";
}

void RoutePlanner::loadRoutesFromFile(const string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        cout << "Could not open " << filename << ".\n";
        return;
    }

    string from;
    string to;
    double distance;

    while (file >> from >> to >> distance)
    {
        graph.addLocation(from);
        graph.addLocation(to);
        graph.addRoute(from, to, distance);
    }

    file.close();
}