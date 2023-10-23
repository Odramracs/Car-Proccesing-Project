#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <iomanip>

enum STATUS {USED = 10, NEW = 20, CERTIFIED = 30};

class car 
{
    int year;
    STATUS stat;
    int mileage;
    int price;
    char* model;
    static int USED_counter;
    static int NEW_counter;
    static int CERTIFIED_counter;

public:

    int getYear() const;
    STATUS getStatus() const;
    int getMileage() const;
    int getPrice() const;
    char* getModel() const;
    const char* getStatusAsCString() const;
    static int getUsedCars();
    static int getNewCars();
    static int getCertifiedCars();

    void setYear(int);
    void setStatus(STATUS);
    void setMileage(int);
    void setPrice(int);
    void setModel(char*);
    friend void print(car& t);
    void print(car& t);
    
    
    friend void print();

    car()
    {
        if(stat == 10)
        {
            USED_counter++;
        }
        if(stat == 20)
        {
            NEW_counter++;
        }
        if(stat == 30)
        {
            CERTIFIED_counter++;
        }
    }

    ~car();
};
#endif