#include "Header.h"

// Folosim mai multe functii pentru a imbunatati calitatea imaginii
Mat sharpen(Mat src) {
	Mat sharpened_img = src.clone();
	int h = src.rows;
	int w = src.cols;

	//marim sharpnessul cu fct predefinite din openCV , definim un kernel de sharpness si facem convolutie pe imagine
	// masca de sharpness
	float mask[9] =
	{ 0, -1, 0,
	 -1, 5, -1,
	  0, -1, 0 };
	Mat mat_mask = Mat(3, 3, CV_32F, mask);
	// facem convolutie
	filter2D(sharpened_img, sharpened_img, -1, mat_mask);

	//marim contrastul folosing limitele a si b (pentru care se cunosc valorile sa = Transformata(a) si sb)
	double a = 125, b = 175, sa = 100, sb = 200;
	double m = (double)sa / a;
	double n = (double)(sb - sa) / (b - a);
	double p = (double)(255 - sb) / (255 - b);

	double aux;
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) {
			if (src.at<uchar>(y, x) <= a)
				aux = m * src.at<uchar>(y, x);
			else if (src.at<uchar>(y, x) > a && src.at<uchar>(y, x) <= b)
				aux = n * (src.at<uchar>(y, x) - a) + sa;
			else
				aux = p * (src.at<uchar>(y, x) - b) + sb;

			if (aux > 255)
				sharpened_img.at<uchar>(y, x) = 255;
			else if (aux < 0)
				sharpened_img.at<uchar>(y, x) = 0;
			else
				sharpened_img.at<uchar>(y, x) = aux;
		}
	return sharpened_img;
}


