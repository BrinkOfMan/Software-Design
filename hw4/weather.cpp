#include"../show_mem.h"

int main() {
  init();

  fetch("https://api.weather.gov/gridpoints/MPX/111,47/forecast", -2000);
  
  int posOriginal;
  int posNew;

  for (posOriginal = 0; posOriginal <= 15; posOriginal++){
    //goes through all the characters in "detailedForecast"
    posNew = posOriginal + 576;             //new character is 576 places away from the original (index 576 is "d" and 591 is "t")
    char &cOriginal = char_at(posOriginal); //assign a character to a new place in memory
    cOriginal = char_at(posNew);            //replace what that character is with the character 576 places away
  }

  quit();
}
