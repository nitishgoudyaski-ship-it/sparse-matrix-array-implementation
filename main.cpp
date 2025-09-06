#include <iostream>
#include <vector>
using namespace std;

// Structure for a sparse matrix element
struct Element {
    int row, col, value;
};

class SparseMatrix {
private:
    int rows, cols, numNonZero;
    vector<Element> elements;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c), numNonZero(0) {}

    // Add a non-zero element
    void addElement(int r, int c, int val) {
        if (val != 0) {
            elements.push_back({r, c, val});
            numNonZero++;
        }
    }

    // Display matrix in triplet form
    void displayTriplet() {
        cout << "Row Col Value" << endl;
        for (auto &e : elements) {
            cout << e.row << "   " << e.col << "   " << e.value << endl;
        }
    }

    // Display full matrix
    void displayMatrix() {
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (k < numNonZero && elements[k].row == i && elements[k].col == j) {
                    cout << elements[k].value << " ";
                    k++;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    SparseMatrix sm(4, 5);

    // Adding non-zero elements
    sm.addElement(0, 1, 10);
    sm.addElement(1, 3, 20);
    sm.addElement(2, 2, 30);
    sm.addElement(3, 0, 40);

    cout << "Sparse Matrix in Triplet Form:" << endl;
    sm.displayTriplet();

    cout << "\nFull Matrix Representation:" << endl;
    sm.displayMatrix();

    return 0;
}
