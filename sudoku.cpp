#include <iostream>

using namespace std;

void init2dArray(int*** ptr, int ROW, int COL) {
	*ptr = new int* [ROW];
	for (int i = 0; i < ROW; i++) {
		(*ptr)[i] = new int[COL];
		for (int j = 0; j < COL; j++) {
			if (rand() % 4 != 3) {
				(*ptr)[i][j] = (rand() % 9) + 1;
				int unique = 0;

				while (unique == 0) {
					int uniqueness = 1;
					for (int z = 0; z < j; z++) {
						if ((*ptr)[i][z] == (*ptr)[i][j]) {
							uniqueness = 0;
						}
					}
					int block = 0;
					int line = 0;
					for (int z = 0; z < i % 3; z += 1) {
						int block = z;

						if (i / 3 == 1) {
							block += 3;
						}
						else if (i / 3 == 2) {
							block += 6;
						}


						for (int h = 0; h < 3; h++) {

							line = h;

							if (j / 3 == 1) {
								line += 3;
							}
							else if (j / 3 ==2) {
								line += 6;
							}

							if ((*ptr)[i][j] == (*ptr)[block][line]) {
								uniqueness = 0;
							}

						}
					
					}
					int block1 = 0;
					int line1 = 0;
					for (int g = 0; g < 3; g++) {
						block1 = g * 3;
						block1 = block1 + (i % 3);
						block1 %= 9;

						for (int h = 0; h < 3; h++){
							line1 = h * 3;
							line1 = line1 + (j % 3);
							line1 %= 9;
							if (i >= 3) {
								if (block1 >= i) {
									break;
								}
								if ((*ptr)[block1][line1] == (*ptr)[i][j] && block1 != i) {
									uniqueness = 0;
									cout << "Ununique column" << endl << endl;
								}
							}

							
						}
					}



					if (uniqueness == 0) {
						(*ptr)[i][j] = (rand() % 9) + 1;
					}
					else {
						cout << "Unique" << endl << endl;
						unique = 1;
					}
				}
			}
		}
	}
}


int main() {
	srand(time(NULL));
	int BLOCKS = 9;
	int ELEMENTS = 9;
	int** sudoku = nullptr;

	init2dArray(&sudoku, BLOCKS, ELEMENTS);
	int block_move = 0;
	int line_move = 0;
	for (int i = 0; i < 3; i++) {
		block_move = 3 * i;
		for (int j = 0; j < 3; j++) {
			line_move = 3 * j;
			for (int z = 0; z < 3; z++) {
				for (int h = 0; h < 3; h++) {
					if (sudoku[z + block_move][h + line_move] == -842150451) {
						cout << "\033[44m" << " " << "\033[40m" << "\t";
					}
					else {
						cout << sudoku[z + block_move][h + line_move] << "\t";
					}
				}
				cout << "\t";
			}
			cout << endl;
		}
		cout << endl;

	}
	delete[] sudoku;
	return 1;

}