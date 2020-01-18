
/*
가능한 모든 조합을 구한다
visit하지않은 x로 쿼리 결과값을 구한다
x가 4s가아니라면
x로 다른 조합들을 비교하여 정답과 다른 result인아이들을 visit체크한다
*/

#define N 4

typedef struct {
	int strike;
	int ball;
} Result;

extern Result query(int guess[]);

int visit[9999];
int num[9999];
int guess_cnt;
bool isInit = false;

//가능한 모든 조합 만들어주는 함수 num에 차례대로 저장
void init() {
	guess_cnt = 0;
	isInit = true;
	for (int i = 1; i <= 9; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (i == j)continue;
			for (int k = 0; k <= 9; ++k) {
				if (i == k || j == k) continue;
				for (int l = 0; l <= 9; ++l) {
					if (i == l || j == l || k == l) continue;
					num[guess_cnt++] = i * 1000 + j * 100 + k * 10 + l;
				}
			}
		}
	}
}

void resetVisit() {
	for (register int i = 0; i < guess_cnt; ++i) {
		visit[num[i]] = 0;
	}
}

Result getResult(int guess[], int obj[]) {
	int cnt[10] = { 0, };
	Result result = { 0,0 };

	for (int i = 0; i < N; ++i) {
		if (guess[i] == obj[i]) result.strike++;
		else {
			cnt[guess[i]]++;
			cnt[obj[i]]++;
		}
	}
	
	for (int i = 0; i <= 9; i++) {
		if (cnt[i] == 2) result.ball++;
	}

	return result;

}
void toArr(int arr[], int x) {
	arr[0] = x / 1000;
	arr[1] = (x / 100) % 10;
	arr[2] = (x / 10) % 10;
	arr[3] = x % 10;
}

void doUserImplementation(int guess[]) {
	Result result = { 0,0 };
	Result objResult = { 0,0 };
	int obj[4];

	if(!isInit)
		init();
	resetVisit();

	while (true)
	{
		for (register int i = 0; i < guess_cnt; ++i) {
			if (visit[num[i]] != -1) {
				toArr(guess, num[i]);
				result = query(guess);
				visit[num[i]] = -1;
				break;
			}
		}

		if (result.strike == 4) break;

		for (register int i = 0; i < guess_cnt; ++i) {
			if (visit[num[i]] != -1) {
				toArr(obj, num[i]);
				objResult = getResult(guess, obj);

				if (objResult.strike == result.strike && objResult.ball == result.ball) continue;
				visit[num[i]] = -1;
			}
		}
	}
}
