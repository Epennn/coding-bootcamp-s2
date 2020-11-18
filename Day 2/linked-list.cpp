// Single Linked - List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value; // Value yang dimiliki node sekarang
    Node *next; // Pointer node selanjutnya
} *head, *tail, *curr; //Diinitialize jadi global struct

Node *createNode(int value)
{
    Node *temp = (Node*)malloc(sizeof(Node)); // Alokasi memory untuk temp
    temp->value = value; // Isi nilai temp
    temp->next = NULL;// Node setelahnya = NULL

    return temp;
}

void pushHead(int value)
{
    Node *temp = createNode(value); // Buat node baru

    if(!head) // Jika tidak ada node
    {
        head = tail = temp; // Temp akan jadi head dan tail 
    }
    else // Jika ada >= 1 node
    {
        temp->next = head; // node setelah head = temp
        head = temp; // temp menjadi head baru
    }
    
}

void pushTail(int value)
{
    Node *temp = createNode(value); // Buat node baru

    if(!head) // Jika tidak ada node
    {
        head = tail = temp; // Temp akan jadi head dan tail
    }
    else
    {
        tail->next = temp; // node setelah tail = temp
        tail = temp; // temp menjadi tail baru
    }
    
}

void popHead() // Delete Node
{
    if(!head) // Cek dulu ada head atau tidak
    {
        return; // Jika tidak, langsung return
    }
    else if(head == tail) // Jika hanya ada 1 node
    {
        head = tail = NULL; // Kosongkan head dan tail
        free(head); // Alokasi memori head dibebaskan
    }
    else
    {
        Node *newHead = head->next;
        head->next = NULL;
        free(head);
        head = newHead;
    }
    // Linked List : 15(head) -> 20(newHead) -> 23 -> 32(tail) -> NULL

    // Node *newHead = head->next;
    // 15(head) -> 20(newHead) -> 23 -> 32(tail) -> NULL

    // head->next = NULL;
    // 15(head) -> NULL | 20(newHead) -> 23 -> 32(tail) -> NULL

    // free(head)
    // 20(newHead) -> 23 -> 32(tail) -> NULL

    // head = newHead;
    // 20(Head) -> 23 -> 32(tail) -> NULL
}


void popTail() // Delete Node
{
    if(!head) // Cek dulu ada head atau tidak
    {
        return; // Jika tidak, langsung return
    }
    else if(head == tail) // Jika hanya ada 1 node
    {
        head = tail = NULL; // Kosongkan head dan tail
        free(head); // Alokasi memori head dibebaskan
    }
    else
    {
       curr = head; // Current node = head
       while(curr) // Selama node sekarang tidak NULL
       {
           if(curr->next == tail) // Jika node selanjutnya adalah tail
           {
               curr->next = NULL; // Putusin link menuju tail
               free(curr->next); // Buang tail
               tail = curr; // Assign tail baru
               break; // break dari loop
           }
           curr = curr->next; // Jika curr->next != tail, lanjut looping
       }
    }
    // curr = head;
    // 15(curr, head) -> 20 -> 30(tail) -> NULL

    // 15(curr, head) -> 20 -> 30(tail) // Cek apakah curr->next == tail
    // 15(head) -> 20(curr) -> 30(tail) // Cek apakah curr->next == tail

    // Karena curr->next == tail, putuskan link + buang tail + assign tail
    // 15(head) -> 20(curr) -> NULL | 30(tail)
    // 15(head) -> 20(curr) -> NULL | dibuang
    // 15(head) -> 20(tail) -> NULL | dibuang
}

void printLinkedList()
{
    if(!head) // Jika tidak ada node
    {
        return; // Langsung return
    }
    else
    {
        curr = head; // Current node adalah head

        while(curr)
        {
            printf("%d, curr->value"); // Print value node sekarang
            curr = curr->next; // Loop hingga akhir
        }    
    }
}

void search(int value)
{
    
}

int main()
{
    // 30 -> 15 -> NULL
    pushHead(15);
    pushHead(30);
}

