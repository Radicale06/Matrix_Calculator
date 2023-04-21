#include <stdio.h>
#include "Menu.h"


/*Menu de Multiplication des matrices*/
void multiplication(){
    unsigned choix;
    while(1)
    {
        printf("\n\t------------ Multiplication des matrices ----------------\n\n");
        printf("\t1- Matrice Dense X Matrice Dense\n");
        printf("\t2- Matrice Dense X Vecteur\n");
        printf("\t3- Matrice Dense X son Transposet\n");
        printf("\t4- Matrice Dense a la puissance 2\n");
        printf("\t5- Matrice Inferieur X Matrice Inferieur\n");
        printf("\t6- Matrice Superieur X Matrice Superieur \n");
        printf("\t7- Matrice Inferieur X Matrice Superieur\n");
        printf("\t8- Matrice Superieur X Matrice Inferieur\n");
        printf("\t9- Retour au menu\n");
        printf("\t------------------------------------------------\n");
        printf("Votre Choix : ");
        scanf("%u",&choix);
        switch(choix){
            case 1:{
                system("cls");
                unsigned n;
                printf("taille De Matrice : ");
                scanf("%d",&n);
                printf("-------- 1er matrice dense --------\n");
                float** M1=saisie_m_Den(n);
                printf("--------2eme matrice dense --------\n");
                float** M2=saisie_m_Den(n);
                printf("-------- Resultat --------\n");
                matrice_Dn_X_matrice_Dn(M1,M2,n);
                break;
            }
            case 2:{
                system("cls");
                unsigned n;
                printf("taille De Matrice : ");
                scanf("%d",&n);
                printf("-------- 1er matrice dense --------\n");
                float** M=saisie_m_Den(n);
                printf("--------- vecteur ---------\n");
                float* V=saisie_vect(n);
                printf("--------- Resultat ---------\n");
                matrice_X_vect(M,V,n);
                break;
            }
            case 3:{
                system("cls");
                unsigned n;
                printf("taille De Matrice : ");
                scanf("%d",&n);
                printf("-------- matrice dense --------\n");
                float** M=saisie_m_Den(n);
                printf("--------- Resultat ---------\n");
                matrice_X_transposee(M,n);

                break;
            }
            case 4:{
                system("cls");
                unsigned n;
                printf("taille De Matrice : ");
                scanf("%d",&n);
                printf("-------- matrice dense --------\n");
                float** M=saisie_m_Den(n);
                printf("--------- Resultat ---------\n");
                matrice_pow_caree(M,n);

                break;
            }
            case 5:{
                system("cls");
                unsigned n;
                printf("taille De Matrice : ");
                scanf("%d",&n);
                printf("---------1er matrice inferieure-------------\n");
                float** M1=saisie_m_Inf(n);
                printf("---------2eme matrice inferieure ------------\n");
                float** M2=saisie_m_Inf(n);
                printf("--------- Resultat ---------\n");
                matrice_inf_X_matrice_inf(M1,M2,n);
                break;
            }
            case 6:{
                system("cls");
                unsigned n;
                printf("taille De Matrice: ");
                scanf("%d",&n);
                printf("--------1er matrice superieure -----------\n");
                float** M1=saisie_m_Sup(n);
                printf("--------2eme matrice superieure------------\n");
                float** M2=saisie_m_Sup(n);
                printf("-------- Resultat --------\n");
                matrice_sup_X_matrice_sup(M1,M2,n);
                break;
            }
            case 7:{
                system("cls");
                unsigned n;
                printf("taille De Matrice: ");
                scanf("%d",&n);
                printf("--------1er matrice inferieur -----------\n");
                float** M1=saisie_m_Inf(n);
                printf("--------2eme matrice superieure------------\n");
                float** M2=saisie_m_Sup(n);
                printf("-------- Resultat --------\n");
                matrice_inf_X_matrice_sup(M1,M2,n);
                break;
            }
            case 8:{
                system("cls");
                unsigned n;
                printf("taille De Matrice: ");
                scanf("%d",&n);
                printf("--------- matrice superieure -----------\n");
                float** M1=saisie_m_Sup(n);
                printf("---------- matrice inferieure ----------\n");
                float** M2=saisie_m_Inf(n);
                printf("---------- Resultat ----------\n");
                matrice_sup_X_matrice_inf(M1,M2,n);
                break;
            }

            case 9:{
                menu();
            }
            default:{system("cls");}
        }
    }
}





