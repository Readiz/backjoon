#include <stdio.h>

int T, M, N, K, wormNum;
int board[51][51] = {0, };
bool isDebug = false;

void printBoard() {
    if (!isDebug) return;
    printf("----------------------------------\n");
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            printf("%d ", board[y][x]);
        }
        printf("\n");
    }
    printf("----------------------------------\n");
}

bool isValidPos(int x, int y) {
    if (x >= 0 && x < M && y >= 0 && y < N) return true;
    return false;
}

void checkNeighbor(int x, int y) {
    if (!isValidPos(x, y)) return;
    if (board[y][x] == 1) {
        board[y][x] = 2;
        // 인접된 녀석들을 2로 만든다.. DFS.
        checkNeighbor(x + 1, y);
        checkNeighbor(x - 1, y);
        checkNeighbor(x, y + 1);
        checkNeighbor(x, y - 1);
    }
}

void deleteCache() { // 2를 지운다
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] == 2) {
                board[y][x] = 0;
            }
        }
    }
}

void findBaechu() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] == 1) { // 배추를 찾았으면
                board[y][x] = 2; // 타겟 배추는 2로 설정
                wormNum++; // 배추 벌레 풀자..
                 // 인접된 녀석들을 2로 만든다.. DFS.
                checkNeighbor(x + 1, y);
                checkNeighbor(x - 1, y);
                checkNeighbor(x, y + 1);
                checkNeighbor(x, y - 1);
                printBoard();
                // 2는 이제 삭제
                deleteCache();
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &M, &N, &K);
        wormNum = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                board[y][x] = 0;
            }
        }
        for (int j = 0; j < K; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            board[y][x] = 1;
        }
        findBaechu();
        printf("%d\n", wormNum);
    }
}

/*
문제
차세대 영농인 한나는 강원도 고랭지에서 유기농 배추를 재배하기로 하였다. 농약을 쓰지 않고 배추를 재배하려면 배추를 해충으로부터 보호하는 것이 중요하기 때문에, 한나는 해충 방지에 효과적인 배추흰지렁이를 구입하기로 결심한다. 이 지렁이는 배추근처에 서식하며 해충을 잡아 먹음으로써 배추를 보호한다. 특히, 어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있어, 그 배추들 역시 해충으로부터 보호받을 수 있다.

(한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있다고 간주한다)

한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어놓았다. 배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로 서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다.

예를 들어 배추밭이 아래와 같이 구성되어 있으면 최소 5마리의 배추흰지렁이가 필요하다.

(0은 배추가 심어져 있지 않은 땅이고, 1은 배추가 심어져 있는 땅을 나타낸다.)

1	1	0	0	0	0	0	0	0	0
0	1	0	0	0	0	0	0	0	0
0	0	0	0	1	0	0	0	0	0
0	0	0	0	1	0	0	0	0	0
0	0	1	1	0	0	0	1	1	1
0	0	0	0	1	0	0	1	1	1
입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다.

출력
각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.
*/
