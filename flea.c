//flea

#include<stdio.h>
#include<stdlib.h>
#define BACK 1
#define FRONT 2


int travel(unsigned int *ways, int target, int trvld_dist, int rm_dist, int lm_dist, int dir, int max_jumps, int total_jumps);

int main()
{
	int target = 0;
	int rm_dist = 0, lm_dist = 0;
	int rm_times = 0, lm_times = 0;
	int rm_count, lm_count;
	
	int trvld_dist = 0;
	unsigned int ways = 0;
	
	int max_jumps = 0;
	int total_jumps = 0;
	
	printf("\nLength of line segment (in cm): ");
	scanf("%d", &target);
	printf("\nDistance that the flea can move to the left in each move (in cm): ");
	scanf("%d", &lm_dist);
	printf("\nDistance that the flea can move to the right in each move (in cm): ");
	scanf("%d", &rm_dist);
	if(lm_dist == rm_dist)
		max_jumps = 0;
	else
		max_jumps = (int)(16*(target/abs(lm_dist-rm_dist)));
	
	travel(&ways, target, trvld_dist, rm_dist, lm_dist, FRONT, max_jumps, total_jumps);
	
	printf("\nNumber of ways to get from A to B = %u\n", ways);

}

int travel(unsigned int *ways, int target, int trvld_dist, int rm_dist, int lm_dist, int dir, int max_jumps, int total_jumps)
{
	if(rm_dist == target) {
		*ways = 1;
		return 1;
	} else if(rm_dist > target) {
		*ways = 0;
		return 0;
	}
	
	if(rm_dist == lm_dist) {
		if((target%rm_dist) != 0)
			*ways = 0;
		else
			*ways = 0xFFFFFFFF;
		return 0;
	}
	
	if(total_jumps > max_jumps) {
//		printf("\nmax jump");
		return 0;
	}
			
	if(dir == FRONT) {
//	    printf("Front-");
		trvld_dist += rm_dist;
	} else if(dir == BACK) {
//	    printf("Back-");
		trvld_dist -= lm_dist;
	}
	
//	printf("\n%d,%d,%d,%d,%d", *ways, target, trvld_dist, rm_dist, lm_dist);
	if(trvld_dist == target) {
//		printf("\ntarget acheived");
		(*ways)++;
		return 1;
	} else if (trvld_dist > target) {
//		printf("\ntarget exceeded");
		return 0;
	} else if (trvld_dist <= 0) {
//		printf("\n negative target");
		return 0;
	}

	travel(ways, target, trvld_dist, rm_dist, lm_dist, BACK, max_jumps, total_jumps+1);
	travel(ways, target, trvld_dist, rm_dist, lm_dist, FRONT, max_jumps, total_jumps+1);	
}
