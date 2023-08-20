#include<stdio.h>
#include<math.h>
int main()
{
signed long long int max=(signed long long int)(pow(2,63) -1);
printf("highest number that can be represented by unsigned long long int is %lld\n",max);
signed long long int min=(signed long long int)(pow(2,63)*(-1));
printf("highest number that can be represented by unsigned long long int is %lld\n",min);
return 0;
}