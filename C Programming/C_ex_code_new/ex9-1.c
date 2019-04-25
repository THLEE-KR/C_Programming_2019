#include <stdio.h>
#include <assert.h>
#define FILE_OPEN(fp, filename, mode) if((fp=fopen(filename, mode))==NULL){  \
		printf("File open error!\n"); \
		getchar(); \
		return  0; \
}
int main(int argc, char  *argv[])
{
	int c;
	FILE *ifp, *ofp;
	if(argc !=  3)	{
		printf("사용법 : %s 원본파일 복사본파일\n", argv[0]);
		getchar();
		return  0;
	}
	FILE_OPEN(ifp, argv[1], "rb");
	FILE_OPEN(ofp, argv[2], "wb");

	while((c=fgetc(ifp))!=EOF) {
		fputc(c,ofp);
	}
	fclose(ifp);
	fclose(ofp);

	getchar();
	return  0;
}
