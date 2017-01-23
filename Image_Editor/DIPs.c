#include "DIPs.h"

#include <string.h>

/* ColorFilter */
void ColorFilter (unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT],
                  int target_r, int target_g, int target_b, int threshold, int replace_r, int replace_g, int replace_b)

{
	int x, y ;
	int temp ;

	for (y=0; y<HEIGHT; y++) {
		for (x=0; x<WIDTH; x++) {
			if ((R[x][y] <= target_r + threshold)&&
					(R[x][y] >= target_r - threshold)&&
					(G[x][y] <= target_g + threshold)&&
					(G[x][y] >= target_g - threshold)&&
					(B[x][y] <= target_b + threshold)&&
					(B[x][y] >= target_b - threshold)) {
				temp = replace_r;
				R[x][y] = (temp > 255)? 255 : (temp <0)? 0 : temp ;
				temp = replace_g;
				G[x][y] = (temp > 255)? 255 : (temp <0)? 0 : temp ;
				temp = replace_b;
				B[x][y] = (temp > 255)? 255 : (temp <0)? 0 : temp ;
			}
		}
	}
}

/* Edge */
void Edge(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y, m, n, a, b;
	int tmpR = 0;
	int tmpG = 0;
	int tmpB = 0;

	unsigned char   R_tmp[WIDTH][HEIGHT];
	unsigned char   G_tmp[WIDTH][HEIGHT];
	unsigned char   B_tmp[WIDTH][HEIGHT];

	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH; x++) {
			R_tmp[x][y] = R[x][y];
			G_tmp[x][y] = G[x][y];
			B_tmp[x][y] = B[x][y];
		}
	}

	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH; x++) {
			for (n = -1; n <= 1; n++) {
				for (m = -1; m <= 1; m++) {
					a = x + m;
					b = y + n;
					if (a > WIDTH - 1)
						a = WIDTH - 1;
					if (a < 0)
						a = 0;
					if (b > HEIGHT - 1)
						b = HEIGHT - 1;
					if (b < 0)
						b = 0;

					if ((n==0)&&(m==0)) {
						tmpR += 8*R_tmp[a][b] ;
						tmpG += 8*G_tmp[a][b] ;
						tmpB += 8*B_tmp[a][b] ;
					} else {
						tmpR -= R_tmp[a][b] ;
						tmpG -= G_tmp[a][b] ;
						tmpB -= B_tmp[a][b] ;
					}
				}
			}
			R[x][y] = (tmpR>255)? 255: (tmpR<0)? 0: tmpR ;
			G[x][y] = (tmpG>255)? 255: (tmpG<0)? 0: tmpG ;
			B[x][y] = (tmpB>255)? 255: (tmpB<0)? 0: tmpB ;
			tmpR = tmpG = tmpB = 0;
		}
	}
}

/* HFlip */
void
HFlip(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int             x, y;
	unsigned char   r, g, b;

	for (y = 0; y < HEIGHT; y ++) {
		for (x = 0; x < WIDTH / 2; x ++) {
			r = R[WIDTH - 1 - x][y];
			g = G[WIDTH - 1 - x][y];
			b = B[WIDTH - 1 - x][y];

			R[WIDTH - 1 - x][y] = R[x][y];
			G[WIDTH - 1 - x][y] = G[x][y];
			B[WIDTH - 1 - x][y] = B[x][y];

			R[x][y] = r;
			G[x][y] = g;
			B[x][y] = b;
		}
	}
}

/* VMirror */
void
VMirror(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int             x, y;

	for (y = 0; y < HEIGHT / 2; y ++) {
		for (x = 0; x < WIDTH; x ++) {
			R[x][HEIGHT - 1 - y] = R[x][y] ;
			G[x][HEIGHT - 1 - y] = G[x][y] ;
			B[x][HEIGHT - 1 - y] = B[x][y] ;
		}
	}
}


/* Zoom */
void Zoom(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])

