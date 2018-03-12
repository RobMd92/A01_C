
//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#include "pal.h"

//--------------------------------------------------
// gen_num
//--------------------------------------------------
int gen_num(int lb, int ub) {
	//1. We create the output variable with an initial value.
	int res = 0;

	//2. We assign num to a random value in the desired range
	res = (rand() % (ub - lb)) + lb;

	//3. We return the output variable
	return res;
}

//--------------------------------------------------
// my_getchar
//--------------------------------------------------
char my_get_char() {
	//1. We create the output variable with the value the user has input by keyboard
	char res = getchar();

	//2. We discard any extra character the user has input by keyboard
	boolean finish = False;
	char dummy_char = ' ';

	while (finish == False) {
		dummy_char = getchar();
		if (dummy_char == '\n')
			finish = True;
	}

	//3. We return the output variable
	return res;
}

//--------------------------------------------------
// initialise_array
//--------------------------------------------------
void initialise_array(int a[6], int num) {
	for (int i = 0; i <6 ; ++i) {
		a[5-i]= num %10;

	};
	num /=10;

	is_pal(a);

}

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int a[6]) {
    boolean b = True;

    for(int i=0;i<6;++i){
        if (a[5-i]==a[i]){
            b=True;
        }
    }
    b=False;


    return b;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command() {
    char res = ' ';
    printf("Please enter a cmd W S A D ");
    res=my_get_char();

    return res;
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int a[6], int** p_p, int* p_nm, char c){
    ask_for_command();
    c = my_get_char();
    if (c =='w') {
        **p_p = **p_p + 1;
        *p_nm = *p_nm + 1;
    }

    if (c =='s') {
        **p_p = **p_p - 1;
        *p_nm = *p_nm + 1;
    }

    if (c =='a') {
        *p_p = *p_p - 1;
        *p_nm = *p_nm + 1;

    }

    if (c =='d') {
        *p_p = *p_p + 1;
        *p_nm = *p_nm + 1;

    } else {


    }

}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int a[6], int* p, int nm) {

    printf("%d\n",&a);

}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num) {
    int a[6];
    int *p = &a[0];
    int nm=0;
    initialise_array(a, pal_num);

}

