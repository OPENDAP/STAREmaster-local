/// @file

/// This class contains the main functionality for reading a file that
/// may be given a STARE sidecar file.

/// Ed Hartnett 4/4/20

#ifndef GEO_FILE_H_ /**< Protect file from double include. */
#define GEO_FILE_H_

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "ssc.h"
#include "STARE.h"

using namespace std;

#define MAX_NUM_INDEX 10 /**< Max number of STARE index vars in a file. */

/**
 * This is the base class for a data file with geolocation.
 */
class GeoFile {
public:
    GeoFile();

    ~GeoFile();

    /** Read file. */
    int readFile(const string fileName, int verbose, int quiet, int build_level);

    /** Get STARE index sidecar filename. */
    string sidecarFileName(string fileName);

    int readSidecarFile(std::string fileName, int verbose, int &ncid);

#if 0
    /** Get STARE index for data variable. */
    int getSTAREIndex(std::string varName, int verbose, int ncid, int &varid,
                      size_t &my_size_i, size_t &my_size_j);
#endif

    /** Get STARE indices for data variable. */
    int getSTAREIndex_2(std::string varName, int verbose, int ncid, vector<unsigned long long> &values);

    /** Close sidecar file. */
    int closeSidecarFile(int verbose, int ncid);

    int num_index; /**< Number of STARE index sets needed for this file. */
    int *geo_num_i1; /**< Number of I. */
    int *geo_num_j1; /**< Number of J. */
    double **geo_lat1; /**< Array of 'index sets' (e.g., 2) latitude values. */
    double **geo_lon1; /**< Array of 'index sets' longitude values. */
    unsigned long long **geo_index1; /**< Array of 'index sets' of STARE indices. */

    int num_cover;
    unsigned long long **geo_cover1; /**< Array of 'index sets' of STARE covers. */
    int *geo_num_cover_values1;
    vector<string> var_name[MAX_NUM_INDEX]; /**< Names of vars that use this index. */
    STARE_SpatialIntervals cover;

    int cover_level;
    int perimeter_stride;

    vector<string> stare_index_name;
    vector<string> stare_cover_name;
    vector<string> variables;

#if 1
    // I think these are only used by the old getSTAREIndex() method
    vector<size_t> size_i, size_j;
    vector<int> stare_varid;
#endif
};

#endif /* GEO_FILE_H_ */