/*Resolution des systemes*/
void resolution(){
 unsigned choix;
    while(1)
    {
        printf("\n\n\n\t------------------ Resolution des systemes triangulaires ----------------------\n\n");
        printf("\t1- triangulair inferieur par ligne\n");
        printf("\t2- triangulair inferieur par colonne\n");
        printf("\t3- triangulair superieur par ligne\n");
        printf("\t4- triangulair superieur par colonne\n");
        printf("\t5- triangulair demi bande inferieur par ligne\n");
        printf("\t6- triangulair demi bande inferieur par colonne\n");
        printf("\t7- triangulair demi bande superieur par ligne\n");
        printf("\t8- triangulair demi bande superieur par colonne\n");
        printf("\t9- Retour au menu\n");
        printf("\t------------------------------------------------------------\n");

        printf("Votre Choix : ");
        scanf("%u",&choix);
        switch(choix){
            case 1:{
                system("cls");
                unsigned n;
                printf("taille de matrice: ");
                scanf("%u",&n);
                float** M=saisie_m_Inf(n);
                float* v=saisie_vect(n);
                resolution_trg_inf_ligne(M,v,n);
                break;
            }
            case 2:{
                system("cls");
                unsigned n;
                printf("taille de matrice: ");
                scanf("%u",&n);
                float** M=saisie_m_Inf(n);
                float* v=saisie_vect(n);
                resolution_trg_inf_colonne(M,v,n);
                break;
            }
            case 3:{
                system("cls");
                unsigned n;
                printf("taille de matrice: ");
                scanf("%u",&n);
                float** M=saisie_m_Sup(n);
                float* v=saisie_vect(n);
                resolution_trg_sup_ligne(M,v,n);
                break;
            }
            case 4:{
                system("cls");
                unsigned n;
                printf("taille de matrice: ");
                scanf("%u",&n);
                float** M=saisie_m_Sup(n);
                float* v=saisie_vect(n);
                resolution_trg_sup_colonne(M,v,n);
                break;
            }
            case 5:{
                system("cls");
                unsigned n,m;
                printf("taille de matrice: ");
                scanf("%u",&n);
                printf("valeur de m: ");
                scanf("%u",&m);
                float** M=saisie_m_DemiBande_inf(n,m);
                float* v=saisie_vect(n);
                resolution_trg_demiBande_inf_ligne(M,v,n,m);
                break;
            }case 6:{
                system("cls");
                unsigned n,m;
                printf("taille de matrice: ");
                scanf("%u",&n);
                printf("valeur de m: ");
                scanf("%u",&m);
                float** M=saisie_m_DemiBande_inf(n,m);
                float* v=saisie_vect(n);
                resolution_trg_demiBande_inf_colonne(M,v,n,m);
                break;
            }case 7:{
               system("cls");
                unsigned n,m;
                printf("taille de matrice: ");
                scanf("%u",&n);
                printf("valeur de m: ");
                scanf("%u",&m);
                float** M=saisie_m_DemiBande_sup(n,m);
                float* v=saisie_vect(n);
                resolution_trg_demiBande_sup_ligne(M,v,n,m);
                break;
            }
            case 8:{
                system("cls");
                unsigned n,m;
                printf("taille de matrice: ");
                scanf("%u",&n);
                printf("valeur de m: ");
                scanf("%u",&m);
                float** M=saisie_m_DemiBande_sup(n,m);
                float* v=saisie_vect(n);
                resolution_trg_demiBande_sup_colonne(M,v,n,m);
            }
            case 9:{
                menu();
            }
            default:{
                system("cls");
                }
        }
    }
}





/*Les Methodes Directes */
void methodes_directes(){
   unsigned choix;
    while(1)
    {
        printf("\n\t--------------- Methodes directes -----------------\n\n");
        printf("\t1- Elimination de gauss sans pivotage \n");
        printf("\t2- Elimination de gauss avec pivotage\n");
        printf("\t3- Elimination Gauss Jordan\n");
        printf("\t4- Elimination LOWER-UPPER\n");
        printf("\t5- Elimination de Cholesky\n\n");
        printf("\t6- Retour au menu\n\n");
        printf("\t------------------------------------------------\n");

        printf("Votre Choix : ");
        scanf("%u",&choix);
        switch(choix){
            case 1:{
                system("cls");
                unsigned n;
                printf("taille de matrice: ");
                scanf("%d",&n);
                float** M=saisie_m_Den(n);
                if(! check_inversible(M,n))
                {
                    system("error: la matrice est non inversible");
                    break;
                }
                float* v=saisie_vect(n);
                Elimination_Gauss(M,v,n);
                break;
            }
            case 2:{
                system("cls");
                unsigned n;
                printf("taille de matrice: ");
                scanf("%u",&n);
                float** M=saisie_m_Den(n);
                if(! check_inversible(M,n))
                {
                    system("error: la matrice est non inversible");
                    break;
                }
                float* v=saisie_vect(n);
                Elimination_Gauss_avec_Pivotage(M,v,n);
                break;
            }
            case 3:{
                system("cls");
                unsigned n;
                printf("taille de matrice: ");
                scanf("%u",&n);
                float** M=saisie_m_Den(n);
                if(! check_inversible(M,n))
                {
                    system("error: la matrice est non inversible");
                    break;
                }
                float* v=saisie_vect(n);
                Elimination_GaussJordan(M,v,n);
                break;
            }
            case 4:{
                system("cls");
                unsigned n;
                printf("taille de matrice: ");
                scanf("%u",&n);
                float** M=saisie_m_Den(n);
                if(! check_inversible(M,n))
                {
                    system("error: la matrice est non inversible");
                    break;
                }
                float* v=saisie_vect(n);
                Elimination_LU(M,v,n);
                break;
            }
            case 5:{
               system("cls");
                unsigned n;
                printf("taille de matrice: ");
                scanf("%u",&n);
                float** M=saisie_m_Den(n);
                if(! check_inversible(M,n))
                {
                    system("error: la matrice est non inversible");
                    break;
                }

                if(! check_symetrique_def_positive(M,n))
                {
                    system("error: la matrice n'est pas symetrique definie positive");
                    break;
                }
                float* v=saisie_vect(n);
                Elimination_Choleskey(M,v,n);
                break;
            }
            case 6:{
                menu();
                }
            default:{system("cls");}
        }
    }
}







/*le Menu principales*/
void menu(){
unsigned choix;
    while(1)
    {
        system("cls");
        printf("\n\t----------------- Calculatrice des Matrices ---------------------\n\n");
        printf("\t1- Multiplications des matrices\n");
        printf("\t2- Resolution des systemes \n");
        printf("\t3- Les Methodes directes\n");
        printf("\t--------------------------------------------------------------------\n");

        printf("Votre Choix : ");
        scanf("%u",&choix);
        switch(choix){
            case 1:{
                system("cls");
                multiplication();
                break;
            }
            case 2:{
                system("cls");
                resolution();
                break;
            }
            case 3:{
                system("cls");
                methodes_directes();
                break;
            }
            default:{system("cls");}
        }
    }
}
