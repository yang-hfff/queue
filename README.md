# 环形队列

#### 介绍
循环队列c语言简单实现，可以用来作为串口的缓冲，解决数据大批传送单片机处理不过来导致丢包的问题


#### 安装教程

1.  把queue.c,queue.h放入工程,初始化
*定义全局,推荐在对应的.c*
```
//队列结构体
Q que;
//数据缓存
uint8_t buf[BUF_SIZE];
```
*初始化段加入以下*

```
//初始化队列
Q_init(&que,buf,BUF_SIZE);
```
2.  在串口(或IIC,SPI等)中断里面判断队列不满的情况下入队
```
/*串口中断服务函数中*/
if(!Q_isFull(&que))
{
    /*temp为串口接收到的数据*/
    Q_enQueue(&que,temp);
}
```
3.  在其它的地方逐个出队处理直到队列为空
```
/*程序其它对速度要求不高的地方，比如main里面*/
while(!Q_isEmpty(&que))
{
    temp = Q_deQueue(&que);
    /*在这里处理...*/
}
```

#### 使用说明

1.  可以调整QING_QUEUE_SIZE从而调整队列大小
```
/**
 * @brief 队列初始化
 * @param queue 队列指针
 * @param size 数据存储区大小
 * @param base 数据存储区首地址
 * @retval None
 * @note 一定要为队列结构体分配内存
*/
void Q_init(RQ *queue,uint8_t *base,uint32_t size);
```
2.  可以使用USE_MACRO_SPEED_UP调为1从而使程序加速(减少函数调用开销)
```
/*使用宏加速(用函数会有调用开销)*/
#define USE_INLINE_SPEED_UP  1
```
3.  数据入队之前一定要判断是否已满(满了就不能入队了)，出队之前一定要判断是否为空(空了就不能出队了)

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request

