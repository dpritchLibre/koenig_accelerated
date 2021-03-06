#!/bin/bash

# program location
exer_loc="exer03_03"

# process command line arguments
. ../testing/process_args.sh

# declare variables to store testing data
. ../testing/declare_vars.sh




# construct tests --------------------------------------------------------------

outstring="Please enter a list of words followed by an EOF character:  Word counts:
------------"

testname[arr_idx]='data of size 0'
input[arr_idx]=''
target[arr_idx]="$outstring"
((arr_idx++))

testname[arr_idx]='data of size 1'
input[arr_idx]='C++'
target[arr_idx]="$outstring
C++		1"
((arr_idx++))

testname[arr_idx]='multiple repeating words'
input[arr_idx]='this is this is a a a test is is is'
target[arr_idx]="$outstring
this		2
is		5
a		3
test		1"
((arr_idx++))




# conduct tests ----------------------------------------------------------------

. ../testing/conduct_tests.sh
