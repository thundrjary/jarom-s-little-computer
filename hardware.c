#include <stdio.h>
#include <stdlib.h>

int nand_gate(int * a,int * b) {
	return !(*a && *b);
}

int not_gate(int * a) {
	return !*a; 
}

int and_gate(int * a, int * b) {
	return *a && *b;
}

int or_gate(int * a, int * b) {
	return *a || *b;
}

int xor_gate(int * a, int *b) {
	int v = *a || *b;
	int w = nand_gate(&*a,&*b);
	int out = v && w; 
	return out;
}

int mux_gate(int * a, int * b, int * s) {
	//printf("mux16: %p\n", s);

	/*
	printf("within mux_gate, *s is %s", *s == 1 ? "high" : "low");
	printf("within mux_gate, s[1] is %s", s[1] == 1 ? "high" : "low");
	printf("\n");
	*/

	//printf("mux_gate: %p\n", s);
	int x = *s && *b;
	int y = !*s && *a;
	int out = x || y;
	return out;
}

void * dmux_gate(int * a, int * s) {
	static int out[2];
	int v = nand_gate(&*s, &*s);
	int w = nand_gate(&*a, &v);
	int x = nand_gate(&*a, &*s);
	int y = nand_gate(&x, &x);
	int z = nand_gate(&w, &w);

	out[0] = z;
	out[1] = y;
	return out;
}

int * not16(int * a) {

	static int out[16];

	for(int i = 0; i < 16; i++) {
		out[i] = !a[i];
	}

	return out;
}

int * and16(int * a, int * b) {
	static int out[16];
	for (int i = 0; i < 16; i++) {
		out[i] = a[i] && b[i];
	}

	return out;
}

int * or16(int * a, int * b) {
	static int out[16];
	for (int i = 0; i < 16; i++) {
		out[i] = a[i] || b[i];
	}
	return out;
}

int or8way(int *i) {

	return i[15] || i[14] || i[13] || i[12] || i[11] || i[10] || i[9] || i[8];
}

int mux4(int * a, int * b, int * c, int * d, int * s0, int * s1) {
	// a = 00
	// b = 01
	// c = 10
	// d = 11

	int v = d && s1 && s0;
	int w = c && s1 && !s0;
	int x = b && !s1 && s0;
	int y = a && !s1 && !s0;
	int z = y || x || w || v;
	int out = z;
	return out;
}

int * mux16(int * a, int * b, int * s) {
	/*
	printf("mux16: %p\n", s);
	printf("within mux16, s is %s", *s == 1 ? "high" : "low");
	printf("\n");
	*/

	int out[16];
	for (int i = 0; i < 16; i++) {
		out[i] = mux_gate(&a[i],&b[i],s);
	}
	/*
	printf("output of mux16: ");
	for (int i = 0; i < 16; i++) {
		printf("%i",out[i]);
	}
	printf("\n");
	*/

	return out;
}

int * dmux4way(a,s0,s1) {
	static int out[4];

	out[3] = a && !s1 && !s0;
	out[2] = a && !s1 && s0;
	out[1] = a && s1 && !s0;
	out[0] = a && s1 && s0;
	
	return out;
}

int * dmux8way(a,s0,s1,s2) {
	static int out[8];

	out[7] = a && !s2 && !s1 && !s0;
	out[6] = a && !s2 && !s1 && s0;
	out[5] = a && !s2 && s1 && !s0;
	out[4] = a && !s2 && s1 && s0;
	out[3] = a && s2 && !s1 && !s0;
	out[2] = a && s2 && !s1 && s0;
	out[1] = a && s2 && s1 && !s0;
	out[0] = a && s2 && s1 && s0;

	return out;
}

int * dmux16way(a,s0,s1,s2,s3) {
	static int out[16];
	out[15] = a && !s3 && !s2 && !s1 && !s0;
	out[14] = a && !s3 && !s2 && !s1 && s0;
	out[13] = a && !s3 && !s2 && s1 && !s0;
	out[12] = a && !s3 && !s2 && s1 && s0;
	out[11] = a && !s3 && s2 && !s1 && !s0;
	out[10] = a && !s3 && s2 && !s1 && s0;
	out[9] = a && !s3 && s2 && s1 && !s0;
	out[8] = a && !s3 && s2 && s1 && s0;

	out[7] = a && s3 && !s2 && !s1 && !s0;
	out[6] = a && s3 && !s2 && !s1 && s0;
	out[5] = a && s3 && !s2 && s1 && !s0;
	out[4] = a && s3 && !s2 && s1 && s0;
	out[3] = a && s3 && s2 && !s1 && !s0;
	out[2] = a && s3 && s2 && !s1 && s0;
	out[1] = a && s3 && s2 && s1 && !s0;
	out[0] = a && s3 && s2 && s1 && s0;

	return out;
}
int * mux4way16 (int * a, int * b, int * c, int * d, int * s0, int * s1) {

	static int out[16];	
	static int left[16];
	static int right[16];

	for (int i = 0; i < 16; i++) {
		left[i] = mux_gate(&a[i],&b[i],s0);
	}
	for (int i = 0; i < 16; i++) {
		right[i] = mux_gate(&c[i],&d[i],s0);
	}
	for (int i = 0; i < 16; i++) {
		out[i] = mux_gate(&left[i],&right[i],s1);
	}
		
	return out;
}


int * mux8way16(int * a, int * b, int * c, int * d, int * e, int * f, int * g, int * h, int * s0, int * s1, int * s2) {

	static int out[16];
	static int left[16];
	static int right[16];
	int * reg;

	reg = mux4way16(a,b,c,d,s0,s1);
	for (int i = 0; i < 16; i++) { left[i] = reg[i]; }

	reg = mux4way16(e,f,g,h,s0,s1);
	for (int i = 0; i < 16; i++) { right[i] = reg[i]; }

	for (int i = 0; i < 16; i++ ) {
		out[i] = mux_gate(&left[i],&right[i],s2);
	}

	return out;
}
