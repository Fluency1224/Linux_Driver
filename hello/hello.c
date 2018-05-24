#include <linux/module.h>
#include <linux/kernel.h>

int hello_init(void)
{
	printk("hello_init\n");
	return 0;
}

void hello_exit(void)
{
	printk("hello_exit\n");
	return;
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("fluency<1005068694@qq.com>");