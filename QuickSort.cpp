#include <stdio.h>
int n, a[100001];

int pozdivizare(int li, int lf)
{
	int i, j, pivot, aux;
	pivot=a[li];
	i=li-1; j=lf+1;
	do
	{
		do{i++;} while(a[i]<pivot);
		do{j--;} while(a[j]>pivot);
		if(i<j)
		{
			aux=a[i];
			a[i]=a[j];
			a[j]=aux;
		}
	}while(i<j);
	return j;
}

void sortare(int li, int lf)
{
	if(li==lf) return;
	else
	{
		int pd;
		pd=pozdivizare(li,lf);
		sortare(li,pd);
		sortare(pd+1,lf);
	}
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sortare(1,n);
	for(i=1; i<=n; i++)
		printf("%d ",a[i]);
	return 0;
}