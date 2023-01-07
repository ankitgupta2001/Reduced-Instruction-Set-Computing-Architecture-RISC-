#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "cpu.h"
using namespace std;

void print_list(i64 *lst, int size) {
	for (int i = 0; i < size - 1; i++) {
		printf("%llu,", lst[i]);
	}
	printf("%llu\n", lst[size-1]);
}

void print_registers(cpu *c) {
	for (int i = 0; i < 7; i++) {
		printf("%llu,", c->r[i]);
	}
	printf("%llu\n", c->r[7]);
}

int main() {
	i64 n;
	printf("Program to Find the factorial of number\n");
	printf("Enter the value of number\n");
	cin >> n;
	i64 b[] = {
		LII, R0, 1,
		LII, R1, n,
		LII, R2, 1,
		MUL, R0, R1,
		SUB, R1, R2,
		CMP, R1, R2,
		JNZ, 8,
		HLT
	};
	printf("instructions:\n");
	print_list(b, 21);

	// create new cpu with the given i64 array for memory
	cpu *c = new_cpu(b, 21);
	run_cpu(c);
	
	printf("Number of instruction exeuted = %llu\n", n+5);
	printf("registers:\n");
	print_registers(c);

	printf("Result = %llu", c->r[0]);
	return 0;
}
