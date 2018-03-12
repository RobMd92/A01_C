//Robert Morgan
//R00132949
//SD2-B

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
//using a for loop to go through the array
void initialise_array(int a[6], int num) {

    for (int i = 5; i >= 0 ; i--) {
        a[i]= num %10;
        num /=10;
    }
}

//--------------------------------------------------
// is_pal
//--------------------------------------------------
//using a loop to go through the filled array and compare the first to last and so on as it increments
// if the count reaches 6 then it returns true and it is a palindrome
//else it returns false
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
//using the my_get_char method to equal res, then use validation to make sure it is our desired cmd
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
// using pointer p i can increment or decrement by one depending on the cmd
//also increment number of moves by one for every cmd
//
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
//minus the address of a[0] from the pointer address to get the amount spaces
//use a for loop to print the numbers of the array
//use a loop to print the number of spaces for each cmd
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
    //declare variables
    int a[6];
    char c = ' ';
    int *p = &a[0];
    int **p_p = &p;
    int nm = 0;
    int *p_nm = &nm;

    //call the method to fill the array with pal num
    initialise_array(a, pal_num);

    while(is_pal(a)!=True) {
        print_status(a, p, nm);


        c = ask_for_command();


        process_movement(a, p_p, p_nm, c);
    }
    printf("solved");

}

