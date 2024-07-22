#include <stdio.h>
#include <stdlib.h>

struct Job{
	char id;
	int deadline;
	int profit;
};

int compareJobs(const void* a, const void* b){
	return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

void jobSequencing(struct Job jobs[], int n){
	qsort(jobs, n, sizeof(struct Job), compareJobs);

	int maxDeadline = 0;
	for(int i = 0; i < n; i++){
		if(jobs[i].deadline > maxDeadline){
			maxDeadline = jobs[i].deadline;
		}
	}

	char result[maxDeadline];
	for (int i = 0; i < maxDeadline; i++)
	{
		result[i] = '-';
	}

	int k;
	for (int i = 0; i < n; i++)
	{
		int j = jobs[i].deadline - 1;
        while (j >= 0 && result[j] != '-') {
            j--;
        }
        if (j >= 0) {
            result[j] = jobs[i].id;
        }
	}

	printf("Job Sequence: ");
	for (int i = 0; i < maxDeadline; i++)
	{
		if (result[i] != '-')
		{
			printf("%c ", result[i]);
		}
	}

	printf("\n");
}

int main(){
	int n;
	printf("Enter the number of jobs: ");
	scanf("%d", &n);

	struct Job *jobs = malloc(n * sizeof(struct Job));
	
	if(jobs == NULL){
		printf("Memory allocation failed.\n");
		return 1;
	}

	printf("Enter job details: \n");
	for (int i = 0; i < n; i++)
	{
		printf("Job %d: \n", i+1);
		jobs[i].id = 'a' + i;
		printf("Deadline: ");
		scanf("%d", &jobs[i].deadline);
		printf("Profit: ");
		scanf("%d", &jobs[i].profit);
	}

	printf("\nGiven Jobs:\n");
	for(int i=0; i < n; i++){
		printf("Job %c: Deadline = %d Profit = %d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
	}
	printf("\n");

	jobSequencing(jobs, n);

	free(jobs);
	return 0;
}