#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <chrono>  
#include <unistd.h>

using namespace std::chrono;

int main(int argc, char **argv) {

  printf("Starting Application 1\n");
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

  while(1){
    microseconds ms = duration_cast< microseconds >(
                        system_clock::now().time_since_epoch());

    printf("Running 1 and time is %lld\n", ms);
    //usleep(1);
  }

  return 0;
}
