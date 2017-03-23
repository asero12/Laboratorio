#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct box{ // tipo de dato 'box'.
	char label; // interfaz de la casilla || # = casilla oculta, M = mina, B = bandera, X = número de minas en las casillas inmediatamente adyacentes.
	char type; // tipo de la casilla || c = casilla oculta, M = mina, B = bandera, X = número de minas en las casillas inmediatamente adyacentes.
	int mineNumber; // Numero de minas en las casillas inmediatamente adyacentes.
}box;
void fillMatrixUpCovered(int z, int n, box **M){
/*Llenará cada casilla de la matriz*/
	int i, j;//Contadores
	/*Llenará las casillas sin revisar*/
	for( i=0 ; i < z ; i++ ){
		for ( j = 0 ; j < n ; j++ ){
			M[i][j].label = '#'; // Itera sobre la matriz dándole a cada casilla la interfaz de un matriz oculta.
			M[i][j].type = 'c';//Itera sobre la matriz, dándole a las casillas tipo C.
			M[i][j].mineNumber = 0;//Itera sobre la matriz, dándole a las casillas 0 minas alrededor
		}
	}
}
void fillMatrixUpMines(int z, int n, box **M, int numberOfMines){
	srand(time(NULL));
	int i, j, w; // Contadores
	for ( w = 0 ; w <= numberOfMines ; w++ ){
		i = rand()%z; // columna random.
		j = rand()%n; //Fila Random.
		M[i][j].type = 'm' ; // Le da a casillas random el tipo mina
	}
}
void fillMatrixUpNumbers(int z, int n, box **M){
	//Esta función llena las casillas con el número de las casillas que están inmediatamente al rededor
	int i, j;
	/*casillas interiores*/
	for( i=1 ; i < z-1 ; i++ ){
		for ( j = 1 ; j < n-1 ; j++ ){
			if ( M[i-1][j-1].type == 'm' ){
			M[i][j].mineNumber = M[i][j].mineNumber + 1 ;
			}
		}
	}
	for( i=1 ; i < z-1 ; i++ ){
		for ( j = 1 ; j < n-1 ; j++ ){
			if ( M[i-1][j].type == 'm' ){
				M[i][j].mineNumber=M[i][j].mineNumber+1;
			}
		}
	}
	for( i=1 ; i < z-1 ; i++ ){
		for ( j = 1 ; j < n-1 ; j++ ){
			if ( M[i-1][j+1].type == 'm' ){
				M[i][j].mineNumber=M[i][j].mineNumber+1;
			}
		}
	}
	for( i=1 ; i < z-1 ; i++ ){
		for ( j = 1 ; j < n-1 ; j++ ){
			if ( M[i][j+1].type == 'm' ){
				M[i][j].mineNumber=M[i][j].mineNumber+1;
			}
		}
	}
	for( i=1 ; i < z-1 ; i++ ){
		for ( j = 1 ; j < n-1 ; j++ ){
			if ( M[i+1][j+1].type == 'm' ){
				M[i][j].mineNumber=M[i][j].mineNumber+1;
			}
		}
	}
	for( i=1 ; i < z-1 ; i++ ){
		for ( j = 1 ; j < n-1 ; j++ ){
			if ( M[i+1][j].type == 'm' ){
				M[i][j].mineNumber=M[i][j].mineNumber+1;
			}
		}
	}
	for( i=1 ; i < z-1 ; i++ ){
		for ( j = 1 ; j < n-1 ; j++ ){
			if ( M[i+1][j-1].type == 'm' ){
				M[i][j].mineNumber=M[i][j].mineNumber+1;
			}
		}
	}
	for( i=1 ; i < z-1 ; i++ ){
		for ( j = 1 ; j < n-1 ; j++ ){
			if ( M[i][j-1].type == 'm' ){
				M[i][j].mineNumber=M[i][j].mineNumber+1;
			}
		}
	}
	/*Casillas de las puntas*/
	//Punta superior izquierda
	if ( M[z-z][n-n+1].type == 'm' ){
		M[z-z][j-j].mineNumber = M[z-z][j-j].mineNumber+1;
	}
	if ( M[z-z+1][n-n+1].type == 'm' ){
		M[z-z][j-j].mineNumber = M[z-z][j-j].mineNumber+1;
	}
	if ( M[z-z+1][n-n].type == 'm' ) {
		M[z-z][n-n].mineNumber = M[z-z][j-j].mineNumber+1;
	}
	//Punta superior derecha.
	if( M[z-z+1][n-2].type == 'm' ){
		M[z-z][n-1].mineNumber = M[z-z][n-1].mineNumber + 1;
	}
	if( M[z-z+1][n-1].type == 'm' ){
		M[z-z][n-1].mineNumber = M[z-z][n-1].mineNumber + 1;
	}
	if( M[z-z][n-2].type == 'm' ){
		M[z-z][n-1].mineNumber = M[z-z][n-1].mineNumber + 1;
	}
	//Punta inferior izquierda.
	if ( M[z-2][n-n].type == 'm' ){
		M[z-1][n-n].mineNumber = M[z-1][n-n].mineNumber + 1;
	}
	if ( M[z-2][n-n+1].type == 'm' ){
		M[z-1][n-n].mineNumber = M[z-1][n-n].mineNumber + 1;
	}
	if ( M[z-1][n-n+1].type == 'm' ){
		M[z-1][n-n].mineNumber = M[z-1][n-n].mineNumber + 1;
	}
	//Punta inferior derecha.
	if( M[z-1][n-2].type == 'm' ){
		M[z-1][n-1].mineNumber = M[z-1][n-1].mineNumber + 1;
	}
	if( M[z-2][n-2].type == 'm' ){
		M[z-1][n-1].mineNumber = M[z-1][n-1].mineNumber + 1;
	}
	if( M[z-2][n-1].type == 'm' ){
		M[z-1][n-1].mineNumber = M[z-1][n-1].mineNumber + 1;
	}
	/*Bordes*/
	//Derecho;
	for ( i = 1; i < z-1 ; i++ ){
		if (M[i][n-n+1].type == 'm'){
			M[i][n-n].mineNumber = M[i][n-n].mineNumber + 1;
		}
	}
	for ( i = 1; i < z-1 ; i++ ){
		if (M[i-1][n-n].type == 'm'){
			M[i][n-n].mineNumber = M[i][n-n].mineNumber + 1;
		}
	}
	for ( i = 1; i < z-1 ; i++ ){
		if (M[i+1][n-n].type == 'm'){
			M[i][n-n].mineNumber = M[i][n-n].mineNumber + 1;
		}
	}
	for ( i = 1; i < z-1 ; i++ ){
		if (M[i+1][n-n+1].type == 'm'){
			M[i][n-n].mineNumber = M[i][n-n].mineNumber + 1;
		}
	}
	for ( i = 1; i < z-1 ; i++ ){
		if (M[i-1][n-n+1].type == 'm'){
			M[i][n-n].mineNumber = M[i][n-n].mineNumber + 1;
		}
	}
	//Izquierdo
	for ( i = 1; i < z-1 ; i++ ){
		if (M[i][n-2].type == 'm'){
			M[i][n-1].mineNumber = M[i][n-1].mineNumber + 1;
		}
	}
	for ( i = 1; i < z-1 ; i++ ){
		if (M[i-1][n-1].type == 'm'){
			M[i][n-1].mineNumber = M[i][n-1].mineNumber + 1;
		}
	}
	for ( i = 1; i < z-1 ; i++ ){
		if (M[i+1][n-1].type == 'm'){
			M[i][n-1].mineNumber = M[i][n-1].mineNumber + 1;
		}
	}
	for ( i = 1; i < z-1 ; i++ ){
		if (M[i+1][n-2].type == 'm'){
			M[i][n-1].mineNumber = M[i][n-1].mineNumber + 1;
		}
	}
	for ( i = 1; i < z-1 ; i++ ){
		if (M[i-1][n-2].type == 'm'){
			M[i][n-1].mineNumber = M[i][n-1].mineNumber + 1;
		}
	}
	//Superior
	for ( j = 1 ; j < n-1; j++ ){
		if( M[z-z+1][j].type == 'm' ){
			M[z-z][j].mineNumber = M[z-z][j].mineNumber + 1;
		}
	}
	for ( j = 1 ; j < n-1; j++ ){
		if( M[z-z][j-1].type == 'm' ){
			M[z-z][j].mineNumber = M[z-z][j].mineNumber + 1;
		}
	}
	for ( j = 1 ; j < n-1 ; j++ ){
		if( M[z-z][j+1].type == 'm' ){
			M[z-z][j].mineNumber = M[z-z][j].mineNumber + 1;
		}
	}
	for ( j = 1 ; j < n-1 ; j++ ){
		if( M[z-z+1][j+1].type == 'm' ){
			M[z-z][j].mineNumber = M[z-z][j].mineNumber + 1;
		}
	}
	for ( j = 1 ; j < n-1 ; j++ ){
		if( M[z-z+1][j-1].type == 'm' ){
			M[z-z][j].mineNumber = M[z-z][j].mineNumber + 1;
		}
	}
	//inferior
	for ( j = 1 ; j < n-1 ; j++ ){
		if ( M[z-2][j].type == 'm' ){
			M[z-1][j].mineNumber =  M[z-1][j].mineNumber + 1;
		}
	}
	for ( j = 1 ; j < n-1 ; j++ ){
		if ( M[z-1][j+1].type == 'm' ){
			M[z-1][j].mineNumber =  M[z-1][j].mineNumber + 1;
		}
	}
	for ( j = 1 ; j < n-1 ; j++ ){
		if ( M[z-1][j-1].type == 'm' ){
			M[z-1][j].mineNumber =  M[z-1][j].mineNumber + 1;
		}
	}
	for ( j = 1 ; j < n-1 ; j++ ){
		if ( M[z-2][j-1].type == 'm' ){
			M[z-1][j].mineNumber =  M[z-1][j].mineNumber + 1;
		}
	}
	for ( j = 1 ; j < n-1 ; j++ ){
		if ( M[z-2][j+1].type == 'm' ){
			M[z-1][j].mineNumber =  M[z-1][j].mineNumber + 1;
		}
	}
}
void printMatrix(int z, int n, box **M){
	/*Imprime la matriz*/
	int i, j; 
	for( i=0 ; i < z ; i++ ){
		printf("\n");
        printf(" |");
		for ( j = 0 ; j < n ; j++ ){
			printf(" | %c | ", M[i][j].label );//Imprime cada celda de la matriz
		}
		printf(" |");
		printf("\n");
	}
}
int estado = 0;
void lose(){
	printf("Sorry, papu, perdiste.");
	estado = 1; 
}

