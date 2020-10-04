#include"../react.h"

struct City{

  int population;

};

struct State{
  int avgTemp;
  short seasons;
  City nested;
};

int main(){

  City Northfield{20007};

  State Minnesota{32,11,Northfield};

  City *nfld = &Northfield;

  print("The population of Northfield, Minnesota is {pop}\n",{{"pop",nfld->population}});

  State *mn = &Minnesota;

  print("The number of actual seasons in Minnesota is {seasons}\n",{{"seasons",mn->seasons}});

  print("The average temperature in Minnesota is is {temp}\n",{{"temp",mn->avgTemp}});

  print("The population of Northfield (using fancy nested structs) is {pop}\n",{{"pop",Minnesota.nested.population}});
  
  return 0;
}
