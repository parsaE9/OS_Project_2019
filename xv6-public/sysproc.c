#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// return the year of which the Unix version 6 was released
int
sys_getyear(void)
{
return 1975;
}

// returns the parent process id
int
sys_getppid(void)
{
    return getppid(myproc());
}

//return the process id of it's children
int
sys_getChildren(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return getChildren(pid);
}

//return number of times a systemcall was called
int
sys_getCount(void)
{
  int n;

  if(argint(0, &n) < 0)
    return -1;
  return getCount(n, myproc());
}

//print process TABLE
int
sys_ppt(void)
{
  return ppt();
}

int
sys_changePolicy(void)
{
  int n;

  if(argint(0, &n) < 0)
    return -1;
  return changePolicy(n);
}
