#include<stdio.h>
struct Person
{
	char name[20];
	char addr[40];
	int  age;
};
struct  Student
{
	int number;
	struct Person  info;
};
int main()
{
	struct Student s1 = { 1, {"ȫ�浿", "����", 21} };
	struct Student s2 = { 2, {"�̼���", "�︪��", 25} };

	printf("�й�: %d, ����: %s, �ּ�: %s, ����: %d\n", s1.number,
			s1.info.name, s1.info.addr, s1.info.age);
	printf("�й�: %d, ����: %s, �ּ�: %s, ����: %d\n", s2.number,
			s2.info.name, s2.info.addr, s2.info.age);

	getchar();
	return 0;
}
