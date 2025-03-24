#ifndef _DATAGAME__H
#define _DATAGAME__H

inline vector<int> scoreList;

inline void loadScoreData() {
    sort(scoreList.begin(), scoreList.end(), greater<>());
    while (scoreList.size() < 20) {scoreList.push_back(0);}
    while (scoreList.size() > 20) {scoreList.pop_back();}
}

inline void addScore(int val) {
    scoreList.push_back(val);
    loadScoreData();
}

inline void prepareData() {
    while (scoreList.size() < 20) {scoreList.push_back(0);}
}

#endif // _DATAGAME__H
