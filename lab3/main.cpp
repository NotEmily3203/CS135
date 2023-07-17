// Name: Emily Lin; Github: NotEmily3203
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
#include "reverseorder.h"
int main()
{
  std::cout << "East basin storage on 05/20/2018: " << get_east_storage("05/20/2018") << " billion gallons" << std::endl;
  std::cout << "East basin storage on 01/01/2018: " << get_east_storage("01/01/2018") << " billion gallons" << std::endl;
  std::cout << "East basin storage on 02/07/2018: " << get_east_storage("02/07/2018") << " billion gallons" << std::endl;
  std::cout << "minimum storage in East basin: " << get_min_east() << " billion gallons" << std::endl;
  std::cout << "maximum storage in East basin: " << get_max_east() << " billion gallons" << std::endl;
  std::cout << "09/13/2018:" << compare_basins("09/13/2018");
  std::cout << "02/09/2018:" << compare_basins("02/09/2018");
  reverse_order("05/29/2018", "06/02/2018");
  reverse_order("01/01/2018", "01/10/2018");
  return 0;
}
