/*
Author: Steven Gobran
Date: 04/23/2025

Lab Purpose: Lloads a graph, displays the adjacency matrix, and computes the shortest path between cities 
using Dijkstra’s algorithm. The program includes a menu for user interaction.

A.I. Disclaimer: All work for this assignment was completed by myself 
and entirely without the use of artificial intelligence tools such as ChatGPT, MS Copilot, other LLMs, etc.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <iomanip> 

using namespace std;

// Function prototypes
void displayAdjacencyMatrix(const vector<vector<int>>& adjMatrix, const vector<string>& cityNames);
void dijkstra(const vector<vector<int>>& adjMatrix, int start, int end, const vector<string>& cityNames);
int cityToIndex(const unordered_map<string, int>& cityToIndexMap, const string& city);

const int INF = INT_MAX; //Max constant

int main() {
    // List of cities
    vector<string> cityNames = {
        "Murfreesboro", "Nashville", "Chattanooga", "Knoxville", "Memphis",
        "Franklin", "Clarksville", "Johnson", "Jackson", "Cookeville"
    };
    
    // Adjacency matrix representing the graph
    vector<vector<int>> adjMatrix = {
        {  0,    35,  150,  INF,  INF,  40,   INF,   INF,  INF,  80 },
        { 35,     0,  130,  INF,  210,  20,    50,   INF,  INF,  70 },
        {150,   130,    0,   80,  310, INF,   INF,   INF,  INF,  90 },
        {INF,   INF,   80,    0,  INF, INF,   INF,    90,  INF,  70 },
        {INF,   210,  310,  INF,    0,  190,   230,  INF,   85,  INF },
        { 40,    20,  INF,  INF,  190,    0,    60,  INF,  INF,  INF },
        {INF,    50,  INF,  INF,  230,   60,     0,  INF,  140,  INF },
        {INF,   INF,  INF,   90,  INF, INF,   INF,     0,  INF,  INF },
        {INF,   INF,  INF,  INF,   85, INF,    140,  INF,    0,  INF },
        { 80,    70,   90,   70,  INF, INF,   INF,   INF,  INF,    0 }
    };

    // Map to store city names and their corresponding index in the adjacency matrix
    unordered_map<string, int> cityToIndexMap;
    for (int i = 0; i < cityNames.size(); ++i) {
        string lowercase = cityNames[i];
        cityToIndexMap[lowercase] = i;
    }

    int choice; 
    //Display menu 
    do {
        cout << "\n===== TN Shortest Path Finder =====\n";
        cout << "1. Display Adjacency Matrix\n";
        cout << "2. Find Shortest Path (Dijkstra)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice; 

        switch (choice) {
            case 1:
                // Display the adjacency matrix
                displayAdjacencyMatrix(adjMatrix, cityNames);
                break;
            case 2:
                {
                    //prompts user for both city names
                    string startCity, endCity;
                    cout << "Enter starting city: ";
                    cin >> startCity;
                    cout << "Enter ending city: ";
                    cin >> endCity;

                    bool startExists = cityToIndexMap.find(startCity) != cityToIndexMap.end();
                    bool endExists = cityToIndexMap.find(endCity) != cityToIndexMap.end();

                    //if not found in the graph 
                    if (!startExists && !endExists) {
                        cout << "Error: \"" << startCity << "\" and \"" << endCity << "\" are not found in the graph.\n";
                    } else if (!startExists) {
                        cout << "Error: \"" << startCity << "\" is not found in the graph.\n";
                    } else if (!endExists) {
                        cout << "Error: \"" << endCity << "\" is not found in the graph.\n";
                    } else {
                        int start = cityToIndexMap[startCity];
                        int end = cityToIndexMap[endCity];
                        dijkstra(adjMatrix, start, end, cityNames);
                    }
                }
                break;

            case 3:
                cout << "Exiting program. Goodbye!\n"; // Exiting program message 
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n"; // Invalid choice message  
        }
    } while (choice != 3);

    return 0;
}


// Function to display the adjacency matrix
void displayAdjacencyMatrix(const vector<vector<int>>& adjMatrix, const vector<string>& cityNames) { 
    cout << endl; 
    cout << "Adjacency Matrix (Distances in miles):\n";
    cout << "               ";
    for (const auto& city : cityNames) {
        cout << setw(15) << city;  // Proper alignment
    }
    cout << endl;

    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        cout << setw(15) << cityNames[i];  //proper alignment
        for (size_t j = 0; j < adjMatrix[i].size(); ++j) {
            if (adjMatrix[i][j] == INF)
                cout << setw(15) << "INF";  // Display INF in a column of the same width
            else
                cout << setw(15) << adjMatrix[i][j];  // Display the distance with proper alignment
        }
        cout << endl;
    }
}

// Function to implement Dijkstra's algorithm and display the shortest path
void dijkstra(const vector<vector<int>>& adjMatrix, int start, int end, const vector<string>& cityNames) {
    int n = adjMatrix.size();  // Number of cities (nodes)
    vector<int> d(n, INF);     // Shortest distances from start to city i
    vector<int> s(n, -1);      // Predecessor of city i in the shortest path
    vector<bool> visited(n, false);  // Whether city i has been visited

    d[start] = 0;  // Distance to start city is 0

    // Main loop of the algorithm
    for (int step = 0; step < n - 1; ++step) {
        int p = -1;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && (p == -1 || d[i] < d[p])) {
                p = i;  // Select the city with the smallest tentative distance
            }
        }

        if (p == -1 || d[p] == INF) {
            break;  // No more reachable cities
        }

        visited[p] = true;

        // Check all neighbors of city p
        for (int v = 0; v < n; ++v) {
            if (adjMatrix[p][v] != INF && !visited[v] && d[p] + adjMatrix[p][v] < d[v]) {
                d[v] = d[p] + adjMatrix[p][v];  // Update shortest distance to city v
                s[v] = p;  // Update predecessor of city v
            }
        }
    }

    // Reconstruct the shortest path from end to start using predecessors
    vector<int> path;
    for (int v = end; v != -1; v = s[v]) {
        path.insert(path.begin(), v);
    }

    // Display the shortest path with city names
    cout << "\nShortest path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << cityNames[path[i]];
        if (i < path.size() - 1) cout << " → ";
    }
    cout << "\nTotal distance: " << d[end] << " miles\n";
}
