#ifndef __TOOLS_H_
#define __TOOLS_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>





void tools_memmory_init(void);

void* tools_malloc (int alloc);

void tools_free(void* ptr, int alloc);

void tools_memory_check_at_end_of_app(void);

void   init_time (void);
double get_time  (void);


#endif