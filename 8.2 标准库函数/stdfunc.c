#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp (const void *px,const void *py)
{
//	int x=0;
//	(double)x;
//	if(��Դ�ز�һ��) return ��Դ��A < ��Դ��B��
//	else return ѧ��A<ѧ��B�� 
	return *((const int *)px) < *((const int *)py);//pxָ�����ֵ����pyָ�����ֵ�������Ӵ�С���򣬿ɰ�>��Ϊ< 
}

int main()
{
	char s[100] = "1 5 4 6 8 3";
	int a[10], n = 0;
	
	int i;
	for (i = 0; i < strlen(s); i += 2) //strlen(s)��ʾ�ַ���s�Ĵ��� 
	{
		sscanf(s+i, "%d", &a[n++]);//    sscanf�����ַ������������� 
	}
	for (i = 0; i < n; i++) 
	{
		sprintf(s+i*3, "%d,,", a[i]); //���һ�����Կ� 
	}
	puts(s);
	printf("\n");
	
	qsort(a, n, sizeof(int), cmp); 
	//qsort������
	//��һ����������������
	//�ڶ��������Ǵ��������еĳ��ȣ�
	//������������ÿ��Ԫ�صĴ�С char��1���ֽڣ�int��4���ֽ�
	//sizeof(int)������int�Ĵ�С��ͬ����sizeof(char),sizeof(double)��
	//���ĸ�������һ������������Ϊ˵������Ĺ��� 
	
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]); //��������Ľ��һ�����Կ� 
	}
	printf("\n");
	
	while(1);
	
	return 0;
}

