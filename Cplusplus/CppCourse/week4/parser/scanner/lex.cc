// Generated by Flexc++ V1.08.00 on Wed, 08 Mar 2017 01:37:10 +0100

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

// $insert class_ih
#include "scanner.ih"


    // s_ranges__: use (unsigned) characters as index to obtain
    //           that character's range-number.
    //           The range for EOF is defined in a constant in the
    //           class header file
size_t const ScannerBase::s_ranges__[] =
{
     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
     3, 3, 3, 3, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 7, 8, 9,10,11,11,
    11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,13,13,13,13,14,15,15,15,15,15,
    15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,16,16,17,18,19,20,21,
    22,23,24,25,26,27,28,28,29,30,31,32,33,34,35,36,37,38,38,38,39,40,40,41,41,
    41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,
    41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,
    41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,
    41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,
    41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,
    41,41,41,41,41,41,
};

    // s_dfa__ contains the rows of *all* DFAs ordered by start state.
    // The enum class StartCondition__ is defined in the baseclass header
    // INITIAL is always 0.
    // Each entry defines the row to transit to if the column's
    // character range was sensed. Row numbers are relative to the
    // used DFA and d_dfaBase__ is set to the first row of the subset to use.
    // The row's final two values are begin and end indices in
    // s_rfc__[] (rule, flags and count), defining the state's rule details
int const ScannerBase::s_dfa__[][45] =
{
    // INITIAL
    {-1, 1, 2, 2, 1, 2, 2, 2, 2, 3, 2, 4, 2, 5, 5, 5, 2, 5, 2, 6,
          5, 7, 8, 9, 5,10, 5, 5, 5,11, 5, 5, 5,12, 5,13,14,15, 5, 5,
          5, 2,-1,   0, 0},  // 0
    {-1, 1,-1,-1, 1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,   0, 1},  // 1
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,   1, 2},  // 2
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,   2, 3},  // 3
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,17,-1, 4,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,   3, 4},  // 4
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,   4, 5},  // 5
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
         18,19, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,20,21, 5, 5,
          5,-1,-1,   5, 6},  // 6
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,22, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,   6, 7},  // 7
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5,23, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,   7, 8},  // 8
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,24,
          5,-1,-1,   8, 9},  // 9
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,25, 5, 5, 5, 5,
          5,-1,-1,   9,10},  // 10
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,26, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  10,11},  // 11
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5,27, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  11,12},  // 12
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1,28,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  12,13},  // 13
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5,29, 5, 5, 5, 5, 5, 5,30, 5, 5, 5, 5, 5,
          5,-1,-1,  13,14},  // 14
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1,31,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  14,15},  // 15
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,16,-1,-1,32,-1,-1,-1,-1,-1,
         -1,-1,-1,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,  15,16},  // 16
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,-1,-1,34,-1,-1,-1,-1,-1,
         -1,-1,-1,34,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,  16,17},  // 17
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,35, 5, 5, 5,
          5,-1,-1,  17,18},  // 18
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,36, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  18,19},  // 19
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5,37, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  19,20},  // 20
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1,38,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  20,21},  // 21
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,39, 5, 5, 5,
          5,-1,-1,  21,22},  // 22
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5,40, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  22,23},  // 23
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,41, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  23,24},  // 24
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1,42,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  24,25},  // 25
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  25,26},  // 26
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  26,27},  // 27
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5,43, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  27,28},  // 28
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,44, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  28,29},  // 29
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,45, 5, 5, 5, 5,
          5,-1,-1,  29,30},  // 30
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,46, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  30,31},  // 31
    {-1,-1,-1,-1,-1,-1,47,-1,47,-1,-1,48,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,  31,31},  // 32
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,-1,-1,49,-1,-1,-1,-1,-1,
         -1,-1,-1,49,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,  31,32},  // 33
    {-1,-1,-1,-1,-1,-1,50,-1,50,-1,-1,51,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,  32,32},  // 34
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  32,33},  // 35
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,52, 5, 5, 5,
          5,-1,-1,  33,34},  // 36
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,53, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  34,35},  // 37
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,54, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  35,36},  // 38
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  36,37},  // 39
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  37,38},  // 40
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  38,39},  // 41
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5,55, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  39,40},  // 42
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  40,41},  // 43
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  41,42},  // 44
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,56, 5, 5,
          5,-1,-1,  42,43},  // 45
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  43,44},  // 46
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,  44,44},  // 47
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,  44,45},  // 48
    {-1,-1,-1,-1,-1,-1,57,-1,57,-1,-1,58,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,  45,45},  // 49
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,51,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,  45,45},  // 50
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,51,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,  45,46},  // 51
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  46,47},  // 52
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  47,48},  // 53
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  48,49},  // 54
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  49,50},  // 55
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5,-1, 5, 5, 5,-1, 5,-1, 5,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          5,-1,-1,  50,51},  // 56
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,58,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,  51,51},  // 57
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,58,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
         -1,-1,-1,  51,52},  // 58
};

    // The first value is the rule index
    // The second value is the FLAG: see the scannerbase.h file
    // 1: Final     4: Count        11: Final/BOL,Inc     
    // 2: Inc.      5: Final,Count  13: Final/BOL,Count
    // 3: Final,Inc 9: Final/BOL    
    // The third value is the LOP count value (valid for Count flags)
