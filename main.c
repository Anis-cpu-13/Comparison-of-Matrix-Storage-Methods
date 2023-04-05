#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "structures.h"
#include "tools.h"


int main(int argc, char** argv)
{
	int length;
	length = 0;
	Mat mat;
	Mat mat_1;
	Mat mat_2;
	Mat reuslt_mat;

	Mco result_mco;
	Mco mco;
	Mco mco_1;

	Vec vec;
	Vec vec_1;

	double result_vec;
	double memory_matrix;
	double memory_vector;
	double memory_mco;
	double time_1;
	double time_2;
	double time_3;

	int row;
	int column;

	tools_memmory_init();
	{
		printf("Saisir le nombre de lignes\n");
		scanf("%d", &row);
		
		printf("Saisir le nombre de colones\n");
		scanf("%d", &column);

	 	mat = float_fill(row, column);
	 	matrix_debug(mat);


		length = mat->h * mat->w;	
		printf("\nTransformation d'une matrice en vecteur :\n");
		vec = tranform_matrix_to_vector(mat, length);						
		vector_debug(vec);	
		printf("\nTransformation d'un vecteur en une matrice :\n");
		mat_1 = transform_vector_to_matrix(vec, length);
		matrix_debug(mat_1);

		printf("\nTransformation d'une matrice en une matrice compacte :\n");
		mco = transform_matrix_to_mco(mat_1);
		matrix_compact_debug(mco);

		printf("\nTransfomraion d'une matrice compact en un vecteur :\n");
		vec_1 = transform_mco_to_vecteur(mco, length);
		vector_debug(vec_1);	
		printf("\nTransformation d'un vecteur en une matrice compacte :\n");
		mco_1 = transform_vector_to_mco(vec_1, length);
		matrix_compact_debug(mco_1);	
		printf("\nTransformation d'une matrice compacte en matrice : \n");
		mat_2 = transform_mco_to_matrix(mco_1);
		matrix_debug(mat_2);


		/*Résulat de la multilication de deux matrices*/
		init_time();
		reuslt_mat = mulplication_matrix(mat_1, mat_2);
		time_1 = get_time();
		printf("\nRésulat de la multiplication de deux matrices:\n");
		matrix_debug(reuslt_mat);	

		/*Résultat de la multiplication de deux vecteurs*/
		
		printf("\nResulat de la multiplication de deux vecturs : ");
		init_time();
		result_vec = multiplication_vector(vec, vec_1);
		time_2 = get_time();
		printf("%g\n", result_vec);	
		
		/*Résultat de la multplication de deux matrices compcate*/
		
		printf("\nRésultat de la multplication de deux matrice compacte :\n");
		init_time();
		result_mco = mulplication_matrix_compact(mco, mco_1);
		time_3 = get_time();
		//matrix_compact_debug(result_mco);	
		/*Calcule de la mémoire consomer par une matrice*/
		memory_matrix = check_memory_matrix(mat);
		printf("La memoire consomer par une matrice %2.0f octets\n", memory_matrix);
		/*Calcule de la mémoire consomer par vecteur*/
		memory_vector = check_memory_vector(vec);
		printf("La memoire consomer par un vecteur %2.0f octets\n", memory_vector);
		/*Calcule de la mémoire consomer par une matrice comapcte*/
		memory_mco = check_memory_mco(mco);
		printf("La memoire consomer par une matrice compact %2.0f octets\n", memory_mco);

		printf("le temps que prend la multiplication de deux matrices %f secondes\n", time_1);
		printf("le temps que prend la multiplication de deux vecteurs %f secondes\n", time_2);
		printf("le temps que prend la multiplication de deux matrices compcate %f secondes \n", time_3);	
		matrix_destroy(&mat);
		matrix_destroy(&mat_1);
		vector_destroy(&vec);
		matrix_compact_destroy(&mco);
		vector_destroy(&vec_1);
		matrix_compact_destroy(&mco_1);
		matrix_destroy(&mat_2);
		matrix_destroy(&reuslt_mat);
		matrix_compact_destroy(&result_mco);	




		tools_memory_check_at_end_of_app();		
	}
	return EXIT_SUCCESS;
}


