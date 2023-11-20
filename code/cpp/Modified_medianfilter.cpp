#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

const int MAX_SIZE = 2000;

int originalImage[MAX_SIZE][MAX_SIZE];
int filteredImage[MAX_SIZE][MAX_SIZE];

int main() {
    int window[9], row, col, numrows = 0, numcols = 0, MAX = 0;

    //Input Image File
    ifstream inputFile("mona_lisa.pgm");
    stringstream ss;
    string inputLine;

    // Read and validate the version
    getline(inputFile, inputLine);
    if (inputLine.compare("P2") != 0) {
        cerr << "Version error" << endl;
        return 0;
    } else {
        cout << "Version: " << inputLine << endl;
    }

    // Continue with a stringstream
    ss << inputFile.rdbuf();

    // Read the size of the image
    ss >> numcols >> numrows >> MAX;

    // Print information about the image
    cout << numcols << " columns and " << numrows << " rows" << endl
         << "Maximum Intensity " << MAX << endl;

    //Start Execution
    auto start = high_resolution_clock::now();

    // Initialize a new array of the same size as the image with 0
    for (row = 0; row <= numrows; ++row) {
        originalImage[row][0] = 0;
    }
    for (col = 0; col <= numcols; ++col) {
        originalImage[0][col] = 0;
    }

    // Read data into the originalImage array
    for (row = 1; row <= numrows; ++row) {
        for (col = 1; col <= numcols; ++col) {
            ss >> originalImage[row][col];
        }
    }

    // Apply median filter to the image
    for (row = 1; row <= numrows; ++row) {
        for (col = 1; col <= numcols; ++col) {
            // Neighbor pixel values are stored in a window including this pixel
            window[0] = originalImage[row - 1][col - 1];
            window[1] = originalImage[row - 1][col];
            window[2] = originalImage[row - 1][col + 1];
            window[3] = originalImage[row][col - 1];
            window[4] = originalImage[row][col];
            window[5] = originalImage[row][col + 1];
            window[6] = originalImage[row + 1][col - 1];
            window[7] = originalImage[row + 1][col];
            window[8] = originalImage[row + 1][col + 1];

            sort(window, window + 9);
            
            // Put the median into the new array
            originalImage[row][col] = window[4];
        }
    }
    for(int i = 0; i < numrows; i++){
        for(int j = 0; j < numcols; j++){
            filteredImage[i][j] = originalImage[i][j];
        }
    }
    ofstream outputFile;
    //Finished Execution
    auto stop = high_resolution_clock::now();
    // Time taken for execution
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Execution Time in milliseconds: " << duration.count() << endl;

    // Created a new output file
    outputFile.open("Medianfilter_monalisa.pgm");
    outputFile << "P2" << endl;
    outputFile << numcols << " " << numrows << endl;
    outputFile << "255" << endl;

    //Writing the output image to output file
    for (row = 1; row <= numrows; ++row) {
        for (col = 1; col <= numcols; ++col) {
            outputFile << filteredImage[row][col] << " ";
        }
    }

    outputFile.close();
    inputFile.close();

    return 0;
}
