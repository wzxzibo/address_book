a brief test for C++









经验总结

1.通过这个例子，充分理解了为什么那么多程序员都喜欢用指针了，对于指针的使用有了一定的认识，我试图不用指针来完成一个显示结构体数组各个成员的不同属性，结果出现警告：

![image-20210128123358538](C:\Users\wzxzibo\AppData\Roaming\Typora\typora-user-images\image-20210128123358538.png)

事实证明这个地址传递更加节省空间，只占4个字节。

2.在遇到写case时，一定要考虑到所有的情况，这样保证无论你输入的是什么都会有一个合乎逻辑的回应。

3.要充分利用逻辑运算 ，如 ：“（ ？：）”，运用好有奇效。

4.清屏操作

	system("pause");
	system("cls");
