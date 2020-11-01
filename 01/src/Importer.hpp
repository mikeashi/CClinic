#ifndef IMPORTER
#define IMPORTER

class Importer
{
public:
    Importer(Repo* repo);
    void loadDateFromFile(std::string fileName);
private:
    Repo* repo;
    void loadDateFromLine(std::string line);
    time_t getDateTime(std::string date, std::string time);
};

#endif