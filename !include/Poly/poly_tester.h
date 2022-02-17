#ifndef POLY_TESTER_H
#define POLY_TESTER_H

#include "poly.h"

void test_add(const Poly& p, const Poly& q);
// tester for addition, with verify
void test_sub(const Poly& p, const Poly& q);
// tester for subtraction, with verify
void test_mul(const Poly& p, const Poly& q);
// tester for multiplication, with verify
void test_div(const Poly& p, const Poly& q);
// tester for division, with verify
void test_all(const Poly& p, const Poly& q);
//tester to do all four math operation: addition, subtraction,
//multiplication, and division
void menu();
//menus with option
void demo();
//the whole procedure of the polynomial, do math operation, and ask user to
//change polynomial.

#endif // POLY_TESTER_H
