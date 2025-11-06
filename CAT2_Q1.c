/*Name:Peter kiarie mwaura
Reg:CT100/G/26128/25
 Description : Arrays   */
//Array-it is a fixed-size collection of similar data items stored in contagious memory location


/*int scores[2][2] = {
    {65, 92},
    {84, 72}
};

int scores2[2][2] = {
    {35, 70},
    {59, 67}
};
*/
#include <stdio.h>

int main() {
    int scores[2][2] = {
        {65, 92},
        {84, 72}
    };

    int i, j;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }

    return 0;
}
