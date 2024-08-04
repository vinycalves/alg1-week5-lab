#include <algorithm>  // Include the algorithm library for sorting
#include <iostream>   // Include the iostream library for input and output
#include <array>      // Include the array library for using std::array

using namespace std; // Use the standard namespace

const int MAX_ARRAY_SIZE = 12; // Define a constant for the maximum array size
const short MIN_VALUE = 0; // Define a constant for the minimum value
const short MAX_VALUE = 100; // Define a constant for the maximum value

int main()
{
    short k; // Declare a short variable k
    cin >> k; // Read a value into k from standard input
    if (k < MIN_VALUE || k > MAX_VALUE) // Check if k is outside the valid range
    {
        cerr << "Invalid number for K, it should be between " << MIN_VALUE << " and " << MAX_VALUE << endl;
        // Print an error message to standard error
        return 1; // Exit the program with an error code
    }

    if (k == MIN_VALUE) // Check if k is the minimum value
    {
        cout << 0 << endl; // Output 0 and a newline
        return 0; // Exit the program successfully
    }

    array<int, MAX_ARRAY_SIZE> arr{}; // Declare and initialize an array of size MAX_ARRAY_SIZE
    for (int i = 0; i < arr.size(); ++i) // Loop through the array
    {
        short a; // Declare a short variable a
        cin >> a; // Read a value into a from standard input

        if (a < MIN_VALUE || a > MAX_VALUE) // Check if a is outside the valid range
        {
            cerr << "Invalid number for a, it should be between " << MIN_VALUE << " and " << MAX_VALUE << endl;
            // Print an error message to standard error
            return 1; // Exit the program with an error code
        }

        arr[i] = a; // Assign the value of a to the array element at index i
    }

    sort(arr.begin(), arr.end(), greater<int>()); // Sort the array in descending order

    short sum = 0; // Declare and initialize a short variable sum
    int total = 0; // Declare and initialize an int variable total
    for (const auto& value : arr) // Loop through each value in the array
    {
        total += value; // Add the current value to total
        ++sum; // Increment sum

        if (total >= k) // Check if total is greater than or equal to k
        {
            cout << sum << endl; // Output the value of sum and a newline
            return 0; // Exit the program successfully
        }
    }

    cout << -1 << endl; // If the loop completes, output -1 and a newline
    return 0; // Exit the program successfully
}
