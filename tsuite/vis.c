#include <ssw.h>
#include <stdlib.h>
#include <string.h>
#include "hilbert.h"

void draw(int m, char *map) {
     for (int i = 0; i < m * m; i++) {
     RegionFill(10 + 5 * (i % m), 10 + 5 * (i / m), 5, 5, map[i] ? RGB(255,255,255) : RGB(0, 0, 0), 0);
     }
}

int main (int argc, char **argv) {
struct cache c;
XI(0, "nope", "", 500, 500, 0, 0, 0);
Eve(&c, 0);
RegionFill(0, 0, 500, 500, RGB(0,0,0), 0);

int n = 6;
int m = 2 << n;
char *map = malloc(m * m);
char *linmap = malloc(m * m);
memset(linmap, 0, m * m);

call(n, linmap, map, 0);
draw(m, map);

  while (1) {
  Eve(&c, 0);
	if (c.t == 3) {
	draw(m, map);
	}
	if (c.t == 1) {
		if (c.txt == 'q') {
		Clean(0);
		return 0;
		}
	}
  }
}
