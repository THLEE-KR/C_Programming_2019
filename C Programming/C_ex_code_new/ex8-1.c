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
	struct Student s1 = { 1, {"홍길동", "서울", 21} };
	struct Student s2 = { 2, {"이순신", "울릉도", 25} };

	printf("학번: %d, 성명: %s, 주소: %s, 나이: %d\n", s1.number,
			s1.info.name, s1.info.addr, s1.info.age);
	printf("학번: %d, 성명: %s, 주소: %s, 나이: %d\n", s2.number,
			s2.info.name, s2.info.addr, s2.info.age);

	getchar();
	return 0;
}
