#include "types.h"
#include "stat.h"
#include "user.h"

void create_process(){
  int n = 3;
  for(int i = 0; i < n; i++){
    int id = fork();
    if(id < 0){
      printf(1, "%d failed in fork!\n", getpid());
    }else if(id > 0){
      printf(1, "parent %d creating child %d\n", getpid(), id);
      wait();
    }else{
      printf(1, "child %d createdd \n", getpid());
        int k = 0;
        for(int j = 0; j < 8000000; j++){
          k = 456 * 3 + 2.354;
        }
        if(k != 0)
          break;
    }
  }
  exit();
}

void print_table(){
  ppt();
  exit();
}


int
main(int argc, char *argv[])
{
  int input = atoi(argv[1]);
  if(input == 1){
    print_table();
  }else if(input == 2){
    create_process();
  }
  getppid();
  printf(1,"**");




  wait();
  exit();
}
