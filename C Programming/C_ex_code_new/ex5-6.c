#include<stdio.h>
#include "ex5-6-my.h"
#if defined (IBMPC)
#include "ex5-6-ibmpc.h"
#elif defined (VAX)
#include "ex5-6-vax.h"
#elif defined (MAC)
#include "ex5-6-mac.h"
#else
#include "ex5-6-general.h"
#endif
int main()
{
	printf("%s\n",MSG);

	getchar();
	return 0;
}
