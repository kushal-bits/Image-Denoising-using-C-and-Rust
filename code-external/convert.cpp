#include <fstream>
#include<iostream>
using namespace std;
int main(int args, char* argv[]) {
  // Open the source file

    string filename = argv[1];
    //int colsize = atoi(argv[2]); 
    int colsize = 0;
    string out = filename+"_Modified.pgm";   
  std::ifstream sourceFile(filename);
  if (!sourceFile.is_open()) {
    return 1;
  }

  // Open the destination file
  ofstream destinationFile(out);
  if (!destinationFile.is_open()) {
    return 1;
  }
  

    string word;
    sourceFile >> word;
    destinationFile << word << endl;
    
    sourceFile >> word;
    colsize = stoi(word);
    destinationFile << word << " ";
    sourceFile >> word;
    destinationFile << word << endl;
    sourceFile >> word;
    destinationFile << word << endl;


    
    int ct = colsize;
  while (sourceFile >> word) {
    ct --;
    destinationFile << word << " ";
    if(ct == 0)
    {
        ct = colsize;
        destinationFile << endl;
    }
  }

  sourceFile.close();
  destinationFile.close();

  return 0;
}