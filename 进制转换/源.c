#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int TenNum(char a[], int B);              //将输入的数字转换成10进制数
void Numchange(int m, int B);            //将转换好了的10进制数转换为所需进制数
int TenNum(char a[], int B)
{
	int len, i, num;
	int sum = 0;
	len = strlen(a);                    //求得字符串长度
	for (i = 0; i < len; i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
			num = a[i] - '0';
		else if (a[i] >= 'A' && a[i] <= 'F')
			num = a[i] - 'A' + 10;
		sum = sum * B + num;
	}
	return sum;
}
void Numchange(int m, int B)
{
	int n;
	if (m)
	{
		Numchange(m / B, B);
		n = m % B;
		if (n < 10)
			printf("%d", n);           //小于10直接输出
		else
			printf("%c", n + 55);      //大于10转换成字符输出
	}
}
int main()
{
	int B, b;
	char a[20];
	printf("请输入待转换数的进制（2-16）：");
	do {
		scanf_s("%d", &B);
	} while (B < 2 && B > 16);
	printf("请输入待转换数：");
	getchar();
	gets_s(a,20);                        //将输入的n进制数存放在数组a中
	int m = TenNum(a, B);             //将输入的数字转换成十进制数
	printf("请输入需要转成几进制数（2-16）：");
	do {
		scanf_s("%d", &b);
	} while (B < 2 && B > 16);
	printf("%d进制数%s转换为%d进制数的结果为：", B, a, b);
	Numchange(m, b);                 //将十进制数转换为所需进制数
	printf("\n");
	system("pause");
	return 0;
}