size_t const ScannerBase::s_rfc__[][3] =
{
//     R  F  C
     { 0, 1, 0},  // 0
     {20, 1, 0},  // 1
     {20, 1, 0},  // 2
     {16, 1, 0},  // 3
     {19, 1, 0},  // 4
     {19, 1, 0},  // 5
     {19, 1, 0},  // 6
     {19, 1, 0},  // 7
     { 1, 1, 0},  // 8
     {19, 1, 0},  // 9
     {19, 1, 0},  // 10
     {19, 1, 0},  // 11
     {19, 1, 0},  // 12
     {19, 1, 0},  // 13
     {19, 1, 0},  // 14
     {18, 1, 0},  // 15
     {17, 1, 0},  // 16
     {19, 1, 0},  // 17
     {19, 1, 0},  // 18
     {19, 1, 0},  // 19
     {19, 1, 0},  // 20
     {19, 1, 0},  // 21
     {19, 1, 0},  // 22
     {19, 1, 0},  // 23
     {19, 1, 0},  // 24
     { 4, 1, 0},  // 25
     { 2, 1, 0},  // 26
     {19, 1, 0},  // 27
     {19, 1, 0},  // 28
     {19, 1, 0},  // 29
     {19, 1, 0},  // 30
     {17, 1, 0},  // 31
     {12, 1, 0},  // 32
     {19, 1, 0},  // 33
     {19, 1, 0},  // 34
     {19, 1, 0},  // 35
     { 6, 1, 0},  // 36
     {14, 1, 0},  // 37
     { 3, 1, 0},  // 38
     {19, 1, 0},  // 39
     {13, 1, 0},  // 40
     { 5, 1, 0},  // 41
     {19, 1, 0},  // 42
     { 7, 1, 0},  // 43
     {18, 1, 0},  // 44
     {17, 1, 0},  // 45
     { 9, 1, 0},  // 46
     { 8, 1, 0},  // 47
     {10, 1, 0},  // 48
     {15, 1, 0},  // 49
     {11, 1, 0},  // 50
     {17, 1, 0},  // 51
};

int const (*ScannerBase::s_dfaBase__[])[45] =
{
    s_dfa__ + 0,
};

size_t ScannerBase::s_istreamNr = 0;

// $insert inputImplementation
ScannerBase::Input::Input()
:
    d_in(0),
    d_lineNr(1)
{}

ScannerBase::Input::Input(std::istream *iStream, size_t lineNr)
:
    d_in(iStream),
    d_lineNr(lineNr)
{}

