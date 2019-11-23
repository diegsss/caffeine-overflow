#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

class Image {
	public:
		int width;
		int height;
		unsigned char *data;
		const char *file;
		Image(const char *fname);
		~Image();

};

#endif
