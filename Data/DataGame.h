#ifndef _DATAGAME__H
#define _DATAGAME__H

inline vector<int> scoreList;

inline void loadScoreData() {
    scoreList.clear();
    freopen("gameScore.txt", "r", stdin);
    for (int i = 1; i <= 20; i++) {
        int num;
        cin >> num;
    }
    sort(scoreList.begin(), scoreList.end(), greater<>());
    while (scoreList.size() < 20) {scoreList.push_back(0);}
    while (scoreList.size() > 20) {scoreList.pop_back();}
}

inline void updateScore(int num) {
    freopen("gameScore.txt", "w", stdout);
    scoreList.push_back(num);
    sort(scoreList.begin(), scoreList.end(), greater<>());
    while (scoreList.size() < 20) {scoreList.push_back(0);}
    while (scoreList.size() > 20) {scoreList.pop_back();}
    for (auto c: scoreList) cout << c << '\n';
}


#endif // _DATAGAME__H
