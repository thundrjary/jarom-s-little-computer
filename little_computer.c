#include <stdio.h>
#include <stdlib.h>
#include "outputs.c"

// main
int main(void) {
	int a[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
	int b[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
	int c[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
	int d[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
	int e[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
	int f[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
	int g[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
	int h[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
	int s[4] = {0,0,0,0};
	int bank = 1;
	int * bank_pointer = &bank;
	int * current_inputs = a;

	int out_a,out_b,out_c,out_d,out_e,out_f,out_g,out_h,
	    out_i,out_j,out_k,out_l,out_m,out_n,out_o,out_p;

    	while (1) {
		system("clear");
		printf(" \\\\ jarom's little computer\n");
		printf("	'q' to quit\n\n");

		printf("1:");
		for (int i = 0; i < 16; i++) {
			printf("%i",a[i]);
		}
		printf("	");
		printf("5:");
		for (int i = 0; i < 16; i++) {
			printf("%i",e[i]);
		}
		printf("\n");


		printf("2:");
		for (int i = 0; i < 16; i++) {
			printf("%i",b[i]);
		}
		printf("	");
		printf("6:");
		for (int i = 0; i < 16; i++) {
			printf("%i",f[i]);
		}
		printf("\n");

		printf("3:");
		for (int i = 0; i < 16; i++) {
			printf("%i",c[i]);
		}
		printf("	");
		printf("7:");
		for (int i = 0; i < 16; i++) {
			printf("%i",g[i]);
		}
		printf("\n");

		printf("4:");
		for (int i = 0; i < 16; i++) {
			printf("%i",d[i]);
		}
		printf("	");
		printf("8:");
		for (int i = 0; i < 16; i++) {
			printf("%i",h[i]);
		}
		printf("\n");




		// display input indicators
		format_input(current_inputs, bank_pointer);
		format_switches(s);

		// display ouputs
		//nand_output(a);
		//not_output(a);
		//and_output(a);
		//or_output(a);
		//xor_output(a);
		//mux_output(a,s);
		//dmux_output(a,s);
		not16_output(a);
		and16_output(a,b);
		or16_output(a,b);
		mux4_output(a,s);
		mux16_output(a,b,s);
		or8way_output(a);
		dmux4way_output(a,s);
		dmux8way_output(a,s);
		dmux16way_output(a,s);
		mux4way16_output(a,b,c,d,s);
		mux8way16_output(a,b,c,d,e,f,g,h,s);

		// key mapping
		system("/bin/stty raw");
		char key_input = getchar();
		system("/bin/stty cooked");

		if (key_input == '/') {
			current_inputs[0] = !(current_inputs[0]);
		}
		else if (key_input == '.') {
			current_inputs[1] = !(current_inputs[1]);
		}
		else if (key_input == ',') {
			current_inputs[2] = !(current_inputs[2]);
		}
		else if (key_input == 'm') {
			current_inputs[3] = !(current_inputs[3]);
		}
		else if (key_input == ';') {
			current_inputs[4] = !(current_inputs[4]);
		}
		else if (key_input == 'l') {
			current_inputs[5] = !(current_inputs[5]);
		}
		else if (key_input == 'k') {
			current_inputs[6] = !(current_inputs[6]);
		}
		else if (key_input == 'j') {
			current_inputs[7] = !(current_inputs[7]);
		}
		else if (key_input == 'p') {
			current_inputs[8] = !(current_inputs[8]);
		}
		else if (key_input == 'o') {
			current_inputs[9] = !(current_inputs[9]);
		}
		else if (key_input == 'i') {
			current_inputs[10] = !(current_inputs[10]);
		}
		else if (key_input == 'u') {
			current_inputs[11] = !(current_inputs[11]);
		}
		else if (key_input == '0') {
			current_inputs[12] = !(current_inputs[12]);
		}
		else if (key_input == '9') {
			current_inputs[13] = !(current_inputs[13]);
		}
		else if (key_input == '8') {
			current_inputs[14] = !(current_inputs[14]);
		}
		else if (key_input == '7') {
			current_inputs[15] = !(current_inputs[15]);
		}

		// input banks
		else if (key_input == '!') {
			bank = 1;	
			current_inputs = a;
		}
		else if (key_input == '@') {
			bank = 2;	
			current_inputs = b;
		}
		else if (key_input == '#') {
			bank = 3;	
			current_inputs = c;
		}
		else if (key_input == '$') {
			bank = 4;	
			current_inputs = d;
		}
		else if (key_input == '%') {
			bank = 5;	
			current_inputs = e;
		}
		else if (key_input == '^') {
			bank = 6;	
			current_inputs = f;
		}
		else if (key_input == '&') {
			bank = 7;	
			current_inputs = g;
		}
		else if (key_input == '*') {
			bank = 8;	
			current_inputs = h;
		}

		// switch inputs
		else if (key_input == 'v') {
			s[0] = !(s[0]);
		}
		else if (key_input == 'c') {
			s[1] = !(s[1]);
		}
		else if (key_input == 'x') {
			s[2] = !(s[2]);
		}
		else if (key_input == 'z') {
			s[3] = !(s[3]);
		}
		else if (key_input == 'q') {
			break;
		}
	}
	return EXIT_SUCCESS; 
}
