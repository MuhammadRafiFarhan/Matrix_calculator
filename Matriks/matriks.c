#include "matriks.h"

void menu(){
	int pilihan;
	do {
//		system("cls");
		gotoxy(45,7); printf("============================");
		gotoxy(45,8);printf("========= MATRIX ========="); 
		gotoxy(45,9);printf("============================");
		gotoxy(45,12);printf("1. addition/subtraction");
		gotoxy(45,13);printf("2. multiplication");
		gotoxy(45,14);printf("3. scalar multiplication");
		gotoxy(45,15);printf("4. inverse"); 
		gotoxy(45,16);printf("5. triangular matrix"); 
		gotoxy(45,17);printf("6. SPL with OBE");
		gotoxy(45,18);printf("7. exit");
		gotoxy(45,11);printf("------ Main Menu ------");
		gotoxy(45,19);printf("Masukkan Pilihan anda : "); 
		scanf("%d", &pilihan);
		char dump = getchar();
		switch (pilihan){
			case 1:
				addsub_operation();
				getch();
				break;
			case 2:
				multiplication_operation();
				getch();
				break;	
			case 3:
				multiplication_scalar_operation();
				getch();
				break;		
			case 4:
				inverse();
				getch();
				break;
			case 5:
				triangular_matriks();
				getch();
				break;
			case 6:
				OBE_SPL();
				getch();
				break;	
		}
	} while(pilihan < 7);
	
} 

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int multiplication_operation(){
	int a[10][10], b[10][10], c[10][10], d[10][10], mul[10][10], row, col, i, j, k;
	system("cls"); 
    printf("Enter the rows number of both matrices\n");
    scanf("%d",&row);
    printf("Enter the columns number of both matrices\n");
    scanf("%d",&col);

        printf("Enter the elements of matrix A\n");
        for(i=0;i<row;i++){
            for(j = 0;j < col;j++){
                printf("Enter the element at [%d%d] : ",i,j);
                scanf("%d",&a[i][j]);
            }
            printf("\n");
		}

        printf("Enter the elements of matrix B\n");
        for(i=0;i<row;i++){
            for(j = 0;j < col;j++){
                printf("Enter the element at [%d%d] : ",i,j);
                scanf("%d",&b[i][j]);
            }
            printf("\n");
        }
	    
	printf("multiply of the matrix=\n");    
		for(i=0;i<row;i++){    
			for(j=0;j<col;j++){    
				mul[i][j]=0;    
				for(k=0;k<col;k++){    
					mul[i][j]+=a[i][k]*b[k][j];    
				}    
			}    
		}  
		  
		//for printing result    
		for(i=0;i<row;i++){    
			for(j=0;j<col;j++){    
				printf("%d\t",mul[i][j]);
			}	    
			printf("\n");    
		}    
		return 0;  
}

int multiplication_scalar_operation(){
	int i, j, rows, columns, Multiplication[10][10], Number;
    system("cls");
    
 	printf("\n Please Enter Number of rows and columns :");
 	scanf("%d %d", &i, &j);
 
 	printf("\n Please Enter the Matrix Elements \n");
 	for(rows = 0; rows < i; rows++){
   		for(columns = 0;columns < j;columns++){
      		scanf("%d", &Multiplication[rows][columns]);
    	}
  	}
   
 	printf("\n Please Enter the Multiplication Value  :  ");
 	scanf("%d", &Number);
 	  
 	for(rows = 0; rows < i; rows++){
   		for(columns = 0; columns < j; columns++){
      		Multiplication[rows][columns] = Number * Multiplication[rows][columns];    
   	 	}
  	}
 
 	printf("\n The Result of a Scalar Matrix Multiplication is : \n");
 	for(rows = 0; rows < i; rows++){
   		for(columns = 0; columns < j; columns++){
      		printf("%d \t ", Multiplication[rows][columns]);
    	}
    	printf("\n");
  	}
 	return 0;
}

