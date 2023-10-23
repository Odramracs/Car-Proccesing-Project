#include "car.h"
using namespace std;

int car::getYear() const
{
    return year;
}
STATUS car::getStatus() const
{
    return stat;
}
int car::getMileage() const
{
    return mileage;
}
int car::getPrice() const
{
    return price;
}

char *car::getModel() const
{
    return model;
}

const char *car::getStatusAsCString() const
{
    if (stat == 10)
    {
        return "USED";
    }
    else if (stat == 20)
    {
        return "NEW";
    }
    else
    {
        return "CERTIFIED";
    }
}

int car::getUsedCars() 
{
    return USED_counter;
}

int car::getNewCars() 
{
    return NEW_counter;
}
int car::getCertifiedCars() 
{
    return CERTIFIED_counter;
}

void car::setYear(int i)
{
    year = i;
}

void car::setStatus(STATUS p)
{
    stat = p;
}

void car::setMileage(int o)
{
    mileage = o;
}
void car::setPrice(int p)
{
    price = p;
}
void car::setModel(char *src)
{
    if (model != nullptr)
    {
        delete[] model;
    }
    int i = 0;
    while (src[i] != '\0')
    {
        i++;
    }
    model = new char[i + 1];
    i = 0;
    while (src[i] != '\0')
    {
        model[i] = src[i];
        i++;
    }
    model[i] = '\0';
}

void car::print(car& t)
{
    cout << year << getStatusAsCString() << mileage << "Mi $" << price << " USD " << model; 
} 

car::car()
{
    year = -1;
    stat = USED;
    mileage = -1;
    price = -1;
    model = nullptr;
}

car::~car()
{
    if (model != nullptr)
    {
        delete[] model;
    }
}