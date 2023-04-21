#include <stdio.h>
#include <stdlib.h>
#include "Les_Methodes_Directes.h"


/*Elimination de Gauss Sans Pivotage*/
void Elimination_Gauss(float** M,float*b,unsigned n){

unsigned i,j,k;
for(k=0;k<n-1;k++)
{
for(i=k+1;i<n;i++)
{
M[i][k]/=M[k][k];

for(j=k+1;j<n;j++)
{
M[i][j]-=M[i][k]*M[k][j];

}
b[i]-=M[i][k]*b[k];

}
}
    resolution_trg_sup_ligne(M,b,n);
}


/*Elimination de Gauss avec Pivotage*/
void Elimination_Gauss_avec_Pivotage(float** M,float* b,unsigned n){

for(int k=0;k<n-1;k++){
        for(int i=k+1;i<n;i++){
            if(fabs(M[k][k])<fabs(M[i][k])){
                for(int j=0;j<n+1;j++){
                    float temp;
                    temp=M[k][j];
                    M[k][j]=M[i][j];
                    M[i][j]=temp;
                }
            }
        }
        for(int i=k+1;i<n;i++)
        {
            M[i][k]=M[i][k]/M[k][k];
            for (int j=k+1;j<n+1;j++)
                M[i][j]=M[i][j]-M[i][k]*M[k][j];
        }
    }
    resolution_trg_sup_ligne(M,b,n);
}


/*Elimination de Gauss-Jordan*/
void Elimination_GaussJordan(float** M,float* b,unsigned n){

     float* x=(float*)malloc(sizeof(float));
    unsigned i,j,k;
    for(i=0;i<n;i++)
        x[i]=b[i];
    for(k=0;k<n;k++)
    {
        for(j=k+1;j<n;j++)
        {
            M[k][j]/=M[k][k];
            for(i=0;i<=k-1;i++)
            {
                for(j=k+1;j<n;j++)
                {
                  M[i][j]-=M[i][k] *M[k][j];
                }
                x[i]-=M[i][k]*x[k];
            }
            for(i=k+1;i<n;i++)
            {
                for(j=k+1;j<n;j++)
                {
                    M[i][j]-=M[i][k] *M[k][j];
                }
                x[i]-=M[i][k]*x[k];
            }

        }
    }

        affichage_vect(x,n);
}


/*Elimination LOWER-UPPER*/
void Elimination_LU(float** M,float* b,unsigned n){
    unsigned i,j,k;
    float**L=(float**)malloc(n*sizeof(float*));
    float**U=(float**)malloc(n*sizeof(float*));
    for (i=0;i<n;i++)
    {
        L[i]=(float*)calloc(n,sizeof(float));
        U[i]=(float*)calloc(n,sizeof(float));
    }
    for(i=0;i<n;i++)
    {
        L[i][i]=1;
        for(j=0;j<=i-1;j++)
        {
            L[i][j]=M[i][j];
            for(k=0;k<=j-1;k++)
                L[i][j]=L[i][j]-L[i][k]*U[k][j];
            L[i][j]=L[i][j]/U[j][j];
        }
        for(j=i;j<n;j++)
        {
            U[i][j]=M[i][j];
            for(k=0;k<=i-1;k++)
                U[i][j]=U[i][j]-L[i][k]*U[k][j];
        }
    }
    resolution_trg_sup_ligne(U,resolution_trg_inf_ligne1(L,b,n),n);
}


/*Elimination de choleskey*/
void Elimination_Choleskey(float** M,float* b,unsigned n){

 float** L=(float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
        L[i]=(float*)malloc(n*sizeof(float));
    for(int j=0;j<n;j++)
    {
        L[j][j]=M[j][j];
        for(int k=0;k<=j-1;k++)
            L[j][j]-=L[j][k]*L[j][k];
        L[j][j]=sqrtf(L[j][j]);
        for(int i=j+1;i<n;i++)
        {
            L[i][j]=M[i][j];
            for(int k=0;k<=j-1;k++)
                L[i][j]-=L[i][k]*L[j][k];
            L[i][j]/=L[j][j];
        }
    }
    float* bi=resolution_trg_inf_ligne1(L,b,n);
    float* x=(float*)malloc(n*sizeof(float));
    for(int i=n-1;i>=0;i--)
    {
        x[i]=b[i];
        for(int j=i+1;j<n;j++)
            x[i]-=L[j][i]*x[j];
        x[i]/=L[i][i];
    }
    affichage_vect(x,n);
}
