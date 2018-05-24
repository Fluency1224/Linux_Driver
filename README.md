# Linux_Driver
Linux内核驱动程序例程 

# Linux设备分类：
字符设备

  key led pwm adc 串口
  
块设备

  mem sd tf 
  
网络设备

  net
  
# 模块机制
入口函数： insmod 调用module_init()

函数调用： 直接调用

运行空间： 内核 所有资源都可以访问 SVC SWI

资源释放： rmmod 调用module_exit() 手动释放

sudo dmesg 查看内核dbug

sudo dmesg -c 清除dbug

内核是常驻内存的

