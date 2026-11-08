#include <stdio.h>
#include <math.h>

float f (float x){ // função para f(x).
    float F; 
    F = -3*pow(x,2) + x + 4;
    return F;
}
float bissecao (float a, float b ){ // função para o método de bisseção.
    float m;
    m = (a + b)/2;
    return m;
}
float secante (float a, float b){ // função para o método das secantes.
    float X,Z;
    if (f(a)-f(b) == 0){
        Z = (a + b) / 2; // caso dê zero dividido por zero, usa bisseção direto.
        return Z; 
    }
    X = ( f(a)*b - f(b)*a)/ ( f(a) - f(b) ); // caso contrário, o método das secantes é aplicado normalmente.
    return X;
}

int main(){
    float a,b;
    int i,j = 0;
    float x;
 do{ // loop feito para caso não tenha garantia de raiz no intervalo.
    printf("por favor,dada a funcao f(x)= -3x^2+x+4, defina o intervalo a qual esta contida a raiz da funcao: [a,b]\n");
    printf("defina a:\n");
    scanf("%f",&a);
    printf("defina b:\n");
    scanf("%f",&b);
    printf("o intervalo definido foi [%.2f,%.2f]\n",a,b);
    if((f(a)*f(b) > 0)){
        printf("Nao ha garantia de raiz nesse intervalo!\n");
    }
    }while((f(a)*f(b) > 0));

    for(i = 0; i < 2; i++){  // começando com duas iterações no método de bisseção.
       x = bissecao(a,b);
        if( f(x)*f(a) <= 0){
            b = x;
        } else {
            a = x;
        }
        j++; // contagem de iterações.
    }

  do{ // Após duas iterações pelo método de bisseção, trocaremos para o método das secantes.
       x = secante(a,b);
    // Garantindo que o valor de 'x' esteja dentro do intervalo.
    if(x > a && x < b){
     // caso esteja no intervalo, x permanecerá com o mesmo valor.
    } else {
        x = bissecao(a,b); // caso não esteja, x irá continuar pelo método da bisseção.
    }
    // escolhendo valores para onde x estará dentro do intervalo.
    if( f(x)*f(a) <= 0){
            b = x;
        } else {
            a = x;
        }
// escolhido o valor de x, a iteração começará novamente até uma das condições ser atingida.
    j++;// contagem de iterações

  } while ((j < 20) && (fabs(b-a) >0.00001 ));
printf("o valor mais proximo para f(x) = 0 eh: %.6f\n",x);
printf("Total de iteracoes: %d",j);
    
    return 0;
}