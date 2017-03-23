#ifndef _BUS_HPP_
#define _BUS_HPP_
class Bus{
public:
  Bus();
  ~Bus();
  Bus(const Bus& rhs);
  const int get_busNumber() const;
  const int get_year() const;
  const int get_mileage() const;
  const int get_route() const;
  const char* get_surname() const;
  const char* get_mark_of_bus() const;
  const char* get_initials()const;
  void set_busNumber(const int bus_number);
  void set_year(const int year);
  void set_mileage(const int mileage);
  void set_route(const int route);
  void set_surname(const char* surname);
  void set_mark_of_bus(const char* mark_of_bus);
  void set_initials(const char* initials);
  void show_name() const;
  void show_mark_of_bus() const;
  void show_busNumber() const;
  void show_year() const;
  void show_mileage() const;
  void show_route() const;

private:
  char* surname;
  int bus_number;
  char* mark_of_bus;
  int year;
  int mileage;
  int route;
  char* initials;
};

void show_busNumber_for_route(Bus* List,int route_number, int N);
void show_old_buses(Bus* List,int N);
void show_buses_over_10000_km(Bus* List, int N);

#endif
