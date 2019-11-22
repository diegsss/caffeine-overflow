#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
using namespace std;

#ifndef MAP_H
#define MAP_H

struct Vect {
	double x,y,z;
};

struct Tile {
	char identity;
	double width, height;
	Vect pos;
};

class Map {
    public: 
	Tile arr[70][70];
	int nrows, ncols;
	int tilesize[2];
	double dbsz[2];
	double tile_base;
	Map(){}
	Map(char *str) {
	    //Log("Level constructor\n");
	    tilesize[0] = 48;
	    tilesize[1] = 48;
	    dbsz[0] = (double)tilesize[0];
	    dbsz[1] = (double)tilesize[1];
	    tile_base = 5.0;
	    //read level
	    FILE *fpi = fopen(str,"r");
	    if (fpi) {
		nrows=0;
		char line[100];
		while (fgets(line, 100, fpi) != NULL) {
		    removeCrLf(line);
		    int slen = strlen(line);
		    ncols = slen;
		    //Log("line: %s\n", line);
		    for (int j=0; j<slen; j++) {
			arr[nrows][j].identity = line[j];
			arr[nrows][j].width = dbsz[j];
			arr[nrows][j].height = dbsz[j];
		    }
		    ++nrows;
		}
		fclose(fpi);
		//printf("nrows of background data: %i\n", nrows);
	    }
	    for (int i=0; i<nrows; i++) {
		for (int j=0; j<ncols; j++) {
		    printf("%c", arr[i][j].identity);
		}
		printf("\n");
	    }
	}
	void removeCrLf(char *str) {
	    //remove carriage return and linefeed from a Cstring
	    char *p = str;
	    while (*p) {
		if (*p == 10 || *p == 13) {
		    *p = '\0';
		    break;
		}
		++p;
	    }
	}
};

#endif
