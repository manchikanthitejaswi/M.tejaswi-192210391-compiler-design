#include <stdio.h>
#include <string.h>

int main() {
    char non, pro[10][10];
    int index = 3, i, num;
    printf("Enter Number of Productions: ");
    scanf("%d", &num);
    printf("Enter the grammar as S->abSc|abSa|bc:\n");
    for (i = 0; i < num; i++) {
        scanf("%s", pro[i]);
    }
    for (i = 0; i < num; i++) {
        printf("\nThe grammar :: %s", pro[i]);
        non = pro[i][0];
        if (pro[i][3] == non) {
            printf(" is left factoring.\n");
            printf("Grammar without left factoring:\n");
            int j;
            printf("%c -> ", non);
            for (j = 3; pro[i][j] != '|' && pro[i][j] != '\0'; j++) {
                printf("%c", pro[i][j]);
            }
            printf("%c'", non);
            printf("\n%c' -> ", non);
            while (pro[i][j] != '\0') {
                if (pro[i][j] == '|') {
                    j++;
                    printf("| ");
                }
                for (; pro[i][j] != '|' && pro[i][j] != '\0'; j++) {
                    if (pro[i][j] != non) {
                        printf("%c", pro[i][j]);
                    }
                }
                if (pro[i][j] != '\0') {
                    printf("%c' | ", non);
                }
            }
            printf("Epsilon\n");
        } else {
            printf(" is not left factoring.\n");
        }
    }
}

