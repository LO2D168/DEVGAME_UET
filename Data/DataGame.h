#ifndef _DATAGAME__H
#define _DATAGAME__H

inline vector<int> scoreList;

inline void loadScoreData() {
    freopen("gameScore.txt", "r", stdin);
    freopen("gameScore.txt", "w", stdout);
    for (int i = 1; i <= 10; i++) {
        int num;
        cin >> num;

    }
    sort(scoreList.begin(), scoreList.end(), greater<>());
    while (scoreList.size() < 20) {scoreList.push_back(0);}
    while (scoreList.size() > 20) {scoreList.pop_back();}
}


#endif // _DATAGAME__H
