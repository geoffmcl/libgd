/* $Id$ */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "gd.h"
#include <stdio.h>
#include <stdlib.h>

const char *out_file = "tempb.png";

int main()
{
	gdImagePtr im;
	FILE *fp;
	int cor_rad = 60;
	im = gdImageCreateTrueColor(400, 400);
	gdImageFilledRectangle(im, 0, 0, 399, 399, 0x00FFFFFF);

	gdImageFilledArc (im, cor_rad, 399 - cor_rad, cor_rad *2, cor_rad *2, 90, 180, 0x0, gdPie);

#ifdef HAVE_LIBPNG
	fp = fopen(out_file, "wb");
	if (!fp) {
		fprintf(stderr, "Can't save png image to %s.\n", out_file);
		gdImageDestroy(im);
		return 1;
	}
	gdImagePng(im, fp);
	fclose(fp);
	fprintf(stderr, "PNG image written to %s.\n", out_file);
#else
	fprintf(stderr, "No PNG support. Cannot save image.\n");
#endif

	gdImageDestroy(im);
	return 0;
}
