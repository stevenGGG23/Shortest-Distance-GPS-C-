# TN Shortest Path Finder

## Description
The **TN Shortest Path Finder** is a C++ program designed to calculate the shortest path between cities in Tennessee based on an adjacency matrix that represents distances between various cities. It implements **Dijkstra's Algorithm** to efficiently find the shortest route between two cities and offers a simple menu-based interface for the user to interact with the program.

The program is especially useful for understanding graph-based algorithms and how they can be applied to real-world problems like route planning and distance calculation.

### Features
- Displays an **adjacency matrix** representing distances between cities.
- Implements **Dijkstra's Algorithm** to compute the shortest path between two cities.
- Allows users to input starting and ending cities to find the shortest route.
- Provides a simple, user-friendly **menu interface** for interacting with the program.
- Handles errors, notifying users when an invalid city is entered.

---

## How to Use
```bash
===== TN Shortest Path Finder =====
1. Display Adjacency Matrix
2. Find Shortest Path (Dijkstra)
3. Exit
Enter your choice (1-3): 1

Adjacency Matrix (Distances in miles):
               Murfreesboro     Nashville       Chattanooga    Knoxville       Memphis         Franklin        Clarksville     Johnson         Jackson         Cookeville     
               35               150             INF             INF             INF             40              INF             INF             INF             80              
    Murfreesboro   0               35              150             INF             INF             40              INF             INF             INF             80              
    Nashville      35              0               130             INF             210             20              50              INF             INF             70              
    Chattanooga    150             130             0               80              310             INF             INF             INF             INF             90              
    Knoxville      INF             INF             80              0               INF             INF             INF             90              INF             70              
    Memphis        INF             210             310             INF             0               190             230             INF             85              INF             
    Franklin       40              20              INF             INF             190             0               60              INF             INF             INF             
    Clarksville    INF             50              INF             INF             230             60              0               INF             140             INF             
    Johnson        INF             INF             INF             90              INF             INF             INF             0               INF             INF             
    Jackson        INF             INF             INF             INF             85              INF             140             INF             0               INF             
    Cookeville     80              70              90              70              INF             INF             INF             INF             INF             0

===== TN Shortest Path Finder =====
1. Display Adjacency Matrix
2. Find Shortest Path (Dijkstra)
3. Exit
Enter your choice (1-3): 2
Enter starting city: Murfreesboro
Enter ending city: Chattanooga

Shortest path: Murfreesboro → Nashville → Chattanooga
Total distance: 165 miles

===== TN Shortest Path Finder =====
1. Display Adjacency Matrix
2. Find Shortest Path (Dijkstra)
3. Exit
Enter your choice (1-3): 3
Exiting program. Goodbye!            
