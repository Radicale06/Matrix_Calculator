#ifndef LES_METHODES_H_INCLUDED
#define LES_METHODES_H_INCLUDED
float** saisie_m_DemiBande_sup(unsigned ,unsigned );
float** saisie_m_DemiBande(unsigned ,unsigned ,unsigned);
float** saisie_m_DemiBande_inf(unsigned ,unsigned );
float** saisie_m_Sup (unsigned );
float** saisie_m_Den(unsigned);
float** saisie_m_Inf (unsigned );
float* saisie_vect(unsigned );
void affichage_m (float** M,unsigned );
void affichage_vect (float* v,unsigned n);
unsigned check_inversible(float** ,unsigned);
unsigned check_symetrique_def_positive(float**,unsigned );
float determinant(float** ,unsigned);
#endif // LES_METHODES_H_INCLUDED
