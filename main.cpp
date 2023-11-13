#include "Header.h"

int main()
{
	//	IMREAD_GRAYSCALE converteste imaginea in grayscale
	Mat src = imread("img/torso1.png", IMREAD_GRAYSCALE);
	Mat sharpened_img, prag, prag_color;

	imshow("Original", src);

	// accentual sharpness-ul si contrastul imaginii pentru a delimita mai clar zonele
	sharpened_img = sharpen(src);
	imshow("Imagine enhanced", sharpened_img);

	// fara functia asta programul ar iesi imediat din executie
	waitKey(0);

	return 0;
}

