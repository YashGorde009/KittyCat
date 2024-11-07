#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[],char *en[])
{
  	int i,j,c,arr[argc],ele;
	
	for(j=0;j<argc-1;j++)
	{
		int n=atoi(argv[j]);
		arr[j]=n;
	}
	
	ele=atoi(argv[j]);
	i=0;j=argc-1;
	c=(i+j)/2;
	while(arr[c]!=ele && i<=j)
	{
		if(ele>arr[c])
		i=c+1;
		else
		j=c-1;
		c=(i+j)/2;
	}
	if(i<=j)
	printf("\n Element found in given array");
	else
	printf("\n Elements not found in given array");
	return 0;
}

/*
[kiosk@foundation5 ~]$ gcc s2a.c -o first
[kiosk@foundation5 ~]$ gcc s2b.c -o second
[kiosk@foundation5 ~]$ ./first ./second

 Enter the size of array
6

 Enter the numbers
6
8
4
9
6
0

 Elements entered are
684960
 Sorted elements are
:046689
 Enter element to search:6

 Element found in given array[kiosk@foundation5 ~]$ 
*/
