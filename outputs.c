#include "hardware.c"

// formatting

const char * off() {
	return "\033[2;90m●\033[0m";
}
const char * on() {
	return "\033[1;36m◯\033[0m";
}

int format_input(int * s, int * bank) {
	// row takes a 0 for a, 1 for b
	//
	int key_color = 90;
	int bank_select_color = 32;

	printf("┌─────────────────────────────────────────────────────────────────────┐\n");
	printf("│ input banks (hold shift to change)                                  │\n");
	if (*bank == 1) {
		printf("│ \033[1;%dm1\033[0m 2 3 4 5 6 7 8						      │\n", bank_select_color);
	}
	else if (*bank == 2) {
		printf("│ 1 \033[1;%dm2\033[0m 3 4 5 6 7 8						      │\n", bank_select_color);
	}
	else if (*bank == 3) {
		printf("│ 1 2 \033[1;%dm3\033[0m 4 5 6 7 8						      │\n", bank_select_color);
	}
	else if (*bank == 4) {
		printf("│ 1 2 3 \033[1;%dm4\033[0m 5 6 7 8						      │\n", bank_select_color);
	}
	else if (*bank == 5) {
		printf("│ 1 2 3 4 \033[1;%dm5\033[0m 6 7 8						      │\n", bank_select_color);
	}
	else if (*bank == 6) {
		printf("│ 1 2 3 4 5 \033[1;%dm6\033[0m 7 8						      │\n", bank_select_color);
	}
	else if (*bank == 7) {
		printf("│ 1 2 3 4 5 6 \033[1;%dm7\033[0m 8 						      │\n", bank_select_color);
	}
	else if (*bank == 8) {
		printf("│ 1 2 3 4 5 6 7 \033[1;%dm8\033[0m    		  				      │\n", bank_select_color);
	}
	printf("│                                                                     │\n");
	printf("│ 		\033[1;%dm7  8  9  0   u  i  o  p   j  k  l  ;   m  ,  .  /\033[0m     │\n", key_color);
	printf("│         	15 14 13 12  11 10 09 08  07 06 05 04  03 02 01 00    │\n");
	printf("│ inputs:       %s  %s  %s  %s   %s  %s  %s  %s   %s  %s  %s  %s   %s  %s  %s  %s     │\n│								      │\n", 
		s[15] == 0 ? off() : on(), s[14] == 0 ? off() : on(), s[13] == 0 ? off() : on(), s[12] == 0 ? off() : on(), 
		s[11] == 0 ? off() : on(), s[10] == 0 ? off() : on(), s[9] == 0 ? off() : on(), s[8] == 0 ? off() : on(), 
		s[7] == 0 ? off() : on(), s[6] == 0 ? off() : on(), s[5] == 0 ? off() : on(), s[4] == 0 ? off() : on(), 
		s[3] == 0 ? off() : on(), s[2] == 0 ? off() : on(), s[1] == 0 ? off() : on(), s[0] == 0 ? off() : on());
	return 0;
}
int format_switches(int *s) {
	printf("│		\033[;90mz  x  c  v\033[0m					      │\n");
	printf("│            	s3 s2 s1 s0                                           │\n");
	printf("│ switches:  	%s  %s  %s  %s 				       	      │\n", 
		s[3] == 0 ? off () : on(), 
		s[2] == 0 ? off () : on(), 
		s[1] == 0 ? off () : on(), 
		s[0] == 0 ? off () : on());
	printf("│								      │\n");
	printf("└─────────────────────────────────────────────────────────────────────┘\n");
	return 0;
}

// output definitions

int nand_output(int * a) {
	printf("nand output (15,14): 	%s\n", 
		nand_gate(&a[15],&a[14]) == 0 ? off() : on());
	return 0;
}

int not_output(int * a) {
	printf("not output (15): 	%s\n", 
		not_gate(&a[15]) == 0 ? off() : on());
	return 0;
}

int and_output(int * a) {
	printf("and output (15,14):	%s\n", 
		and_gate(&a[15],&a[14]) == 0 ? off() : on());
	return 0;
}

int or_output(int * a) {
	printf("or output (15,14):	%s\n", 
		or_gate(&a[15],&a[14]) == 0 ? off() : on());
	return 0;
}

int xor_output(int * a) {
	printf("xor output (15,14):	%s\n", 
		xor_gate(&a[15],&a[14]) == 0 ? off() : on());
	return 0;
}

int mux_output(int * a, int * s) {
	printf("mux output: %p\n", &s[0]);
	printf("mux out	(15,14,s0):	%s\n", 
		mux_gate(&a[15],&a[14],&s[0]) == 0 ? off() : on());
	return 0;
}

