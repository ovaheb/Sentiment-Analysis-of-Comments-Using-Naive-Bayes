#ifndef __MODEL_H__
#define __MODEL_H__

#include "libraries.hpp"
#include "word.hpp"

class badRequest {};

class Model
{
public:
    void evaluateModel(string filePath);
    void insertWord(string line);
    void train(string filePath);
    bool isBadComment(string comment);
private:
    unordered_map<string, Word> dictionary;
};

#endif