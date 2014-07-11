#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** Fonctions de tri : insertion > selection > bulles **/

void swapint(int *a,int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/********************* O(n*n) **********************/
void triBulles(int tab[], int taille) {
    int i = 0, j = 0;
    for(i = 0; i < taille; ++i)
        for(j = 1; j < taille-i; ++j)
            if(tab[j] < tab[j-1])
                swapint(&tab[j], &tab[j-1]);
}

void triSelection(int tab[], int taille) {
    int i, j, minimum = tab[0];
    for(i = 0; i < taille; ++i) {
        minimum = i;
        for(j = i; j < taille; ++j)
            if(tab[j] < tab[minimum])
                minimum = j;
        swapint(&tab[i], &tab[minimum]);
    }
}

void triInsertion(int tab[], int taille) {
    int i;
    for(i = 1; i < taille; ++i) {
        int tmp = tab[i];
        int index = i;
        while(index > 0 && tab[index-1] > tmp) {
            tab[index] = tab[index-1];
            --index;
        }
        tab[index] = tmp;
    }
}

/********************* O(n*lg(n)) *********************/
void triFusion(int tab[], int taille) {
    ;
}

void afficherTableau(int tab[], int taille) {
    int i;
    for(i = 0; i < taille; ++i)
        printf("%d ", tab[i]);
    printf("\n");
}

#define BEG 0
#define END 1000
int main(void) {
    clock_t t1, t2, totbulles = 0, totsel = 0, totins = 0;
    int i,
        j,
        tab1[END],
        tab2[END],
        tab3[END];
    srand((unsigned int)time(NULL));
    for(i = BEG; i < END; ++i) {
        for(j = 0; j < i; ++j) {
            tab1[j] = tab2[j] = tab3[j] = rand();
        }
        t1 = clock(); triBulles(tab1, i); t2 = clock() - t1; totbulles += t2;
        t1 = clock(); triSelection(tab2, i); t2 = clock() - t1; totsel += t2;
        t1 = clock(); triInsertion(tab3, i); t2 = clock() - t1; totins += t2;

        if((i-BEG) % ((END-BEG)/100) != 0) printf("\r%d %%", (i-BEG) / ((END-BEG)/100));
    }
    printf("\nMoyenne :\n\t- Bulles : %d tests, %d ms ==> %.4g ms/test\n"
           "\t- Selection : %d tests, %d ms ==> %.4g ms/test\n"
           "\t- Insertion : %d tests, %d ms ==> %.4g ms/test\n",
           END-BEG, totbulles, totbulles/(double)(END-BEG),
           END-BEG, totsel, totsel/(double)(END-BEG),
           END-BEG, totins, totins/(double)(END-BEG));
    return 0;
}
