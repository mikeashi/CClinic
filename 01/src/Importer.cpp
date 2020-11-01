#include "Importer.hpp"
#include <fstream>
#include <sstream>

Importer::Importer(Repo* repo)
{
    this->repo = repo;
}

void Importer::loadDateFromFile(std::string fileName)
{
    std::fstream fileStream;
    fileStream.open(fileName);
    
    std::string line;
    // parse first line
    std::getline(fileStream, line);
    
    while (std::getline(fileStream, line))
    {
       this->loadDateFromLine(line);
    }

    fileStream.close();
}

void Importer::loadDateFromLine(std::string line)
{
    std::string date, time;
    double Air_Temp, Barometric_Press, Dew_Point, Relative_Humidity, Wind_Dir, Wind_Gust, Wind_Speed;
    std::istringstream buffer(line);
    buffer >> date >> time >> Air_Temp >> Barometric_Press >> Dew_Point >> Relative_Humidity >> Wind_Dir >> Wind_Gust >> Wind_Speed;
    time_t datetime = this->getDateTime(date, time);
    this->repo->append(datetime, Barometric_Press);
}

time_t Importer::getDateTime(std::string date, std::string time)
{
    int yyyy, mon, dd;
    if (sscanf(date.c_str(), "%d_%d_%d", &yyyy, &mon, &dd) != 3)
    {
        std::cerr << "ERROR: Failed to parse date string " << date << std::endl;
        return -1;
    }

    int hh, mm, ss;
    if (sscanf(time.c_str(), "%d:%d:%d", &hh, &mm, &ss) != 3)
    {
        std::cerr << "ERROR: Failed to parse time string " << time << std::endl;
        return -2;
    }

    struct tm dateTime = {};
    dateTime.tm_year = yyyy - 1900; // years since 1900
    dateTime.tm_mon = mon - 1;      // months since January
    dateTime.tm_mday = dd;          // day of the month
    dateTime.tm_hour = hh;          // hours since midnight
    dateTime.tm_min = mm;           // minutes after the hour
    dateTime.tm_sec = ss;           // seconds after the minute

    // return a time_t value representing seconds since 1970
    return mktime(&dateTime);
}
