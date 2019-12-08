#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int a = atoi(argv[1]);
  //sleep(10);
  printf(1, "argument is %d\nsyscall number is %d\n", a, getCount(a));
  //int num[100] = {1,2,3,4};
  //num[4] = 67;
  //printf(1, "%d", num[4]);
  wait();
  exit();
}
