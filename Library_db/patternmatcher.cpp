#include "patternmatcher.h"
#include <algorithm>

qint32 PatternMatcher::bmpSearch(const QString &text, const QString &pattern){
    qint32 textLen = text.length();
    qint32 patternLen = pattern.length();
    if(textLen == 0 || patternLen == 0){
        return -1;
    }
    if(patternLen > textLen){
        return -1;
    }

    QHash<QChar,int> bmpLast = computeBmpLast(pattern);
    qint32 tIdx = patternLen - 1;
    qint32 pIdx = patternLen - 1;
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
            qint32 lastOccur;
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
    for(qint32 i = 0; i < pattern.length(); i++) {
        bmpLast.insert(pattern.at(i), i);
    }
    return bmpLast;
}
