#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <float.h>


#include "functoin.h"



FuncReturningValue* entryPoint(int action, FuncArgument* fa)
{
    FuncReturningValue* result;

    switch (action) {
        case 1:
            result = ReadFile(fa->filename);
            break;
        case 2:
           result = searchR(fa->nStruct, fa->Region);
           break;
        case 3:
            result = findMetric(fa->Region, fa->metric, fa->nStruct);
            break;
    }

    return result;
}



Demog RusDemog[N];

FuncReturningValue* ReadFile(std::string fPath)
{
    FuncReturningValue *frv = (FuncReturningValue *)malloc(sizeof(FuncReturningValue));
    std::string line, word, temp;
    //    std::string::size_type sz;

    std::fstream fin;

    fin.open(fPath, std::fstream::in);
    if (!fin) {
        frv->numberStructs = -1;
        return frv;
    }

    getline(fin, temp);

        int i = 0;
        while ( getline(fin, line) ) {

            std::stringstream s;
            s << line;

            getline(s, word, ',');
            RusDemog[i].year = stoi(word);

            getline(s, word, ',');
            RusDemog[i].region = word;

            getline(s, word, ',');
            if (word == "") word = '0';
            RusDemog[i].natural_population_growth = std::stod(word);

            getline(s, word, ',');
            if (word == "") word = '0';
            RusDemog[i].birth_rate = stof(word);

            getline(s, word, ',');
            if (word == "") word = '0';
            RusDemog[i].death_rate = stof(word);

            getline(s, word, ',');
            if (word == "") word = '0';
            RusDemog[i].general_demographic_weight = stof(word);

            getline(s, word, ',');
            if (word == "") word = '0';
            RusDemog[i].urbanization = stof(word);

            i++;
        }

    frv->numberStructs = i - 1;
    return frv;
}

FuncReturningValue * searchR(int i, std::string Region)
{
    FuncReturningValue *frv = (FuncReturningValue *)malloc(sizeof(FuncReturningValue));

    if (Region.compare(RusDemog[i].region) == 0) {
        frv->st = &RusDemog[i];
        return frv;
    } else {
        return NULL;
    }
}



double searchMax(std::string Region, int nMetric, int numStruct)
{
    double vM = -DBL_MAX;
    for (int i = 0; i <= numStruct; i++ ){
        if (Region.compare(RusDemog[i].region) == 0) {
            switch (nMetric) {
                case 1:
                    if ( RusDemog[i].natural_population_growth > vM) { vM = RusDemog[i].natural_population_growth; }
                    break;
                case 2:
                    if ( RusDemog[i].birth_rate > vM) { vM = RusDemog[i].birth_rate; }
                    break;
                case 3:
                    if ( RusDemog[i].death_rate > vM) { vM = RusDemog[i].death_rate; }
                    break;
                case 4:
                    if ( RusDemog[i].general_demographic_weight > vM) { vM = RusDemog[i].general_demographic_weight; }
                    break;
                case 5:
                    if ( RusDemog[i].urbanization > vM) { vM = RusDemog[i].urbanization; }
                    break;
            }
        }
    }

    return vM;
}

double searchMin(std::string Region, int nMetric, int numStruct)
{
    double vM = DBL_MAX;
    for (int i = 0; i <= numStruct; i++ ){
        if (Region.compare(RusDemog[i].region) == 0) {
            switch (nMetric) {
                case 1:
                    if ( RusDemog[i].natural_population_growth < vM) { vM = RusDemog[i].natural_population_growth; }
                    break;
                case 2:
                    if ( RusDemog[i].birth_rate < vM) { vM = RusDemog[i].birth_rate; }
                    break;
                case 3:
                    if ( RusDemog[i].death_rate < vM) { vM = RusDemog[i].death_rate; }
                    break;
                case 4:
                    if ( RusDemog[i].general_demographic_weight < vM) { vM = RusDemog[i].general_demographic_weight; }
                    break;
                case 5:
                    if ( RusDemog[i].urbanization < vM) { vM = RusDemog[i].urbanization; }
                    break;
            }
        }
    }

    return vM;
}

double searchMed(std::string Region, int nMetric, int numStruct) {
    std::vector <double> items;

    for (int i = 0; i <= numStruct; i++ ){
        if (Region.compare(RusDemog[i].region) == 0) {
            switch (nMetric) {
                case 1:
                    items.push_back(RusDemog[i].natural_population_growth);
                    break;
                case 2:
                    items.push_back(RusDemog[i].birth_rate);
                    break;
                case 3:
                    items.push_back(RusDemog[i].death_rate);
                    break;
                case 4:
                    items.push_back(RusDemog[i].general_demographic_weight);
                    break;
                case 5:
                    items.push_back(RusDemog[i].urbanization);
                    break;
            }
        }
    }

    sort(items.begin(), items.end());

    if (items.size() % 2) {
        return items[(items.size() - 1) / 2 + 1];
//        return items[items.size() / 2 + 1]
    } else {
        return (items[items.size() / 2] + items[items.size() / 2 - 1]) / 2;
    }
}

QVector<double> DataForDraw(std::string Region, std::string metric)
{
    QVector <double> myVector;
    for (int i = 0; i < N; i++)
    {
        if (Region.compare(RusDemog[i].region) == 0) {
            if (metric.compare("natural_population_growth") == 0)
                myVector.push_back(RusDemog[i].natural_population_growth);
            if (metric.compare("birth_rate") == 0)
                myVector.push_back(RusDemog[i].birth_rate);
            if (metric.compare("death_rate") == 0)
                myVector.push_back(RusDemog[i].death_rate);
            if (metric.compare("general_demographic_weight") == 0)
                myVector.push_back(RusDemog[i].general_demographic_weight);
            if (metric.compare("urbanization") == 0)
                myVector.push_back(RusDemog[i].urbanization);
        }
    }
    return myVector;
}

FuncReturningValue* findMetric (std::string Region,std::string metric, int n)
{
    FuncReturningValue *frv = (FuncReturningValue *)malloc(sizeof(FuncReturningValue));

    if (metric.compare("natural_population_growth") == 0)  { frv->Max = searchMax(Region, 1, n); }
    if (metric.compare("birth_rate") == 0)                 { frv->Max = searchMax(Region, 2, n); }
    if (metric.compare("death_rate") == 0)                 { frv->Max = searchMax(Region, 3, n); }
    if (metric.compare("general_demographic_weight") == 0) { frv->Max = searchMax(Region, 4, n); }
    if (metric.compare("urbanization") == 0)               { frv->Max = searchMax(Region, 5, n); }

    if (metric.compare("natural_population_growth") == 0)  { frv->Min = searchMin(Region, 1, n); }
    if (metric.compare("birth_rate") == 0)                 { frv->Min = searchMin(Region, 2, n); }
    if (metric.compare("death_rate") == 0)                 { frv->Min = searchMin(Region, 3, n); }
    if (metric.compare("general_demographic_weight") == 0) { frv->Min = searchMin(Region, 4, n); }
    if (metric.compare("urbanization") == 0)               { frv->Min = searchMin(Region, 5, n); }

    if (metric.compare("natural_population_growth") == 0)  { frv->Med = searchMed(Region, 1, n); }
    if (metric.compare("birth_rate") == 0)                 { frv->Med = searchMed(Region, 2, n); }
    if (metric.compare("death_rate") == 0)                 { frv->Med = searchMed(Region, 3, n); }
    if (metric.compare("general_demographic_weight") == 0) { frv->Med = searchMed(Region, 4, n); }
    if (metric.compare("urbanization") == 0)               { frv->Med = searchMed(Region, 5, n); }

    return frv;
}

