#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int a = atoi(argv[1]);
  printf(1, "%d\nargument is %d", argc, a);
  wait();
  exit();
}
