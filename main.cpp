#include "lab2.h"

int main() {      
  std::cout << "function: cos(x)th(x)" << "\tinterval: [ 7; 11 ]\n\n";
  double a2 = 7, b2 = 11; // границы интервала
  std::cout << "Unimodal:\n";
  // случайный поиск для унимодальной функции
  random_search(a2, b2, 'u');
  std::cout << "Multimodal:\n";
  // случайный поиск для мультимодальной функции
  random_search(a2, b2, 'm');
  break;
  return 0;
}