void uncoverBox(int i, int j, box **M, int z, int n){
	if ( M[i][j].type == 'c' ){
		M[i][j].label = (char)(M[i][j].mineNumber+48);
	}
	if ( M[i][j].type == 'm' ){
		M[i][j].label = M[i][j].type;
		lose();
	}
	printMatrix(z,n,M);
}
void setFlag(int i, int j, box **M, int z, int n){
	M[i][j].label = 'B';
	printMatrix(z,n,M);
}
void eraseFlag(int i, int j, box **M, int z, int n){
	M[i][j].label = '#';
	printMatrix(z,n,M);
}
void actionBox(int z, int n, box **M){
	int i, j;
	char a;
	printf("Ingrese la coordenada de la fila : ");
	scanf("%i", &i);
	printf("Ingrese la coordenada de la columna : ");
	scanf("%i", &j);
	printf("Ingrese la acción a realizar (d = destapar , b = poner bandera, q = quitar bandera) : ");
	scanf(" %c", &a);
	if ( (( i >= 0 ) && ( i <= z-1 )) && (( j >= 0 ) && ( j <= n-1 )) && (a =='d') && ( M[i][j].label != 'B' ) ){
		system("clear");
		uncoverBox(i,j,M,z,n);
	}
	else if ( (( i >= 0 ) && ( i <= z-1 )) && (( j >= 0 ) && ( j <= n-1 )) && (a == 'b') && ( M[i][j].label != 'B' ) && ( M[i][j].label != M[i][j].mineNumber+48 ) ){
		system("clear");
		setFlag(i,j,M,z,n);
	}
	else if( (( i >= 0 ) && ( i <= z-1 )) && (( j >= 0 ) && ( j <= n-1 )) && (a == 'q') && ( M[i][j].label == 'B' ) ){
		system("clear");
		eraseFlag(i,j,M,z,n);
	}
	else{
		printf("No válido, repetir :\n");
		actionBox(i,j,M);
	}
}
void main(int argc, char *argv[]){ // main recibe argumentos de la linea de comandos argv[1] será Z, argv[2] será N.
	/*En main se creará la matriz como tal, para llamar posteriormente las otras funciones*/
	int z = atoi(argv[1]), n = atoi(argv[2]); //Se le asigna argv[1] a Z, y argv[2] a n.
	box **M; //Se declara la existencia de M, tal que M es un puntero que apunta a punteros de box.
	M = ( box ** ) malloc(z * sizeof(box));//Se reservan z espacios de tamaños enteros, que apuntarán a apuntadores.
	int row; //Se declara la existencia de la variable row, que recorrera los z elementos de M, creando en cada uno un array de n elementos
	for ( row = 0; row < z ; row++ ){ 
		M[row] = (box *) malloc( n * sizeof(box)); //Se itera sobre los z espacios de M, dándole a cada uno un array de n espacios. 
	}
	fillMatrixUpCovered(z,n,M); //Se llama la función que llenará las casillas de la matriz. Se le pasa z y n numero de casillas, y la matriz.
	fillMatrixUpMines(z,n,M,z);
	fillMatrixUpNumbers(z,n,M);
	printMatrix(z,n,M);//Se llama la función que imprimirá la matriz. Se le pasa z y n numero de casillas, y la matriz.
	while( estado == 0 ){
		printf("\n");
		actionBox(z,n,M);
	}
}