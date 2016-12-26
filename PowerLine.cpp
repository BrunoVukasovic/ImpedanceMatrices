#include <iostream>
#include <cstdio>
#include <math.h>
#define pi 3.14159265

float **CreateNovaMatrica2(float **, float, float);
float **SubtractMatrix(float **, float **, int, int);
float **MultiplyMatrixAndFloatNumber(float **, int, int, float);
float **MultiplyOneDimensionalMatrix(float *, float*, int, int);
float** CreateMatrixFromRootMatrix(float **, int, int, int, int);
float* CreateArrayFromRootMatrix(float **, int, int, int, int);
float GetElementFromMatrix(float **, int, int);
float CalculateXs(float **);
float CalculateXm(float **);
float CalculateDm(float, float, float);
float CalculateDs(float);
float CalculateLd(float, float);
float CalculateXd(float);
void PrintXoXiXd(float, float);
void PrintXd(float);


int main ()
{
	int i=0,j=0;

	float visina_a=0.0;
	float visina_b=0.0;
	float visina_c=0.0;
	float visina_n=0.0;
	float udaljenost_a=0.0;
	float udaljenost_b=0.0;
	float udaljenost_c=0.0;
	float rf_1=0.0;
	float r0_1=0.0;
	float rf=0.0;
	float r0=0.0;
	float ro_zemlje=0.0;
	float Xu=0.0;
	float f=0.0;

	float Dab=0.0;
	float Dac=0.0;
	float Dan=0.0;
	float Dbc=0.0;
	float Dbn=0.0;
	float Dcn=0.0;

	float Xaa=0.0;
	float Xbb=0.0;
	float Xcc=0.0;
	float Xnn=0.0;
	float Xab=0.0, Xba=0.0;
	float Xac=0.0, Xca=0.0;
	float Xbc=0.0, Xcb=0.0;
	float Xan=0.0, Xbn=0.0, Xcn=0.0;



	printf ("Na slici je prikazan dalekovod s fazama a, b, c te neutralnim vodicem. Potrebno je unijeti parametre.\n""\t\t n \n""\t\t __ \n""\t\t || \n""\t\t ||---------b \n""\t\t || \n""\t\t || \n""\t\t || \n""\t\t || \n"
		"\t a-------|| \n""\t\t || \n""\t\t || \n""\t\t || \n""\t\t || \n""\t\t ||---------c \n" "\t\t || \n""\t\t || \n""\t\t || \n""\t\t || \n"
		"\t\t || \n""\t\t || \n""\t\t || \n""\t\t || \n""\t ___________________ \n""\t / / / / / / / / / / \n"
		);
	printf ("Unesite radijus faznih vodica u milimetrima\n");
	scanf ("%f", &rf_1);
	rf = rf_1 * 0.001;

	printf ("Unesite radijus neutralnog vodica u milimetrima\n");
	scanf ("%f", &r0_1);
	r0 = r0_1 * 0.001;

	printf ("Unesite specificni elektricni otpor zemlje u ohmima po metru\n");
	scanf ("%f", &ro_zemlje);

	printf ("Unesite Xu u ohmima po kilometru\n");
	scanf ("%f", &Xu);

	printf ("Unesite frekvenciju u herzima\n");
	scanf ("%f", &f);


	printf ("Unesite visinu (u metrima) na koju je postavljen vodic a\n");
	scanf ("%f", &visina_a);
	printf ("Unesite visinu (u metrima) na koju je postavljen vodic b\n");
	scanf ("%f", &visina_b);
	printf ("Unesite visinu (u metrima) na koju je postavljen vodic c\n");
	scanf ("%f", &visina_c);
	printf ("Unesite visinu (u metrima) na koju je postavljen neutralni vodic n\n");
	scanf ("%f", &visina_n);

	printf ("Unesite udaljenost (u metrima) vodica a od stupa\n");
	scanf ("%f", &udaljenost_a);
	printf ("Unesite udaljenost (u metrima) vodica b od stupa\n");
	scanf ("%f", &udaljenost_b);
	printf ("Unesite udaljenost (u metrima) vodica c od stupa\n");
	scanf ("%f", &udaljenost_c);


	Dab = sqrt ( pow(udaljenost_a+udaljenost_b, 2) + pow(visina_b - visina_a, 2) );
	printf ("Udaljenost vodica a i b (Dab) je %f\n", Dab) ;

	Dac = sqrt ( pow(udaljenost_a+udaljenost_c, 2) + pow(visina_a - visina_c, 2) );
	printf ("Udaljenost vodica a i c (Dac) je %f\n", Dac) ;

	Dbc = sqrt ( pow(udaljenost_c-udaljenost_b, 2) + pow(visina_b - visina_c, 2) );
	printf ("Udaljenost vodica a i b (Dbc) je %f\n", Dbc) ;

	Dan = sqrt ( pow(udaljenost_a, 2) + pow(visina_n - visina_a, 2) );
	printf ("Udaljenost vodica a i n (Dan) je %f\n", Dan) ;

	Dbn = sqrt ( pow(udaljenost_b, 2) + pow(visina_n - visina_b, 2) );
	printf ("Udaljenost vodica b i n (Dbn) je %f\n", Dbn) ;

	Dcn = sqrt ( pow(udaljenost_c, 2) + pow(visina_n - visina_c, 2) );
	printf ("Udaljenost vodica c i n (Dcn) je %f\n", Dcn) ;
	
	
	Xaa=0.1445*log10 ((658/rf)*sqrt(ro_zemlje/f)) + Xu;
	Xnn=0.1445*log10 ((658/r0)*sqrt(ro_zemlje/f)) + Xu;
	Xab=0.1445*log10 ((658/Dab)*sqrt(ro_zemlje/f));
	Xac=0.1445*log10 ((658/Dac)*sqrt(ro_zemlje/f));
	Xbc=0.1445*log10 ((658/Dbc)*sqrt(ro_zemlje/f));
	Xan=0.1445*log10 ((658/Dan)*sqrt(ro_zemlje/f));
	Xbn=0.1445*log10 ((658/Dbn)*sqrt(ro_zemlje/f));
	Xcn=0.1445*log10 ((658/Dcn)*sqrt(ro_zemlje/f));

	printf ("Xaa=Xbb=Xcc = %f\n", Xaa);
	printf ("Xnn = %f\n", Xnn);
	printf ("Xab = Xba = %f\n", Xab);
	printf ("Xac = Xca = %f\n", Xac);
	printf ("Xbc = Xcb = %f\n", Xbc);
	printf ("Xan = Xna = %f\n", Xan);
	printf ("Xbn = Xnb = %f\n", Xbn);
	printf ("Xcn = Xnc = %f\n", Xcn);

	float X_reakt_vodica[4][4]= { 
	{Xaa,Xab,Xac,Xan},
	{Xab,Xaa,Xbc,Xbn},
	{Xac,Xbc,Xaa,Xcn},
	{Xan,Xbn,Xcn,Xnn} 
	};
	
	printf("Matrica X_reakt_vodica\n");
	for(i=0;i<4; ++i){
		for(j=0;j<4; ++j){
			printf("%3f\t", X_reakt_vodica[i][j]);
		}
		printf("\n");
	}
	
	float *ptr_X_reakt_vodica[4];
	
	for(i=0;i<4;i++){
		ptr_X_reakt_vodica[i]=X_reakt_vodica[i];
	}



	
	float **ptr_element1=NULL;
	ptr_element1=CreateMatrixFromRootMatrix(ptr_X_reakt_vodica, 0, 0, 3, 3);
	
	float *ptr_element2=NULL;
	ptr_element2=CreateArrayFromRootMatrix(ptr_X_reakt_vodica, 0, 3, 2, 3);
	
	float *ptr_element3=NULL;
	ptr_element3=CreateArrayFromRootMatrix(ptr_X_reakt_vodica, 3, 0, 3, 2);
	
	float element4 = 0.0;
	element4 = GetElementFromMatrix(ptr_X_reakt_vodica, 3, 3);
	element4=1/element4;
	
	float **ptr_novaMatrica=NULL;
	ptr_novaMatrica=SubtractMatrix(ptr_element1, MultiplyMatrixAndFloatNumber(MultiplyOneDimensionalMatrix(ptr_element2, ptr_element3, 3, 3), 3, 3, element4), 3, 3);
	
	printf("Matrica nova Matrica\n");
	for(i=0;i<3; ++i){
		for(j=0;j<3; ++j){
			printf("%3f\t", ptr_novaMatrica[i][j]);
		}
		printf("\n");
	}
	
	float Xs=0.0, Xm=0.0;
	Xs = CalculateXs(ptr_novaMatrica);
	Xm = CalculateXm(ptr_novaMatrica);
	
	float **ptr_novaMatrica2=NULL;
	ptr_novaMatrica2=CreateNovaMatrica2(ptr_novaMatrica, Xs, Xm);
	
	printf("Matrica nova Matrica 2\n");
	for(i=0;i<3; ++i){
		for(j=0;j<3; ++j){
			printf("%3f\t", ptr_novaMatrica2[i][j]);
		}
		printf("\n");
	}
	
	PrintXoXiXd(Xs, Xm);
	
	float Dm=0.0;
	Dm = CalculateDm(Dab, Dac, Dbc);
	
	float Ld=0.0;
	Ld = CalculateLd(Dm, CalculateDs(rf));
	
	float Xd=0.0;
	Xd = CalculateXd(Ld);
	PrintXd(Xd);
	
	return 0;
}

