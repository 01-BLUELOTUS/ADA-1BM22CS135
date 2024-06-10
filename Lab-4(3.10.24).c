#include<stdio.h>
#include<stdlib.h>


void topologicalSorting(int arr[10][10],int n){
    int in[n],out[n],s[n],top=-1;
	int i,j,k=0;
	for(i=0;i<n;i++){
		in[i]=0;
		for(j=0;j<n;j++){
			if(arr[j][i]==1)
				in[i]++;
		}
	}

	while(1){
		for(i=0;i<n;i++)
			if(in[i]==0){
				s[++top]=i;
				in[i]=-1;
			}

		if(top==-1)
			break;

		out[k]=s[top--];

		for(i=0;i<n;i++){
			if(arr[out[k]][i]==1){
				in[i]--;
			}
		}
		k++;
	}

	printf("Topological sorting order is \n");
	for(i=0;i<n;i++)
		printf("%d ",out[i]+1);
}

int main(){
	int n;
	printf("Enter the number of vertices in graph: ");
	scanf("%d",&n);

	int arr[10][10];
	printf("Enter the adjacency matrix for the graph\n");

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&arr[i][j]);

	topologicalSorting(arr,n);
	return 0;
}
