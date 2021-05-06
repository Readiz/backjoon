#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit(char fbasename[]) {
        char fname[100];
        char* ftailname = "_input.txt";
        int p;
        for (p = 0; fbasename[p] != 0; p++) fname[p] = fbasename[p];
        int t;
        for (t = 0; ftailname[t] != 0; t++) fname[p++] = ftailname[t];
        fname[p] = 0;
        printf("[DEBUG] No Online Judge detected!\n");
        printf("[DEBUG] Trying to use TC file: %s\n", fname);
        freopen(fname, "rt", stdin); 
    }
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END }return 0;}
#else
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
#define R register
typedef unsigned long long ull;
typedef long long ll;

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int S, T, D;
    scanf("%d %d %d", &S, &T, &D);
    printf("%d\n", D / (S * 2) * T);
MAIN_END

/*
폰 노이만과 파리 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB	1603	1317	1245	83.389%
문제
역사상 최고의 천재중 하나인 폰 노이만에게는 다음과 같은 재밌는 일화가 있다.

그의 동료는 어느 날 폰 노이만의 천재성을 시험해보기 위해서 다음과 같은 질문을 던졌다.

“200마일 길이의 철로의 양쪽 끝에 서 있는 두 대의 기차가 시속 50마일의 속도로 서로를 향해 출발했습니다. 이때부터 두 기차가 서로 충돌할 때까지 파리가 시속 75마일의 속도로 두 기차사이를 왔다 갔다 했습니다. 파리가 이동한 거리는 모두 몇 마일일까요?”

폰 노이만은 문제를 듣고 1초의 지체도 없이 150마일이라고 답했다. 그의 동료는 크게 실망하며 말했다.

“역시 당신은 똑똑하군요. 보통 사람들은 이 문제를 무한급수를 이용해서 풀려고 하지만 그렇게 하면 매우 긴 시간이 걸리죠. 하지만 간단한 논리를 사용하면 순식간에 파리가 이동한 거리를 구할 수 있습니다. 당신도 그 논리를 이용한 것이죠?”

그러자 폰 노이만은 이렇게 답했다.

“아니요, 무한급수로 풀었는데요?”

이 문제를 무한급수를 통해 푸는 방법은 다음과 같다.  수직선 위에 기차 A, B가 있다고 하자.  파리와 같이 출발하는 기차를 A라 하고, 그 위치를 기준점으로 하면 기차 B는 기준점에서 200마일 만큼 떨어진 지점에 있다. 이때 시간 t에서 파리의 위치는 75t 이고 기차 B의 위치는 200 – 50t 이다. 이를 이용하면 파리와 기차 B가 처음 만나는 위치는 기준점에서 120마일 떨어진 지점임을 알 수 있다.  120마일은 파리의 첫 이동거리 이고 이를 a1이라고 하자.  한편 이때 기차 A는 80마일 떨어진 지점에 위치한다 (기차 A의 속도는 파리의 속도의 2/3 이므로).  그러므로 기차 A와 B의 사이가 40마일로 줄어들었고, 같은 식으로 파리의 두 번째 이동거리 a2는 (1/5)a1임을 알 수 있다.  이와 같이 생각하면, ai+1은 (1/5)ia1이고, 파리의 총 이동거리는 Σ(1/5)ia1 = 150 즉 150마일임을 알 수 있다.

이 문제를 푸는 “간단한 논리”는 다음과 같다.  두 기차는 200/(50*2) = 2 시간 후에 만난다.  파리는 2시간동안 시간당 75마일의 속도로 이동하므로 2*75 = 150 마일을 이동한다.

우리는 위에서 제시한 문제를 풀 수 있는 프로그램을 만들고 싶다. 하지만 우리의 컴퓨터는 안타깝게도 폰 노이만의 두뇌보다 성능이 좋지 못하기 때문에 무한급수를 이용하여 프로그램을 만들 수는 없다.  위에서 말한 “간단한 논리”를 이용하여 기차의 속도 S,  파리의 속도 T, 그리고 처음 두 기차 사이의 거리 D가 주어졌을 때 두 기차가 만날 때까지 파리의 이동거리 F를 계산하는 프로그램을 작성하라.

입력
S T D 
각각 10,000보다 작거나 같은 양의 정수, T>S, D는 2*S의 배수
출력
F
예제 입력 1 
50 75 200
예제 출력 1 
150
*/