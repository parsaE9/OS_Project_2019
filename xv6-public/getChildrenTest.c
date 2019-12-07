#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  int id = getpid();
  fork();
  if(getpid() == id){
    fork();
    if(id == getpid()){
      //1
      printf(1, "pid = %d\tppid = %d\tchildrenId = %d\n", getpid(), getppid(), getChildren(getpid()));
    }
    else if(id != getpid()){
      //3
      sleep(40);
      printf(1, "pid = %d\tppid = %d\tchildrenId = %d\n", getpid(), getppid(), getChildren(getpid()));
    }
  }
  else if(getpid() != id){
    id = getpid();
    fork();
    if(getpid() == id){
      //2
      sleep(20);
      printf(1, "pid = %d\tppid = %d\tchildrenId = %d\n", getpid(), getppid(), getChildren(getpid()));
    }
    else if (getpid() != id){
      //4
      sleep(60);
      printf(1, "pid = %d\tppid = %d\tchildrenId = %d\n", getpid(), getppid(), getChildren(getpid()));
    }
  }
  wait();
  exit();
}
