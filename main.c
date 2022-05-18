#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#define INFINITO 0

void print ( long long int n) {
    if (n / 10 != 0)
        print(n / 10);
    putchar((n % 10) + '0');

}

typedef struct {
    long long int numeroGrafo;
    unsigned long long int pesoGrafo;
}posizioneGrafo;

int main(int argc, char *argv[]) {
    char command;
    unsigned long long int trash=1;
    long long int i,j;
    unsigned long long int numNodi;
     long long int lungClassifica;
    unsigned long long int minore;
    unsigned long long int nodoMinore=1;
    unsigned long long int distanzaTotale=0;
    unsigned long long int iterazioni=1;
    unsigned long long int ultimoInClassifica=0;
    unsigned long long int pesoMaggiore=0;
     long long int posizioniClassificaRiempite=0;
    long long int numCurrGrafo=-1;
    unsigned long long int num=0;
    unsigned long long int distanzaParziale;
    int value;
    int dec;
    int found;






    value=getchar();

    while ( value!=EOF &&value!='\n'&& value!=' '){
        dec=value-'0';

        num=(num*10)+dec;
        value=getchar();
        //}

    }
    numNodi= num;//popolo matrice adiacenza

    num=0;
    value=getchar();

    while ( value!=EOF &&value!='\n'&& value!=' '){
        dec=value-'0';

        num=(num*10)+dec;
        value=getchar();
        //}
    }
    lungClassifica=num;



    unsigned int visitati[numNodi];


    unsigned long long int distanza[numNodi];

    posizioneGrafo realClassifica[lungClassifica];
    unsigned long long int grafo[numNodi][numNodi];

    do {

        command=getchar();
        if(command!=EOF){
            if(command=='A') {
                while(command!='\n'){
                    command=getchar();
                }
                iterazioni=1;
                distanzaTotale=0;
                numCurrGrafo=numCurrGrafo+1;
                posizioniClassificaRiempite=posizioniClassificaRiempite+1;
                for (i = 0; i < numNodi; i++) {
                    visitati[i]=0;
                    for (j = 0; j < numNodi; j++) {
                        num=0;
                        value=getchar();

                        while ( value!=EOF &&value!='\n'&& value!=','){
                            dec=value-'0';

                            num=(num*10)+dec;
                            value=getchar();
                            //}

                        }
                        grafo[i][j]= num;
                        if(i==0){
                            if(num==0){
                                distanza[j]=ULONG_MAX;

                            }
                            else{
                                distanza[j] = num;

                            }

                        }
                    }}

                minore = ULONG_MAX;
                if (trash) {}
                visitati[0] = 1;
                distanza[0]=0;
                for (j = 1; j < numNodi; j++) {
                    if (distanza[j] < minore) {
                        nodoMinore = j;
                        minore = distanza[j];
                    }
                }
                if (minore==ULONG_MAX ){
                    iterazioni=numNodi;//il grafo non e connesso
                }

                visitati[nodoMinore] = 1;

                while (iterazioni < numNodi -1){
                    for (j = 1; j < numNodi; j++) {
                        if (grafo[nodoMinore][j] > INFINITO){
                            if (visitati[j] == 0) {//se non visitato
                                distanzaParziale = grafo[nodoMinore][j] + distanza[nodoMinore];
                                if (distanzaParziale < distanza[j]) {//distanza maggiore di 0 e minore
                                    distanza[j] = distanzaParziale;//salvo il minore
                                }
                            }
                        }
                    }
                    minore=ULONG_MAX;
                    for(i=1;i<numNodi;i++){
                        if(visitati[i]==0){
                            if(distanza[i]<minore){
                                minore=distanza[i];
                                nodoMinore=i;
                            }
                        }}

                    if(minore==ULONG_MAX){
                        iterazioni=numNodi;//se non ci sono nodi raggiungibili esco dal  while
                    }
                    if(iterazioni!=numNodi){
                        visitati[nodoMinore] = 1;//dico che ho visitato quel nodo
                        iterazioni++;

                    }
                }

                for(i=1;i<numNodi;i++){
                    if(distanza[i]==ULONG_MAX){
                        distanzaTotale=distanzaTotale;
                    }
                    else{
                        distanzaTotale=distanzaTotale+distanza[i];
                    }
                }

                if(posizioniClassificaRiempite==1){
                    realClassifica[0].numeroGrafo=numCurrGrafo;
                    realClassifica[0].pesoGrafo=distanzaTotale;
                }
                else{
                    if(posizioniClassificaRiempite<=lungClassifica){
                        if(realClassifica[0].pesoGrafo>distanzaTotale){
                            for(i=posizioniClassificaRiempite-2;i>=0;i--){
                                realClassifica[i+1].pesoGrafo=realClassifica[i].pesoGrafo;
                                realClassifica[i+1].numeroGrafo=realClassifica[i].numeroGrafo;
                            }
                            realClassifica[0].pesoGrafo=distanzaTotale;
                            realClassifica[0].numeroGrafo=numCurrGrafo;
                        }
                        else if(realClassifica[posizioniClassificaRiempite-2].pesoGrafo>distanzaTotale){
                            found=0;
                            for(i=posizioniClassificaRiempite-2;i>=0&&found==0;i--){
                                if(realClassifica[i].pesoGrafo<distanzaTotale){
                                    realClassifica[i+1].pesoGrafo=distanzaTotale;
                                    realClassifica[i+1].numeroGrafo=numCurrGrafo;
                                    found=1;
                                }
                                else {
                                    realClassifica[i+1].pesoGrafo=realClassifica[i].pesoGrafo;
                                    realClassifica[i+1].numeroGrafo=realClassifica[i].numeroGrafo;
                                }
                            }
                        }
                    }
                    else{
                        if(realClassifica[0].pesoGrafo>distanzaTotale){
                            for(i=lungClassifica-2;i>=0;i--){
                                realClassifica[i+1].pesoGrafo=realClassifica[i].pesoGrafo;
                                realClassifica[i+1].numeroGrafo=realClassifica[i].numeroGrafo;
                            }
                            realClassifica[0].pesoGrafo=distanzaTotale;
                            realClassifica[0].numeroGrafo=numCurrGrafo;
                        }
                        else if (realClassifica[lungClassifica-1].pesoGrafo>distanzaTotale){
                            found=0;
                            for(i=lungClassifica-2;i>=0&&found==0;i--){
                                if(realClassifica[i].pesoGrafo<distanzaTotale){
                                    realClassifica[i+1].pesoGrafo=distanzaTotale;
                                    realClassifica[i+1].numeroGrafo=numCurrGrafo;
                                    found=1;
                                }
                                else{
                                        realClassifica[i+1].pesoGrafo=realClassifica[i].pesoGrafo;
                                        realClassifica[i+1].numeroGrafo=realClassifica[i].numeroGrafo;
                                    }
                                }

                                }
                            }
                        }
            }
            else {
                while(command!='\n'){
                    command=getchar();
                }
                if (posizioniClassificaRiempite == 0) {
                    printf("\n");
                }
                else if (posizioniClassificaRiempite <=lungClassifica) {
                    // printf("%lld ", realClassifica[0].numeroGrafo);
                    for (i = 0; i < posizioniClassificaRiempite-1; i++) {
                        print(realClassifica[i].numeroGrafo);
                        putchar(' ');

                    }
                    print(realClassifica[posizioniClassificaRiempite-1].numeroGrafo);
                    putchar('\n');
                } else if (posizioniClassificaRiempite>lungClassifica){

                    for (i = 0; i < (lungClassifica-1); i++) {
                        print(realClassifica[i].numeroGrafo);
                        putchar(' ');

                    }
                    print(realClassifica[lungClassifica-1].numeroGrafo);
                    putchar('\n');
                   
                }
            }}

    }while (command!=EOF);


    return 0;}



