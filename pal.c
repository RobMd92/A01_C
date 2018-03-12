
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

    for (int i = 5; i >= 0 ; i--) {
        a[i]= num %10;
        num /=10;
    }
}

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int a[6]) {
    boolean b;// = True;
    int count=0;

    for(int i=0;i<6;++i){
        if (a[5-i]==a[i]){
            count++;
            if (count==6){
                b=True;
            }

        } else {
            b=False;
        }
    }

    return b;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command() {
    char res = ' ';

    res=my_get_char();
    if (res=='w'){
        return res;
    }
    if (res=='a'){
        return res;
    }
    if (res=='x'){
        return res;
    }
    if (res=='d'){
        return res;
    }

    printf("NEW MOVEMENT: Enter a valid command by keyword:\n");
    printf("Valid commands: a       d       w       x \n");

}

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int a[6], int** p_p, int* p_nm, char c){


    if (c =='w') {
        **p_p = **p_p + 1;
        *p_nm = *p_nm + 1;
    }

    if (c =='x') {
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

    }

}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int a[6], int* p, int nm) {

    int space = p-&a[0];

    printf("------ Game Status -------\n");
    printf("Number = ");
    printf("{");

    int i;
    for (i = 0; i < 6; i++) {
        printf("%d", a[i]);
    }
    printf("}\n");


    for (int j = 0; j < space; j++) {
        printf(" ");
    }
    printf("          ");
    printf("^\n");
    printf("Num mov = ");
    printf("%d\n",nm);
    printf("--------------------------\n");
    printf("NEW MOVEMENT: Enter a valid command by keyword:\n");
    printf("Valid commands: a       d       w       x \n");

}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num) {
    int a[6];
    char c = ' ';
    int *p = &a[0];
    int **p_p = &p;
    int nm = 0;
    int *p_nm = &nm;

    initialise_array(a, pal_num);

    while(is_pal(a)!=True) {
        print_status(a, p, nm);


        c = ask_for_command();


        process_movement(a, p_p, p_nm, c);
    }
    printf("solved");

}

