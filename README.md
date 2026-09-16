# C++ Route Planner

A console-based route planning application written in C++ that models locations and routes as a weighted graph and uses Dijkstra's algorithm to find the shortest path between locations.

## Features

- Display all available locations
- Add new locations
- Add weighted routes between locations
- Find the shortest path between two locations
- Calculate the total distance of the shortest path
- Load location and route data from a text file

## Concepts Used

- C++
- Object-Oriented Programming (OOP)
- Graph data structure
- Adjacency lists
- STL containers
- Priority queues
- Dijkstra's shortest-path algorithm
- Path reconstruction
- File I/O
- Multi-file program structure

## Project Structure

- `main.cpp` - Program menu and user interaction
- `Graph.h` / `Graph.cpp` - Graph representation and operations
- `RoutePlanner.h` / `RoutePlanner.cpp` - Route planning and shortest-path logic
- `locations.txt` - Initial location and route data
- `.gitignore` - Excludes compiled files from version control

## Build and Run

Compile the source files:

```bash
g++ main.cpp Graph.cpp RoutePlanner.cpp -o route_planner