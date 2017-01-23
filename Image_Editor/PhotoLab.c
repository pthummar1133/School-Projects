/*********************************************************************/
/* Image Editor: homework assignment #3                              */                           
/* Please use this template to submit your hw3.                      */
/*********************************************************************/

/*
Parth Thummar
EECS 22
#26047811
*/

#include <stdio.h>
#include <string.h>

#include "DIPs.h"
#include "Advanced.h"
#include "FileIO.h"
#include "Constants.h"

/*** function declarations ***/

/* print a menu */
void PrintMenu();

/* Test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);


int main()
{
	int FileNotRead ;
	unsigned char R[WIDTH][HEIGHT];
	unsigned char G[WIDTH][HEIGHT];
	unsigned char B[WIDTH][HEIGHT];


#ifdef DEBUG
	AutoTest(R, G, B);
	FileNotRead = 0 ;
#else
	char fname[SLEN];
	char color[SLEN];
	int choice;

	int target_r;
	int target_g;
	int target_b;
	int threshold;
	double factor_r;
	double factor_g;
	double factor_b;

	int border_width ;

	FileNotRead = 1 ;
	PrintMenu();
	printf("please make your choice: ");
	scanf("%d", &choice);

	while (choice != 14) {
		switch (choice) {
		case 1:
			printf("Please input the file name to load: ");
			scanf("%s", fname);
			FileNotRead = ReadImage(fname, R, G, B);
			break;
		case 2:
			if (FileNotRead != 0) {
				printf("No Image Read Yet !!\n") ;
			} else {
				printf("Please input the file name to save: ");
				scanf("%s", fname);
				SaveImage(fname, R, G, B);
			}
			break;
		case 3:
			if (FileNotRead != 0) {
				printf("No Image Read Yet !!\n") ;
			} else {
				Negative(R,G,B);
				printf( "\"Negative\" operation is done!\n" );
			}
			break;
		case 4:
			if (FileNotRead != 0)
			{
				printf("No Image Read Yet !!\n") ;
			} else {
				printf("Enter Red   component for the target color: ") ;
				scanf("%d", &target_r) ;
				printf("Enter Green component for the target color: ") ;
				scanf("%d", &target_g) ;
				printf("Enter Blue  component for the target color: ") ;
				scanf("%d", &target_b) ;
				printf("Enter threshold for the color difference: ") ;
				scanf("%d", &threshold) ;
				printf("Enter value for Red component in the target color: ") ;
				scanf("%lf", &factor_r) ;
				printf("Enter value for Green component in the target color: ") ;
				scanf("%lf", &factor_g) ;
				printf("Enter value for Blue  component in the target color: ") ;
				scanf("%lf", &factor_b) ;

				ColorFilter(R, G, B, target_r, target_g, target_b, threshold, factor_r, factor_g, factor_b);
				printf("\"Color Filter\" operation is done!\n");
			}
			break;
		case 5:
			if (FileNotRead != 0) {
				printf("No Image Read Yet !!\n") ;
			} else {
				Edge(R, G, B);
				printf("\"Edge\" operation is done!\n");
			}
			break;
		case 6:
			if (FileNotRead != 0) {
				printf("No Image Read Yet !!\n") ;
			} else {
				HFlip(R,G,B);
				printf( "\"Horizontally Flip\" operation is done!\n" );
			}
			break;
		case 7:
			if (FileNotRead != 0) {
				printf("No Image Read Yet !!\n") ;
			} else {
				VMirror(R, G, B);
				printf("\"Vertically Mirror\" operation is done!\n");
			}
			break;
		case 8:
			if (FileNotRead != 0)
			{
				printf("No Image Read Yet !!\n") ;
			} else {
				printf("Enter border width:") ;
				scanf("%d", &border_width) ;
				printf("Available border colors : black, white, red, green, blue, yellow, cyan, pink, orange\n");
				printf("Select border color from the options: ");
				scanf("%s",color);
				AddBorder(R, G, B, color, border_width);
				printf("\"Border\" operation is done!\n");
			}
			break;
		case 9:
			if (FileNotRead != 0) {
				printf("No Image Read Yet !!\n") ;
			} else {
				Zoom(R, G, B);
				printf("\"Zoom\" operation is done!\n");
			}
			break;
		case 10:
			if (FileNotRead != 0) {
				printf("No Image Read Yet !!\n") ;
			} else {
				int n;
				printf("Please input noise percentage: ");
				scanf("%d", &n);
				AddNoise(n, R, G, B);
				printf("\"Noise\" operation is done!\n");
			}
			break;
		case 11:
			if (FileNotRead != 0) {
				printf("No Image Read Yet !!\n") ;
			} else {
				Shuffle(R, G, B);
				printf("\"Shuffle\" operation is done!\n");
			}
			break;
		case 12:
			if (FileNotRead != 0) {
				printf("No Image Read Yet !!\n") ;
			} else {
				unsigned char rbits, gbits, bbits;
				printf("Enter the number of posterization bits for R chennel (1 to 8):");
				scanf("%hhu", &rbits);
				printf("Enter the number of posterization bits for G chennel (1 to 8):");
				scanf("%hhu", &gbits);
				printf("Enter the number of posterization bits for B chennel (1 to 8):");
				scanf("%hhu", &bbits);
				Posterize(R, G, B, rbits, gbits, bbits);
				printf("\"Posterize\" operation is done!\n");
			}
			break;
		case 13:
			AutoTest(R, G, B);
			FileNotRead = 0 ;
			break;
		default:
			printf("Invalid selection!\n");
			break;
		}

		PrintMenu();
		printf("please make your choice: ");
		scanf("%d", &choice);
	}
#endif

	return 0;
}


/*******************************************/
/* Function implementations should go here */
/*******************************************/

