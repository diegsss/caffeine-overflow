class Map {
    public: 
	unsigned char arr[16][80];
	int nrows, ncols;
	int tilesize[2];
	Flt ftsz[2];
	Flt tile_base;
	Map() {
	    //Log("Level constructor\n");
	    tilesize[0] = 32;
	    tilesize[1] = 32;
	    ftsz[0] = (Flt)tilesize[0];
	    ftsz[1] = (Flt)tilesize[1];
	    tile_base = 220.0;
	    //read level
	    FILE *fpi = fopen("level1.txt","r");
	    if (fpi) {
		nrows=0;
		char line[100];
		while (fgets(line, 100, fpi) != NULL) {
		    removeCrLf(line);
		    int slen = strlen(line);
		    ncols = slen;
		    //Log("line: %s\n", line);
		    for (int j=0; j<slen; j++) {
			arr[nrows][j] = line[j];
		    }
		    ++nrows;
		}
		fclose(fpi);
		//printf("nrows of background data: %i\n", nrows);
	    }
	    for (int i=0; i<nrows; i++) {
		for (int j=0; j<ncols; j++) {
		    printf("%c", arr[i][j]);
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
} map;

