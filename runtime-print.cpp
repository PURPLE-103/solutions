#include <bits/stdc++.h>
using namespace std;

int main()
{
    int TIME = 0;
    clock_t start = clock();
    
    // RANDOM CODE

    TIME += ((int)clock() - start) / (CLOCKS_PER_SEC / 1000);
    cout << TIME;
}

// int TIME = 0;
//
//   /* Timer on */
//	clock_t start = clock();
//
//	/* 실행 코드 들어가는 부분*/
//
//  /* Timer off */
//	TIME += ((int)clock() - start) / (CLOCKS_PER_SEC / 1000);
//
//	printf("TIME : %d ms\n", TIME); /* ms 단위로 출력 */