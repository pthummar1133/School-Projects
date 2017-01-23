#include "Advanced.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/* Shuffle an image */
void
Shuffle(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	/* Generate 25 different integers in the range from 0 to 24 */
	srand(time(NULL));
	int sequence[25];
	int i,j;

	for (i = 0; i < 25; i++) {
		int count;
		do {
			/* sequence[i] is a random number from 0 through 24 */
			sequence[i] = rand() % 25;

			/* Assume that sequence[i] is unique */
			count = 0;

			/* Check whether sequence[i] is the same as previous numbers */
			for (j = 0; j < i; j++) {
				if (sequence[j] == sequence[i]) {
					count = 1;
					break;
				}
			}
		} while(count);
	}

	/* temporally arrays to store the shuffled image */
	unsigned char temp_r[WIDTH][HEIGHT];
	unsigned char temp_g[WIDTH][HEIGHT];
	unsigned char temp_b[WIDTH][HEIGHT];

	int height, width;
	int block_width = WIDTH / 5;
	int block_height = HEIGHT /5;

	for(i=0; i<25; i++) {

		int target_block_height = i/5;
		int target_block_width = i%5;

		int source_block_height = sequence[i]/5;
		int source_block_width = sequence[i]%5;

		for (height=0; height<block_height; height++) {

			for (width=0; width<block_width; width++) {

				int source_height = (source_block_height * block_height) + height;
				int source_width = (source_block_width * block_width) + width;

				int target_height = (target_block_height * block_height) + height;
				int target_width = (target_block_width * block_width) + width;

				temp_r[target_width][target_height] = R[source_width][source_height];
				temp_g[target_width][target_height] = G[source_width][source_height];
				temp_b[target_width][target_height] = B[source_width][source_height];
			}
		}
	}

	/* overwrite the original image with the shuffled image */
	for(width=0; width<WIDTH; width++) {
		for(height=0; height<HEIGHT; height++) {
			R[width][height] = temp_r[width][height];
			G[width][height] = temp_g[width][height];
			B[width][height] = temp_b[width][height];
		}
	}
}

/* Posterize an image */
void
Posterize(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], unsigned int rbits, unsigned int gbits, unsigned int bbits)
{
	int x, y;
	for(x=0; x<WIDTH; x++) {
		for(y=0; y<HEIGHT; y++) {

			unsigned char one = 1;
			int i;
			for(i=0; i<rbits-1; i++) {
				R[x][y] |= one;
				one <<= 1;
			}
			one = ~one;
			R[x][y] &= one;

			one = 1;
			for(i=0; i<gbits-1; i++) {
				G[x][y] |= one;
				one <<= 1;
			}
			one = ~one;
			G[x][y] &= one;

			one = 1;
			for(i=0; i<bbits-1; i++) {
				B[x][y] |= one;
				one <<= 1;
			}
			one = ~one;
			B[x][y] &= one;
		}
	}
}

/* Add noise to an image */
void
AddNoise(int n, unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y, i;
	int num; /* number of noise added */
	num = ( n*HEIGHT*WIDTH )/100;
	srand(time(NULL));

	for ( i = 0; i < num; i++ ) {
		x = ( (double)rand()/RAND_MAX )*(WIDTH-1);
		y = ( (double)rand()/RAND_MAX )*(HEIGHT-1);
		R[x][y] = 255;
		G[x][y] = 255;
		B[x][y] = 255;
	}
}