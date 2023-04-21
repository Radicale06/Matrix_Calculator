#include <stdio.h>
#include <stdlib.h>
#include "Resolution_Directe.h"


/*retourne le minumum entre deux nombre*/
unsigned min(unsigned a,unsigned b){
    return (a<b)?a:b;
}


/*retourne le maximum entre deux nombre*/
unsigned max(unsigned a,unsigned b){
    return (a>b)?a:b;
}


/*Resolution triangulaire inferieur par ligne*/
void resolution_trg_inf_ligne(float** M,float* b,unsigned n){

    float* x=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
    {
        x[i]=b[i];
        for(int j=0;j<=i-1;j++)
            x[i]-=M[i][j]*x[j];
        x[i]/=M[i][i];
    }
    affichage_vect(x,n);
}
float* resolution_trg_inf_ligne1(float** M,float* b,unsigned n){

    float* x=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
    {
        x[i]=b[i];
        for(int j=0;j<=i-1;j++)
            x[i]-=M[i][j]*x[j];
        x[i]/=M[i][i];
    }
    return x;
}



/*Resolution triangulaire inferieur par colonne*/
void resolution_trg_inf_colonne(float** M,float* b,unsigned n){

float* x=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
        x[i]=b[i];
    for(int j=0;j<n;j++)
    {
        x[j]/=M[j][j];
        for(int i=j+1;i<n;i++)
            x[i]-=M[i][j]*x[j];
    }
    affichage_vect(x,n);
}


/*resolution des matrices triangulaire inferieur si la diagonale est unitaire par ligne*/
void resolution_trg_inf_Diag_unitaire_ligne(float** M,float* b,unsigned n){
float* x=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
    {
        x[i]=b[i];
        for(int j=0;j<=i-1;j++)
            x[i]-=M[i][j]*x[j];
    }
    affichage_vect(x,n);
}


/*resolution des matrices triangulaire inferieur si la diagonale est unitaire par colonne*/
void resolution_trg_inf_Diag_unitaire_colonne(float** M,float* b,unsigned n){
float* x=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
        x[i]=b[i];
    for(int j=0;j<n;j++)
    {
        for(int i=j+1;i<n;i++)
            x[i]-=M[i][j]*x[j];
    }
    affichage_vect(x,n);

}


/*Resolution triangulaire superieur par ligne*/
void resolution_trg_sup_ligne(float** M,float* b,unsigned n){
  float* x=(float*)malloc(n*sizeof(float));
        for(int i=n-1;i>=0;i--)
        {
            x[i]=b[i];
            for(int j=i+1;j<n;j++)
                x[i]-=M[i][j]*x[j];
            x[i]/=M[i][i];
        }
    affichage_vect(x,n);
}


/*Resolution triangulaire superieur par colonne*/
void resolution_trg_sup_colonne(float** M,float* b,unsigned n){
 float* x=(float*)malloc(n*sizeof(float));
        for(int i=0;i<n;i++)
            x[i]=b[i];
        for(int j=n-1;j>=0;j--)
        {
            x[j]/=M[j][j];
            for(int i=0;i<=j-1;i++)
                x[i]-=M[i][j]*x[j];
}
affichage_vect(x,n);
}

/*resolution des matrices triangulaire superieur si la diagonale est unitaire par ligne*/
void resolution_trg_sup_Diag_unitaire_ligne(float** M,float* b,unsigned n){
  float* x=(float*)malloc(n*sizeof(float));
    for(int i=n-1;i>=0;i--)
    {
        x[i]=b[i];
        for(int j=i+1;j<n;j++)
            x[i]-=M[i][j]*x[j];
    }
    affichage_vect(x,n);
}


/*resolution des matrices triangulaire superieur si la diagonale est unitaire par colonne*/
void resolution_trg_sup_Diag_unitaire_colonne(float** M,float* b,unsigned n){
float* x=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
        x[i]=b[i];
    for(int j=n-1;j>=0;j--)
        for(int i=0;i<=j-1;i++)
            x[i]-=M[i][j]*x[j];

    affichage_vect(x,n);
}


/*Resolution triangulaire demi-bande inferieur par ligne*/
void resolution_trg_demiBande_inf_ligne(float** M,float* b,unsigned n,unsigned r){

float* x=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
    {
        x[i]=b[i];
        for(int j=max(0,i-r);j<=i-1;j++)
            x[i]-=M[i][j]*x[j];
        x[i]/=M[i][i];
    }
    affichage_vect(x,n);
}


/*Resolution triangulaire inferieur demi-bande par colonne*/
void resolution_trg_demiBande_inf_colonne(float** M,float* b,unsigned n,unsigned r){
float* x=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
        x[i]=b[i];
    for(int j=0;j<n;j++)
    {
        x[j]/=M[j][j];
        for(int i=j+1;i<=min(i+r,r);i++)
            x[i]-=M[i][j]*x[j];
    }
    affichage_vect(x,n);
}


/*Resolution triangulaire superieur demi-bande par ligne*/
void resolution_trg_demiBande_sup_ligne(float** M,float* b,unsigned n,unsigned s){
  float* x=(float*)malloc(n*sizeof(float));
    for(int i=n-1;i>=0;i--)
    {
        x[i]=b[i];
        for(int j=i+1;j<=min(i+s,n-1);j++)
            x[i]-=M[i][j]*x[j];
        x[i]/=M[i][i];
    }
  affichage_vect(x,n);
}


/*Resolution triangulaire superieur demi-bande par colonne*/
void resolution_trg_demiBande_sup_colonne(float** M,float* b,unsigned n,unsigned s){
    float* x=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
        x[i]=b[i];
    for(int j=n-1;j>=0;j--)
    {
        x[j]/=M[j][j];
        for(int i=max(0,j-s);i<=j-1;i++)
            x[i]-=M[i][j]*x[j];
    }
    affichage_vect(x,n);

}
