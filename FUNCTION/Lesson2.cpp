#include<bits/stdc++.h>
using namespace std;
int foo(int y);
int foo(int x)
{
  return x+1;
}
int main(int argc, char** argv)
{
  int x = 3;
  int y = 6;

  std::cout << foo(x) << std::endl;

  return 0;
}
