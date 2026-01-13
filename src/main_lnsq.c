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
       if (map[i] == 1) {
       RegionFill((i % m) / 4, (i / m) / 4, 1, 1, RGB(255,255,255), 0);
       }
       if (map[i] == 2) {
       RegionFill((i % m) / 4, (i / m) / 4, 1, 1, RGB(0,255,255), 0);
       }
     }
}

int main (int argc, char **argv) {
int n = 12;
int m = 1 << n;

struct cache c;
XI(0, "nope", "", m, m, 0, 0, 0);
Eve(&c, 0);
RegionFill(0, 0, m, m, RGB(0,0,0), 0);

char *map = malloc(m * m);
char *linmap = malloc(m * m);
memset(linmap, 0, m * m);

//long long linmap_ptr = 13631488;
//13893632-14417920 range all triangles
//14020608
long long linmap_ptr = 14022016;
long long az, bz;
az = 3;
bz = 3;

double out;

    for (long long i = 3; i < m * m * 4; i++) {
    out = logarithm(i);
    out *= out * out;
    az = bz;
    bz = clamp(2 * (double)i / out);
        if (az != bz) {
        linmap[i/4] = 1;
        }
    }

call(n, linmap, map, 0);
draw(m, map);

  while (1) {
  Eve(&c, 0);
	if (c.t == 3) {
	}
	if (c.t == 1) {
		if (c.txt == 'q') {
		Clean(0);
		return 0;
		}
	}
        if (c.t == 2) {
        for (int i = 0; i < 1<<4; i++) {
        linmap[linmap_ptr + i] = 2 - linmap[linmap_ptr + i];
        }
        printf("start of envelope: %d\n", linmap_ptr);
        linmap_ptr += 1<<4;
        call(n, linmap, map, 0);
	draw(m, map);
        printf("%d\n", call_deduce(n, c.x * 4, c.y * 4));
        }
  }
}

