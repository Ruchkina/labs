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


//Demog RusDemog[N];

int ReadFile(std::string);
Demog* searchR(int, std::string);
double searchMax(std::string, int, int);
double searchMin(std::string, int, int);
double searchMed(std::string, int, int);
double findMax (std::string Region, std::string metric, int n);
double findMin (std::string Region,std::string metric, int n);
double findMed (std::string Region,std::string metric, int n);
QVector<double> DataForDraw(std::string Region, std::string metric);
