#ifndef P1_LIBRARY_HPP
#define P1_LIBRARY_HPP
/* p1_library.hpp
 *
 * Libraries needed for EECS 280 project 1
 *
 * by Andrew DeOrio <awdeorio@umich.edu>
 * 2015-04-28
 */

#include <vector>
#include <string>
#include <utility> // pair

//EFFECTS: Extracts two columns of data from a delimited file (e.g. .csv, .tsv),
//         omitting rows where either column has a missing or invalid value. The
//         columns are returned as a pair of vectors. Prints errors to stdout and
//         exits with non-zero status on errors.
std::pair<std::vector<double>, std::vector<double>> extract_columns(
  std::string filename, std::string column_name1, std::string column_name2);

//EFFECTS: Returns a bootstrap resampling of the given data, which has the
//         same number of elements as the original data vector. The values
//         of those elements are determined by pseudorandomly selecting from
//         the original data, with replacement, where the sample_num is used
//         to seed a pseudorandom number generator. The resample generated by
//         this function is uniquely determined by the values in the original
//         data vector (regardless of their ordering) and the provided
//         sample_num, and is consistent across platforms.
std::vector<double> bootstrap_resample(std::vector<double> data, int sample_num);

#endif
