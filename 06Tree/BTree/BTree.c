// #include <stdio.h>
// #include <stdlib.h>
//
// #define type char
//
// typedef struct Node
// {
//     type data;
//     struct Node *left, *right;
// } Node;
//
// typedef Node* BTree;
//
// BTree buildTreeByFront(type data[],int length)
// {
//     BTree n;
//     for(int i=0;i<length;i++)
//     {
//         if (data == '#')
//         {
//             n = NULL;
//         }
//         else
//         {
//             n = (BTree)malloc(sizeof(Node));
//             if (n != NULL)
//             {
//                 n->data = data;
//                 n->left = buildTreeByFront(n->left);
//                 n->right = buildTreeByFront(n->right);
//             }
//         }
//     }
//     return n;
// }
//
// BTree buildTreeByMiddle()
// {
//     BTree n;
//     type data;
//     scanf("%c", &data);
//     if (data == '#')
//     {
//         n = NULL;
//     }
//     else
//     {
//         n = (BTree)malloc(sizeof(Node));
//         if (n != NULL)
//         {
//             n->left = buildTreeByMiddle(n->left);
//             n->data = data;
//             n->right = buildTreeByMiddle(n->right);
//         }
//     }
//     return n;
// }
//
// BTree buildTreeByBack()
// {
//     BTree n;
//     type data;
//     scanf("%c", &data);
//     if (data == '#')
//     {
//         n = NULL;
//     }
//     else
//     {
//         n = (BTree)malloc(sizeof(Node));
//         if (n != NULL)
//         {
//             n->left = buildTreeByBack(n->left);
//             n->right = buildTreeByBack(n->right);
//             n->data = data;
//         }
//     }
//     return n;
// }
//
// void destroyTree(BTree n)
// {
//     if(n)
//     {
//         if(n->left)
//         {
//             destroyTree(n->left);
//         }
//         if(n->right)
//         {
//             destroyTree(n->right);
//         }
//         free(n);
//     }
// }
//
//
// int main()
// {
//     BTree front = buildTreeByFront();
//     BTree middle = buildTreeByMiddle();
//     BTree back = buildTreeByBack();
//     destroyTree(front);
//     destroyTree(middle);
//     destroyTree(back);
//     return 0;
// }
