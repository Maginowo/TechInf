#ifndef CARCLASS_H
#define CARCLASS_H
#pragma once
#include <string>

class CarClass
{
private:
    static int m_numberOfCarEntries;
    std::string m_brand;
    std::string m_ownerName;
    double m_value;
    double m_mileage;
    int m_year;

public:
    static int numberOfCarEntries();
    static void incrementNumberOfCarEntries();
    static void decrementNumberOfCarEntries();
    CarClass();
    CarClass(const std::string& brand, const std::string& ownerName, double value = 0, double mileage = 0, int year = 0);
    ~CarClass();

    void setBrand(const std::string& brand);
    void setOwnerName(const std::string& ownerName);
    void setValue(double value);
    void setMileage(double mileage);
    void setYear(int year);

    std::string getBrand() const;
    std::string getOwnerName() const;
    double getValue() const;
    double getMileage() const;
    int getYear() const;

    void printInfo() const;

};

#endif //CARCLASS_H
