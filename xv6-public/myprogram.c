#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  printf(1, "parent id = %d\n", getpid());
  int id = getpid();
  fork();
  if(getpid() != id){
    printf(1, "child id = %d\n", getpid());
    for(int i = 0; i < 100; i++);
  }
  else{
    for(int i = 0; i < 100; i++);
    int child = getChildren(getpid());
    printf(1, "getchildren = %d\n", child);
  }
  wait();
  exit();
}
