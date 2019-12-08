#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int number = atoi(argv[1]);
  int id = getpid();
  fork();
  if(getpid() == id){
    sleep(2);
    sleep(10);
    sleep(3);
    sleep(4);
    printf(1, "parent : systemcall with number %d was called %d times!\n", number, getCount(number));
    wait();
  }
  else{
    sleep(3);
    printf(1, "child : systemcall with number %d was called %d times!\n", number, getCount(number));
  }
  wait();
  exit();
}
