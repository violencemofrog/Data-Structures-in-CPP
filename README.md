# Data-Structures-in-Cpp
数据结构笔记（C++实现）

代码参考清华大学MOOC [数据结构（上）](https://next.xuetangx.com/course/THU08091000384/1516243)和 [数据结构（下）](https://next.xuetangx.com/course/THU08091002048/1515966)

# Vector说明
* Vector包含三个属性：
  * size：当前元素数目
  * elem：指针域
  * capacity：数组容量
* 通过复制数组或向量建立vector时，lo下标对应的元素被复制，而hi对应的元素下标未被复制
* 接口函数不包含对边界的检查，越界的情况没有处理
* 给出某个元素的Rank时，这个Rank对应的是该元素下标（从0开始），而不是顺序（从1开始）
* 函数中需要给出序列范围时，前闭后开