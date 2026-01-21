#include <stdio.h>

int main(){
	int x1,x2,y;
	float z;
	x1=7;
	x2=2;
	printf("1/ %d/%d=%f\n",x1,x2,x1/x2);

	y=x1/x2;
	printf("2/ %d/%d=%d\n",x1,x2,y);

	z=x1/x2;
	printf("3/ %d/%d=%f\n",x1,x2,z);

	z=(x1+0.0)/x2;
	printf("4/ %d/%d=%f\n",x1,x2,z);

	z=((float)x1)/x2;
	printf("5/ %d/%d=%f\n",x1,x2,z);

	z=(float)(x1/x2);
	printf("6/ %d/%d=%f\n",x1,x2,z);

	return 0;
}
