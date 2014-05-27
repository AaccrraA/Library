#ifndef PATTERNMATCHER_H
#define PATTERNMATCHER_H

#include <QtCore>

class PatternMatcher
{
public:
    static int bmpSearch(const QString& text, const QString& pattern);

private:
    static QHash<QChar,int> computeBmpLast(const QString &pattern);

    PatternMatcher();
    PatternMatcher(const PatternMatcher&);
    const PatternMatcher& operator=(const PatternMatcher&);
};

#endif // PATTERNMATCHER_H