float CalculateDm(float Dab, float Dac, float Dbc){
	return pow((Dab * Dac * Dbc), (1.0/3.0));
}

float CalculateDs(float rfaznog){
	return 0.78 * rfaznog;
}

float CalculateLd(float Dm, float Ds){
	return 2 * (pow(10.0, -4.0)) * log(Dm/Ds);
}

float CalculateXd(float Ld){
	return 2 * pi * 50 * Ld;
}

void PrintXd(float Xd){
	printf("Xd = w * Ld = 2 * pi * 50 * Ld = %3f\n", Xd);
}

void PrintXoXiXd(float Xs, float Xm){
	
	printf("Xo = Xs + 2Xm = %3f\n", (Xs + 2*Xm));
	printf("Xi = Xd = Xs - Xm = %3f\n", (Xs - Xm));
}

float CalculateXs(float **ptr_novaMatrica){
	float Xs=0.0;
	Xs = ( GetElementFromMatrix(ptr_novaMatrica, 0, 0) + GetElementFromMatrix(ptr_novaMatrica, 1, 1) + GetElementFromMatrix(ptr_novaMatrica, 2, 2) ) / 3;
	return Xs;
}

float CalculateXm(float **ptr_novaMatrica){
	float Xm=0.0;
	Xm = ( GetElementFromMatrix(ptr_novaMatrica, 0, 1) + GetElementFromMatrix(ptr_novaMatrica, 0, 2) + GetElementFromMatrix(ptr_novaMatrica, 1, 2) ) / 3;
	return Xm;
}

