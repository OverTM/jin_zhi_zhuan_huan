#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int TenNum(char a[], int B);              //�����������ת����10������
void Numchange(int m, int B);            //��ת�����˵�10������ת��Ϊ���������
int TenNum(char a[], int B)
{
	int len, i, num;
	int sum = 0;
	len = strlen(a);                    //����ַ�������
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
			printf("%d", n);           //С��10ֱ�����
		else
			printf("%c", n + 55);      //����10ת�����ַ����
	}
}
int main()
{
	int B, b;
	char a[20];
	printf("�������ת�����Ľ��ƣ�2-16����");
	do {
		scanf_s("%d", &B);
	} while (B < 2 && B > 16);
	printf("�������ת������");
	getchar();
	gets_s(a,20);                        //�������n���������������a��
	int m = TenNum(a, B);             //�����������ת����ʮ������
	printf("��������Ҫת�ɼ���������2-16����");
	do {
		scanf_s("%d", &b);
	} while (B < 2 && B > 16);
	printf("%d������%sת��Ϊ%d�������Ľ��Ϊ��", B, a, b);
	Numchange(m, b);                 //��ʮ������ת��Ϊ���������
	printf("\n");
	system("pause");
	return 0;
}