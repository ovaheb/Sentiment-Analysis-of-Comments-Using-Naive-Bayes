#include "libraries.hpp"
#include "model.hpp"

int main()
{
    string command;
    Model commentHandler;
    commentHandler.train("train.csv");
    try
    {
        commentHandler.evaluateModel("test.csv");
    }
    catch (badRequest ex)
    {
        cout << "Bad Request\n";
    }
    return 0;
}