#include <linux/module.h>
#include <linux/kernel.h>

int howmany = 10;
char *whom="kernel";

int hello_init(void)
{
	printk("hello_init\n");
	printk("howmany=%d whom=%s \n", howmany, whom);
	return 0;
}

void hello_exit(void)
{
	printk("hello_exit\n");
	printk("howmany=%d whom=%s \n", howmany, whom);
	return;
}

module_param(howmany, int, 0600);
module_param(whom, charp, 0600);

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("fluency<1005068694@qq.com>");