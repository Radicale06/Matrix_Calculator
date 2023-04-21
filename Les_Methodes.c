#include<stdio.h>
#include <stdlib.h>
#include "Les_Methodes.h"

/*saisie d'une matrice demi-bande superieur*/
float** saisie_m_DemiBande_sup(unsigned n,unsigned r){
    unsigned i,j ;
    float** M=(float**)malloc(n*sizeof(float*));
    for(i=0;i<n;i++)
    M[i]=(float*)calloc(n,sizeof(float));
    for(i=0;i<n;i++){
        for(j=i;j<=i+r; j++)
    {
        printf("M[%d][%d]= ",i,j);
        scanf("%f",&M[i][j]);
    }

    }
    return M;
}


/*saisie d'une matrice demi-bande*/
float** saisie_m_DemiBande(unsigned n,unsigned r,unsigned s){
    unsigned i,j,k ;
    float** M=(float**)malloc(n*sizeof(float*));
    for(i=0;i<n;i++)
    M[i]=(float*)calloc(n,sizeof(float));
    for(i=0;i<n;i++){
         if(i<n-s)
          k=0;
            else
                k++;
        for(j=k;j<=n-r; j++)
    {
        printf("M[%d][%d]= ",i,j);
        scanf("%f",&M[i][j]);
    }

    }
    return M;
}


/*saisie d'une matrice demi-bande inferieur*/
float** saisie_m_DemiBande_inf(unsigned n,unsigned r){
    unsigned i,j,k ;
    float** M=(float**)malloc(n*sizeof(float*));
    for(i=0;i<n;i++)
    M[i]=(float*)calloc(n,sizeof(float));
    for(i=0;i<n;i++){
            if(i<n-r)
                k=0;
            else
                k++;
        for(j=k;j<=i; j++)
    {
        printf("M[%d][%d]= ",i,j);
        scanf("%f",&M[i][j]);
    }

    }
    return M;
}


/* saisie d'une matrice dense */
float** saisie_m_Den (unsigned n){
    unsigned i,j ;
    float** M=(float**)malloc(n*sizeof(float*));
    for(i=0;i<n;i++)
    M[i]=(float*)calloc(n,sizeof(float));
    for(i=0; i<n; i++)
        {
        for(j=0; j<n; j++)
            {
            printf("M[%d][%d]= ",i,j);
            scanf("%f",&M[i][j]);
            }
        printf("\n");
        }
        return M;
}


/* saisie d'une matrice superieur */
float** saisie_m_Sup (unsigned n){
    unsigned i,j ;
    float** M=(float**)malloc(n*sizeof(float*));
    for(i=0;i<n;i++)
    M[i]=(float*)calloc(n,sizeof(float));
    for(i=0; i<n; i++)
        {
        for(j=i; j<n; j++)
            {
            printf("M[%d][%d]= ",i,j);
            scanf("%f",&M[i][j]);
            }
        printf("\n");
        }
        return M;
}


/* saisie d'une matrice inferieur */
float** saisie_m_Inf (unsigned n){
    unsigned i,j ;
    float** M=(float**)malloc(n*sizeof(float*));
    for(i=0;i<n;i++)
    M[i]=(float*)calloc(n,sizeof(float));

    for(i=0; i<n; i++)
        {
        for(j=0; j<=i; j++)
            {
            printf("M[%d][%d]= ",i,j);
            scanf("%f",&M[i][j]);
            }
        printf("\n");
        }
        return M;
}


/*saisie d'un vecteur*/
float* saisie_vect(unsigned n){
    float* vect=(float*)malloc(n*sizeof(float));

    for(unsigned i=0; i<n; i++)
        {
            printf("V[%d]= ",i);
            scanf("%f",&vect[i]);
        }
        return vect;
}


/* affichage de matrice  */
void affichage_m (float** M,unsigned n){
    unsigned i,j;
    for(i=0; i<n; i++)
        {
        for(j=0; j<n; j++)
            {
            printf("%.2f\t",M[i][j]);
            }
        printf("\n");
        }
    printf("\n");
}


/* affichage de vecteur  */
void affichage_vect (float* v,unsigned n)
{
    for(unsigned i=0;i<n;i++){
    printf("%.2f\t",v[i]);
}
}


/*calcule determinant*/
float determinant(float** M,unsigned n)
{
    float **N=(float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
        N[i]=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            N[i][j]=M[i][j];
    for(int k=0;k<n-1;k++)
    {
        for(int i=k+1;i<n;i++)
        {
            N[i][k]=N[i][k]/N[k][k];
            for (int j=k+1;j<n;j++)
                N[i][j]=N[i][j]-N[i][k]*N[k][j];
        }
    }
    float p=1;
    for(int i=0;i<n;i++)
        p*=N[i][i];
    return p;
}


/*tester si inversible*/
unsigned check_inversible(float** M,unsigned n)
{

    return (determinant(M,n)!= 0)?1:0;
}


/*tester si symetrique def positive*/
unsigned check_symetrique_def_positive(float** M,unsigned n)
{
    if(M[0][0]<=0) return 0;
    for(int i=0;i<n;i++)
        if(determinant(M,i+1)<=0)
            return 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(M[i][j] != M[j][i]) return 0;
    return 1;
}



