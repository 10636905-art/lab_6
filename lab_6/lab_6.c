#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void task933();
void task947();
void task973();
void task1017();
void task968();
//933, 947, 973, 1017, 968.

int  main() {
	srand((unsigned int)time(NULL));
	printf("Мої завдання: ");
	
	int K = 16;

	for (int N = 1; N < 6; N++) {
		int num = ((N * N * N + 7 * N + K * K) % 117) + 903;

		if (N < 5) {
			printf("%d, ", num);
		}
		else {
			printf("%d.", num);
		}
	}

	 task933();
	task947();
	task973();
	task1017();
	task968();

	return 0;
}

void task933() {
	printf("\n\nЗавдання 933: Відсортувати непарні стовпці масиву за зростанням.");
	
	int rows = rand() % 8 + 2;

	int columns = rand() % 8 + 2;

	int** matrix = (int**)malloc(rows * sizeof(int*));

	if (matrix == NULL) {
		return;
	}

	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*)malloc(columns * sizeof(int));

		if (matrix[i] == NULL) {
			return;
		}
	

		for (int j = 0; j < columns; j++) {
			matrix[i][j] = rand() % 100 ;
		}
	}

	printf("\nПочаткова матриця: \n{");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (!(i == rows - 1 && j == columns - 1)) {
				if (j < columns - 1) {
					printf("%d, ", matrix[i][j]);
				}
				else {
					printf("%d.\n", matrix[i][j]);
				}
			}
			else {
				printf("%d.}", matrix[i][j]); 
			}
		}
	}

	for (int j = 0; j < columns; j += 2) {
		for (int z = 0; z < rows - 1; z++) {
			for (int i = 0; i < rows - 1; i++) {
				if (matrix[i][j] > matrix[i + 1][j]) {
					int a = matrix[i][j];
					matrix[i][j] = matrix[i + 1][j];
					matrix[i + 1][j] = a;
				}
			}
		}
	}

	printf("\nВідсортована матриця: \n{");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (!(i == rows - 1 && j == columns - 1)) {
				if (j < columns - 1) {
					printf("%d, ", matrix[i][j]);
				}
				else {
					printf("%d.\n", matrix[i][j]);
				}
			}
			else {
				printf("%d.}", matrix[i][j]);
			}
		}
	}

	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}

	free(matrix);
}

void task947() {
	printf("\n\nЗавдання 947: Визначити: а) координати першого максимального елемента головної діагоналі масиву; б) координати першого мінімального елемента побічної діагоналі масиву; в) координати останнього мінімального елемента головної діагоналі масиву; г) координати останнього максимального елемента побічної діагоналі масиву. Початковий масив: \n");
	
	int rows = rand() % 8 + 2;

	int columns = rows;

	int** matrix = (int**)malloc(rows * sizeof(int*));

	if (matrix == NULL) {
		return;
	}

	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*)malloc(columns * sizeof(int));

		if (matrix[i] == NULL) {
			return;
		}

		for (int j = 0; j < columns; j++) {
			matrix[i][j] = rand() % 100;
		}
	}

	printf("\nПочаткова матриця: \n{");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (!(i == rows - 1 && j == columns - 1)) {
				if (j < columns - 1) {
					printf("%d, ", matrix[i][j]);
				}
				else {
					printf("%d.\n", matrix[i][j]);
				}
			}
			else {
				printf("%d.}", matrix[i][j]);
			}
		}
	}

	//a) координати першого максимального елемента головної діагоналі масиву

	int mainDiagMatrix_max = matrix[0][0], coordinates_max_main = 0;

	for (int i = 0; i < rows; i++) {
		if (matrix[i][i] > mainDiagMatrix_max) {
			mainDiagMatrix_max = matrix[i][i];
			coordinates_max_main = i;
		}
	}

	printf("\nа)Координати першого максимального елемента головної діагоналі: (%d; %d).", coordinates_max_main + 1, coordinates_max_main + 1);

	//б) координати першого манімального елемента побічної діагоналі масиву

	int antiDiagMatrix_min = matrix[0][columns - 1], coordinates_min_anti = 0;

	for (int i = 0; i < rows; i++) {
		if (matrix[i][columns - i - 1] < antiDiagMatrix_min) {
			antiDiagMatrix_min = matrix[i][columns - i - 1];
			coordinates_min_anti = i;
		}
	}

	printf("\nб)Координати першого мінімального елемента побічної діагоналі: (%d; %d).", coordinates_min_anti + 1, columns - coordinates_min_anti);

	//в) координати останнього мінімального елемента головної діагоналі масиву

	int mainDiagMatrix_min = matrix[0][0], coordinates_min_main = 0;

	for (int i = 0; i < rows; i++) {
		if (matrix[i][i] <= mainDiagMatrix_min) {
			mainDiagMatrix_min = matrix[i][i];
			coordinates_min_main = i;
		}
	}

	printf("\nв)Координати останнього мінімального елемента головної діагоналі: (%d; %d).", coordinates_min_main + 1, coordinates_min_main + 1);

	//г) координати останнього максимального елемента головної діагоналі

	int antiDiagMatrix_max = matrix[0][columns - 1], coordinates_max_anti = 0;

	for (int i = 0; i < rows; i++) {
		if (matrix[i][columns - i - 1] >= antiDiagMatrix_max) {
			antiDiagMatrix_max = matrix[i][columns - i - 1];
			coordinates_max_anti = i;
		}
	}

	printf("\nг)Координати останнього максимального елемента побічної діагоналі: (%d; %d).", coordinates_max_anti + 1, columns - coordinates_max_anti);

	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}

	free(matrix);
}

