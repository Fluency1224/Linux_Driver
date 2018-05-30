#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>

dev_t devno;
int major = 244;
int minor = 0;
struct cdev cdev;


int hello_open(struct inode *inode, struct file *file)
{
	printk("hello_open\n");
	return 0;
}

int hello_release(struct inode *inode, struct file *file)
{
	printk("hello_release\n");
	return 0;
}

struct file_operations fops={
	.owner = THIS_MODULE,
	.open = hello_open,
	.release = hello_release,
};

int hello_init(void)
{
	int ret;
	
	printk("hello_init\n");
	devno = MKDEV(major, minor);
	
	if((ret = register_chrdev_region(devno, 1, "hello")) != 0)
	{
		printk(KERN_ERR"register_chrdev_region\n");
		return ret;
	}
	cdev_init(&cdev, &fops);
	
	if((ret = cdev_add(&cdev, devno, 1)) < 0)
	{
		printk(KERN_ERR"cdev_add\n");
		unregister_chrdev_region(devno, 1);
		return ret;
	}
	
	return 0;
}

void hello_exit(void)
{
	printk("hello_exit\n");
	cdev_del(&cdev);
	unregister_chrdev_region(devno, 1);
	return;
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("fluency<1005068694@qq.com>");