#include <iostream>
#include<string>
#include<fstream>
#include<cmath>
using namespace std;


// Function to convert a pattern to a square matrix
void convertToSquareMatrix(char** squareMatrix, const string& pattern, int m) {
    int k = 0;

    cout << "The pattern converted to matrix: " << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (k < pattern.length()) {
                squareMatrix[i][j] = pattern[k++];
                cout << squareMatrix[i][j];
            }

            else {
                squareMatrix[i][j] = 'X'; //X is default incase the pattern and length dont match
            }
        }
        cout << endl;
    }
}



// Function to count square pattern in a larger matrix
int countSquarePatternOccurrences(char** largerMatrix, int n, const string& pattern, int m) {
   
    
    if (m > n) {
        cout << "Error: Pattern size exceeds the larger matrix size." << endl;
        return 0;
    }

    int count = 0;

    // Create a square matrix for the pattern and convert it
    char** patternMatrix = new char* [m];
    for (int i = 0; i < m; ++i) {
        patternMatrix[i] = new char[m];
    }
    convertToSquareMatrix(patternMatrix, pattern, m);


    // Iterate through the larger matrix
    for (int i = 0; i <= n - m; ++i) {
        for (int j = 0; j <= n - m; ++j) {
            // Check if the pattern matches diagonally from (i, j)
            bool check = true;
            for (int k = 0; k < m; ++k) {
                for (int l = 0; l < m; ++l) {
                    if (largerMatrix[i + k][j + l] != patternMatrix[k][l]) {
                        check = false;
                        break;
                    }
                }
                if (!check) {
                    break;
                }
            }
            if (check) {
                count++;

               //printing the position of each occurrence
               cout << "Pattern is found at position() (" << i << ", " << j << ")"<<endl;
            }
        }
    }


    // Deallocate memory for the pattern matrix
    for (int i = 0; i < m; ++i) {
        delete[] patternMatrix[i];
    }
    delete[] patternMatrix;

    return count;
}




int main() {
    // Read input from a text file
    ifstream inputFile("TestCase8.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening the file." << endl;
        return 1;
    }




    string text;
    int size = 0;
    int lineNumber = 0;
    while (getline(inputFile, text))
    {
        if (lineNumber == 0)
        {
            size = text[2] - '0';
            lineNumber++;
            break;
        }

    }

    //cout << size << endl;

    //larger matrix
    char** largerMatrix = new char* [size];
    for (int i = 0; i < size; ++i)
    {
        largerMatrix[i] = new char[size];
    }

    int i = 0, j = 0, letter = 0;
    bool check = false;
    string pattern;
    while (getline(inputFile, text))
    {
        j = 0;
        letter = 0;
        if (check == true)
        {
            pattern = text;
            break;
        }
        if (text.empty())
        {
            check = true;
            continue;
        }
        else
        {
            while (text[letter] != '\0')
            {
                if (text[letter] == ',')
                {
                    letter++;
                    continue;
                }
                else
                {
                    largerMatrix[i][j] = text[letter];
                    j++;
                    letter++;
                }
            }
            i++;
        }


    }

    //The larger matrix printed
    cout << "The larger matrix read is :" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << largerMatrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    // Read the pattern string
    cout << endl<< "The pattern to be searched is: ";
    cout << pattern << endl;

    //int n;
    //cout << "Enter the size of the larger matrix: ";
    //cin >> n;

    //if (n <= 0 || n > MAX_SIZE) {
    //    cout << "Error: Invalid matrix size." << std::endl;
    //    return 1;
    //}

    //// Input the larger matrix
    //char** largerMatrix = new char* [n];
    //for (int i = 0; i < n; ++i) {
    //    largerMatrix[i] = new char[n];
    //    for (int j = 0; j < n; ++j) {
    //        cin >> largerMatrix[i][j];
    //    }
    //}

    //// Find the length of the pattern string
    //string pattern;
    //cout << "Enter the pattern as a string: ";
    //cin >> pattern;
    //int m = pattern.length();


    // Find the length of the pattern string
    int m = pattern.length();
    if (m % 2 == 0) {
        m = m / 2;
    }
    else {
        m = m / 2;
        m = m - 1;
    }
   
    // Find and print the result
    int result = countSquarePatternOccurrences(largerMatrix, size, pattern, m);
    cout << "Result: " << result << endl;

    // Deallocate memory for the larger matrix
    for (int i = 0; i < size; ++i) {
        delete[] largerMatrix[i];
    }
    delete[] largerMatrix;

    inputFile.close();

    return 0;
}
