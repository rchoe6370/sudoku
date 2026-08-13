#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "raylib.h"

void printBoard(char nums[]) {
	for (int i = 0; i < 81; i++)  {
		if (i % 9 == 0 && i != 0) {
			printf("\n");
			if (i % 27 == 0) {
				printf("- - - - - - - - - - -\n");
			}
		}
		
		if (i % 3 == 0 && i % 9 != 0) {
			printf("| ");
		}
		
		printf("%c ", nums[i]);
	}
}

int main(void)
{
	const int gridSize = 9;
	const int cellSize = 50;
	const int margin = 50;

	const int windowWidth = gridSize * cellSize + margin * 2;
	const int windowHeight = gridSize * cellSize + margin * 2;

	const int startX = margin;
	const int startY = margin;

	const int gridWidth = gridSize * cellSize;
	const int gridHeight = gridSize * cellSize;

	InitWindow(windowWidth, windowHeight, "sudoku");

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(RAYWHITE);


			for (int i = 0; i <= gridSize; i++) {
				DrawLine(startX, i * cellSize + startY, startX + gridWidth, i * cellSize + startY, LIGHTGRAY);
				DrawLine(i * cellSize + startX, startY, i * cellSize + startX, startY + gridHeight, LIGHTGRAY);
			}

			for (int i = 1; i < 3; i++) {
				int boundary = i * 3 * cellSize;
				DrawLineEx((Vector2){ startX + boundary, startY }, (Vector2){ startX + boundary, startY + gridHeight }, 3.0f, DARKBLUE);
				DrawLineEx((Vector2){ startX, startY + boundary }, (Vector2){ startX + gridWidth, startY + boundary }, 3.0f, DARKBLUE);
			}
		EndDrawing();

	}

	CloseWindow();


	/*



	int lineLength = 100;
	
	FILE *Pointer = fopen("puzzles/easy.txt", "r");
		
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

	*/
	
	return 0;
}


