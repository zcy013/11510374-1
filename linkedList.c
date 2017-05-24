#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    struct Node* next;
};

struct Node* buildList();// 建表
void addNode(struct Node* head, int value);// 新增元素（到表尾）（扩大表）
struct Node* nodeAt(struct Node* head, int index);// 访问指定位置元素
void insertAt(struct Node* head, int index, int value);// 在表的指定位置插入元素
void removeAt(struct Node* head, int index);// 删除指定位置元素
int contains(struct Node* head, int value);// 某元素是否在表中出现
void printElements(struct Node* head);// 遍历表，输出所有元素值
void deleteList(struct Node* head);// 清除表

int main(void)
{
    struct Node* head = buildList();
    printf("The new list\n");
    printElements(head);

    int value;
    for(value = 1; value < 6; ++value)
        addNode(head, value);
    printf("\nAfter addNode(1-5)\n");
    printElements(head);
    printf("value of Node at index 3 = %d\n", nodeAt(head, 3) -> value);

    insertAt(head, 3, 6);
    printf("\nAfter insert Node with value 6 at index 3\n");
    printElements(head);

    removeAt(head, 5);
    printf("\nAfter remove Node at index 5\n");
    printElements(head);

    value = 7;
    int index = contains(head, value);
    if(index < 0)
        printf("\n%d is not in the list\n", value);
    else
        printf("\n%d is in the index %d\n", value, index);

    deleteList(head);
    return 0;
}

struct Node* buildList()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head -> next = NULL;
    return head;
}

void addNode(struct Node* head, int value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = head;
    while(ptr -> next != NULL)
        ptr = ptr -> next;
    node -> value = value;
    node -> next = NULL;
    ptr -> next = node;
}

struct Node* nodeAt(struct Node* head, int index)
{
    struct Node* ptr = head;
    int i;
    for(i = 0; i < index; ++i)
        ptr = ptr -> next;
    return ptr;
}

void insertAt(struct Node* head, int index, int value)
{
    struct Node* ptr = nodeAt(head, index - 1);
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node -> value = value;
    node -> next = ptr -> next;
    ptr -> next = node;
}

void removeAt(struct Node* head, int index)
{
    struct Node* pre = nodeAt(head, index - 1);
    struct Node* next = pre -> next -> next;
    free(pre -> next);
    pre -> next = next;
}

int contains(struct Node* head, int value)
{
    struct Node* ptr = head;
    int i = 1;
    while((ptr = ptr -> next)!= NULL)
    {
        if(ptr -> value == value)
            return i;
        ++i;
    }
    return -1;
}

void deleteList(struct Node* head)
{
    while(head != NULL)
    {
        struct Node* ptr = head;
        head = head -> next;
        free(ptr);
    }
}

void printElements(struct Node* head)
{
    struct Node* ptr = head;
    int i = 0;
    while((ptr = ptr -> next)!= NULL)
    {
        if((i+1) % 10 == 0)
            putch('\n');
        printf("%4d  ", ptr -> value);
        ++i;
    }
    printf("\nlength = %d\n", i);
}
