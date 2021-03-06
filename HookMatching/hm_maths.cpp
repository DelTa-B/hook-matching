/*
   please keep this reference in this file when using this code anywhere
   https://github.com/DelTa-B/hook-matching/
   I would be glad if you give this link when you take part of this file :)
*/
#include "hm_maths.hpp"

int hm_mod(int a, int b)
{
  if (b < 0)
    return -hm_mod(-a, -b);
  int ret = a % b;
  if (ret < 0)
    ret += b;
  return ret;
}

int hm_div(int a, int b)
{
  float ret = 1. * a / b;
  if ((a % b) < 0) // detecting which implementation was chosen
    return (int)ret - 1;
  return (int)ret;
}