size_t ScannerBase::Input::get()
{
    switch (size_t ch = next())         // get the next input char
    {
        case '\n':
            ++d_lineNr;
        // FALLING THROUGH

        default:
        return ch;
    }
}

size_t ScannerBase::Input::next()
{
    size_t ch;

    if (d_deque.empty())                    // deque empty: next char fm d_in
    {
        if (d_in == 0)
            return AT_EOF;
        ch = d_in->get();
        return *d_in ? ch : static_cast<size_t>(AT_EOF);
    }

    ch = d_deque.front();
    d_deque.pop_front();

    return ch;
}

void ScannerBase::Input::reRead(size_t ch)
{
    if (ch < 0x100)
    {
        if (ch == '\n')
            --d_lineNr;
        d_deque.push_front(ch);
    }
}

void ScannerBase::Input::reRead(std::string const &str, size_t fm)
{
    for (size_t idx = str.size(); idx-- > fm; )
        reRead(str[idx]);
}

ScannerBase::ScannerBase(std::istream &in, std::ostream &out)
:
    d_filename("-"),
    d_startCondition(StartCondition__::INITIAL),
    d_state(0),
    d_out(new std::ostream(out.rdbuf())),
    d_sawEOF(false),
    d_atBOL(true),
    d_tailCount(21, std::numeric_limits<size_t>::max()),
// $insert interactiveInit
    d_in(&in),
    d_line(new std::istringstream()),
    d_input(new std::istream(d_line->rdbuf())),
    d_dfaBase__(s_dfa__)
{}

void ScannerBase::switchStream__(std::istream &in, size_t lineNr)
{
    d_input.close();
    d_state = 0;
    d_input = Input(new std::istream(in.rdbuf()), lineNr);
    d_sawEOF = false;
    d_atBOL = true;
}


void ScannerBase::switchOstream(std::ostream &out)
{
    *d_out << std::flush;
    d_out.reset(new std::ostream(out.rdbuf()));
}

// $insert debugFunctions
void ScannerBase::setDebug(bool onOff)
{}

bool ScannerBase::debug() const
{
    return false;
}

void ScannerBase::redo(size_t nChars)
{
    size_t from = nChars >= length() ? 0 : length() - nChars;
    d_input.reRead(d_matched, from);
    d_matched.resize(from);
}

void ScannerBase::switchOstream(std::string const &outfilename)
{
    *d_out << std::flush;
    d_out.reset(
            outfilename == "-"    ? new std::ostream(std::cout.rdbuf()) :
            outfilename == ""     ? new std::ostream(std::cerr.rdbuf()) :
                                    new std::ofstream(outfilename));
}


void ScannerBase::p_pushStream(std::string const &name, std::istream *streamPtr)
{
    if (d_streamStack.size() == s_maxSizeofStreamStack__)
    {
        delete streamPtr;
        throw std::length_error("Max stream stack size exceeded");
    }

    d_streamStack.push_back(StreamStruct{d_filename, d_input});
    d_filename = name;
    d_input = Input(streamPtr);
    d_sawEOF = false;
    d_atBOL = true;
}


bool ScannerBase::popStream()
{
    d_input.close();

    if (d_streamStack.empty())
        return false;

    StreamStruct &top = d_streamStack.back();

    d_input =   top.pushedInput;
    d_filename = top.pushedName;
    d_streamStack.pop_back();
    d_sawEOF = false;

    return true;
}

ScannerBase::ActionType__ ScannerBase::actionType__(size_t range)
{
    d_nextState = d_dfaBase__[d_state][range];

    if (d_nextState != -1)                  // transition is possible
        return ActionType__::CONTINUE;

    if (atFinalState())                     // FINAL state reached
        return ActionType__::MATCH;

    if (d_matched.size())
        return ActionType__::ECHO_FIRST;    // no match, echo the 1st char

    return range != s_rangeOfEOF__ ? 
                ActionType__::ECHO_CH 
            : 
                ActionType__::RETURN;
}

