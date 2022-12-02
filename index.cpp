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
 Node *head =NULL;//ó��
 int count;
/* function */

Node* insertItem()
{
    Node *newNode = ( Node *)malloc(sizeof( Node));
    printf("\n��ǰ �߰� ��������������\n\n");

    printf("�߰��� ��ǰ���� �Է��ϼ��� : ");
    scanf("%s",  (newNode->name));

    printf("��ǰ�� ������ �Է��ϼ��� : ");
    scanf("%d", &(newNode->price));

    printf("��ǰ�� ������� �Է��ϼ��� : ");
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
    printf("Nabin Market ��������������\n\n");

    printf(" * ���� ���Ͽ� ���� ���� ȯ���մϴ�. \n");
    printf(" * ���� ������ C++�� ������ ���� ��ǰ ���� ���α׷��Դϴ�. \n\n");

    printf("���� ���� ��Ȳ ����������\n\n");

    printf(" * ���� ���� ���� ��ǰ ���� (������ ����) : %d\n", 17);
    printf(" * ���� ���� ���� ���� ���� (�޸� ũ��) : %d\n", 17 * 4);

    printf("���� ���� �޴� ����������\n\n");

    printf(" * ��ǰ ��� ��ȸ ( 1�� �������� )\n");
    printf(" * ���� ��ǰ �߰� ( 2�� �������� )\n");
    printf(" * ���� ��ǰ ���� ( 3�� �������� )\n");
    printf(" * ��ǰ �� & ���� ( 4�� �������� )\n\n");
    printf("�޴��� �����ϼ��� : ");
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
