#include<bits/stdc++.h>
using namespace std;
  
const int k = 2;

struct Node
{
    int point[k];
    Node *left, *right;
};


struct Node* newNode(int value, int timeStamp)
{
    struct Node* temp = new Node;
    
    temp->point[0] = value;
    temp->point[1] = timeStamp;
    
    
    temp->left = temp->right = NULL;
    return temp;
}

Node *insertRec(Node *key, int value,int timeStamp, unsigned depth)
{
    if (key == NULL){
       return newNode(value, timeStamp);
      }
    int point[k];
    point[0] = value;
    point[1] = timeStamp;
    unsigned cd = depth % k;
    if (point[cd] < (key->point[cd]))
        key->left  = insertRec(key->left, value, timeStamp, depth + 1);
    else
        key->right = insertRec(key->right, value, timeStamp, depth + 1);
  
    return key;
}

Node* setNode(Node *key, int value, int timeStamp)
{
    return insertRec(key, value, timeStamp ,0);
}


int searchNode(Node* key, int timeStamp, unsigned depth){
  if(key==NULL)
  {
    return -1;
    }
  if (timeStamp == key->point[1]){
    return key->point[0];
    }
  else{
    unsigned cd = depth % k;
    if(cd==0){
    // return searchNode(key->left,timeStamp,depth+1) || searchNode(key->right,timeStamp,depth+1);
    if(searchNode(key->left,timeStamp,depth+1)==-1) return searchNode(key->right,timeStamp,depth+1);
    if(searchNode(key->right,timeStamp,depth+1)==-1) return searchNode(key->left,timeStamp,depth+1); 
  }
  if(cd==1){
    if(timeStamp < key->point[1]) return searchNode(key->left,timeStamp, depth+1);
    else return searchNode(key->right, timeStamp, depth+1);
  }
}
  }

int getValue(Node* root, int timeStamp)
{
    return searchNode(root, timeStamp, 0);
}

void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──(L)" : "└──(R)" );

        // print the value of the node
        std::cout << node->point[0]<<" "<<node->point[1] << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);    
}



int main(){
  struct Node *A = NULL;
  int points[][k] = {{3, 6}, {17, 15}, {13, 15}, {6, 12},
                       {9, 1}, {2, 7}, {10, 19}};
  int n = sizeof(points)/sizeof(points[0]);
  
  for (int i=0; i<n; i++)
    A = setNode(A, points[i][0], points[i][1]);

  printBT(A);
  cout << "Enter the timestamp and key to be searched from : ";
  int timeStamp;
  char key;
  cin >> timeStamp;
  cin >> key;
  cout << "The value for the given input is : "<< getValue(A,timeStamp);
  return 0;
}