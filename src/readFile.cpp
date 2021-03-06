/**
*    Purpose: Class to read the files of matrixes.
*    @author Juliana Barbosa, Nalbert Gabriel
*    @version 1.0 10/5/2017
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <string>

#include "readFile.h"

using namespace std;

/**
* @brief  The constructor of the class ReadFile is responsible to build a object
* with the expecified parameters
* @param  fileName1
* @param  fileName2
* @param  matrixSize
*/
ReadFile::ReadFile(string fileName1, string fileName2, int matrixSize) {
  this->fileName1 = fileName1;
  this->fileName2 = fileName2;
  this->matrixSize = matrixSize;

  this->fileMatrixA.open(this->fileName1);
  cout << fileName1 << ": " << _isOpen(this->fileMatrixA) << "\n";

  this->fileMatrixB.open(this->fileName2);
  cout << fileName2 << ": " << _isOpen(this->fileMatrixB) << "\n";
}

/**
* @brief
*/
ReadFile::~ReadFile() {
  /* EMPTY */
}

/**
* @brief
*/
void ReadFile::readA() {
  string fileString = this->_read(this->fileMatrixA);
  this->_createMatrix(fileString, this->matrixA);
}

/**
* @brief
*/
void ReadFile::readB() {
  string fileString = this->_read(this->fileMatrixB);
  this->_createMatrix(fileString, this->matrixB);
}

/**
* @brief
* @return
*/
string ReadFile::_isOpen(ifstream& file) {
  if(!(file.is_open())) {
    return "file is open.";
  }
  else {
    return "file is closed.";
  }
}

/**
* @brief
*/
string ReadFile::_read(ifstream& file) {
  string fileString = "";
  string line = "";
  int isFirstLine = 0;

  for(unsigned int index = 0; index < (this->matrixSize * this->matrixSize); index++) {
    file >> line;
    if(isFirstLine < 2) {
      isFirstLine++;
      continue;
    }
    fileString = fileString + " " + line;
  }

  return fileString;
}

/**
* @brief
*/
void ReadFile::_createMatrix(string fileString, vector< vector<int> >& vec) {
  stringstream ss(fileString);

  string stringElement = "";

  for(int line = 0; line < this->matrixSize; line++) {
    vector<int> temp;
    for(int col = 0; col < this->matrixSize; col++) {

      ss >> stringElement;

      for(unsigned int index = 0; index < stringElement.length(); index++) {
        if(isdigit(stringElement[index])) {
          continue; // the stringElement isn't a number, so get next element
        }
      }
      if(stringElement == "\n") {
        continue; // the stringElement is a "breakLine" character, not a number, so get net element
      }

      // cout << stringElement << endl;
      temp.push_back( atoi(stringElement.c_str()) );
      // vec[line]->push_back( atoi(stringElement.c_str()) );
      // cout << vec[line][0] << endl;
    }
    vec.push_back( temp );
  }
}

vector< vector<int> >& ReadFile::getMatrixA() {
  return this->matrixA;
}

vector< vector<int> >& ReadFile::getMatrixB() {
  return this->matrixB;
}