/* Menu */
void
PrintMenu()
{
	printf("\n--------------------------------\n");
	printf(" 1:  Load a PPM image\n");
	printf(" 2:  Save an image in PPM and JPEG format\n");
	printf(" 3:  Make a negative of an image\n");
	printf(" 4:  Color filter an image\n");
	printf(" 5:  Sketch the edge of an image\n");
	printf(" 6:  Flip an image horizontally\n");
	printf(" 7:  Mirror an image vertically\n");
	printf(" 8:  Add Border to an image\n");
	printf(" 9:  Zoom an image\n");
	printf("10:  Add noise to an image\n");
	printf("11:  Shuffle an image\n");
	printf("12:  Posterize an image\n");
	printf("13:  Test all functions\n");
	printf("14:  Exit\n");
}

/* Negative */
void Negative(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	int x, y;

	for( y = 0; y < HEIGHT; y ++ ) {
		for( x = 0; x < WIDTH; x ++ ) {
			R[x][y]=255-R[x][y];
			G[x][y]=255-G[x][y];
			B[x][y]=255-B[x][y];
		}
	}
	printf( "\"Negative\" operation is done!\n" );
}


/* auto test*/
void
AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	char fname[SLEN] = "Auditorium";
	char sname[SLEN];

	ReadImage(fname, R, G, B);
	Negative (R, G, B) ;
	strcpy(sname, "negative");
	SaveImage(sname, R, G, B) ;
	#ifdef DEBUG
	printf("Negative tested!\n\n");
	#endif

	ReadImage(fname, R, G, B);
	ColorFilter(R, G, B, 190, 100, 150, 60, 0, 0, 255);
	strcpy(sname, "colorfilter");
	SaveImage(sname, R, G, B);
	#ifdef DEBUG
	printf("Color Filter tested!\n\n");
	#endif

	ReadImage(fname, R, G, B);
	Edge(R, G, B);
	strcpy(sname, "edge");
	SaveImage(sname, R, G, B);
	#ifdef DEBUG
	printf("Edge Detection tested!\n\n");
	#endif

	ReadImage(fname, R, G, B);
	HFlip(R, G, B);
	strcpy(sname, "hflip");
	SaveImage(sname, R, G, B);
	#ifdef DEBUG
	printf("HFlip tested!\n\n");
	#endif

	ReadImage(fname, R, G, B);
	VMirror(R, G, B);
	strcpy(sname, "vmirror");
	SaveImage(sname, R, G, B);
	#ifdef DEBUG
	printf("VMirror tested!\n\n");
	#endif

	ReadImage(fname, R, G, B);
	AddBorder (R, G, B, "black", 64) ;
	strcpy(sname, "border");
	SaveImage(sname, R, G, B) ;
	#ifdef DEBUG
	printf("Border tested!\n\n");
	#endif

	ReadImage(fname, R, G, B);
	Zoom (R, G, B) ;
	strcpy(sname, "zoom");
	SaveImage(sname, R, G, B) ;
	#ifdef DEBUG
	printf("Zoom tested!\n\n");
	#endif


	ReadImage(fname, R, G, B);
	AddNoise (9, R, G, B) ;
	strcpy(sname, "noise");
	SaveImage(sname, R, G, B) ;
	#ifdef DEBUG
	printf("AddNoise tested!\n\n");
	#endif

	ReadImage(fname, R, G, B);
	Shuffle (R, G, B) ;
	strcpy(sname, "shuffle");
	SaveImage(sname, R, G, B) ;
	#ifdef DEBUG
	printf("Shuffle tested!\n\n");
	#endif

	ReadImage(fname, R, G, B);
	Posterize (R, G, B, 6, 7, 8) ;
	strcpy(sname, "posterize");
	SaveImage(sname, R, G, B) ;
	#ifdef DEBUG
	printf("Posterize tested!\n\n");
	#endif
}


