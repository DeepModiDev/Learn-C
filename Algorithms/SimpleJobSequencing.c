#include <stdio.h>

typedef struct Job{
	char id[6];
	int deadline;
	int profit;
}Job;

void SimpleJobSequencing(struct Job jobs[],int n,int timeslotsize);

int min(int x,int y){
	if (x > y)
	{
		return y;
	}else{
		return x;
	}
}

int main(){

	int i,j, maxtimeslot, slot_val;

	Job jobs[6] = {
		{"J1", 5, 200},
		{"J2", 3, 180},
		{"J3", 3, 190},
		{"J4", 2, 300},
		{"J5", 4, 120},
		{"J6", 2, 100}
	};

	// Number of Jobs
	int n = 6;

	// Sort the jobs in profile wise decending order
	for(i = 0; i < n-1; i++){
		int max = i;
		maxtimeslot = i;

		for (j = i+1; j < n; j++)
		{
			// This if block is for sorting
			if (jobs[j].profit > jobs[max].profit){
				max = j;
			}

			// This if block is for finding the maximum time slot.
			if (jobs[maxtimeslot].deadline < jobs[j].deadline)
			{
				maxtimeslot = j;
			}
		}

		if (max != i)
		{
			Job temp = jobs[i];
			jobs[i] = jobs[max];
			jobs[max] = temp;
		}

		if (maxtimeslot != i)
		{
			slot_val = maxtimeslot;
			printf("%d \n", slot_val);
		}
	}

	printf("%10s %10s %10s","Job","Deadline","Profit\n");
	for (i = 0; i < n; i++)
	{
		printf("%10s %10i %10i\n",jobs[i].id, jobs[i].deadline, jobs[i].profit);
	}

	SimpleJobSequencing(jobs, n, slot_val);

	return 0;
}

void SimpleJobSequencing(Job jobs[],int n,int timeslotsize){
	int i, j, k, max_profit;

	//free timeslots
	int timeslots[timeslotsize];

	for (i = 1; i <= timeslotsize; i++)
	{
		timeslots[i] = -1;
	}

	printf("Max time slot (deadline): %i\n", timeslotsize);
	
	for(i=1; i<=n; i++){
		k = min(jobs[i-1].deadline, timeslotsize);
		while(k >= 1){
			if (timeslots[k] == -1)
			{
				timeslots[k] = i-1;
				break;
			}
			k--;
		}
	}

	for(int i=0; i<timeslotsize; i++){
		printf(" %s ",jobs[timeslots[i]].id);
		printf(" -----> ");
	}	

	printf("\n");
	max_profit = 0;
	for(int i=0; i<timeslotsize; i++){
		max_profit += jobs[timeslots[i]].profit;
	}

	printf("\nMax Profit is: %d\n", max_profit);

}