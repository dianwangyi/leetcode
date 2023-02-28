// #include <cstdio>
// #include <queue>

// using namespace std;

// struct node{
//     int x, y;
//     int step;
// }S, T, Node;

// const int maxn = 100;

// int n ,m;
// char maze[maxn][maxn];
// bool inq[maxn][maxn] = {0};
// int x[4] = {0, 0, 1, -1};
// int y[4] = {1, -1, 0, 0};

// bool test(int x, int y){
//     if (x >= n || y >= m || x < 0 || y < 0) return false;
//     if (maze[x][y] == '*') return false;
//     if (inq[x][y] == true) return false;
// }

// int BFS(){
//     queue<node> q;
//     q.push(S);
//     while(!q.empty()){
//         node temp = q.front();
//         q.pop();
//         if(temp.x == T.x && temp.y == T.y) return temp.step;

//         for(int i = 0; i < 4; i++){
//             int newX = temp.x + x[i];
//             int newY = temp.y + y[i];
//             if (test(newX, newY)){
//                 Node.x = newX;
//                 Node.y = newY;
//                 Node.step = temp.step++;
//                 inq[newX][newY] = true;
//                 q.push(Node);
//             }
//         }
//     }
//     return -1;
// }

// void insert(node* &root, int x){
//     if(root == nullptr) {
//         root = newNode(x);
//         return;
//     }

//     if(x == root->data){
//         return;
//     }else if(x < root->data){
//         insert(root->lchild, x);
//     }else{
//         insert(root->rchild, x);
//     }
// }

// node* Create(int data[], int n){
//     node* root = NULL;
//     for(int i = 0; i < n; i++){
//         insert(root, data[i]);
//     }
//     return root;
// }

// node* findMax(node* root){
//     while(root->rchild != nullptr){
//         root  = root->rchild;
//     }

//     return root;
// }

// node* findMin(node* root){
//     while(root->lchild != nullptr){
//         root = root->lchild;
//     }
//     return root;
// }

// void deleteNode(node* &root, int x){
//     if(root == nullptr) return;
//     if(root->data == x){
//         if(root->child == nullptr && root->rchild == nullptr){
//             root = nullptr;
//         }else if(root->lchild != nullptr){
//             node* pre = findMax(root->lchild);
//             root->data = pre->data;
//             deleteNode(root->lchild, pre->data);
//         }else{
//             node* next = findMin(root->rchild);
//             root->data = next->data;
//             deleteNode(root->rchild, next->data);
//         }
//     }else if(root->data > x){
//         deleteNode(root->lchild, x);
//     }else{
//         deleteNode(root->rchild, x);
//     }
// }

// int main(){
//     scanf("%d%d", &n, &m);
//     for(int i = 0; i < n; i++){
//         getchar();
//         for(int j = 0; j < m; j++){
//             maze[i][j] = getchar();
//         }
//         maze[i][m+1] = '\0';
//     }
//     scanf("%d%d%d%d",&S.x, &S.y, &T.x, &T.y);
//     S.step = 0;
//     printf("%d\n", BFS());
//     return 0;
// }