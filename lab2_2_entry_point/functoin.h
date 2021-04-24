#ifndef FUNCES_H
#define FUNCES_H
#include <string>
#include <sstream>
#include <string.h>
#include <QVector>

#endif // FUNCES_H

#define N 3000

struct Demog {
    int year;
    std::string region;
    double natural_population_growth;
    double birth_rate;
    double death_rate;
    double general_demographic_weight;
    double urbanization;
};
//int action;

struct FuncArgument
{
    std::string filename;
    std::string Region;
    std::string metric;
    int nStruct;


};

struct FuncReturningValue
{
    int numberStructs;
    Demog* st;
    double Max, Min, Med;
                                // число столбцов в таблице
};

FuncReturningValue* entryPoint(int action, FuncArgument* fa);


//Demog RusDemog[N];

FuncReturningValue* ReadFile(std::string fPath);
FuncReturningValue * searchR(int, std::string);
double searchMax(std::string, int, int);
double searchMin(std::string, int, int);
double searchMed(std::string, int, int);
FuncReturningValue* findMetric (std::string Region,std::string metric, int n);
QVector<double> DataForDraw(std::string Region, std::string metric);


