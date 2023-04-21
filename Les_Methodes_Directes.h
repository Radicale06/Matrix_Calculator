#ifndef LES_METHODES_DIRECTES_H_INCLUDED
#define LES_METHODES_DIRECTES_H_INCLUDED
void Elimination_Gauss(float** ,float*,unsigned);
void Elimination_Gauss_avec_Pivotage(float**,float*,unsigned);
void Elimination_GaussJordan(float** ,float*,unsigned);
void Elimination_LU(float**,float*,unsigned);
void Elimination_Choleskey(float**,float*,unsigned);
#endif // LES_METHODES_DIRECTES_H_INCLUDED
