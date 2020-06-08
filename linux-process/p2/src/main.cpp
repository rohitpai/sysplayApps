#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <chrono>  
#include <unistd.h>

using namespace std::chrono;

int main(int argc, char **argv) {

  printf("Starting Application 2\n");
  int ret = 0;

  // We'll operate on the currently running thread.
  pthread_t this_thread = pthread_self();
  // struct sched_param is used to store the scheduling priority
  struct sched_param params;

  int policy = 0;
  ret = pthread_getschedparam(this_thread, &policy, &params);
  if (ret != 0) {
      printf("Couldn't retrieve initial scheduling paramers\n");
      return 0;
  } else {
    // Print thread scheduling priority
    printf("Thread initial priority is %d\n", params.sched_priority); 
  }



  // We'll set the priority to the maximum.
  params.sched_priority = sched_get_priority_max(SCHED_FIFO);

  printf("Trying to set thread realtime prio = %d\n", params.sched_priority);

  // Attempt to set thread real-time priority to the SCHED_FIFO policy
  ret = pthread_setschedparam(this_thread, SCHED_FIFO, &params);
  if (ret != 0) {
      // Print the error
      printf("Unsuccessful in setting thread realtime prio\n");
      return 0;     
  }

  // Now verify the change in thread priority
  ret = pthread_getschedparam(this_thread, &policy, &params);
  if (ret != 0) {
      printf("Couldn't retrieve real-time scheduling paramers\n");
      return 0;
  }

  // Check the correct policy was applied
  if(policy != SCHED_FIFO) {
      printf("Scheduling is NOT SCHED_FIFO!\n");
  } else {
      printf("SCHED_FIFO OK\n");
  }

  // Print thread scheduling priority
  printf("Thread priority is %d", params.sched_priority); 




  while(1){
    microseconds ms = duration_cast< microseconds >(
                        system_clock::now().time_since_epoch());

    printf("Running 2 and time is %lld\n", ms);
    //usleep(1);
  }

  return 0;
}
