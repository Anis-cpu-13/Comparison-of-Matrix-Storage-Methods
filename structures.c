#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "structures.h"
#include "tools.h"


/*-------------------------Matrice---------------------*/

Mat matrix_create(int w, int h)
{
	Mat A = tools_malloc (sizeof (struct _matrix));
	
	A->w = w;
	A->h = h;
	A->data = tools_malloc (sizeof (double) * w * h);
	return A;
}

/*Fonction qui permet de calculer la mémoire allouer pour la matrice*/

double check_memory_matrix(Mat A)
{
	return sizeof(struct _matrix) + sizeof (double) * A->w * A->h;
}
/* Fonction permet de free les lignes une par une */
void matrix_destroy (Mat* AA)
{
	Mat A = *AA;
	tools_free(A->data, sizeof (double) * A->w * A-> h);
	tools_free(A, sizeof(struct _matrix));
	
	*AA = NULL;
}
/* Fonction qui permet d'afficher une matrice*/
void matrix_debug (Mat A)
{
	int j, i; 
	fprintf(stderr, "\n");
	for (j = 0 ; j < A->h ; j++ )
		{
			for ( i = 0 ; i < A->w ; i++)
			{
				fprintf( stderr, "%.2lf \t", A->data[i * A->w +j]);
				
			}	
			fprintf(stderr, "\n");	
		}
}


double genrate_random_value(double max){   
  srand((unsigned int)clock());
  return  ((double)rand()/(double)(RAND_MAX)) * 10.0; 
}


/*Mat float_fill (int w, int h)
{
	int i, j;
	time_t t;
	Mat A;
	A = matrix_create(w, h);
	srand((unsigned) time(&t));
	for (i = 0; i < A->h; i++) 	{
		for (j = 0; j < A->w; j++) {
									
			A->data[i * A->w + j] = roundf(genrate_random_value(10)*100)/100;
		}
	}

	return A;

}*/

/* Trouver le nombre d'élements nulle */

int find_element ( Mat A)
{
	int i, j, h, w, count;
	count = 0;
	for ( i = 0; i < A->h; i++)
	{
		for ( j = 0; j < A->w; j++)
		{
			if ( A->data[i * A->w + j] != 0.0)
				count++;
		}
		
	}
	
	return count;
}

/* Tentative de supression des éléments nul dans,*/
/* une matrice chose que je n'est pas pu faire */
Mat delete_element ( Mat A)
{
	int i, j, k, l, w, h, counter;
	Mat T;
	double tmp;
	counter = find_element(A);

	w = counter/2;
	h = counter/2;

	T = matrix_create(w, h);
	T->h = h;
	T->w = w;
	k = 0;
	l = 0;
	for ( i = 0; i < A->h; i++)
	{
		for ( j = 0; j < A->w; j++)
		{
	
					if ( A->data[i * A->w + j ] != 0)
					{
						
						
						T->data[ k * T->w + l] = A->data[i * A->w + j ]; 
						printf("\n%lf", A->data[i * A->w + j ]);
						k++;
						l++;
					}

		
		}
		
	}

	return T;	
}

Mat float_fill (int w, int h)
{
	Mat m;
	int i, j, k, l, z, zi, nb;
	m = matrix_create(w,h);
	h = m->h;
	w = m->w;
	nb = h*w;

	for (i = 0, k=nb; i < m->h; i++, k--) {
		l = k;
		m->data[i * m->w + i] = (double) l;	
		l >>= 1;
		for (j = i+1, z=1, zi = 0; j < m->w; j++) {
		if (z == zi) {
			m->data[i * m->w + j] = (double) l;
			l >>= 1;
			z <<= 1;
			zi = 0;
		}
		else {
			m->data[i * m->w + j] = 0.0;
			zi++;
		}
		}
  }
  return m;
}


Mat mulplication_matrix (Mat A, Mat B)
{
	int j, i, k; 
	Mat R;
	R = matrix_create(A->w, B->h);
	for (i = 0 ; i < A->w ; i++ )
		{
			for ( j = 0 ; j < B->h ; j++)
			{
				for ( k = 0; k < B->w; k++)
				{
					R->data[i * R->w + j] += (A->data[i * A->w + k] * B->data[k * B->w + j]);

				}
				
			}	
				
		}

		return R;
}

/*-----------------------Vecteur------------------------*/

/* Fonction qui alloue le vecteur */

Vec vector_create (int length)
{
	Vec V =  tools_malloc(sizeof (struct _vector));
	V->length = length;
	V->vec = tools_malloc( length * sizeof  * (V->vec));
	return V;
}

/* Fonction qui calcule la mémoire allouer pour un vecteur */
double check_memory_vector(Vec V)
{
	return sizeof(struct _vector) + V->length * sizeof  * (V->vec);
}

/* Fonction qui permet de désallouer un vecteur*/

void vector_destroy (Vec* VV)
{
	Vec V = *VV;
	tools_free(V->vec, V->length * sizeof * V->vec);
	tools_free(V, sizeof(struct _vector));
	*VV = NULL;
}

/*Fonction qui transforme une matrice en un vecteur*/

Vec tranform_matrix_to_vector (Mat A, int length)
{
	int i, j;
	Vec V;
	V = vector_create (length);
	for ( i = 0; i < A->h ; i++)
	{
		for ( j = 0; j < A->w; j++)
		{
			V->vec[i * A->w +j].i = i;
			V->vec[i * A->w +j].j = j;
			V->vec[i * A->w +j].data = A->data[i * A->w +j];
		}
		
	}
	return V;
}

