#ifndef TESTS_H
#define TESTS_H

#include "Graphs.h"

void Gen_Chord_test(int);
void isChord_test(int);

void IndSet_test(Graph&);
void IndSetChord_test(Graph&);
void IndSetChord_simplvert_test(Graph&);
void IndependentSet_AllAgorithms_test(int n);

void ColoringGeneral_forChord_test(int);
void ColoringChord_test(int);
void ColoringGeneral_forRandomGenGraph_test(int);
int ColoringGeneral_and_ColoringChord_forRandomChordGraph_test(int);

int ArrangeChordNumInd(int n);
int NumIndGeneal(int n);

int NumIndGenealAndChord(int n);

int ColorChordNum(int n);
int ColorGeneralNum(int n);

void ChordIndNumAll(int n);




#endif