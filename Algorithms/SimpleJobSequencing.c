// Job sequencing with deadline using greedy method
#include <stdio.h>
#include <stdlib.h>

#define ID_LENGTH 6

typedef struct Job{
	char id[ID_LENGTH];
	int deadline;
	int profit;
}Job;

int min(int a, int b){
	if (a > b)
		return b;
	else
		return a;	
}


void JobSequencing(Job jobs[], int numberOfJobs){

	printf("--------------------------------------\n");
	// Step 1: Find the farthest or max deadline.
	int i,j,k,m,maxdeadLine = 0;
	for(i=0; i<numberOfJobs; i++){
		if (jobs[i].deadline > maxdeadLine)
		{
			maxdeadLine = jobs[i].deadline;
		}
	}
	
	int timeSlots[maxdeadLine+2];

	for(j=1; j <= maxdeadLine; j++){
		timeSlots[j] = -1;
	}

	printf("Maximum deadline: %d\n", maxdeadLine);
	// Step 2: Prepare / Initialize the Time slots

	printf("--------------------------------------\n");
	// Step 3: Job Sequencing Algorithm
	for(int k=1; k <= maxdeadLine; k++){
		int minval = min(jobs[k-1].deadline, maxdeadLine);
		while(minval >= 1){
			if(timeSlots[minval] == -1){
				timeSlots[minval] = k-1;
				break; 
			}
			minval--;
		}
	}

	// Step 4: Print the Selected Jobs and total profit
	printf("\nSelected Jobs:\n");
	int maxProfit = 0;
	for(int m=1; m <= maxdeadLine; m++){
		printf("%s\t",jobs[timeSlots[m]].id);
		maxProfit += jobs[timeSlots[m]].profit;
	}

	printf("Total Profit: %d\n", maxProfit);

}

int main(){
	Job jobs[] = {
		"P1", 4, 500,
		"P2", 2, 100,
		"P3", 1, 300,
		"p4", 3, 301,
		"p5", 1, 130
	};

	int numberOfJobs = 5;

	// Sort the Jobs based on the profit in decending order.
	for(int i=0; i<numberOfJobs; i++){
		int job_with_max_profit = i;
		for(int j = i + 1; j < numberOfJobs; j++){
			if(jobs[job_with_max_profit].profit < jobs[j].profit){
				job_with_max_profit = j;
			}
		}

		if(job_with_max_profit != i){
			Job tmpJob = jobs[i];
			jobs[i] = jobs[job_with_max_profit];
			jobs[job_with_max_profit] = tmpJob;
		}
	}

	printf("\n Number of Jobs: %d\n",numberOfJobs);
	printf("Sorted jobs based on profit in decending order: \n");
	for(int i=0; i<numberOfJobs; i++){
		printf("Job %d: Id: %s, Profit: %d, Deadline: %d\n",i+1, jobs[i].id, jobs[i].profit, jobs[i].deadline);
	}

	JobSequencing(jobs, numberOfJobs);

	return 0;
}