int addsub_operation(){
	int a[10][10], b[10][10], c[10][10], d[10][10], row, col, i, j;
	system("cls");  
    printf("Enter the rows number of both matrices\n");
    scanf("%d",&row);
    printf("Enter the columns number of both matrices\n");
    scanf("%d",&col);

        printf("Enter the elements of matrix A\n");
        for(i=0;i<row;i++){
            for(j = 0;j < col;j++){
                printf("Enter the element at [%d%d] : ",i,j);
                scanf("%d",&a[i][j]);
            }
            printf("\n");
		}

        printf("Enter the elements of matrix B\n");
        for(i=0;i<row;i++){
            for(j = 0;j < col;j++){
                printf("Enter the element at [%d%d] : ",i,j);
                scanf("%d",&b[i][j]);
            }
            printf("\n");
        }

        printf("The addition of A and B is \n\t\t");
        for(i=0;i<row;i++){
            for(j = 0;j < col;j++){
                c[i][j]=a[i][j] + b[i][j];
            }
        }
        
        //printing addition
        for(i=0;i<row;i++){
            for(j = 0;j < col;j++){
                printf(" %d ",c[i][j]);
            }
            printf("\n\t\t");
        }

        printf("\nThe subtraction of A and B is \n\t\t");
        for(i=0;i<row;i++){
            for(j = 0;j < col;j++){
                d[i][j]=a[i][j] - b[i][j];
            }
        }

        //printing subtraction
        for(i=0;i<row;i++){
            for(j = 0;j < col;j++){
                printf(" %d ",d[i][j]);
            }
            printf("\n\t\t");
        }
		return 0;
}