float **CreateNovaMatrica2(float **ptr_novaMatrica, float Xs, float Xm){
	int i=0, j=0;
	float **ptr_NovaMatrica2=NULL;
	
	ptr_NovaMatrica2 = new float*[3];
	
	for(i=0;i<3; ++i){
		ptr_NovaMatrica2[i] = new float [3];
		
		for(j=0; j<3; ++j){
			if(i == j){
				*(*(ptr_NovaMatrica2 + i) + j) = Xs;
			}	
			else{
				*(*(ptr_NovaMatrica2 + i) + j) = Xm;
			}
		}
	}
	
	return ptr_NovaMatrica2;
}

float **SubtractMatrix(float **firstMatrix, float **secondMatrix, int rows, int columns){
	int i=0, j=0;
	float **ptr_NewMatrix=NULL;
	
	ptr_NewMatrix = new float*[3];
	
	for(i = 0; i < rows; ++i){
		
		ptr_NewMatrix[i] = new float [3];
		for(j = 0; j < columns; ++j){
	
			*(*(ptr_NewMatrix + i) + j) = *(*(firstMatrix + i) + j) - *(*(secondMatrix + i) + j);
			
		}
	}
	
	return ptr_NewMatrix;
}

float **MultiplyMatrixAndFloatNumber(float **matrix, int rows, int columns, float number){
	int i=0, j=0;
	
	for(i = 0; i < rows; ++i){
		
		for(j = 0; j < columns; ++j){
	
			*(*(matrix + i) + j) = *(*(matrix + i) + j) * number;
			
		}
	}
	
	return matrix;
}

float **MultiplyOneDimensionalMatrix(float *firstMatrix, float *secondMatrix, int rowFirst, int columnSecond){
	int i=0, j=0;
	float **ptr_NewMatrix=NULL;
	
	ptr_NewMatrix = new float*[3];
	
	for(i = 0; i < rowFirst; ++i){
		
		ptr_NewMatrix[i] = new float [3];
		for(j = 0; j < columnSecond; ++j){
	
			*(*(ptr_NewMatrix + i) + j) = firstMatrix[i] * secondMatrix[j];
			
		}
	}
	
	return ptr_NewMatrix;
}

float GetElementFromMatrix(float **matrix, int row, int column){

	return *((matrix[row]) + column);
}


float* CreateArrayFromRootMatrix(float **rootMatrix, int initialRow, int initialColumn, int finalRow, int finalColumn){
	int rootRow=initialRow, rootColumn=initialColumn;
	float *ptr_NewMatrix=NULL;
	
	if(initialRow != finalRow){
	ptr_NewMatrix = new float[finalRow];
	
	for(rootRow=initialRow; rootRow<=finalRow; rootRow++){
		*(ptr_NewMatrix + rootRow) = *((rootMatrix[rootRow]) + rootColumn);
	}
	}
	
	else if (initialColumn != finalColumn) {
	ptr_NewMatrix = new float[finalColumn];
	for(rootColumn=initialColumn; rootColumn<=finalColumn; rootColumn++){
		*(ptr_NewMatrix + rootColumn) = *((rootMatrix[rootRow]) + rootColumn);
	}
	}
	
	else {
		printf("Error! Initial and final row/clolumn must be same to get array from matrix!\n");
		return 0;
	}
	
	return ptr_NewMatrix;
}


float** CreateMatrixFromRootMatrix(float **rootMatrix, int initialRow, int initialColumn, int finalRow, int finalColumn){
	int i=0, j=0;
	float **ptr_NewMatrix=NULL;
	
	ptr_NewMatrix = new float*[3];
	
	for(i=initialRow; i<finalRow; i++){
		ptr_NewMatrix[i] = new float [3];
		for(j=initialColumn ; j<finalColumn ;j++){
			*(*(ptr_NewMatrix + i) + j) = *((rootMatrix[i]) + j);
		}
	}
	return ptr_NewMatrix;
}

