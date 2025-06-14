#include "CarClass.h"
#include <iostream>

int CarClass::m_numberOfCarEntries = 0;

CarClass::CarClass() {
    m_brand = "None";
    m_ownerName = "None";
    m_value = 0;
    m_mileage = 0;
    m_year = 0;
}
CarClass::CarClass(const std::string& brand, const std::string& ownerName, double value, double mileage, int year) {
    m_brand = brand;
    m_ownerName = ownerName;
    m_value = value;
    m_mileage = mileage;
    m_year = year;
}
CarClass::~CarClass(){

}

void CarClass::setBrand(const std::string& brand) {
    m_brand = brand;
}
void CarClass::setOwnerName(const std::string& ownerName) {
    m_ownerName = ownerName;
}
void CarClass::setValue(const double value) {
    m_value = value;
}
void CarClass::setMileage(const double mileage) {
    m_mileage = mileage;
}
void CarClass::setYear(const int year) {
    m_year = year;
}

std::string CarClass::getBrand() const {
    return m_brand;
}
std::string CarClass::getOwnerName() const {
    return m_ownerName;
}
double CarClass::getValue() const {
    return m_value;
}
double CarClass::getMileage() const {
    return m_mileage;
}
int CarClass::getYear() const {
    return m_year;
}


void CarClass::printInfo() const {
    std::cout << "Brand: " << m_brand << std::endl;
    std::cout << "OwnerName: " << m_ownerName << std::endl;
    std::cout << "Value: " << m_value << std::endl;
    std::cout << "Mileage: " << m_mileage << std::endl;
    std::cout << "Year: " << m_year << std::endl;
}

int CarClass::numberOfCarEntries() {
    return m_numberOfCarEntries;
}
void CarClass::incrementNumberOfCarEntries(){
    m_numberOfCarEntries++;
}
void CarClass::decrementNumberOfCarEntries(){
    m_numberOfCarEntries--;
}