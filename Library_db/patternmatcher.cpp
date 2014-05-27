#include "patternmatcher.h"
#include <algorithm>

int PatternMatcher::bmpSearch(const QString &text, const QString &pattern){
    int textLen = text.length();
    int patternLen = pattern.length();
    if(textLen == 0 || patternLen == 0){
        return -1;
    }
    if(patternLen > textLen){
        return -1;
    }

    QHash<QChar,int> bmpLast = computeBmpLast(pattern);
    int tIdx = patternLen - 1;
    int pIdx = patternLen - 1;
    while(tIdx < textLen){
        if(pattern.at(pIdx) == text.at(tIdx)){
            if(pIdx == 0){   //found a match
                return tIdx;
            }
            tIdx--;
            pIdx--;
        }
        else {
            // --- Эвристика перехода
            int lastOccur;
            if (bmpLast.contains(text.at(tIdx)))
                lastOccur = bmpLast.value(text.at(tIdx));
            else
                lastOccur = -1;
            tIdx = tIdx + patternLen - qMin(pIdx, 1 + lastOccur);
            pIdx = patternLen - 1;
        }
    }
    return - 1;
}

QHash<QChar,int> PatternMatcher::computeBmpLast(const QString &pattern) {
    QHash<QChar,int> bmpLast;
    for(int i = 0; i < pattern.length(); i++) {
        bmpLast.insert(pattern.at(i), i);
    }
    return bmpLast;
}
