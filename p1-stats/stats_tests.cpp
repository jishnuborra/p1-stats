/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();
void test_count();
void test_sum();
void test_mean();
void test_median();
void test_min();
void test_max();
void test_stdev();
void test_percentile();
void test_filter();
// Add prototypes for you test functions here.

int main() {
  test_sum_small_data_set();
  // Call your test functions here
  test_count();
  test_sum();
  test_mean();
  test_median();
  test_min();
  test_max();
  test_stdev();
  test_percentile();
  test_filter();
  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

// Add the test function implementations here.
void test_count() {
  
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(count(data) == 3);
  cout << "PASS!" << endl;
}

void test_sum() {

  vector<double> data;
  data.push_back(5.2);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 10.2);
  cout << "PASS!" << endl;
}

void test_mean(){

  vector<double> data;

  data.push_back(10.1);
  data.push_back(5);
  data.push_back(2);

  assert(mean(data) == 5.7);
  cout << "PASS!" << endl;

}

void test_median(){

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(median(data) == 2);
  cout << "PASS!" << endl;
}

void test_min(){

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(min(data) == 1);
  cout << "PASS!" << endl;

}

void test_max(){
  
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(max(data) == 3);
  cout << "PASS!" << endl;
}

void test_stdev(){
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(stdev(data) == 1);
  cout << "PASS!" << endl;
}

void test_percentile(){
  vector<double> data = {35, 20, 15, 50, 40};
  assert(percentile(data, 0.4) == 29);
  cout << "PASS!" << endl;

}

void test_filter(){
  vector<double> locations = {0, 1, 0, 1, 1, 2, 2, 0, 1};
  vector<double> temps = {15.5, 23.1, 7.8, 19.2, 22.6, 4.6, 1.9, 14.3, 18.0}; 
  vector<double> temps_1 = {23.1, 19.2, 22.6, 18.0};
  assert(filter(temps, locations, 1) == temps_1);
  cout << "PASS!" << endl;
}