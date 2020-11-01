#ifndef REPO
#define REPO

class Repo
{
public:
    Repo();
    void append(time_t datetime, double press);
    int size();
private:
    std::map<time_t, double> data;
};

#endif