int dmux_output(int * a, int * s) {

	int * out = dmux_gate(&a[15],&s[0]);
	printf("dmux out (15,14):	%s %s\n", 
		out[0] == 0 ? off() : on(),
		out[1] == 0 ? off() : on());
	return 0;
}

int not16_output(int * a) {
	int * not16_out = not16(a);
		
	printf("not16 output: 		%s %s %s %s  %s %s %s %s  %s %s %s %s  %s %s %s %s\n", 
		not16_out[15] == 0 ? off() : on(),
		not16_out[14] == 0 ? off() : on(),
		not16_out[13] == 0 ? off() : on(),
		not16_out[12] == 0 ? off() : on(),

		not16_out[11] == 0 ? off() : on(),
		not16_out[10] == 0 ? off() : on(),
		not16_out[9] == 0 ? off() : on(),
		not16_out[8] == 0 ? off() : on(),
				
		not16_out[7] == 0 ? off() : on(),
		not16_out[6] == 0 ? off() : on(),
		not16_out[5] == 0 ? off() : on(),
		not16_out[4] == 0 ? off() : on(),

		not16_out[3] == 0 ? off() : on(),
		not16_out[2] == 0 ? off() : on(),
		not16_out[1] == 0 ? off() : on(),
		not16_out[0] == 0 ? off() : on());
	return 0;
}

int and16_output(int * a, int * b) {
	int * and16_out = and16(a,b);
	printf("and16 output:		%s %s %s %s  %s %s %s %s  %s %s %s %s  %s %s %s %s\n", 
		and16_out[15] == 0 ? off() : on(),
		and16_out[14] == 0 ? off() : on(),
		and16_out[13] == 0 ? off() : on(),
		and16_out[12] == 0 ? off() : on(),

		and16_out[11] == 0 ? off() : on(),
		and16_out[10] == 0 ? off() : on(),
		and16_out[9] == 0 ? off() : on(),
		and16_out[8] == 0 ? off() : on(),

		and16_out[7] == 0 ? off() : on(),
		and16_out[6] == 0 ? off() : on(),
		and16_out[5] == 0 ? off() : on(),
		and16_out[4] == 0 ? off() : on(),

		and16_out[3] == 0 ? off() : on(),
		and16_out[2] == 0 ? off() : on(),
		and16_out[1] == 0 ? off() : on(),
		and16_out[0] == 0 ? off() : on());
	return 0;
}


int or16_output(int * a, int * b) {
	int * or16_out = or16(a,b);
	printf("or16 output:		%s %s %s %s  %s %s %s %s  %s %s %s %s  %s %s %s %s\n", 
		or16_out[15] == 0 ? off() : on(),
		or16_out[14] == 0 ? off() : on(),
		or16_out[13] == 0 ? off() : on(),
		or16_out[12] == 0 ? off() : on(),

		or16_out[11] == 0 ? off() : on(),
		or16_out[10] == 0 ? off() : on(),
		or16_out[9] == 0 ? off() : on(),
		or16_out[8] == 0 ? off() : on(),

		or16_out[7] == 0 ? off() : on(),
		or16_out[6] == 0 ? off() : on(),
		or16_out[5] == 0 ? off() : on(),
		or16_out[4] == 0 ? off() : on(),

		or16_out[3] == 0 ? off() : on(),
		or16_out[2] == 0 ? off() : on(),
		or16_out[1] == 0 ? off() : on(),
		or16_out[0] == 0 ? off() : on());
	return 0;
}

int lightgray = 94;


int mux4_output(int * a, int * s) {
	printf("mux4 (15-12;s):		%s\n", 
		mux4(&a[15], &a[14], &a[13], &a[12], &s[0], &s[1]) == 0 ? off() : on());
	return 0;
}


int mux16_output(int * a, int * b, int * s) {
	int * out = mux16(a,b,&s[0]);
	printf("mux16 (15-0;s0-3):	%s %s %s %s  %s %s %s %s  %s %s %s %s  %s %s %s %s\n", 
		out[15] == 0 ? off() : on(),
		out[14] == 0 ? off() : on(),
		out[13] == 0 ? off() : on(),
		out[12] == 0 ? off() : on(),
		out[11] == 0 ? off() : on(),
		out[10] == 0 ? off() : on(),
		out[9] == 0 ? off() : on(),
		out[8] == 0 ? off() : on(),
		out[7] == 0 ? off() : on(),
		out[6] == 0 ? off() : on(),
		out[5] == 0 ? off() : on(),
		out[4] == 0 ? off() : on(),
		out[3] == 0 ? off() : on(),
		out[2] == 0 ? off() : on(),
		out[1] == 0 ? off() : on(),
		out[0] == 0 ? off() : on());
	return 0;
}
int or8way_output(int * a) {
	printf("or8way output (15-8):	%s\n", 
		or8way(a) == 0 ? off() : on());
	return 0;
}

