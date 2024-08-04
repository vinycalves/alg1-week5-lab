#include <algorithm>  // Include for algorithm functions like sort
#include <iostream>   // Include for input and output
#include <sstream>    // Include for stringstream
#include <vector>     // Include for vector container

using namespace std; // Use the standard namespace

// Function to split a string by '+' and convert parts to integers
vector<int> splitString(const string& str)
{
    vector<int> result; // Vector to store the integers
    stringstream ss(str); // Create a stringstream from the input string
    string item; // String to hold each part

    // Split the string by '+' and convert each part to an integer
    while (getline(ss, item, '+'))
    {
        result.push_back(stoi(item)); // Convert to integer and add to the result vector
    }

    return result; // Return the vector of integers
}

int main()
{
    string str; // String to hold the input
    getline(cin, str); // Read the input string

    // Check if the length of the input string exceeds 100 characters
    if (str.length() > 100)
    {
        cerr << "Input line exceeds maximum allowed length of 100 characters." << endl;
        return 1; // Exit with an error code
    }

    vector<int> numbers = splitString(str); // Split the string into numbers
    ranges::sort(numbers); // Sort the numbers in ascending order

    // Print the sorted numbers separated by '+'
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i] << (i == numbers.size() - 1 ? "" : "+");
        // Print each number, adding '+' except for the last one
    }

    return 0; // Return successfully
}
