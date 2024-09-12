// #include <stdio.h>
// #include <stdlib.h>
//
// // 统一重点：ToDo
// // 统一提示：中文
// // 统一注释：代码上方
// // 统一状态：-1失败，0成功，1其他
//
// // ToDo
// // BinarySortTree
//
// typedef struct Node
// {
//     int data;
//     struct Node* left;
//     struct Node* right;
// } Node;
//
// typedef Node* PNode;
//
// PNode toList(int data[], int length);
// int judgeList(PNode list);
//
// int main()
// {
//     int data[8] = {0, 1, 2, 3, 4, 5, 6, 7};
//     PNode list = toList(data, 8);
//     if (judgeList(list) == 0)
//     {
//         printf("是二叉排序树\n");
//     }
//     else
//     {
//         printf("非二叉排序树\n");
//     }
//     free(list);
//     return 0;
// }
//
// PNode toList(int data[], int length)
// {
//     PNode head = NULL;
//     PNode tail = NULL;
//     for (int i = 0; i < length; i++)
//     {
//         PNode temp = malloc(sizeof(Node));
//         if (temp != NULL)
//         {
//             temp->data = data[i];
//             temp->next = NULL;
//             if (head == NULL || tail == NULL)
//             {
//                 head = temp;
//                 tail = temp;
//             }
//             else
//             {
//                 tail->next = temp;
//                 tail = temp;
//             }
//         }
//         else
//         {
//             free(head);
//             free(tail);
//             free(temp);
//             head = NULL;
//             tail = NULL;
//             temp = NULL;
//             break;
//         }
//     }
//     return head;
// }
//
// int judgeList(PNode list)
// {
//     int result = 0;
//     PNode left=list->
//     if(list->data)
//     return result;
// }
