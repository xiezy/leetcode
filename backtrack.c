#include<stdio.h>
#include <stdbool.h>
#define MAXCANDIDATES 100
#define NMAX 100000
bool finished  = false;
bool is_a_solution(int a[], int k, int n)
{
	return (k == n);                /* is k == n? */
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
	c[0] = true;
	c[1] = false;
	*ncandidates = 2;
}

void process_solution(int a[], int k)
{

	int i;	/* counter */
	printf("{");
	for (i=1; i<=k; i++)
  	if (a[i] == true) printf(" %d",i);
	printf(" }\n");
}

void backtrack(int a[], int k, int input)
{

	int c[MAXCANDIDATES];
	int ncandidates;
	int i;
	/* candidates for next position */
	/* next position candidate count */
	/* counter */
	if (is_a_solution(a,k,input))
  	process_solution(a,k);
	else {
		k = k+1;
    construct_candidates(a,k,input,c,&ncandidates);
   	for (i=0; i<ncandidates; i++) {
			a[k] = c[i];
			backtrack(a,k,input);
			if (finished) return;			/* terminate early */
		} 
	}
}
void generate_subsets(int n)
{
	int a[NMAX];                    /* solution vector */
	backtrack(a,0,n);
}

int main()
{
	int n;
	printf("enter n\n");
	scanf("%d",&n);
	generate_subsets(n);
}
