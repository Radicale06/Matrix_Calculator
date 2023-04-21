#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Multiplication_des_matrices.h"

/*matrice superieur X matrice superieur*/
void matrice_sup_X_matrice_sup(float** M,float** N,unsigned n){

    float** r=(float**)malloc(n*sizeof(float*));
    for (int i=0;i<n;i++)
          r[i]=(float*)calloc(n,sizeof(float));
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            for(int k=i;k<n;k++)
                r[i][j]+=M[i][k]*N[k][j];

    affichage_m(r,n);
}


/*matrice superieur X matrice inferieur*/
void matrice_sup_X_matrice_inf(float** M,float** N,unsigned n){

float**r=(float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
        r[i]=(float*)calloc(n,sizeof(float));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
            for(int k=i;k<n;k++)
                r[i][j]+=M[i][k]*N[k][j];
        for(int j=i+1;j<n;j++)
            for(int k=i+1;k<n;k++)
                r[i][j]+=M[i][k]*N[k][j];
    }
    affichage_m(r,n);
}


/*matrice inferieur X matrice inferieur*/
void matrice_inf_X_matrice_inf(float** M,float** N,unsigned n){
 float** r=(float**)malloc(n*sizeof(float*));
    for (int i=0;i<n;i++)
        r[i]=(float*)calloc(n,sizeof(float));
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            for(int k=0;k<=i;k++)
                r[i][j]+=M[i][k]*N[k][j];
    affichage_m(r,n);
}


/*matrice inferieur X matrice superieur*/
void matrice_inf_X_matrice_sup(float** M,float** N,unsigned n)
{
 float** r=(float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
        r[i]=(float*)calloc(n,sizeof(float));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
            for(int k=0;k<=j;k++)
                r[i][j]+=M[i][k]*N[k][j];
        for(int j=i+1;j<n;j++)
            for(int k=0;k<=i;k++)
                r[i][j]+=M[i][k]*N[k][j];
    }
    affichage_m(r,n);
}


/*matrice dense X matrice dense*/
void matrice_Dn_X_matrice_Dn(float** M,float** N,unsigned n){

float** r=(float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
        r[i]=(float*)calloc(n,sizeof(float));
    for(int k=0;k<n;k++)
        for(int j=0;j<n;j++)
            for(int i=0;i<n;i++)
                r[k][j]+=M[k][i]*N[i][j];
    affichage_m(r,n);

}


/*matrice X son transposé*/
void matrice_X_transposee(float** M,unsigned n){
float** r=(float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
        r[i]=(float*)calloc(n,sizeof(float));
    for(int k=0;k<n;k++)
        for(int j=0;j<n;j++)
            for(int i=0;i<n;i++)
                r[k][j]+=M[k][i]*M[j][i];
    affichage_m(r,n);
}


/*matrice a la puissance 2*/
void matrice_pow_caree(float** M,unsigned n){

float** r=(float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
        r[i]=(float*)calloc(n,sizeof(float));
    for(int k=0;k<n;k++)
        for(int j=0;j<n;j++)
            for(int i=0;i<n;i++)
                r[k][j]+=M[k][i]*M[i][j];
    affichage_m(r,n);

}


/*matrice X vecteur*/
void matrice_X_vect(float** M,float* v,unsigned n){

 float* r=(float*)calloc(n,sizeof(float));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            r[i]+=M[i][j]*v[j];
    affichage_vect(r,n);
}




