#ifndef RESOLUTION_DIRECTE_H_INCLUDED
#define RESOLUTION_DIRECTE_H_INCLUDED
void resolution_trg_inf_ligne(float** ,float*,unsigned);
float* resolution_trg_inf_ligne1(float** ,float*,unsigned);
void resolution_trg_inf_colonne(float**,float*,unsigned);
void resolution_trg_inf_Diag_unitaire_ligne(float**,float*,unsigned);
void resolution_trg_inf_Diag_unitaire_colonne(float**,float*,unsigned);

void resolution_trg_sup_ligne(float**,float*,unsigned);
void resolution_trg_sup_colonne(float**,float*,unsigned);
void resolution_trg_sup_Diag_unitaire_ligne(float**,float*,unsigned);
void resolution_trg_sup_Diag_unitaire_colonne(float**,float*,unsigned);

void resolution_trg_demiBande_inf_ligne(float**,float*,unsigned,unsigned);
void resolution_trg_demiBande_inf_colonne(float**,float*,unsigned,unsigned);
void resolution_trg_demiBande_sup_ligne(float**,float*,unsigned,unsigned);
void resolution_trg_demiBande_sup_colonne(float**,float*,unsigned,unsigned);



#endif // RESOLUTION_DIRECTE_H_INCLUDED
