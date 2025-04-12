#ifndef _DATAGAME__H
#define _DATAGAME__H

inline vector<int> scoreList;

inline void resetT() {
    ofstream outFile("../Data/gameScore.bin", ios::binary);
    int num[20];
    for (int i = 0; i < 20; i++) {num[i] = 0;}
    outFile.write((char*)num, sizeof(num));
    outFile.close();
}

inline void loadScoreData() {
    scoreList.clear();
    ifstream inFile("../Data/gameScore.bin", ios::binary);
    int num[20];
    inFile.read((char*)num, sizeof(num));
    for (int i = 0; i < 20; i++) {
        scoreList.push_back(num[i]);
    }
    sort(scoreList.begin(), scoreList.end(), greater<>());
    while (scoreList.size() < 20) {scoreList.push_back(0);}
    while (scoreList.size() > 20) {scoreList.pop_back();}
    inFile.close();
}

inline void updateScore(int num) {
    ofstream outFile("../Data/gameScore.bin", ios::binary);
    scoreList.push_back(num);
    sort(scoreList.begin(), scoreList.end(), greater<>());
    while (scoreList.size() < 20) {scoreList.push_back(0);}
    while (scoreList.size() > 20) {scoreList.pop_back();}
    int Num[20];
    for (int i = 0; i < 20; i++) {Num[i] = scoreList[i];}
    outFile.write((char*)Num, sizeof(Num));
    outFile.close();
}


#endif // _DATAGAME__H
