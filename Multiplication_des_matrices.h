#ifndef MULTIPLICATION_DES_MATRICES_H_INCLUDED
#define MULTIPLICATION_DES_MATRICES_H_INCLUDED

void matrice_sup_X_matrice_sup(float** ,float**,unsigned);
void matrice_sup_X_matrice_inf(float** ,float**,unsigned);

void matrice_inf_X_matrice_inf(float** ,float**,unsigned);
void matrice_inf_X_matrice_sup(float** ,float**,unsigned);

void matrice_Dn_X_matrice_Dn(float** ,float**,unsigned);

void matrice_X_transposee(float**,unsigned);

void matrice_pow_caree(float**,unsigned);

void matrice_X_vect(float**,float* ,unsigned);



#endif // MULTIPLICATION_DES_MATRICES_H_INCLUDED
