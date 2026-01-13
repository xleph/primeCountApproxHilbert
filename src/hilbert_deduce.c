/* for each of the respective functions hilbert/move,
we have pos[4]:
  pos[0]: x coordinate of curve traversal
  pos[1]: y coordinate of curve traversal
  pos[2]: linear map traverser (is incremented every time move is called)
  pos[3]: max x/y component

  Ideally pos[2] could be removed and we could increment the linmap pointer
*/

int move_deduce (int j, int pos[4], int x, int y) {
int ret = 0;
        if (pos[0] == x && pos[1] == y) {
        ret = pos[2];
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
return ret;
};

int hilbert_deduce_actual(int r, int d, int l, int u, int i, int pos[4], int x, int y) {
int ret = 0;
        if (i) {
        i--;
        ret += hilbert_deduce_actual(d, r, u, l, i, pos, x, y);
        ret += move_deduce(r, pos, x, y);

        ret += hilbert_deduce_actual(r, d, l, u, i, pos, x, y);
        ret += move_deduce(d, pos, x, y);

        ret += hilbert_deduce_actual(r, d, l, u, i, pos, x, y);
        ret += move_deduce(l, pos, x, y);

        ret += hilbert_deduce_actual(u, l, d, r, i, pos, x, y);
        }
return ret;
};

// nice wrapper
int call_deduce(int n, int x, int y) {
// n is orientation
// dir is write operation specifier,
//    as in when dir = 0, we write to the 2d array occupied by the curve
//    and when dir = 1, we write to the 1d array, linmap, thereby
// unwinding the former operation

int pos[4];
pos[0] = 0;
pos[1] = 0;
pos[2] = 0;
pos[3] = 1<<n;
hilbert_deduce_actual(2+(n&1), 3-(n&1), 4-3*(n&1), 1+3*(n&1), n, pos, x, y);
}
