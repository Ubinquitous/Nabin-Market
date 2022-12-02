#include <stdio.h>
#include <malloc.h>
int select;

/* define */
typedef struct Node {
    char name[50];
    int price;
    char date[20];
    struct Node * next;
}Node;

/* variable define*/
 Node *head =NULL;//처음
 int count;
/* function */

Node* insertItem()
{
    Node *newNode = ( Node *)malloc(sizeof( Node));
    printf("\n물품 추가 ───────\n\n");

    printf("추가할 물품명을 입력하세요 : ");
    scanf("%s",  (newNode->name));

    printf("물품의 가격을 입력하세요 : ");
    scanf("%d", &(newNode->price));

    printf("물품의 등록일을 입력하세요 : ");
    scanf("%s", (newNode->date));

			newNode->next = NULL;

			if (head == NULL)
			{
				head = newNode;
			}
			else
			{
				struct Node* nextNode = head;
				while (nextNode->next != NULL)
					nextNode = nextNode->next;

				nextNode->next = newNode;

			}
			return head;
}

/* main function */

int main()
{
    printf("Nabin Market ───────\n\n");

    printf(" * 나빈 마켓에 오신 것을 환영합니다. \n");
    printf(" * 나빈 마켓은 C++로 구현한 매장 물품 관리 프로그램입니다. \n\n");

    printf("나빈 마켓 현황 ─────\n\n");

    printf(" * 나빈 마켓 현재 물품 개수 (데이터 개수) : %d\n", 17);
    printf(" * 나빈 마켓 현재 진열 공간 (메모리 크기) : %d\n", 17 * 4);

    printf("나빈 마켓 메뉴 ─────\n\n");

    printf(" * 물품 목록 조회 ( 1을 누르세요 )\n");
    printf(" * 마켓 물품 추가 ( 2를 누르세요 )\n");
    printf(" * 마켓 물품 삭제 ( 3을 누르세요 )\n");
    printf(" * 물품 찜 & 구매 ( 4를 누르세요 )\n\n");
    printf("메뉴를 선택하세요 : ");
    scanf("%d", &select);

    if (select == 1)
    {
        /* showAllItem(); */
    }
    else if (select == 2)
    {
        insertItem();
    }
    else if (select == 3)
    {
        /* deleteItem(); */
    }
    else if (select == 4)
    {
        /* selectItem(); */
    }

    printf("%s",  &head->name);

}
