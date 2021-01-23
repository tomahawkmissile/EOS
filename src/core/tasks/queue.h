#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "../debug/debug.h"
#include "../utils/string/strings.h"
#include "../../HAL/time/time.h"

struct TaskArguments {
  int length;
  const char* elements;
};
struct TaskTimer {
  bool (*func)(TaskArguments args); //boolean is if the task completed. Functions should always return false if it is an infinite task
  TaskArguments args; //Argument to pass to callback
  int id; //ID of the task
  unsigned long start; //Time started
  unsigned long delay; //Delay between calling and start
  unsigned long interval; //Delay between runs
  unsigned long lastrun; //Last run time. 0 means never ran before
  unsigned long timeout; //Time until it gives up. Set to 0 to disable
};

const TaskArguments NULL_ARGS = (TaskArguments) {.length=0,.elements=NULL}; //Null struct for referencing

#endif