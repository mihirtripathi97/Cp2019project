#include<stdio.h>
#include<math.h>


void Bessals_1(long double B[],long double N[] ,int l, double x)
{
	int k;
	B[0] = (sin(x)/x);
	B[1] = (sin(x)/(x*x)) - (cos(x)/x); 
	N[0] = -(cos(x)/x);
	N[1] = (-sin(x)/x) - (cos(x)/(x*x));
	for(k=2;k<=l;k++)
	{
		B[k] = (2*(k-1) +1)*B[k-1]/x - B[k-2];
		N[k] = (2*(k-1) +1)*N[k-1]/x - N[k-2];
	}

}

	//Reverse Algorythm
	//B[16] = 1.5567E-19;
	//B[15] = 5.13269E-19;
	//for(k=14;k>=10;k--)
	//{
	//B[k] = (2*(k+1) +1)*B[k+1]/x - B[k+2];
	//N[k] = (2*(k+1) +1)*N[k+1]/x - N[k+2];
	//}
	//



int main()
{
	int l,i;
	double x;
	printf("Enter the value of x and l");
	scanf("%lf %d",&x,&l);
	long double B[l],N[l];
	Bessals_1(B, N, l,x);

	for(i=0;i<=l;i++)
	{
		printf("\n B[%d] = %0.19Lf",i,B[i]);
	}	

	for(i=0;i<=l;i++)
	{
		printf("\n N[%d] = %0.19Lf",i,N[i]);
	}	
}