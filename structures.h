#ifndef _STOCKAGE_H_
#define _STOCKAGE_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "tools.h"
/* Structure d'une matrice du type int */

typedef struct _matrix* Mat;
struct _matrix{
	int w; /* width */
	int h; /* height */
	double* data;
};

/* Structure d'un vecteur */
/* Sous structure d'un vecteur ou cas particulier d'une matrice compcate */
typedef struct triplet triplet;
struct triplet{
    int i; /* Cursor i */
	int j; /* Cursor j */
	double data;
};

typedef struct _vector* Vec; 
struct _vector{
	int length; /* Size */
	triplet *vec;
};

/* Structure de matrice compact */
typedef struct _compact_matrix* Mco;
struct _compact_matrix
{
	int w; /* width */
	int h; /* height */
	triplet *vec;

};




/*----------------------------------Matrice--------------------------*/

/* Fonction qui permet de crée une matrice */
Mat matrix_create (int , int );

/* Fonction qui permet d'initiliser la matrice */

Mat float_fill ( int , int );
//Mat float_fill ( int  );

/* Fonction qui permet de désalouer la matrice */
void matrix_destroy (Mat*);
void matrix_debug (Mat );
void array_fill (Mat *);

/* Fonction qui génére un tableau  de valeur aléatoire */
double genrate_random_value(double );
/* Fonction qui multiplie deux matrice de double*/
Mat mulplication_matrix (Mat , Mat );


/* Foncion qui permet de crée un vecteur */
Vec vector_create (int );

/* Focntion qui transforme un une matrice en un vecteur*/

Vec tranform_matrix_to_vector (Mat , int );

/* Fonction qui affiche un vecteur */

void vector_debug(Vec );

void vector_destroy (Vec* );

Mat transform_vector_to_matrix (Vec , int );

double multiplication_vector ( Vec , Vec );

/*--------------------------Matrice compact ----------------------*/

/* Fonction qui permet d'allouer une matrice compcat*/
Mco matrix_compact_create (int  , int );

/* Fonction qui permet de désalouer une matrice compcat*/
void matrix_compact_destroy (Mco* );

/* Fonction qui permet de transfomer une matrice en une matice compact */

Mco transform_matrix_to_mco (Mat );

/* Fonction qui transforme une matrice compact en mco */

Mat transform_mco_to_matrix (Mco );

/* Fonction qui permet d'afficher une matrice compacte*/
void matrix_compact_debug(Mco );

Mco transform_vector_to_mco (Vec , int );

Vec transform_mco_to_vecteur( Mco , int );

Mco mulplication_matrix_compact(Mco , Mco );

Mat get_index_matrix (Vec , int );

Mco get_index_mco (Vec , int );

Mat delete_element ( Mat );
int find_element ( Mat );
/* Calcule de la mémoire consomer par les différente structure Mat, Vec, Mco */
double check_memory_matrix(Mat );
double check_memory_vector(Vec );
double check_memory_mco(Mco );


#endif
