#ifndef KERNEL
#define KERNEL
#define QUEUE_SIZE 64

struct task_struct {
    unsigned long long x19;
    unsigned long long x20;
    unsigned long long x21;
    unsigned long long x22;
    unsigned long long x23;
    unsigned long long x24;
    unsigned long long x25;
    unsigned long long x26;
    unsigned long long x27;
    unsigned long long x28;
    unsigned long long x29;
    unsigned long long x30;
    char *kstack_top;

    int valid;
    int id;
    int status;
};

struct run_queue {
    struct task_struct* queue[QUEUE_SIZE];
    unsigned int start;
    unsigned int end;
    int size;
};

int kernel_init();

int privilege_task_create(void(*func)());

extern struct task_struct* get_current();

void init();

void context_switch(struct task_struct* next);

void test();

#endif