void ScannerBase::accept(size_t nChars)          // old name: less
{
    if (nChars < d_matched.size())
    {
        d_input.reRead(d_matched, nChars);
        d_matched.resize(nChars);
    }
}

  // The size of d_matched is determined:
  //    The current state is a known final state (as determined by 
  // inspectRFCs__(), just prior to calling matched__). 
  //    The contents of d_matched are reduced to d_final's size or (if set)
  // to the LOP-rule's tail size.
void ScannerBase::determineMatchedSize(FinData const &final)
{
    size_t length = final.matchLen;
    if (final.tailCount != std::numeric_limits<size_t>::max())
        length -= final.tailCount;

    d_input.reRead(d_matched, length);      // reread the tail section
    d_matched.resize(length);               // return what's left
}

  // At this point a rule has been matched.  The next character is not part of
  // the matched rule and is sent back to the input.  The final match length
  // is determined, the index of the matched rule is determined, and then
  // d_atBOL is updated. Finally the rule index is returned.
size_t ScannerBase::matched__(size_t ch)
{
    d_input.reRead(ch);

    if (!d_atBOL)
        d_final.atBOL.rule = std::numeric_limits<size_t>::max();

    FinData &final = d_final.atBOL.rule == std::numeric_limits<size_t>::max() ? 
                            d_final.notAtBOL
                        :
                            d_final.atBOL;

    determineMatchedSize(final);

    d_atBOL = *d_matched.rbegin() == '\n';


    return final.rule;
}

size_t ScannerBase::getRange__(int ch)       // using int to prevent casts
{
    if (ch != AT_EOF)
        d_sawEOF = false;

    return ch == AT_EOF ? static_cast<size_t>(s_rangeOfEOF__) : s_ranges__[ch];
}

  // At this point d_nextState contains the next state and continuation is
  // possible. The just read char. is appended to d_match, and LOP counts
  // are updated.
void ScannerBase::continue__(int ch)
{
    d_state = d_nextState;

    if (ch != AT_EOF)
        d_matched += ch;
}

void ScannerBase::echoCh__(size_t ch)
{
    *d_out << static_cast<char>(ch);
    d_atBOL = ch == '\n';
}


   // At this point there is no continuation. The last character is
   // pushed back into the input stream as well as all but the first char. in
   // the buffer. The first char. in the buffer is echoed to stderr. 
   // If there isn't any 1st char yet then the current char doesn't fit any
   // rules and that char is then echoed
void ScannerBase::echoFirst__(size_t ch)
{
    d_input.reRead(ch);
    d_input.reRead(d_matched, 1);
    echoCh__(d_matched[0]);
}

    // Inspect all s_rfc__ elements associated with the current state
    //  If the s_rfc__ element has its COUNT flag set then set the 
    // d_tailCount[rule] value to the element's tailCount value, if it has its 
    // INCREMENT flag set then increment d_tailCount[rule]
    //  If neither was set set the d_tailCount[rule] to numeric_limits<size_t>::max()
    // 
    // If the s_rfc__ element has its FINAL flag set then store the rule number
    // in d_final.second. If it has its FINAL + BOL flags set then store the
    // rule number in d_final.first
void ScannerBase::inspectRFCs__()
{
    for 
    (
        size_t begin = d_dfaBase__[d_state][s_finacIdx__], 
                 end = d_dfaBase__[d_state][s_finacIdx__ + 1];
            begin != end;
                ++begin
    )
    {
        size_t const *rfc = s_rfc__[begin];
        size_t flag = rfc[FLAGS];
        size_t rule = rfc[RULE];

        if (flag & INCREMENT)
            ++d_tailCount[rule];
        else 
            d_tailCount[rule] = (flag & COUNT) ? rfc[ACCCOUNT] : std::numeric_limits<size_t>::max();

        if (flag & FINAL)
        {
            FinData &final = (flag & BOL) ? d_final.atBOL : d_final.notAtBOL;
            final = FinData { rule, d_matched.size(), d_tailCount[rule] };
        }
    }
}

