#include "sheet.hpp"
#include <iostream>

using namespace std;

int main(){
  Sheet *s1 = new Sheet(1, "A3");
  Sheet *s2 = new Sheet(2, "A3");
  Sheet s3 = *s1;
  s3 = *s1;
  s3 = *s2;

  delete s2;
  delete s1;
  
  return 0;
}