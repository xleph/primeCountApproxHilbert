#include <ssw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hilbert.h"
#include "logarithm.h"
#include "hilbert_deduce.h"

long long clamp(double x) {
double y = x - (long long)x;

    if ( y > 0.5 ) {
    return (long long)x + 1;
    } else {
    return (long long)x;
    }

}

void draw(int m, char *map) {
     for (int i = 0; i < m * m; i++) {
     RegionFill((i % m), (i / m), 1, 1, map[i] ? RGB(255,255,255) : RGB(0, 0, 0), 0);
     }
}

int main (int argc, char **argv) {
int n = 11;
int m = 1 << n;

struct cache c;
XI(0, "nope", "", m, m, 0, 0, 0);
Eve(&c, 0);
RegionFill(0, 0, m, m, RGB(0,0,0), 0);

char *map = malloc(m * m);
char *linmap = malloc(m * m);
memset(linmap, 0, m * m);

long long az, bz;
az = 3;
bz = 3;

    for (long long i = 3; i < m * m; i++) {
    az = bz;
    bz = clamp((double)i / logarithm(i));
        if (az != bz) {
        linmap[i] = 1;
        }
    }

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
        if (c.t == 2) {
        printf("%d\n", call_deduce(n, c.x, c.y));
        }
  }
}
