#include "relogio.h"
#include "relogio.cpp"

int main()
{
  config();
  printa();
  while (1)
  {
    Sleep(950);
    relogioCalendario();
    printa();
  }
}
