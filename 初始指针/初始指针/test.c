#include<stdio.h>
//指针是个变量，存放内存单元的地址（编号）

//指针就是变量，用来存放地址的变量（存放在指针中的值都被当成地址处理）

//一个单元到底多大：（一个字节）

//32位的机器上，地址是32个0或者1组成二进制序列，那地址就得有4个字节的空间来存储，所以一个指针变量的大小就是4个字节

//64位的机器上，地址是64个0或者1组成二进制序列，那地址就得有8个字节的空间来存储，所以一个指针变量的大小就是8个字节
//int main()
//{
//	printf("%d\n", sizeof(char*));//8
//	printf("%d\n", sizeof(int*));//8
//	printf("%d\n", sizeof(double*));//8
//	printf("%d\n", sizeof(short*));//8
//	return 0;
//}

//指针和指针类型
//指针是用来存放地址的，地址指向真正的值，值有类型
//两个16进制位表示一个字节
//int main()
//{
//	int a = 0x11223344;
//	//int* pa = &a;
//	//*pa = 0;//进行调试内存看看
//	char* pc = &a;
//	*pc = 0;
//	//printf("%p\n", pa);
//	printf("%p\n", pc);
//	return 0;
//}
//指针类型决定了指针进行解引用操作的时候，能够访问空间的大小
//int*p  *p能够访问4个字节
//char*p *p能够访问1个字节
//double*p *p能够访问8个字节


//指针+-整数
//int main()
//{
//	int a = 0x11223344;
//	int* pa = &a;
//	char* pc = &a;
//	printf("%p\n", pa);
//	printf("%p\n", pa+1);//跳过四个字节找到下一个整型地址  比如地址是：125变成了129   ；跳过一个整型
//
//	printf("%p\n", pc);
//	printf("%p\n", pc+1);//跳过一个字节找到下一个字符地址 比如地址是：125变成了126    ；跳过一个字符
//	return 0;
//}
//指针类型决定的：指针走一步有多远（指针的步长）
//int*p；p+1-->4
//char*p; p+1-->1
//double*p; p+1-->8


//int main()
//{
//	int arr[10] = { 0 };
//	//int* p = arr;//每间隔4个字节改变一个0->1
//	char* p = arr;//每间隔1个字节改变一个0->1
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = 1;
//	}
//	return 0;
//}


//野指针 概念：野指针就是指针指向位置是不可知的（随机的，不正确的，没有明确限制的）；野指针是要避免的
//  1. 指针未初始化
//int main()
//{
//	int a;//局部变量不初始化，默认为随机值
//	int* p;//局部的指针变量，就被初始化为随机值
//	*p = 20;//这样就随机地址 改变了很多值，不可控
//	return 0;
//}

//  2. 指针的越界访问(被称为野指针）
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 12; i++)
//	{
//		p++;//地址加到10，11超出了p指针的地址   指针越界
//	}
//	return 0;
//}

//  3. 指针指向内存空间释放
//int* test()
//{
//	int a = 20;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	//*p = 40;//在形参部分创建了一块地址，return &a的时候销毁地址，把地址传递给了p，把内存返回给了计算机，*p=40，
//	printf("%d\n", *p);	//*p想通过p找到&a，但是&a已被销毁
//	p=NULL;
// return 0;
//}

//  如何避免野指针
//  1. 指针初始化
//  2. 小心指针越界
//  3. 指针指向空间释放即把指针设置为NULL
//  4. 指针使用之前检查有效性
//int main()
//{
//	int a = 10;
//	int* p = &a;//初始化
//	int* pa = NULL;//NULL 用来初始化指针，给指针赋值，  空指针
//	return 0;
//}


//指针运算
//  1. 指针的加减
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *p);
//		p++;
//	}
//	return 0;
//}
//#define N_VALUES
//float values[N_VALUES];
//float* vp;
//for (vp = &values[0]; vp < &values[N_VALUES];)
//{
//	*vp++ = 0;
//}

//指针减去指针
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	char ch[5] = { 0 };
//	printf("%d\n", &arr[9] - &arr[1]);//两个地址间的元素个数
//	//printf("%d\n", &arr[9] - &ch[0]);//这个就是不符合规定的错误示范。指针在相同空间中才能相减
//	return 0;
//}


//自定义strlen
//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - start;
//}
//int main()
//{
//	char arr[] = "bit";
//	int a = my_strlen(arr);
//	printf("%d\n", a);
//	return 0;
//}


//指针的关系运算
//#define N_VALUES 5
//float values[N_VALUES];
//float* vp;
//for (vp = &values[N_VALUES]; vp > values[0];);//5,  5>0,  先5-1=4，再赋值给*vp循环下去
//{
//	*--vp = 0;
//}
//  最好用上边这种写法，虽然下边那种很正规，但是标准并不保证他可行

//  c语言的标准规定：允许指向数组元素的指针与指向数组最后一个元素后面那个内存位置的指针比较，但是不允许
//  与指向第一个元素之前的那个内存位置的指针进行比较
//         比如下面那个例子：最后一次使用-1和0作比较，左边超出了指向的第一个元素
//#define N_VALUES 5
//float values[N_VALUES];
//float* vp;
//for (vp = &values[N_VALUES-1]; vp >= values[0];vp--);//5-1=4，4>0,进入循环，*vp=0，vp--直到循环结束
//{
//	*vp = 0;
//}


//指针和数组
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);//首元素地址
//	printf("%p\n", arr+1);
//
//	printf(" %p\n", &arr[0]);
//	printf(" %p\n", &arr[0]+1);
//
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);
//	//     只有以下两种情况arr不表示首元素地址
//	// 1. &arr-&数组名- 数组名不是首元素地址，数组名表示整个数组，&数组名取出的是整个地址的大小
//	// 2. sizeof（arr）-sizeof（数组名）-数组名表示整个数组-sizeof（数组名）计算的是整个数组大大小
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//		printf("%d ", *(p + i));
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p+i));
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("\n%p====%p\n", p + i,&arr[i]);
//	}
//	return 0;
//}


//二级指针
//int main()
//{
//	int a = 10;
//	int * pa = &a;//*表示pa是指针，int表示pa指向的a是int类型
//	int* * ppa = &pa;//ppa就是二级指针   右边的那颗星表示ppa是指针 int*表示ppa指向对象pa的类型是int*
//	int** * pppa = &ppa;//pppa三级指针   右边的那颗星表示pppa是指针 int**表示pppa指向对象ppa的类型是int**
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	int* * pa = &p;
//	**pa = 20;
//	printf("%d\n", **pa);
//	return 0;
//}


//指针数组 本质是 数组
//数组指针 本质是 指针
//  我们已知的有 整型数组int arr[10]，字符数组char arr[10] 。现在要加一个指针数组int* arr[10]
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int i = 0;
//	int* arr[3] = { &a,&b,&c };
//	printf("%d\n", *arr[0]);
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", *(arr[i]));
//	}
//	return 0;
//}