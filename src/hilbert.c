/* for each of the respective functions hilbert/move,
we have pos[4]:
  pos[0]: x coordinate of curve traversal
  pos[1]: y coordinate of curve traversal
  pos[2]: linear map traverser (is incremented every time move is called)
  pos[3]: max x/y component

  Ideally pos[2] could be removed and we could increment the linmap pointer
*/

void move (int j, int pos[4], char *linmap, char *map, char dir) {
	if (dir==0) {
	map[pos[0]+pos[1]*pos[3]] = linmap[pos[2]];
	}
	if (dir==1) {
	linmap[pos[2]] = map[pos[0]+pos[1]*pos[3]];
	}
        if (j==1) {
        pos[1]-=1;
        }
        if (j==2) {
        pos[0]+=1;
        }
        if (j==3) {
        pos[1]+=1;
        }
        if (j==4) {
        pos[0]-=1;
        }
pos[2]++;
};

void hilbert_actual(int r, int d, int l, int u, int i, int pos[4],
                               char *linmap, char *map, char dir) {
        if (i) {
        i--;
        hilbert_actual(d, r, u, l, i, pos, linmap, map, dir);
        move(r, pos, linmap, map, dir);

        hilbert_actual(r, d, l, u, i, pos, linmap, map, dir);
        move(d, pos, linmap, map, dir);

        hilbert_actual(r, d, l, u, i, pos, linmap, map, dir);
        move(l, pos, linmap, map, dir);

        hilbert_actual(u, l, d, r, i, pos, linmap, map, dir);
        }
};

// nice wrapper
int call(int n, char *linmap, char *map, char dir) {
// n is orientation
// dir is write operation specifier,
//    as in when dir = 0, we write to the 2d array occupied by the curve
//    and when dir = 1, we write to the 1d array, linmap, thereby
// unwinding the former operation

  if (dir > 1) {
  return 2;
  }
int pos[4];
pos[0] = 0;
pos[1] = 0;
pos[2] = 0;
pos[3] = 1<<n;
hilbert_actual(2+(n&1), 3-(n&1), 4-3*(n&1), 1+3*(n&1), n, pos, linmap, map, dir);
}
