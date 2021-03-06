#!/bin/bash

# warning: run in the background, this takes ~10 minutes to run!
#
# compares the time needed to run the failing grade extraction for the
# vector-based implementation versus the list-based implementation

NGRADES=7              # number of grades generated for each observation
NAMELEN=10             # length of randomly generated names
NOBS=(735 7350 73500)  # vector of the number of observations

# filenames to be benchmarked
exec_arr=(exer05_02_vector exer05_02_list)

# program descriptions
desc_arr=(vector-based list-based vector-resizing-based)


# run benchmarking script using variable settings as provided above
. benchmark_list_vs_vec.sh
