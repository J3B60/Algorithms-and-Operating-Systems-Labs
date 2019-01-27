/* file: copy file ifp to file ofp*/
#include "filecopy.h"
#include <stdio.h>
void filecopy(FILE *ifp, FILE *ofp){
	int c;
	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}
