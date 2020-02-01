#include<iostream>
#include<queue>
#include<deque>
#include<vector>
using namespace std;

int main() {
	int va[1001], vb[1001];				//찾고자하는창고에온사람의idx -> true
	int tn[10], tm[10];					//창고걸리는시간
	int cnt,kdx;
	vector<int>emptyN, emptyM;
	int n, m, k, a, b;
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> k >> a >> b;
		deque<int> tk(k);
		vector<pair<int, int>> narr(n);
		vector<pair<int, int>> marr(m);
		queue<int>waitN, waitM;				//waiting하는 사람들idx
		fill_n(&va[0], 1001, 0);
		fill_n(&vb[0], 1001, 0);

		for (int i = 0; i < n; i++)
			cin >> tn[i];
		for (int i = 0; i < m; i++)
			cin >> tm[i];
		for (int i = 0; i < k; i++) {
			cin >> tk[i];
		}
		
		cnt = 0;
		kdx = 0;
		while (true) {
			emptyN.clear(); emptyM.clear();

			///m창구
			for (int i = 0; i < m; i++) {
				if (marr[i].first == 0) {					//비어있으면 x
					continue;
				}
				else if (marr[i].second == tm[i]-1) {		//창구처리시간다되면
					marr[i] = { 0,0 };						//0,0으로 빼주기
				}
				else {										//그외모두 시간+1해주기
					marr[i].second += 1;
				}
			}
			///m창구 비어있는 idx저장 -> emptyM
			for (int i = 0; i < m; i++) {				
				if (marr[i].first == 0 && marr[i].second == 0)
					emptyM.push_back(i);
			}

			///n창구
			for (int i = 0; i < n; i++) {
				if (narr[i].first == 0) {					//비어있으면 x
					continue;
				}
				else if (narr[i].second == tn[i]-1) {		//창구처리시간다되면
					waitM.push(narr[i].first);				//웨이팅M에 사람인덱스넣기
					narr[i] = { 0,0 };						//0,0으로 빼주기
				}
				else {										//그외모두 시간+1해주기
					narr[i].second += 1;
				}
			}
			///n창구 비어있는 idx 저장 -> emptyN
			for (int i = 0; i < n; i++) {
				if (narr[i].first == 0 && narr[i].second == 0)
					emptyN.push_back(i);
			}

			///waitM -> m창구
			for (int i = 0; i < emptyM.size(); i++) {		//m창구비어있는수만큼넣어줄수있음
				if (!waitM.empty()) {						//기다리는사람이있으면
					if (emptyM[i] == b-1)					//구하고자하는타켓m이면 vb에 체크해줌
						vb[waitM.front()] = -1;
					marr[emptyM[i]] = { waitM.front(),0 };	//m창구에 넣어줌
					waitM.pop();							//waitm에서 빼줌
				}
			}

			///들어온사람->waitN
			int temp=0;
			for (int i = kdx; i < k; i++) {
				if (cnt == tk[i]) {			//현재시간이 들어온사람의도착시간이면
					waitN.push(i+1);		//waitN에 넣어줌
					temp = i;
				}
				else {
					kdx = i;
					break;
				}
			}
			if (temp > kdx) kdx = temp;		//kdx = tk의 인덱스 : 아직도착못한사람인덱스

			///waitN -> n창구
			for (int i = 0; i < emptyN.size(); i++) {		//n창구비어있는수만큼넣어줄수있음
				if (!waitN.empty()) {						//기다리는사람있으면
					if (emptyN[i] == a-1)
						va[waitN.front()] = -1;
					narr[emptyN[i]] = { waitN.front(), 0 };
					waitN.pop();
				}
			}


			//사람모두 창구완료했는가
			int etyn=0, etym=0;
			for (int i = 0; i < n; i++) {		//n창고에아무도x
				if (narr[i].first != 0)
					etyn++;
			}
			for (int i = 0; i < m; i++) {		//m창고에아무도x
				if (marr[i].first != 0)
					etym++;
			}
			if (etyn == 0 && etym == 0 && kdx>=k-1)	//모든사람들어옴
				break;

	
			cnt++;

		}

		//va와 vb에 모두간 사람의 idx 합구하기
		int anw = -1;
		for (int i = 1; i <= k; i++) {
			if (va[i] == -1 && vb[i] == -1) {
				anw += i;
			}
		}
		if (anw != -1) anw++;
		cout <<"#"<<t<<" "<< anw << endl;
	}
	return 0;
}
