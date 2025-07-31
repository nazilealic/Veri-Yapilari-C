#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};

struct node* newNode(int x) {
    struct node* yeni = (struct node*)malloc(sizeof(struct node));
    yeni->data = x;
    yeni->next = NULL;
    return yeni;
}

void basaEkle(struct node** head, int x) {
    struct node* yeni = newNode(x);
    if (*head == NULL) {
        *head = yeni;
    } else {
        yeni->next = *head;
        *head = yeni;
    }
}

void arayaEkle(struct node* head, int x, int y) {
    if (head == NULL) {
        return basaEkle(&head, x);
    }
    struct node* yeni = newNode(x);
    struct node* tmp = head;
    while (tmp != NULL && tmp->data != y) {
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        printf("Aradiginiz deger listede yok!\n");
        return;
    }
    yeni->next = tmp->next;
    tmp->next = yeni;
}

void sonaEkle(struct node* head, int x) {
    if (head == NULL) {
        return basaEkle(&head, x);
    }
    struct node* yeni = newNode(x);
    struct node* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = yeni;
}

void printList(struct node* head) {
    struct node* tmp = head;
    while (tmp != NULL) {
        printf("%d => ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void bastanSil(struct node** head) {
    if (*head == NULL) {
        printf("Liste zaten bos!\n");
        return;
    }
    struct node* tmp = *head;
    *head = tmp->next;
    free(tmp);
}

void aradanSil(struct node* head, int x) {
	struct node* tmp = head;
	struct node* tmp2 = head;
	struct node* silinecek;
	if (head== NULL){
		printf("Liste zaten bos!\n");
		return;
	}
    int kontrol=0;
    while (tmp2 != NULL){
    	if(tmp2->data == x){
    		kontrol=1;
		}
		tmp2 = tmp2 -> next;
    }
    if(kontrol == 0){
    	printf("%d degeri listede yok!\n",x);
        return;
	}
	while(tmp ->next != NULL && tmp -> next -> data != x){
		tmp = tmp -> next;
	}
	silinecek = tmp->next;
    tmp->next = tmp->next->next;
    free(silinecek);
}

void sondanSil(struct node** head) {
    if (*head == NULL) {
        printf("Liste zaten bos!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node* tmp = *head;
    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
}

void reverse(struct node** head) {
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void merge(struct node* head1, struct node* head2) {
    struct node* tmp = head1;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = head2;
}

int main() {
    struct node* first = newNode(10);  
    struct node* second = newNode(20); 
    struct node* third = newNode(30); 
    first->next = second;
    second->next = third;
    third->next = NULL;
    struct node* head = first;
    printList(head);
    int devam = 1;
    while (devam) {
        printf("Hangi islemi yapmak istediginizi giriniz: \n");
        printf("\n1-Basa Ekle\n2-Araya Ekle\n3-Sona Ekle\n4-Bastan Sil\n5-Aradan Sil\n6-Sondan Sil\n7-Ters Cevir\n8-Birlestir\n");
        int secim;
        printf("\nSeciminizi giriniz: ");
        scanf("%d", &secim);
        switch (secim) {
            case 1: {
                printf("Basa eklemek istediginiz degeri giriniz:\n");
                int basa;
                scanf("%d", &basa);
                basaEkle(&head, basa);
                printList(head);
                break;
            }
            case 2: {
                printf("Araya eklemek istediginiz degeri ve hangi degerden sonra girmek istediginizi giriniz:\n");
                int x, y;
                scanf("%d%d", &x, &y);
                arayaEkle(head, x, y);
                printList(head);
                break;
            }
            case 3: {
                printf("Sona eklemek istediginiz degeri giriniz:\n");
                int sona;
                scanf("%d", &sona);
                sonaEkle(head, sona);
                printList(head);
                break;
            }
            case 4:
                bastanSil(&head);
                printList(head);
                break;
            case 5: {
                printf("Aradan silinecek degeri giriniz:\n");
                int aradansil;
                scanf("%d", &aradansil);
                aradanSil(head, aradansil);
                printList(head);
                break;
            }
            case 6:
                printf("Sondan sil:\n");
                sondanSil(&head);
                printList(head);
                break;
            case 7: {
                printf("Tersle:\n");
                reverse(&head);
                printList(head);
                break;
            }
            case 8: {
                struct node* first2 = newNode(40);  
                struct node* second2 = newNode(80); 
                struct node* third2 = newNode(120); 
                first2->next = second2;
                second2->next = third2;
                third2->next = NULL;
                struct node* head2 = first2;
                printList(head2);
                printf("\n");
                merge(head, head2);
                printList(head);
                break;
            }
            default:
                printf("Yanlis deger girisi! Tekrar deneyiniz.\n");
                break;
        }

        printf("\nDevam etmek istiyor musunuz? (E/H):\n");
        char devamMi;
        scanf(" %c", &devamMi);
        if (devamMi == 'E' || devamMi == 'e') {
            devam = 1;
        } else {
            devam = 0;
        }
    }
    return 0;
}


