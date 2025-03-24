#ifndef _DataVocal__H
#define _DataVocal__H

inline vector<string> dictionary;
inline void loadData() {
       freopen("dictionary.txt","r",stdin);
       string s;
       while (cin >> s) {
              dictionary.push_back(s);
       }
}
#endif // _DataVocal__H
