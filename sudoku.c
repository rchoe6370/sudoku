#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printBoard(char nums[]) {
	for(int i = 0; i < 81; i++)  {
		if(i % 9 == 0 && i != 0) {
			printf("\n");
			if(i % 27 == 0) {
				printf("- - - - - - - - - - -\n");
			}
		}
		
		if(i % 3 == 0 && i % 9 != 0) {
			printf("| ");
		}
		
		printf("%c ", nums[i]);
	}
}

int main(void)
{
	int lineLength = 100;
	
	FILE *Pointer = fopen("easy.txt", "r");
		
	srand(time(NULL));
	
	//char filename[20];
	
	fseek(Pointer, 0, SEEK_END);	
	int size = ftell(Pointer) / lineLength;
	fseek(Pointer, 0, SEEK_SET);
	
	int r = (rand() % size) + 1;
	
	long byteOffset = (long)r * lineLength;
	fseek(Pointer, byteOffset, SEEK_SET);
	
	char fileLine[101];
	fgets(fileLine, sizeof(fileLine), Pointer);
	
	fgets(fileLine, sizeof(fileLine), Pointer);
	
	fclose(Pointer);
	
	char hash[13], nums[82], diff[5];
	
	sscanf(fileLine, "%12s %81s %4s", hash, nums, diff);
	
	printf("Hash: %s\n", hash);
	printf("Nums: %s\n", nums);
	printf("Difficulty: %s\n\n", diff);
	
	printBoard(nums);
	
	return 0;
}


