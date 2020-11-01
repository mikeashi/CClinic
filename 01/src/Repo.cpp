#include "Repo.hpp"

Repo::Repo()
{
    // empty constructor
}

void Repo::append(time_t datetime, double press){
    this->data[datetime] = press;
}

int Repo::size(){
    return this->data.size();
}