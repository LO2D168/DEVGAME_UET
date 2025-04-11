#ifndef _DataVocal__H
#define _DataVocal__H

inline vector<string> dictionary;
inline void loadData() {
       freopen("../Data/dictionary.txt","r",stdin);
       string s;
       for (int i = 0; i < mod_vocal; i++) {
              cin >> s;
              dictionary.push_back(s);
       }
}
#endif // _DataVocal__H