int dmux4way_output(int * a,int * s) {

	int * dmux4way_out = 
		dmux4way(a[15],s[0],s[1]);

	printf("dmux4way:		%s %s %s %s\n", 
		dmux4way_out[3] == 0 ? off() : on(),
		dmux4way_out[2] == 0 ? off() : on(),
		dmux4way_out[1] == 0 ? off() : on(),
		dmux4way_out[0] == 0 ? off() : on());

	return 0;
}

int dmux8way_output(int * a,int * s) {

	int * dmux8way_out = 
		dmux8way(a[15],s[0],s[1],s[2]);

	printf("dmux8way:		%s %s %s %s  %s %s %s %s\n", 
		dmux8way_out[7] == 0 ? off() : on(),
		dmux8way_out[6] == 0 ? off() : on(),
		dmux8way_out[5] == 0 ? off() : on(),
		dmux8way_out[4] == 0 ? off() : on(),
		dmux8way_out[3] == 0 ? off() : on(),
		dmux8way_out[2] == 0 ? off() : on(),
		dmux8way_out[1] == 0 ? off() : on(),
		dmux8way_out[0] == 0 ? off() : on());
	return 0;
}

int dmux16way_output(int * a,int * s) {

	int * dmux16way_out = 
		dmux16way(a[15],s[0],s[1],s[2],s[3]);

	printf("dmux16way:		%s %s %s %s  %s %s %s %s  %s %s %s %s  %s %s %s %s\n", 
		dmux16way_out[15] == 0 ? off() : on(),
		dmux16way_out[14] == 0 ? off() : on(),
		dmux16way_out[13] == 0 ? off() : on(),
		dmux16way_out[12] == 0 ? off() : on(),
		dmux16way_out[11] == 0 ? off() : on(),
		dmux16way_out[10] == 0 ? off() : on(),
		dmux16way_out[9] == 0 ? off() : on(),
		dmux16way_out[8] == 0 ? off() : on(),

		dmux16way_out[7] == 0 ? off() : on(),
		dmux16way_out[6] == 0 ? off() : on(),
		dmux16way_out[5] == 0 ? off() : on(),
		dmux16way_out[4] == 0 ? off() : on(),
		dmux16way_out[3] == 0 ? off() : on(),
		dmux16way_out[2] == 0 ? off() : on(),
		dmux16way_out[1] == 0 ? off() : on(),
		dmux16way_out[0] == 0 ? off() : on());
	return 0;
}

int mux4way16_output(int * a, int * b, int * c, int * d, int * s) {
	int * o = mux4way16(a,b,c,d,&s[0],&s[1]);
	printf("mux4way16:		%s %s %s %s  %s %s %s %s  %s %s %s %s  %s %s %s %s\n", 
		o[15] == 0 ? off() : on(),
		o[14] == 0 ? off() : on(),
		o[13] == 0 ? off() : on(),
		o[12] == 0 ? off() : on(),
		o[11] == 0 ? off() : on(),
		o[10] == 0 ? off() : on(),
		o[9] == 0 ? off() : on(),
		o[8] == 0 ? off() : on(),

		o[7] == 0 ? off() : on(),
		o[6] == 0 ? off() : on(),
		o[5] == 0 ? off() : on(),
		o[4] == 0 ? off() : on(),
		o[3] == 0 ? off() : on(),
		o[2] == 0 ? off() : on(),
		o[1] == 0 ? off() : on(),
		o[0] == 0 ? off() : on());
	return 0;
}

int mux8way16_output(int * a, int * b, int * c, int * d, int * e, int * f, int * g, int * h, int * s) {
	int * o = mux8way16(a,b,c,d,e,f,g,h,&s[0],&s[1],&s[2]);
	printf("mux8way16:		%s %s %s %s  %s %s %s %s  %s %s %s %s  %s %s %s %s\n", 
		o[15] == 0 ? off() : on(),
		o[14] == 0 ? off() : on(),
		o[13] == 0 ? off() : on(),
		o[12] == 0 ? off() : on(),
		o[11] == 0 ? off() : on(),
		o[10] == 0 ? off() : on(),
		o[9] == 0 ? off() : on(),
		o[8] == 0 ? off() : on(),

		o[7] == 0 ? off() : on(),
		o[6] == 0 ? off() : on(),
		o[5] == 0 ? off() : on(),
		o[4] == 0 ? off() : on(),
		o[3] == 0 ? off() : on(),
		o[2] == 0 ? off() : on(),
		o[1] == 0 ? off() : on(),
		o[0] == 0 ? off() : on());
	return 0;
}



