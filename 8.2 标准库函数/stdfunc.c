#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp (const void *px,const void *py)
{
//	int x=0;
//	(double)x;
//	if(生源地不一样) return 生源地A < 生源地B；
//	else return 学号A<学号B； 
	return *((const int *)px) < *((const int *)py);//px指向的数值大于py指向的数值，如果想从大到小排序，可把>改为< 
}

int main()
{
	char s[100] = "1 5 4 6 8 3";
	int a[10], n = 0;
	
	int i;
	for (i = 0; i < strlen(s); i += 2) //strlen(s)表示字符串s的串长 
	{
		sscanf(s+i, "%d", &a[n++]);//    sscanf：从字符串中输入数据 
	}
	for (i = 0; i < n; i++) 
	{
		sprintf(s+i*3, "%d,,", a[i]); //输出一下试试看 
	}
	puts(s);
	printf("\n");
	
	qsort(a, n, sizeof(int), cmp); 
	//qsort：排序
	//第一个参数是数组名，
	//第二个参数是待排序序列的长度，
	//第三个参数是每个元素的大小 char是1个字节，int是4个字节
	//sizeof(int)：就是int的大小，同理有sizeof(char),sizeof(double)等
	//第四个参数是一个函数，功能为说明排序的规则 
	
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]); //输出排序后的结果一下试试看 
	}
	printf("\n");
	
	while(1);
	
	return 0;
}

