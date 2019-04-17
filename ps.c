#include "types.h"
#include "stat.h"
#include "user.h"
#include "ProcessInfo.h"

int
main(int argc, char *argv[])
{
    int i;
    char *stateArr[] = { "UNUSED", "EMBRYO", "SLEEPING", "RUNNABLE", "RUNNING", "ZOMBIE" };
//    for(i = 1; i < argc; i++)
//        printf(1, "%s%s", argv[i], i+1 < argc ? " " : "\n");

    struct ProcessInfo pi[64];
    struct ProcessInfo *p;
    p = &pi[0];
    int res;
    res = getprocs(p);
    printf(1, "%s%d%s","The number of current processes is ", res, "\n");
    for(i =0; i<res; i++, p++) {
        printf(1, "%d  %d  %s  %d  %s%s", p->pid,  p->pid == 1 ? -1 : p->ppid, stateArr[p->state], p->sz, p->name, "\n");
    }
    exit();
}