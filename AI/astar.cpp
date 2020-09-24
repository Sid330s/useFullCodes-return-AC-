// A C++ Program to implement A* Search Algorithm
#include<bits/stdc++.h>
#define ROW 4
#define COL 8
using namespace std;
typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> pPair;


struct cell {
	int pi, pj;
	double f, g, h;
};

bool isValid(int row, int col) {
	return (row >= 0) && (row < ROW) &&
		(col >= 0) && (col < COL);
}

double hOfN(int row, int col, Pair dest) {
	return ((double)sqrt ((row-dest.first)*(row-dest.first)
						+ (col-dest.second)*(col-dest.second)));
}

void printPath(cell cellat[][COL], Pair dest) {
	int row = dest.first;
	int col = dest.second;

	stack<Pair> Path;

	printf ("\nF(n) = H(n) + G(n) \n");
    for (int i=0; i<ROW; i++) {
        for (int ii=0; ii<COL; ii++) {
            if (cellat[i][ii].pi==-1) {
                            cout << cellat[i][ii].pi << ", " << cellat[i][ii].pj << "   |   ";
            } else {
                            cout << " " << cellat[i][ii].pi << ", " << " " << cellat[i][ii].pj << "   |   ";
            }
        }
        cout<<endl;
    }

    printf ("\nThe Path is ");

	while (!(cellat[row][col].pi == row && cellat[row][col].pj == col )) {
		Path.push (make_pair (row, col));
		int temp_row = cellat[row][col].pi;
		int temp_col = cellat[row][col].pj;
		row = temp_row;
		col = temp_col;
	}

	Path.push (make_pair (row, col));
	while (!Path.empty()) {
		pair<int,int> p = Path.top();
		Path.pop();
		printf("-> (%d,%d) ",p.first,p.second);
	}
	return;
}

void aStar(int maze[][COL], Pair src, Pair dest) {
	if (isValid (src.first, src.second) == false || isValid (dest.first, dest.second) == false) {
		printf ("Enter Valid Inputs\n");
		return;
	}

	if (maze[src.first][src.second] == 0 || maze[dest.first][dest.second] == 0) {
		printf ("Path Blocked!! \n");
		return;
	}

	if (src.first==dest.first && src.second==dest.second) {
		printf ("Your Sourec is your Destination \n");
		return;
	}



	bool cList[ROW][COL];
	memset(cList, false, sizeof (cList));


	cell cellat[ROW][COL];
	int i, j;
	for (i=0; i<ROW; i++) {
		for (j=0; j<COL; j++) {
			cellat[i][j].f = FLT_MAX;
			cellat[i][j].g = FLT_MAX;
			cellat[i][j].h = FLT_MAX;
			cellat[i][j].pi = -1;
			cellat[i][j].pj = -1;
		}
	}

	i = src.first, j = src.second;
	cellat[i][j].f = 0.0;
	cellat[i][j].g = 0.0;
	cellat[i][j].h = 0.0;
	cellat[i][j].pi = i;
	cellat[i][j].pj = j;

	set<pPair> oList;

	oList.insert(make_pair (0.0, make_pair (i, j)));

	bool pathFound = false;
    int tl[][2] = {-1, 0,
                        1, 0,
                        0, 1,
                        0, -1,
                        -1, 1,
                        -1, -1,
                        1, 1,
                        1, -1};

	while (!oList.empty()) {
		pPair p = *oList.begin();
		oList.erase(oList.begin());
		i = p.second.first;
		j = p.second.second;
		cList[i][j] = true;
		double gNew, hNew, fNew;

        for(int tp=0; tp<8; tp++) {
            if (isValid(i+tl[tp][0], j+tl[tp][1]) == true) {
                if (i+tl[tp][0]==dest.first && j+tl[tp][1]==dest.second) {
                    cellat[i+tl[tp][0]][j+tl[tp][1]].pi = i;
                    cellat[i+tl[tp][0]][j+tl[tp][1]].pj = j;
                    printf ("Path Found \n");
                    printPath (cellat, dest);
                    pathFound = true;
                    return;
                }
                else if (cList[i+tl[tp][0]][j+tl[tp][1]] == false && maze[i+tl[tp][0]][j+tl[tp][1]] == 1) {
                    gNew = cellat[i][j].g + 1.0;
                    hNew = hOfN (i+tl[tp][0], j+tl[tp][1], dest);
                    fNew = gNew + hNew;
                    if (cellat[i+tl[tp][0]][j+tl[tp][1]].f == FLT_MAX || cellat[i+tl[tp][0]][j+tl[tp][1]].f > fNew) {
                        oList.insert( make_pair(fNew, make_pair(i+tl[tp][0], j+tl[tp][1])));
                        cellat[i+tl[tp][0]][j+tl[tp][1]].f = fNew;
                        cellat[i+tl[tp][0]][j+tl[tp][1]].g = gNew;
                        cellat[i+tl[tp][0]][j+tl[tp][1]].h = hNew;
                        cellat[i+tl[tp][0]][j+tl[tp][1]].pi = i;
                        cellat[i+tl[tp][0]][j+tl[tp][1]].pj = j;
                    }
                }
            }
        }
	}

	if (pathFound == false)
		printf("No Path Found\n");
	return;
}


int main() {
	int maze[ROW][COL] = {
		{ 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 1 },
	};
	Pair from = make_pair(0, 0);
	Pair to = make_pair(3, 7);
	aStar(maze, from, to);
	return(0);
}
