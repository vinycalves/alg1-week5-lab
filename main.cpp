#include <algorithm>  // Include for algorithm functions like find
#include <iostream>   // Include for input and output
#include <list>       // Include for list container
#include <map>        // Include for map container
#include <vector>     // Include for vector container

using namespace std; // Use the standard namespace

// Custom comparator to order houses
struct HouseComparator
{
    bool operator()(const string& a, const string& b) const
    {
        // Order in which houses should be compared
        static const vector<string> order = {"Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw"};
        auto itA = find(order.begin(), order.end(), a); // Find position of house a
        auto itB = find(order.begin(), order.end(), b); // Find position of house b
        // Compare positions or default to lexicographical order
        return itA != order.end() && itB != order.end() ? itA < itB : a < b;
    }
};

int main()
{
    string n;
    getline(cin, n); // Read the number of students
    int N = stoi(n); // Convert string to integer

    // Validate the number of students
    if (N < 1 || N > 1000)
    {
        cerr << "The number should be between 1 and 1000";
        return 1;
    }

    // Map to store students grouped by house with custom sorting
    map<string, list<string>, HouseComparator> students;
    string person;
    string house;

    // Read student information
    while (N--)
    {
        getline(cin, person); // Read student name
        // Validate the length of the student's name
        if (person.length() > 200)
        {
            cerr << "Student name exceeds maximum allowed length of 200 characters.";
            return 1;
        }

        getline(cin, house); // Read house name
        students[house].push_back(person); // Add student to the corresponding house
    }

    // Print the students organized by house
    for (const auto& student : students)
    {
        cout << student.first << ":" << endl; // Print house name
        for (const auto& student_name : student.second)
        {
            cout << student_name << endl; // Print each student's name
        }
        cout << endl; // Print a blank line between houses
    }
    return 0;
}