// function for the calculation of determinant
float determinant(float a[25][25], float k){
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  
  if (k == 1){
     return (a[0][0]);
  }
  else{
     det = 0;
     for (c = 0; c < k; c++){
        m = 0;
        n = 0;
        for (i = 0;i < k; i++){
            for (j = 0 ;j < k; j++){
                b[i][j] = 0;
                if (i != 0 && j != c){
                   b[m][n] = a[i][j];
                   if (n < (k - 2)){
                    n++;
                	}	
					else{
                     n = 0;
                     m++;
                     }
                   }
               }
             }
             
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    } 
	return (det);
}
 
 
// function for cofactor calculation
void cofactor(float num[25][25], float f){
 float b[25][25], fac[25][25];
 int p, q, m, n, i, j;
 
 for (q = 0;q < f; q++){
   for (p = 0;p < f; p++){
     m = 0;
     n = 0;
     for (i = 0;i < f; i++){
       for (j = 0;j < f; j++){
          if (i != q && j != p){
            b[m][n] = num[i][j];
            if (n < (f - 2)){
             n++;
            }
            else{
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f);
}
 
 
///function to find the transpose of a matrix
void transpose(float num[25][25], float fac[25][25], float r){
  int i, j;
  float b[25][25], inverse[25][25], d;
 
  for (i = 0;i < r; i++){
     for (j = 0;j < r; j++){
         b[i][j] = fac[j][i];
        }
    }
    
  d = determinant(num, r);
  for (i = 0;i < r; i++){
     for (j = 0;j < r; j++){
        inverse[i][j] = b[i][j] / d;
        }
    }
    
   printf("\nThe inverse of matrix: \n");
   for (i = 0;i < r; i++){
     for (j = 0;j < r; j++){
         printf("\t%f", inverse[i][j]);
        }
    printf("\n");
    }
}

float inverse(){
	float a[25][25], n, d;
  	int i, j;
  	system("cls"); 
  	
  	printf("Enter the order of the Matrix: ");
  	scanf("%f", &n);
  	printf("Enter the elements of a matrix: \n");
  	for (i = 0;i < n; i++){
    	for (j = 0;j < n; j++){
        	scanf("%f", &a[i][j]);
        }
    }

    
  d = determinant(a, n);
  if (d == 0){
	printf("Since the determinant is zerp (0), therefor inverse is not possible.");
	}
  	else{
  		printf("the determinant for the matrix: %f", d);
   		cofactor(a, n);	
	}
}

// upper and lower triangular using gauss elimination (OBE)
int triangular_matriks(){
	int size,row,column,ctr1,ctr2;
	float matrix[10][10];
	float lowertriangle[10][10]; //matrices for lower triangle 
    float uppertriangle[10][10]; //matrices for Upper triangle 
	system("cls");
	
    printf("Enter The Size of The Matrix : \n");
    scanf("%d",&size);
    
    printf("Enter The Element\n");
    for(row=0;row<size;row++)
        for(column=0;column<size;column++)
            scanf("%f",&matrix[row][column]);
            
    
    for(row=0;row<size;row++)
        for(column=0;column<size;column++)
            {
                if(row>column)//initialise all elements of lower triangle in upper triangular matrix as 0
                     uppertriangle[row][column]=0.0;
                if(row<column)//initialise all elements of upper triangle in lower triangular matix as 0
                    lowertriangle[row][column]=0.0;
                if(row==column)//initialise all diagonal elements of lower triangular matrix as 1
                    lowertriangle[row][column]=1.0;
            }
            
/*The algorithm used later is from the book Introduction to algorithms by Thomas Cormen.For a better understaning one can
read this text under chapter Matrix Operations. */
    for(ctr1=0;ctr1<size;ctr1++){
        uppertriangle[ctr1][ctr1]=matrix[ctr1][ctr1];
            for(ctr2=ctr1+1;ctr2<size;ctr2++)
            {
                uppertriangle[ctr1][ctr2]=matrix[ctr1][ctr2];
                lowertriangle[ctr2][ctr1]=matrix[ctr2][ctr1]/uppertriangle[ctr1][ctr1];
            }
             for(row=ctr1+1;row<size;row++)
                for(column=ctr1+1;column<size;column++)
                    matrix[row][column]=matrix[row][column]-lowertriangle[row][ctr1]*uppertriangle[ctr1][column];
    }
    
    printf("UPPER TRIANGULAR MATRIX\n");
    for(row=0;row<size;row++)
    {//displays upper triangular matrix
        for(column=0;column<size;column++)
            printf("%.2f ",uppertriangle[row][column]);
        printf("\n");
    }
    
        printf("LOWER TRIANGULAR MATRIX\n");
    for(row=0;row<size;row++)
    {//displays lower triangular matrix
        for(column=0;column<size;column++)
            printf("%.2f ",lowertriangle[row][column]);
        printf("\n");
    }
    getch();
}

float OBE_SPL(){
	int i,j,k,n;
	float a[10][10], x[10], ratio;
	system("cls");
	
    printf("SPL solution using gauss jordan \n\n");

	/* read the number of elements input */
    printf("How many elements of the equations:");
	scanf("%d",&n);
	printf("%d\n",n);
	
	/* input the number of ax +- by +- cz = n */
	printf("\nInput Coefficients a[i, j+1], row-wise\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n+1;j++){
        	scanf("%f",&a[i][j]);
    	}
	}
    printf("\n\n");
    
    /* output the number of ax, by, and cz */
	for(i=1;i<=n;i++){
    	for(j=1;j<=n+1;j++){
        	printf("\t%10.0f",a[i][j]);
		}
		printf("\n\n");
	}

	/* Applying Gauss Jordan Elimination */
		 for(i=1;i<=n;i++){
			  if(a[i][i] == 0.0){
				   printf("Mathematical Error!");
				   exit(0);
			  }
			  for(j=1;j<=n;j++){
				   if(i!=j){
					    ratio = a[j][i]/a[i][i];
					    for(k=1;k<=n+1;k++){
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }
		 
		 /* Obtaining Solution */
		 for(i=1;i<=n;i++){
		  	x[i] = a[i][n+1]/a[i][i];
		 }
		 
		 /* Displaying Solution */
		 printf("\nSolution:\n");
		 for(i=1;i<=n;i++){
		  	printf("x[%d] = %0.3f\n",i, x[i]);
		 }
		 getch();
		 return(0);
}
