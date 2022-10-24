//Programa que crea un arbol AVL
//Leonardo Millán Velázquez A01639823

#include <iostream>
using namespace std;

template <class T>
class NodeTree { 
  public: 
      T data; 
      NodeTree<T>* left;
      NodeTree<T>* right;
      int height;
      NodeTree();
      NodeTree(T);
}; 

template<class T>
  NodeTree<T>::NodeTree(){
    left = nullptr;
    right = nullptr;
    height = 1;
  }
  template<class T>
  NodeTree<T>::NodeTree(T val){
      data = val;
      left = nullptr;
      right = nullptr;
      height = 1;
  }

 template <class T>
  class AVLTree { 
  private:
      NodeTree<T> *root;
      void preorder(NodeTree<T>* nodo);
      void postorder(NodeTree<T>* nodo);
      void inorder(NodeTree<T>* nodo);
      
      // AVL methods
      int max(int a, int b);
      NodeTree<T> *rightRotate(NodeTree<T> *y);
      NodeTree<T> *leftRotate(NodeTree<T> *x);
      int getBalance(NodeTree<T> *N);

  public: 
      AVLTree();
      ~AVLTree();
      void clearMemory(NodeTree<T> *p);
      bool search(T valor);
      void insert(T valor);
      NodeTree<T> *insertRec(NodeTree<T> *r, T valor);
      void callPreorder();
      void callPostorder();
      void callInorder(); 
      // AVL methods
      int height(NodeTree<T> *N);
      
      
  }; 

  template<class T>
  AVLTree<T>::AVLTree() {
    cout << "Creando un arbol AVL vacio: " <<  this << endl;
    root = nullptr;
  }

  template<class T>
  AVLTree<T>::~AVLTree() {
    cout << "Liberando memoria del arbol AVL: " << this << endl;
    clearMemory(root);
  }

  template<class T>
  void AVLTree<T>::clearMemory(NodeTree<T> *p) {
    if (p != NULL) {
      clearMemory(p->left);
      clearMemory(p->right);
      delete p;
      p = NULL;
    }
  }

  template<class T>
  bool AVLTree<T>::search(T valor) {
    NodeTree<T> *p = root;
    while(p != nullptr) {
      if (p->data == valor) {
        return true;
      }
      else { 
        p = (valor < p->data ? p->left : p->right);
      }
    }
    return false;
  }

  //Funcion para la altura del arbol
  template<class T>
  int AVLTree<T>::height(NodeTree<T> *N) {
      if (N == nullptr)
          return 0;
      return N->height;
  }
  
 
  // Funcion que obtiene el maximo de 2 enteros
  template<class T>
  int AVLTree<T>::max(int a, int b) {
      return (a > b)? a : b;
  }


  template<class T>
  NodeTree<T> *AVLTree<T>::rightRotate(NodeTree<T> *y) {
    NodeTree<T> *x = y->left;
    NodeTree<T> *T2 = x->right;
    // Rotacion
    x->right = y;
    y->left = T2;
    // Actualización de alturas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    // Regresa raiz nueva
    return x;
  }

  template<class T> 
  NodeTree<T> *AVLTree<T>::leftRotate(NodeTree<T> *x) {
      NodeTree<T> *y = x->right;
      NodeTree<T> *T2 = y->left;
    // Rotacion
      y->left = x;
      x->right = T2;
    // Actualización de alturas
      x->height = max(height(x->left), height(x->right)) + 1;
      y->height = max(height(y->left), height(y->right)) + 1;
    // Regresa raiz nueva
      return y;
  }
  
  //Obtiene el factor balanceado del nodo N
  template<class T> 
  int AVLTree<T>::getBalance(NodeTree<T> *N) {
      if (N == nullptr)
          return 0;
      return height(N->left) - height(N->right);
  }

  template<class T>
  NodeTree<T>* AVLTree<T>::insertRec(NodeTree<T>* node, T key) {

      // 1. LLeva acabo el BST
      if (node == NULL)
          return(new NodeTree<T>(key));
  
      if (key < node->data)
          node->left = insertRec(node->left, key);
      else if (key > node->data)
          node->right = insertRec(node->right, key);
      else 
          return node;
  
      // 2. Actualiza la altura de su antecesor 
      node->height = 1 + max(height(node->left),
                          height(node->right));
  
      // 3. Obtiene el valor balanceado
      int balance = getBalance(node);
  
      // Left Left Case
      if (balance > 1 && key < node->left->data)
          return rightRotate(node);
  
      // Right Right Case
      if (balance < -1 && key > node->right->data)
          return leftRotate(node);
  
      // Left Right Case
      if (balance > 1 && key > node->left->data) {
          node->left = leftRotate(node->left);
          return rightRotate(node);
      }
  
      // Right Left Case
      if (balance < -1 && key < node->right->data) {
          node->right = rightRotate(node->right);
          return leftRotate(node);
      }
  

      return node;
  }

  template<class T>
  void AVLTree<T>::insert(T valor) {
    root = insertRec(root, valor);  
  }

  template<class T>
  void AVLTree<T>::preorder(NodeTree<T>* nodo){
      if(nodo != nullptr){
        cout << nodo->data << " ";
        preorder(nodo->left); // left
        preorder(nodo->right); // right
      }
  }
    

  template<class T>
  void AVLTree<T>::inorder(NodeTree<T>* nodo) {
      if(nodo != nullptr){
      inorder(nodo->left);
      cout << nodo->data << " ";
      inorder(nodo->right);
      }
  }

  template<class T>
  void AVLTree<T>::postorder(NodeTree<T>* nodo) {
      if(nodo != nullptr){
      postorder(nodo->left);
      postorder(nodo->right);
      cout << nodo->data << " ";
      }
  }

  template<class T>
  void AVLTree<T>::callPostorder() {
    postorder(root);
    cout << endl;
  }

  template<class T>
  void AVLTree<T>::callInorder(){
    inorder(root);
    cout << endl;
  }

  template<class T>
  void AVLTree<T>::callPreorder(){
    preorder(root);
    cout << endl;
  }


int main() {
  AVLTree<int> avl;

  avl.insert(10);
  avl.insert(20);
  avl.insert(30);
  avl.insert(40);
  avl.insert(50);
  avl.insert(25);   

  avl.callPreorder();  
}