void task973() {
	printf("\n\nЗавдання 973: побудувати квадратну матрицю порядку 2n: ");

	int n = rand() % 8 + 2;

	int** matrix = (int**)malloc((2 * n) * sizeof(int*));

	if (matrix == NULL) {
		return;
	}

	for (int i = 0; i < 2 * n; i++) {
		matrix[i] = (int*)malloc((2 * n) * sizeof(int));
		
		if (matrix[i] == NULL) {
			return;
		}

		for (int j = 0; j < 2 * n; j++) {
			if (i < n && j < n) {
				matrix[i][j] = 1;
			}
			else if (i < n && j >= n) {
				matrix[i][j] = 2;
			}
			else if (i >= n && j < n) {
				matrix[i][j] = 3;
			}
			else if (i >= n && j >= n) {
				matrix[i][j] = 4;
			}
		}
	}

	printf("\nОтримана матриця: {");

	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if (!(i == 2 * n - 1 && j == 2 * n - 1)) {
				if (j < 2 * n - 1) {
					printf("%d, ", matrix[i][j]);
				}
				else {
					printf("%d.\n", matrix[i][j]);
				}
			}
			else {
				printf("%d.}", matrix[i][j]);
			}
		}
	}

	for (int i = 0; i < 2 * n; i++) {
		free(matrix[i]);
	}

	free(matrix);
}

void task1017() {
	printf("\n\nЗавдання 1017: Визначити номери рядків матриці, в яких знаки елементів чергуються.\nСама матриця: \n{");

	int rows = rand() % 10 + 2;

	int columns = rand() % 4 + 2;

	int** matrix = (int**)malloc(rows * sizeof(int*));

	if (matrix == NULL) {
		return;
	}

	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*)malloc(columns * sizeof(int));

		if (matrix[i] == NULL) {
			return;
		}

		for (int j = 0; j < columns; j++) {
			matrix[i][j] = rand() % 200 - 100;
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (!(i == rows - 1 && j == columns - 1)) {
				if (j < columns - 1) {
					printf("%d, ", matrix[i][j]);
				}
				else {
					printf("%d.\n", matrix[i][j]);
				}
			}
			else {
				printf("%d.}", matrix[i][j]);
			}
		}
	}

	printf("\nЦе рядки під номером: \n");

	int count = 0;

	for (int i = 0; i < rows; i++) {
		int a = 1;
		for (int j = 0; j < columns - 1; j++) {
			if (matrix[i][j] * matrix[i][j + 1] >= 0) {
				a = 0;
				break;
			}
		}
		if (a == 1) {
			printf("%d, ", i + 1);
			count += 1;
		}
	}
	if (count == 0) {
		printf("Номера з таким рядком не існує.");
	}


	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

void task968() {
	printf("\n\nЗавдання 968: У двовимірному масиві зберігається інформація про оцінки кожного з 20 учнів класу з того чи іншого предмета( у першому рядку - інформація про оцінки першого учня, у другому - другого). Загальна кількість предметів дорівнює 10. Визначити середню оцінку п'ятого учня.\nОцінки всіх учнів: \n{");
	
	int** matrix = (int**)malloc(20 * sizeof(int*));

	if (matrix == NULL) {
		return;
	}

	for (int i = 0; i < 20; i++) {
		matrix[i] = (int*)malloc(10 * sizeof(int));

		if (matrix[i] == NULL) {
			return;
		}

		for (int j = 0; j < 10; j++) {
			matrix[i][j] = rand() % 12 + 1;
		}
	}

	int sum_all5 = 0;

	for (int j = 0; j < 10; j++) {
		sum_all5 += matrix[4][j];
	}
	
	double average = (sum_all5 / 10.0);

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			if (!(i == 20 - 1 && j == 10 - 1)) {
				if (j < 10 - 1) {
					printf("%d, ", matrix[i][j]);
				}
				else {
					printf("%d.\n", matrix[i][j]);
				}
			}
			else {
				printf("%d.}", matrix[i][j]);
			}
		}
	}

	printf("\nСередня оцінка у п'ятого учня - %.1f.", average);

	for (int i = 0; i < 20; i++) {
		free(matrix[i]);
	}

	free(matrix);
}