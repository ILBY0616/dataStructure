// #include <stdio.h>
// #include <stdlib.h>
//
// #define type int
//
// typedef struct Node
// {
//     type data;
//     struct Node* next;
// } Node;
//
// Node* initiateList(type data[])
// {
//     Node* head = (Node*)malloc(sizeof(Node));
//     if (head != NULL)
//     {
//         head->data = data[0];
//         Node* temp = head;
//         for (int i = 1; i <= data[0]; i++)
//         {
//             Node* n = (Node*)malloc(sizeof(Node));
//             if (n != NULL)
//             {
//                 n->data = data[i];
//                 n->next = NULL;
//             }
//             temp->next = n;
//             temp = n;
//         }
//     }
//     return head;
// }
//
// void sortList(Node* list)
// {
//     Node* i=list->next;
//     while (i!=NULL)
//     {
//         Node* j= i->next;
//         while (j!=NULL)
//         {
//             if(j->data<i->data)
//             {
//                 type temp=i->data;
//                 i->data=
//             }
//         }
//     }
// }
//
// void printList(Node* list)
// {
//     Node* temp = list->next;
//     while (temp != NULL)
//     {
//         printf("%d", temp->data);
//         temp = temp->next;
//     }
// }
//
// int main()
// {
//     int data[8] = {7, 7, 6, 5, 4, 3, 2, 1};
//     Node* n = initiateList(data);
//     printList(n);
//     return 0;
// }