/* Fonction qui calcule les indices h et w d'une matrice à partir d'un vecteur */

Mat get_index_matrix (Vec V, int length)
{
	int i, h, w;
	Mat A;
	h = 0;
	w = 0;
	for ( i = 0; i < length; i++)
	{
		h = V->vec[i].i+1;
		w = V->vec[i].j+1;
	}
	A = matrix_create(w, h);

	return A;
}

/* Fonction qui transfrome un vecteur en une matrice */

Mat transform_vector_to_matrix (Vec V, int length)
{
	int i, j;
	Mat A;
    A = get_index_matrix ( V, length);

	for ( i = 0; i < A->h; i++)
	{
		for ( j = 0; j < A->w; j++)
		{	
				A->data[i * A->w +j] = V->vec[i * A->w +j].data;		
		}
		
	}
	
	return A;
}

/* FOncion qui donne le résulat du produit de deux vecteur */

double multiplication_vector ( Vec A, Vec B)
{
	double result;
	int i;
	
	result = 0;

	if (A->length == B->length)
	{
		for ( i = 0; i < A->length ; i++)
		{
				result += A->vec[i].data * B->vec[i].data;
		}
		
	}
	return result;
}


/* Fonction qui affiche un vecteur */

void vector_debug(Vec V){
  int i;
  fprintf(stderr, "\n");
  for (i = 0; i < V->length; i++)
   fprintf(stderr ,"\nVecteur[%d] = %.2lf\n ", i, V->vec[i].data);
}

/* Fonction qui alloue une mtrice compact */

Mco matrix_compact_create (int h , int w)
{
	Mco A = tools_malloc(sizeof(struct _compact_matrix));
	A->w = w;
	A->h = h;	
	A->vec = tools_malloc( w*h* sizeof * A->vec);
	return A;

}


/* Fonction qui calcule la mémoire allouer pour une matrice compact */
double check_memory_mco(Mco A)
{
	return sizeof(struct _compact_matrix) + A->h * A->w * sizeof  * A->vec;
}

/* Fonction qui permet de désalouer une matrice compcat*/

void matrix_compact_destroy (Mco* VV)
{
	Mco V = *VV;
	tools_free(V->vec, V->h * V->w * sizeof * V->vec);
	tools_free(V, sizeof(struct _compact_matrix));
	*VV = NULL;
}

/* Fonction qui transforme une matrice en une matrice compact */

Mco transform_matrix_to_mco (Mat A)
{
	int i, j;
	Mco B = matrix_compact_create(A->w, A->h);
	for ( i = 0; i < A->h; i++)
	{
		for ( j = 0; j < A->w; j++)
		{
			B->vec[i * A->w +j].i = i;
			B->vec[i * A->w +j].j = j;
			B->vec[i * A->w +j].data = A->data[i * A->w +j];
			
		}
		
	}

	return B;	
}
/* Fonction qui calcule le produit de deux matrice compact */

Mco mulplication_matrix_compact(Mco A, Mco B)
{
	int j, i, k; 
	Mco R;
	R = matrix_compact_create(A->w, B->h);
	for (i = 0 ; i < A->w ; i++ )
		{
			for ( j = 0 ; j < B->h ; j++)
			{
				for ( k = 0; k < B->w; k++)
				{
					R->vec[i * R->w + j].data += A->vec[i * R->w + k].data * B->vec[k * R->w + j].data;
				}
				
			}	
				
		}

		return R;
}

/* Fonction qui permet de transformer une matrice compact en une matrice */

Mat transform_mco_to_matrix (Mco A )
{
	int i, j;
	Mat B;
	B = matrix_create (A->h, A->w);

	for ( i = 0; i < A->h; i++)
	{
		for ( j = 0; j < A->w; j++)
		{
			B->data[i * A->w +j] = A->vec[i * A->w +j].data;
		}
		
	}
	
	return B ;
}

Mco get_index_mco (Vec V, int length)
{
	int i, h, w;
	Mco A;

	h = 0;
	w = 0;
	for ( i = 0; i < length; i++)
	{
		h = V->vec[i].i+1;
		w = V->vec[i].j+1;
	}
	A = matrix_compact_create(w, h);

	return A;
}

/* Fonction qui permet de transforme un vecteur en une matrice compacte */

Mco transform_vector_to_mco (Vec V, int length)
{

	int i, j;
	Mco A;
    A = get_index_mco ( V, length);

	for ( i = 0; i < A->h; i++)
	{
		for ( j = 0; j < A->w; j++)
		{	
				A->vec[i * A->w +j].data = V->vec[i * A->w +j].data;		
		}
		
	}
	
	return A;
}


/* Fonction qui transfrome une matrice compact en un vecteur */
Vec transform_mco_to_vecteur( Mco A, int length)
{
	int i, j;
	Vec V;
	V = vector_create(length);
	for ( i = 0; i < A->h; i++)
	{
		for ( j = 0; j < A->w; j++)
		{
			V->vec[i * A->w +j].i = i;
			V->vec[i * A->w +j].j = j;
			V->vec[i * A->w +j].data = A->vec[i * A->w +j].data;
		}
		
	}
	
	return V;
}


void matrix_compact_debug(Mco A)
{
	int i, j;

	fprintf(stderr, "\n");
	for (j = 0 ; j < A->h ; j++ )
		{
			for ( i = 0 ; i < A->w ; i++)
			{
				fprintf( stderr, "%.2lf \t", A->vec[i * A->w +j].data);	
			}	
			fprintf(stderr, "\n");	
		}	
}



