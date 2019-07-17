#include <linux/init.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

int proc_init(void) {
    struct task_struct *task;
    unsigned long long used_jiffies= 0;

    printk(KERN_INFO "F\tS\tUID\tPID\tPPID\tC\tPRI\tNI\tADDR\tSZ\tWCHAN\tTTY\tTIME\tCMD\n");
    for_each_process(task) {
        printk(KERN_INFO "%d\t%d\t%d\t%d\t\%d\t", 
               task->flags, task->state, task->cred->uid, 
               task->pid, task->parent->pid);
        used_jiffies += task->
    }
    return 0;
}

void proc_exit(void) {
    return;
}

module_init(proc_init);
module_exit(proc_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("proc stat");
MODULE_AUTHOR("Shengjun Ma");