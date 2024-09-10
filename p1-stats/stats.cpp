// stats.cpp
#include "stats.hpp"
#include <cassert>
#include <vector>
#include <algorithm> // sort
#include <cmath> //sqrt, 
#include <iostream>
using namespace std;

using namespace std;

int count(vector<double> v) {
  return v.size();
}

double sum(vector<double> v) {
  double numSum = 0;

  for (int x = 0; x < v.size(); ++x){
    numSum += v[x];
  }
  return numSum;
}

double mean(vector<double> v) {
    return sum(v)/count(v);
}

double median(vector<double> v) {
    sort(v.begin(), v.end());
    int centerNum = count(v)/2; //Dividing the number of values by 2 to get the middle index of the vector
    if (count(v) % 2 == 0){ //If even number of values
        return (v[centerNum] + v[centerNum + 1]) / 2; //Return the average of the value between the Center and the number after
    }else{
        return v[centerNum];
    }
}

double min(vector<double> v) {
  sort(v.begin(), v.end());
  return v[0];
}

double max(vector<double> v) {
    sort(v.begin(), v.end());
    return v[count(v) - 1]; //Returns the last value by using the count function - minus one because the index value is greater thna the ;ast value
}

double stdev(vector<double> v) {
  double num = 0;
  for (int i = 0; i < v.size(); ++i){
    num += pow(v[i] - mean(v), 2);
  }
  return sqrt((num / (v.size() - 1)));
}

double percentile(vector<double> v, double p) {
  sort(v.begin(), v.end());
  double rank = ((p)*(v.size()-1.0) + 1.0);
  double d = 0;
  double k = 0;
  d = modf(rank, &k);
  return (v[k-1] + d*(v[k] - v[k-1]));
}

vector<double> filter(vector<double> v,
                      vector<double> criteria,
                      double target) {
                        vector<double> filteredList;
                        for (int i = 0; i < criteria.size(); ++i){
                          if (criteria[i] == target){
                            filteredList.push_back(v[i]); //storing all the indices of the target value
                          }                         
                        }
                        return filteredList;
}
