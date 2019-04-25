#include<stdio.h>
#include<assert.h>
typedef struct _person
{
	char name[10];
	int age;
	double height;
}Person;
int main()
{
	FILE *fp;
	int i, res;
	int size;
	Person ary[5]={ {"È«±æ¼ø", 500, 175.3},
			{"ÀÌ½ÂÈñ", 350, 179.5}, {"°­°¨Âù", 25, 175.5},
			{"È«½Â¿¬", 25, 175.3},{"ÀÌ±æ¾Æ", 46, 165.5}};
	Person temp;
	size = sizeof(ary) / sizeof(ary[0]);

	fp=fopen("c:\\data\\ftest.txt", "wb");
	assert(fp!=NULL);
	for(i=0; i<size; i++)
	{
		fwrite(ary+i, sizeof(Person), 1, fp);
	}
	fclose(fp);
	fp=fopen("c:\\data\\ftest.txt", "rb");
	assert(fp!=NULL);
	printf("[1Â÷Ãâ·Â]\n");
	while(!feof(fp))
	{
		res=fread(&temp, sizeof(Person), 1, fp);
		if(res!=1){break;}
		printf("%s %d %.2lf\n",temp.name,temp.age,temp.height);
	}
	rewind(fp);

	printf("[2Â÷Ãâ·Â]\n");
	while(!feof(fp))
	{
		res=fread(&temp, sizeof(Person), 1, fp);
		if(res!=1){break;}
		printf("%s %d %.2lf\n",temp.name,temp.age,temp.height);
	}
	fclose(fp);

	getchar();
	return 0;
}
