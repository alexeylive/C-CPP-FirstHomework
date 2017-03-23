using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include "Bus.hpp"

const int Bus::get_busNumber() const{
return this->bus_number;
}

const int Bus::get_year() const{
  return this->year;
}

const int Bus::get_mileage() const{
  return this->mileage;
}

const int Bus::get_route() const{
  return this->route;
}

const char* Bus::get_surname() const{
  return this->surname;
}

const char* Bus::get_mark_of_bus() const{
  return this->mark_of_bus;
}

const char* Bus::get_initials()const{
  return this->initials;
}

void Bus::show_name() const {
  cout << "Name is " << get_surname() <<' '<< get_initials() << '.'<<endl;
}

void Bus::show_mark_of_bus() const {
  cout << "Mark of bus is " << get_mark_of_bus() << '.'<<endl;
}

void Bus::show_busNumber() const {
  cout << "Bus number is " << get_busNumber()<< '.'<<endl;
}

void Bus::show_year() const {
  cout << "Production year: " << get_year()<< '.'<<endl;
}

void Bus::show_mileage() const {
  cout << "Mileage: " << get_mileage()<< '.'<<endl;
}
void Bus::show_route() const {
  cout << "Route: " << get_route()<< '.'<<endl;
}

void show_buses_over_10000_km(Bus* List, int N){
  int i=0;
  cout << endl << "Mileage over 10000: " << endl;
  while(i<N){
    if(List[i].get_mileage()>10000)
    List[i].show_busNumber();
    i++;
  }
}

void show_old_buses(Bus* List, int N){
  int i=0;
  cout << endl << "Older than 10: " << endl;
  while(i<N){
    if((2017-List[i].get_year()) > 10)
    List[i].show_busNumber();
    i++;
  }
}

void show_busNumber_for_route(Bus* List,int route_number, int N){
  int i=0;
  cout << endl << "Your numbers of buses: " << endl;
  while(i<N){
    if(List[i].get_route() == route_number)
    List[i].show_busNumber();
    i++;
  }
}

Bus::Bus(){
      this->bus_number = 0;
      this->year = 0;
      this->mileage = 0;
      this->route = 0;
      this->surname = NULL;
      this->mark_of_bus = NULL;
      this->initials = NULL;
}

Bus::~Bus(){
  delete[] surname;
  delete[] mark_of_bus;
  delete[] initials;
}

Bus::Bus(const Bus& rhs):
year(rhs.year),
route(rhs.route),
mileage(rhs.mileage),
bus_number(rhs.bus_number)
{
  if (rhs.surname){
    size_t len =strlen(rhs.surname)+1;
    this->surname = new char[len];
    memcpy(this->surname,rhs.surname,len);
  }
  if (rhs.mark_of_bus){
    size_t len =strlen(rhs.mark_of_bus)+1;
    this->mark_of_bus = new char[len];
    memcpy(this->mark_of_bus,rhs.mark_of_bus,len);
  }
  if (rhs.initials){
    size_t len =strlen(rhs.initials)+1;
    this->initials = new char[len];
    memcpy(this->initials,rhs.initials,len);
  }
}

void Bus::set_busNumber(const int bus_number){
  this->bus_number = bus_number;
}

void Bus::set_year(const int year){
  this->year = year;
}

void Bus::set_mileage(const int mileage){
  this->mileage = mileage;
}

void Bus::set_route(const int route){
  this-> route = route;
}

void Bus::set_mark_of_bus(const char* mark_of_bus)
{
  if (mark_of_bus){
    size_t len =strlen(mark_of_bus)+1;
    this->mark_of_bus = new char[len];
    memcpy(this->mark_of_bus,mark_of_bus,len);
  }
}

void Bus::set_surname(const char* surname)
{
  if (surname){
    size_t len =strlen(surname)+1;
    this->surname = new char[len];
    memcpy(this->surname,surname,len);
  }
}

void Bus::set_initials(const char* initials)
{
  if (initials){
    size_t len =strlen(initials)+1;
    this->initials = new char[len];
    memcpy(this->initials,initials,len);
  }
}
