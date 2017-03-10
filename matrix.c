#include <stdio.h>
#include <stdlib.h>

void print_matrix(int** A, int col, int row); 		//Функция для печати матрицы

int main(int argc, char *argv[]) {
if (argc!=3){
  printf("A data-entry error. \n");		//Проверка количества введеных данных через консоль
  return EXIT_FAILURE;
 }

FILE* matrix_1 = fopen (argv[1],"r");
FILE* matrix_2 = fopen (argv[2],"r");

if ((!matrix_1)||(!matrix_2)){  	//Проверка самих файлов
  printf("Bug with files. \n");
  return EXIT_FAILURE;
 }

int col_1,row_1,col_2,row_2;		// Ввод количества строк и столбцов певрой и второй матрицы
fscanf(matrix_1,"%i",&col_1);
fscanf(matrix_1,"%i",&row_1);
fscanf(matrix_2,"%i",&col_2);
fscanf(matrix_2,"%i",&row_2);

if(row_1!=col_2){
  printf("Error in matrix. They are not consisent. \n");  //Проверяется возоможность умножения матриц
  return EXIT_FAILURE;
 }

int** m_1=(int**)malloc(sizeof(int*)*col_1);		//Выделение памяти под строки и проверка(m_1)
if(!m_1){
  printf("Bug with memory allocation in m_1. \n");
  return EXIT_FAILURE;
  }

for(int i=0;i<col_1;i++){		//Выделение памяти под столцы (+заполнение 0) и проверка (m_1)
  m_1[i]=(int*)calloc(row_1,sizeof(int));
  if(!m_1[i]){
    printf("Bug with memory allocation in m_1[%d]. \n",i);
    return EXIT_FAILURE;
    }
  }

int** m_2=(int**)malloc(sizeof(int*)*col_2);		//Выделение памяти под строки и проверка (m_2)
if(!m_2){
  printf("Bug with memory allocation in m_2. \n");
  return EXIT_FAILURE;
  }

for(int i=0;i<col_2;i++){ 		//Выделение памяти под столбцы (+заполнение 0) и проверка (m_2)
  m_2[i]=(int*)calloc(row_2,sizeof(int));
    if(!m_2[i]){
    printf("Bug with memory allocation in m_2[%d]. \n",i);
    return EXIT_FAILURE;
    }

  }

int** m_res=(int**)malloc(sizeof(int*)*col_1);		//Выделение памяти под строки и проверка (m_res)
if(!m_res){
  printf("Bug with memory allocation in m_res. \n");
  return EXIT_FAILURE;
  }

for(int i=0;i<col_1;i++){		//Выделение памяти под столбцы (+заполнение 0) и проверка (m_res)
  m_res[i]=(int*)calloc(row_2,sizeof(int));
  if(!m_res[i]){
    printf("Bug with memory allocation in m_res[%d]. \n",i);
    return EXIT_FAILURE;
    }
  }

for (int i=0; i<col_1;i++)	//Считывание значений с файла и заполнение m_1
  for(int j=0;j<row_1;j++)
    fscanf(matrix_1,"%i",&m_1[i][j]);

for (int i=0; i<col_2;i++)	//Считывание значений с файла и заполнение m_2
  for(int j=0;j<row_2;j++)
    fscanf(matrix_2,"%i",&m_2[i][j]);

for (int i=0;i<col_1;i++) 	//Перемножение матриц (m_1,m_2) и последующая запись результата в матрицу m_res
  for (int j=0; j<row_2; j++){
    m_res[i][j]=0;
    for(int k=0;k<row_1;k++)
      m_res[i][j]=m_res[i][j]+m_1[i][k]*m_2[k][j];
  }

print_matrix(m_1,col_1,row_1);		//Печать всех матриц
print_matrix(m_2,col_2,row_2);
print_matrix(m_res,col_1,row_2);
return 0;
}

void print_matrix(int** A, int col, int row){
int  i, j;
for (i = 0; i < col; i++){
  for (j = 0; j < row; j++)
    printf("%5d", A[i][j]);
    printf("\n");
  }
printf("\n");
}
