#include <iostream> //DEYMI DAYANA MARTÌNEZ LÒPEZ
//					CARNE: 9941-24-13290
using namespace std;

// =========================
// NODE STRUCTURE
// =========================
struct TreeNode {
    int key;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

// =========================
// FUNCTION TO CREATE NODE
// =========================
TreeNode* createNode(int val) {
    TreeNode* node = new TreeNode();
    node->key = val;
    node->leftChild = 0;
    node->rightChild = 0;
    return node;
}

// =========================
// FUNCTION TO INSERT IN BST
// =========================
TreeNode* insertNode(TreeNode* root, int val) {
    if (root == 0) {
        return createNode(val);
    }

    if (val < root->key) {
        root->leftChild = insertNode(root->leftChild, val);
    } else {
        root->rightChild = insertNode(root->rightChild, val);
    }

    return root;
}

// =========================
// INORDER TRAVERSAL
// LEFT - ROOT - RIGHT
// =========================
void traverseInOrder(TreeNode* root) {
    if (root != 0) {
        traverseInOrder(root->leftChild);
        cout << root->key << " ";
        traverseInOrder(root->rightChild);
    }
}

// =========================
// PREORDER TRAVERSAL
// ROOT - LEFT - RIGHT
// =========================
void traversePreOrder(TreeNode* root) {
    if (root != 0) {
        cout << root->key << " ";
        traversePreOrder(root->leftChild);
        traversePreOrder(root->rightChild);
    }
}

// =========================
// POSTORDER TRAVERSAL
// LEFT - RIGHT - ROOT
// =========================
void traversePostOrder(TreeNode* root) {
    if (root != 0) {
        traversePostOrder(root->leftChild);
        traversePostOrder(root->rightChild);
        cout << root->key << " ";
    }
}

// =========================
// FUNCTION TO FREE MEMORY
// =========================
void freeTree(TreeNode* root) {
    if (root != 0) {
        freeTree(root->leftChild);
        freeTree(root->rightChild);
        delete root;
    }
}

// =========================
// MAIN FUNCTION
// =========================
int main() {
    TreeNode* treeRoot = 0;
    int choice;
    int inputVal;

    do {
    cout << "\n--- MENU ---";
cout << "\n1. Insertar valor";
cout << "\n2. Mostrar InOrden";
cout << "\n3. Mostrar PreOrden";
cout << "\n4. Mostrar PostOrden";
cout << "\n5. Mostrar todos los recorridos";
cout << "\n6. Salir";
cout << "\nSeleccione una opcion: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "ingrese valor ";
                cin >> inputVal;
                treeRoot = insertNode(treeRoot, inputVal);
                cout << "valor insertado.\n";
                break;

            case 2:
                if (treeRoot == 0) {
                    cout << "el arbol esta vacio.\n";
                } else {
                    cout << "InOrder : ";
                    traverseInOrder(treeRoot);
                    cout << endl;
                }
                break;

            case 3:
                if (treeRoot == 0) {
                    cout << "el arbol esta vacio.\n";
                } else {
                    cout << "PreOrder : ";
                    traversePreOrder(treeRoot);
                    cout << endl;
                }
                break;

            case 4:
                if (treeRoot == 0) {
                    cout << "el arbol esta vacio.\n";
                } else {
                    cout << "PostOrder : ";
                    traversePostOrder(treeRoot);
                    cout << endl;
                }
                break;

            case 5:
                if (treeRoot == 0) {
                    cout << "el arbol esta vacio.\n";
                } else {
                    cout << "InOrder : ";
                    traverseInOrder(treeRoot);
                    cout << endl;

                    cout << "PreOrder : ";
                    traversePreOrder(treeRoot);
                    cout << endl;

                    cout << "PostOrder : ";
                    traversePostOrder(treeRoot);
                    cout << endl;
                }
                break;

            case 6:
                cout << "salida del programa...\n";
                break;

            default:
                cout << "Opcion invalida. Intente otra vez.\n";
                break;
        }

    } while (choice != 6);

    freeTree(treeRoot);

    return 0;
}
