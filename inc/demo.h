#ifndef _DEMO_H
#define _DEMO_H

#include "con.h"
#include "function.h"
#include "stack.h"
#include "chapter5.h"

/** chapter 4 **/
void is_elem_test_demo();
void stack_test_demo(vector<int> &ve );
void Triangular_test_demo();
void Matrix_test_demo();
void iterator_class_test_demo();
int function_object_test_demo( const vector<int> &, int );
void print_less_than( const vector<int> &vec, int comp, ostream &os = cout );
void overload_iostream_test_demo();

/** chapter 5 **/
void three_tier_class_test_demo();
void num_sequence_test_demo();

#endif