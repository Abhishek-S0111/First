#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b,c=0,i,n,m,t[100],d=100;
	printf("Enter the mod key:");
	scanf("%d",&m);
	printf("Enter the no. of elements you want to enter:");
	scanf("%d",&n);
	while(c < d)
	{
		t[c]=NULL;
		c++;
	}
	for(i=0;i<n;i++)
	{
		printf("Enter the element:");
		scanf("%d",&a);
		b=a%m; 
		if (t[b] == NULL)
		{
			t[b] = a;
		}
		else
		{
			while(t[b] != NULL)
			{
				b++;
			}
			t[b]=a;
		}
	}
	for(i=0;i<=n;i++)
	{
		printf("%d\n",t[i]);
	}
	return 0;
}