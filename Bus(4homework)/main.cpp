using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include "Bus.hpp"

int main(int argc, char const *argv[]) {
  if (argc!=2){
  cout << "A data-entry error." << endl;
  return 1;
}
  ifstream doc(argv[1]);
  if(!doc)
  return 1;
  int N;
  doc >> N;
  Bus* List = new Bus[N];
  char str[40]; int num;
  for(int i = 0;i<N;i++){
    doc>>str;
    List[i].set_surname(str);
    doc>>str;
    List[i].set_initials(str);
    doc>>str;
    List[i].set_mark_of_bus(str);
    doc>>num;
    List[i].set_year(num);
    doc>>num;
    List[i].set_mileage(num);
    doc>>num;
    List[i].set_busNumber(num);
    doc>>num;
    List[i].set_route(num);
  }
  show_busNumber_for_route(List,1,N);
  show_old_buses(List, N);
  show_buses_over_10000_km(List, N);
  return 0;
}
