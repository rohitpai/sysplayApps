#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <chrono>  
#include <unistd.h>
#include <gpiod.h>

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

  struct gpiod_chip *chip;
	struct gpiod_line *line;
	int req, value;

	chip = gpiod_chip_open("/dev/gpiochip1");
	if (!chip)
		return -1;

	line = gpiod_chip_get_line(chip, 23);
	if (!line) {
		gpiod_chip_close(chip);
		return -1;
	}

	req = gpiod_line_request_output(line, "gpio_state", 0);
	if (req) {
		gpiod_chip_close(chip);
		return -1;
	}

  value = 1;
	gpiod_line_set_value(line, value);

	printf("GPIO value is: %d\n", value);

    microseconds ms = duration_cast< microseconds >(
                        system_clock::now().time_since_epoch());
    microseconds msold = duration_cast< microseconds >(
                        system_clock::now().time_since_epoch());

  while(1){
    ms = duration_cast< microseconds >(
                        system_clock::now().time_since_epoch());

    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(ms - msold).count();

    if(diff > 200000){
     	gpiod_line_set_value(line, value);
      value = !value;
      msold = ms;
      printf("GPIO value is: %d\n", value);
    }

    //usleep(1000);
  }



	gpiod_chip_close(chip);

  
  return 0;
}
