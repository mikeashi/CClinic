#include <iostream>
#include <map>
#include "Repo.cpp"
#include "Importer.cpp"
#define RESOURCE_PATH "data/"
using namespace std;

void loadData(Importer *importer);

int main(int argc, char const *argv[])
{
    Repo repo;
    Importer importer(&repo);
    loadData(&importer);
    
    cout << repo.size() << endl;
    cout << "every thing is working :)" << endl;
    return 0;
}

void loadData(Importer *importer)
{
    for (int year = 2012; year <= 2015; year++)
    {
        ostringstream fileNameStream;
        fileNameStream << RESOURCE_PATH << "Environmental_Data_Deep_Moor_" << year << ".txt";
        string fileName = fileNameStream.str();
        cout << "Loading " << fileName << endl;
        importer->loadDateFromFile(fileName);
    }
}