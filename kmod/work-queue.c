#include <linux/module.h> 
#include <linux/init.h> 
#include <linux/sched.h> 
#include <linux/time.h> 
#include <linux/delay.h> 
#include<linux/workqueue.h> 
 
static DECLARE_WAIT_QUEUE_HEAD(my_wq); 
static int condition = 0; 
 
 /*
 Log
[  172.147125] 000: Wait queue example
[  172.147162] 000: Going to sleep my_init
[  172.147184] 000: Waitqueue module handler work_handler
[  177.201274] 000: Wake up the sleeping module
[  177.201314] 000: woken up by the work job
[  198.256330] 000: waitqueue example cleanup

 */
/* declare a work queue*/        
static struct work_struct wrk; 
static struct work_struct wrk_extra; 

static void work_handler_extra(struct work_struct *work) 
{  
    printk("Waitqueue module handler %s\n", __FUNCTION__); 
    msleep(500); 
    printk("Wake up the sleeping module %s\n", __FUNCTION__); 

} 

static void work_handler(struct work_struct *work) 
{  
    printk("Waitqueue module handler %s\n", __FUNCTION__); 
    msleep(5000); 
    printk("Wake up the sleeping module\n"); 
    condition = 1; 
    wake_up_interruptible(&my_wq); 
} 
 
static int __init my_init(void) 
{ 
    printk("Wait queue example\n"); 
 
    INIT_WORK(&wrk, work_handler); 
    schedule_work(&wrk); 
 
    INIT_WORK(&wrk_extra, work_handler_extra); 
    schedule_work(&wrk_extra); 

    printk("Going to sleep %s\n", __FUNCTION__); 
    wait_event_interruptible(my_wq, condition != 0); 
 
    pr_info("woken up by the work job\n"); 
    return 0; 
} 
 
void my_exit(void) 
{ 
    printk("waitqueue example cleanup\n"); 
} 
 
module_init(my_init); 
module_exit(my_exit); 
MODULE_AUTHOR("John Madieu <john.madieu@foobar.com>"); 
MODULE_LICENSE("GPL"); 