void ScannerBase::reset__()
{
    d_final = Final { {std::numeric_limits<size_t>::max(), std::numeric_limits<size_t>::max(), std::numeric_limits<size_t>::max() }, 
                      {std::numeric_limits<size_t>::max(), std::numeric_limits<size_t>::max(), std::numeric_limits<size_t>::max() } };
    d_state = 0;
    d_return = true;

    if (!d_more)
        d_matched.clear();

    d_more = false;
}

int Scanner::executeAction__(size_t ruleIdx)
try
{
    switch (ruleIdx)
    {
        // $insert actions
        case 1:
        {
#line 12 "lexer"
            return Parser::E;

        }
        break;
        case 2:
        {
#line 14 "lexer"
            return Parser::PI;

        }
        break;
        case 3:
        {
#line 16 "lexer"
            return Parser::EXP;

        }
        break;
        case 4:
        {
#line 18 "lexer"
            return Parser::LN;

        }
        break;
        case 5:
        {
#line 20 "lexer"
            return Parser::SIN;

        }
        break;
        case 6:
        {
#line 22 "lexer"
            return Parser::COS;

        }
        break;
        case 7:
        {
#line 24 "lexer"
            return Parser::TAN;

        }
        break;
        case 8:
        {
#line 26 "lexer"
            return Parser::ASIN;

        }
        break;
        case 9:
        {
#line 28 "lexer"
            return Parser::ACOS;

        }
        break;
        case 10:
        {
#line 30 "lexer"
            return Parser::ATAN;

        }
        break;
        case 11:
        {
#line 32 "lexer"
            return Parser::SQRT;

        }
        break;
        case 12:
        {
#line 34 "lexer"
            return Parser::ABS;

        }
        break;
        case 13:
        {
#line 36 "lexer"
            return Parser::RAD;

        }
        break;
        case 14:
        {
#line 38 "lexer"
            return Parser::DEG;

        }
        break;
        case 15:
        {
#line 40 "lexer"
            return Parser::GRAD;

        }
        break;
        case 16:
        case 17:
        case 18:
        {
#line 44 "lexer"
            return Parser::NUMBER;

        }
        break;
        case 19:
        {
#line 46 "lexer"
            return Parser::IDENT;

        }
        break;
        case 20:
        {
#line 48 "lexer"
            return matched()[0];

        }
        break;
    }
    noReturn__();
    return 0;
}
catch (Leave__ value)
{
    return static_cast<int>(value);
}

int Scanner::lex__()
{
    reset__();
    preCode();

    while (true)
    {
        size_t ch = get__();                // fetch next char
        size_t range = getRange__(ch);      // determine the range

        inspectRFCs__();                    // update d_tailCount values

        switch (actionType__(range))        // determine the action
        {
            case ActionType__::CONTINUE:
                continue__(ch);
            continue;

            case ActionType__::MATCH:
            {
                d_token__ = executeAction__(matched__(ch));
                if (return__())
                {
                    print();
                    postCode(PostEnum__::RETURN);
                    return d_token__;
                }
                break;
            }

            case ActionType__::ECHO_FIRST:
                echoFirst__(ch);
            break;

            case ActionType__::ECHO_CH:
                echoCh__(ch);
            break;

            case ActionType__::RETURN:
                if (!popStream())
                {
                     postCode(PostEnum__::END);
                     return 0;
                }
                postCode(PostEnum__::POP);
             continue;
        } // switch

        postCode(PostEnum__::WIP);

        reset__();
        preCode();
    } // while
}

void ScannerBase::print__() const
{
}

// $insert interactiveLex
bool ScannerBase::interactiveLine()
{
    std::string line;

    if (not std::getline(*d_in, line))
        return false;

    line += '\n';
    d_line->clear();
    d_line->str(line);
    switchStream__(*d_line, lineNr());

    return true;
}

int Scanner::lex()
{
    return lex__() != 0        ? d_token__ :
           interactiveLine() ?   lex__()   :
                                 0;
}

