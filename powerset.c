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
	int tsum;

	if(SUM==0)
	{
		printf("\nSet[");
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

	for(i=S;i<N;i++)
	{
		tsum=SUM-Set[i];

		if(tsum>=0)
		{
			Selected[i]=1;
			power_set(Set, Selected, i+1, N, tsum);
			Selected[i]=0;
		}
	}
}
