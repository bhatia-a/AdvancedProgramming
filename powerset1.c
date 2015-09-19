/* Power Set Problem ! */

/* Approach : Backtracking */

/* Solution using recursion where recursion is made on selection or deselection
 * of a participating item */

# include <stdio.h>
# define MAX_NUM 10

void power_set(int Set[MAX_NUM], int Selected[MAX_NUM], int S, int N,int SUM);

int main()
{
	int N,SUM;
	int Set[MAX_NUM];
	int Selected[MAX_NUM]={0,};

	scanf("%d %d",&N,&SUM);

	int i;

	for(i=0;i<N;i++)
	{
		scanf("%d",&Set[i]);
	}
	
	power_set(Set,Selected,0,N,SUM);

	printf("\n");
}

void power_set(int Set[MAX_NUM], int Selected[MAX_NUM], int S, int N,int SUM)
{
	int i;
	if(SUM==0)
	{
		printf("\n[");
		for(i=0;i<N;i++)
		{
			if(Selected[i]==1)
			{
				printf("%d,",Set[i]);
			}
		}
		printf("\b]");
		return;
	}

	if(S==N || SUM<0)
	{
		return;
	}

	power_set(Set,Selected,S+1,N,SUM);

	Selected[S]=1;
	power_set(Set,Selected,S+1,N,SUM-Set[S]);
	Selected[S]=0;
}
