// switch:
// en.cppreference.com/w/cpp/language/switch.html

#include <iostream>

int main()
{
  std::cout << "1 - prva\n"
            << "2 - druga\n"
            << "3 - treca\n"
            << std::endl;

  int opcija = 3;

  ///////////////////////////////////////////////////////////

  switch (opcija)
  {
  case 1:
    std::cout << "Izabrana je prva opcija" << std::endl;
    break;
  case 2:
    std::cout << "Izabrana je druga opcija" << std::endl;
    break;
  case 3:
    std::cout << "Izabrana je treca opcija" << std::endl;
    break;
  default:
    std::cout << "Izabrana je nevalidna opcija" << std::endl;
    break;
  }

  ///////////////////////////////////////////////////////////

  // falltrough
  switch (opcija)
  {
  case 1:
  case 2:
  case 3:
    std::cout << "Opcija je validna" << std::endl;
    break;
  default:
    std::cout << "Opcija nije validna" << std::endl;
  }

  ///////////////////////////////////////////////////////////

  char c = 'a';
  switch (c)
  {
  case 'a':
  {
    int ascii = 'a';
    std::cout << "ASCII a -> " << ascii << std::endl;
  }
  break;
  case 'b':
    break;
  default:
    std::cout << "Default" << std::endl;
  }
}
