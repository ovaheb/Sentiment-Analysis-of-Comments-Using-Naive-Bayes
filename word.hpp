#ifndef __WORD_H__
#define __WORD_H__

#include "libraries.hpp"

class Word
{
public:
    Word(string word, double neg, double pos)
        : feature(word), posP(pos), negP(neg) {}
    string getFeature() { return feature; }
    double getNegP() { return negP; }
    double getPosP() { return posP; }
private:
    string feature;
    double posP;
    double negP;
};

#endif