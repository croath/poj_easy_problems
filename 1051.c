//
//  main.c
//  poj1051
//
//  Created by croath on 11/17/13.
//  Copyright (c) 2013 Croath. All rights reserved.
//

#include <stdio.h>

// '.'-> 0, '-'-> 1, blank -> 2
char dict[3][3][3][3];

void init_dict();

int main(int argc, const char * argv[]){
    init_dict();
    int n;
    scanf("%d", &n);
    int answer_count = n;
    getchar();
    while (n--) {
        int codes[400];
        int numbers[100];
        int codes_flag = 0;
        int numbers_flag = 0;
        char tmp;
        while ((tmp = getchar()) != '\n') {
            int i, j, k, l;
            int find_flag = 0;
            
            for (i = 0; i < 3; i ++) {
                for (j = 0; j < 3; j ++) {
                    for (k = 0; k < 3; k ++) {
                        for (l = 0; l < 3; l ++) {
                            if (dict[i][j][k][l] == tmp) {
                                find_flag = 1;
                                break;
                            }
                        }
                        if (find_flag == 1) {
                            break;
                        }
                    }
                    if (find_flag == 1) {
                        break;
                    }
                }
                if (find_flag == 1) {
                    break;
                }
            }
            
            if (find_flag) {
                int number = 1;
                codes[codes_flag] = i;
                codes_flag++;
                if (j != 2) {
                    codes[codes_flag] = j;
                    codes_flag++;
                    number ++;
                }
                if (k != 2) {
                    codes[codes_flag] = k;
                    codes_flag++;
                    number ++;
                }
                if (l != 2) {
                    codes[codes_flag] = l;
                    codes_flag++;
                    number ++;
                }
                numbers[numbers_flag] = number;
                numbers_flag ++;
            }
        }
        
        printf("%d: ", answer_count-n);
        
        int start = 0;
        for (int i = 0; i < numbers_flag; i ++) {
            int one = numbers[numbers_flag-1-i];
            int c[4] = {2, 2, 2, 2};
            
            for (int j = 0; j < one; j ++) {
                c[j] = codes[start + j];
            }
            char ch = dict[c[0]][c[1]][c[2]][c[3]];
            putchar(ch);
            start += one;
        }
        
        putchar('\n');
    }
    return 0;
}

void init_dict(){
    dict[0][1][2][2] = 'A';
    dict[1][0][0][0] = 'B';
    dict[1][0][1][0] = 'C';
    dict[1][0][0][2] = 'D';
    dict[0][2][2][2] = 'E';
    dict[0][0][1][0] = 'F';
    dict[1][1][0][2] = 'G';
    dict[0][0][0][0] = 'H';
    dict[0][0][2][2] = 'I';
    dict[0][1][1][1] = 'J';
    dict[1][0][1][2] = 'K';
    dict[0][1][0][0] = 'L';
    dict[1][1][2][2] = 'M';
    dict[1][0][2][2] = 'N';
    dict[1][1][1][2] = 'O';
    dict[0][1][1][0] = 'P';
    dict[1][1][0][1] = 'Q';
    dict[0][1][0][2] = 'R';
    dict[0][0][0][2] = 'S';
    dict[1][2][2][2] = 'T';
    dict[0][0][1][2] = 'U';
    dict[0][0][0][1] = 'V';
    dict[0][1][1][2] = 'W';
    dict[1][0][0][1] = 'X';
    dict[1][0][1][1] = 'Y';
    dict[1][1][0][0] = 'Z';
    dict[0][0][1][1] = '_';
    dict[1][1][1][0] = '.';
    dict[0][1][0][1] = ',';
    dict[1][1][1][1] = '?';
}