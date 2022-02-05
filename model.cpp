#include "model.hpp"

vector<string> parseInput(string input, char parsingCriteria)
{
    vector<string> brokenLine;
    string word;
    istringstream s(input);
    while (getline(s, word, parsingCriteria))
        brokenLine.push_back(word);    
    return brokenLine;
}
void Model::insertWord(string line)
{
    vector<string> brokenLine = parseInput(line, COMMA);
    dictionary.insert(make_pair(brokenLine[0], Word(brokenLine[0], stod(brokenLine[2]), stod(brokenLine[1]))));
    return;
}
void Model::train(string filePath)
{
    ifstream csvFile;
    csvFile.open(filePath, ios::in);
    if (!csvFile.is_open()) 
    {
        csvFile.close();
        throw badRequest();
    }
    string line;
    getline(csvFile, line);
    while (getline(csvFile, line))
        insertWord(line);
    csvFile.close();
    return;
}
void Model::evaluateModel(string filePath)
{
    float allComments = 0, allAppropriateComments = 0, correctAppropriateDetected = 0, correctDetected = 0, appropriateDetected = 0;
    ifstream csvFile;
    ofstream report;
    csvFile.open(filePath, ios::in);
    report.open("output.txt", ios::out);
    if (!csvFile.is_open()) 
    {
        csvFile.close();
        throw badRequest();
    }
    string line;
    getline(csvFile, line);
    while (getline(csvFile, line))
    {
        vector<string> brokenLine = parseInput(line, COMMA);
        allComments++;
        if (!stoi(brokenLine[1]))
            allAppropriateComments++;
        bool goodOrBad = isBadComment(brokenLine[0]);
        if (!goodOrBad)
            appropriateDetected++;
        if (goodOrBad == stoi(brokenLine[1]))
        {
            correctDetected++;
            if (!goodOrBad)
                correctAppropriateDetected++;
        }
    }
    csvFile.close();
    report << "Recall = " << (correctAppropriateDetected / allAppropriateComments) * 100 << endl;
    report << "Precision = " << (correctAppropriateDetected / appropriateDetected) * 100 << endl;
    report << "Accuracy = " << (correctDetected / allComments) * 100 << endl;
    report.close();
    return;
}
bool Model::isBadComment(string comment)
{
    double positiveP = log10(0.91175), negativeP = log10(1 - 0.91175);
    stringstream s(comment);
    string word;
    while (s >> word)
    {
        if (dictionary.find(word) == dictionary.end() || ((dictionary.at(word).getNegP() == 0) && (dictionary.at(word).getPosP() == 0)))
            continue;
        if ((dictionary.at(word).getNegP() == 0) && (dictionary.at(word).getPosP() != 0))
            return false;
        else if ((dictionary.at(word).getNegP() != 0) && (dictionary.at(word).getPosP() == 0))
            return true;
        negativeP += log10(dictionary.at(word).getNegP());
        positiveP += log10(dictionary.at(word).getPosP());
    }
    if (negativeP >= positiveP)
        return true;
    else
        return false;
    
}