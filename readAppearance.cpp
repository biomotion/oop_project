#include"readAppearance.h"
vector<string> readFile(string fileName)
{
    ifstream inFile(fileName.c_str());
    vector<string> result;
    string tmp;

    if(!inFile){
        result.push_back("File not found.");
        return result;
    }

    getline(inFile, tmp);
    while(!inFile.eof()){
        result.push_back(tmp);
        getline(inFile, tmp);
    }
    return result;
}

