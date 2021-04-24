#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <float.h>


#include "funces.h"

Demog RusDemog[N];

int ReadFile(std::string fPath)
{
    std::string line, word, temp;
    //    std::string::size_type sz;

    std::fstream fin;

    fin.open(fPath, std::fstream::in);
    if (!fin) {
        return -1;
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
    return i-1;
}

Demog* searchR(int i, std::string Region){
    if (Region.compare(RusDemog[i].region) == 0) {
        return &RusDemog[i];
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

double findMax (std::string Region,std::string metric, int n)
{
    double vM;
    if (metric.compare("natural_population_growth") == 0)  { vM = searchMax(Region, 1, n); }
    if (metric.compare("birth_rate") == 0)                 { vM = searchMax(Region, 2, n); }
    if (metric.compare("death_rate") == 0)                 { vM = searchMax(Region, 3, n); }
    if (metric.compare("general_demographic_weight") == 0) { vM = searchMax(Region, 4, n); }
    if (metric.compare("urbanization") == 0)               { vM = searchMax(Region, 5, n); }
    return vM;
}

double findMin (std::string Region,std::string metric, int n)
{
    double vM;
    if (metric.compare("natural_population_growth") == 0)  { vM = searchMin(Region, 1, n); }
    if (metric.compare("birth_rate") == 0)                 { vM = searchMin(Region, 2, n); }
    if (metric.compare("death_rate") == 0)                 { vM = searchMin(Region, 3, n); }
    if (metric.compare("general_demographic_weight") == 0) { vM = searchMin(Region, 4, n); }
    if (metric.compare("urbanization") == 0)               { vM = searchMin(Region, 5, n); }
    return vM;
}

double findMed (std::string Region,std::string metric, int n)
{
    double vM;
    if (metric.compare("natural_population_growth") == 0)  { vM = searchMed(Region, 1, n); }
    if (metric.compare("birth_rate") == 0)                 { vM = searchMed(Region, 2, n); }
    if (metric.compare("death_rate") == 0)                 { vM = searchMed(Region, 3, n); }
    if (metric.compare("general_demographic_weight") == 0) { vM = searchMed(Region, 4, n); }
    if (metric.compare("urbanization") == 0)               { vM = searchMed(Region, 5, n); }
    return vM;
}