{
	int x,y,z,i;
	unsigned char FirstValue;
	unsigned char SecondValue;
	signed char diff;
	unsigned char   all[WIDTH][HEIGHT][3];
	unsigned char	Tmp_1[ZOOM_FACTOR*(WIDTH-1)+1][HEIGHT][3];
	unsigned char	Tmp_2[ZOOM_FACTOR*(WIDTH-1)+1][ZOOM_FACTOR*(HEIGHT-1)+1][3];

	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH; x++) {
			all[x][y][0] = R[x][y];
			all[x][y][1] = G[x][y];
			all[x][y][2] = B[x][y];
		}
	}

	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH-1; x++) {
			for (z = 0; z < 3; z++) {
				FirstValue = all[x][y][z];
				SecondValue = all[x+1][y][z];
				diff = -(FirstValue - SecondValue)/ZOOM_FACTOR;
				for (i=0; i<ZOOM_FACTOR; i++) {
					if (i==0) {
						Tmp_1[x*ZOOM_FACTOR][y][z] = all[x][y][z];
					} else {
						Tmp_1[x*ZOOM_FACTOR+i][y][z]  = all[x][y][z]+diff;
						diff += diff;
					}
				}
			}
		}
        }

	for (x = 0; x < (ZOOM_FACTOR*(WIDTH-1)+1);x++){
		for (y = 0; y < HEIGHT-1; y++) {
			for (z = 0; z < 3; z++) {
				FirstValue = Tmp_1[x][y][z];
				SecondValue = Tmp_1[x][y+1][z];
				diff = -(FirstValue - SecondValue)/ZOOM_FACTOR;
				for (i=0; i<ZOOM_FACTOR; i++) {
					if (i==0) {
						Tmp_2[x][y*ZOOM_FACTOR][z] = Tmp_1[x][y][z];
					} else {
						Tmp_2[x][y*ZOOM_FACTOR+i][z]  = Tmp_1[x][y][z]+diff;
						diff += diff;
					}
				}
			}
		}
	}

	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH; x++) {
			R[x][y] = Tmp_2[x][y][0];
			G[x][y] = Tmp_2[x][y][1];
			B[x][y] = Tmp_2[x][y][2];
		}
	}
}


/* AddBorder */
void AddBorder(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT],
               char color[SLEN], int border_width)
{
	int x, y ;
	int border_r = 255;
	int border_g = 255;
	int border_b = 255;
	if (!strcmp(color, "black")) {
		border_r = 0;
		border_g = 0;
		border_b = 0;
	} else if (!strcmp(color, "white")) {
		border_r = 255;
		border_g = 255;
		border_b = 255;
	} else if (!strcmp(color, "red")) {
		border_r = 255;
		border_g = 0;
		border_b = 0;
	} else if (!strcmp(color, "green")) {
		border_r = 0;
		border_g = 255;
		border_b = 0;
	} else if (!strcmp(color, "blue")) {
		border_r = 0;
		border_g = 0;
		border_b = 255;
	} else if (!strcmp(color, "yellow")) {
		border_r = 255;
		border_g = 255;
		border_b = 0;
	} else if (!strcmp(color, "cyan")) {
		border_r = 0;
		border_g = 255;
		border_b = 255;
	} else if (!strcmp(color, "pink")) {
		border_r = 255;
		border_g = 192;
		border_b = 203  ;
	} else if (!strcmp(color, "orange")) {
		border_r = 255;
		border_g = 165;
		border_b = 0;
	}

	for (y = 0; y < HEIGHT; y++){
		for (x = 0; x < WIDTH; x++) {
			if ((y < border_width)||
					(y > HEIGHT - border_width)||
					(x < (9*border_width)/16)||
					(x > (WIDTH -(9*border_width/16)))) {
				R[x][y] = border_r ;
				G[x][y] = border_g ;
				B[x][y] = border_b ;
			}
		}
	}
}