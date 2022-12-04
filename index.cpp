#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <windows.h>
<<<<<<< HEAD

/* ¹°Ç° ¸ñ·Ï ¿¬°á¸®½ºÆ® Á¤ÀÇ */

=======

int userselect;

/* define */
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
typedef struct Node
{
    char name[50];
    int price;
    int date;
    int category;
    struct Node *next;
} Node;

<<<<<<< HEAD
/* ¸ñ·Ï ¼±ÅÃ º¯¼ö */

int userselect;

/* ¹°Ç° ¸ñ·Ï ¿¬°á¸®½ºÆ® ¼±¾ğ */

Node *head = (Node *)malloc(sizeof(Node));
/* ¿¬°á¸®½ºÆ® ÃÊ±âÈ­ º¯¼ö */

=======
/* variable define*/

Node *head = (Node *)malloc(sizeof(Node));
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
void init()
{
    head->next = NULL;
}
<<<<<<< HEAD

/* ¹°Ç° Ãß°¡ ÇÔ¼ö */

void deleteItem(Node *heads)
{
    Node *DateSortItem[1000];
    Node *temp[2];
        int i = 0, count = 0;
        struct Node *countHead = head;

        heads = heads->next;

        /* ¹è¿­¿¡ ¹°Ç° ¸ñ·Ï ´ã±â */
        while (heads != NULL)
        {
            DateSortItem[i] = heads;
            heads = heads->next;
            i++;
        }

        /* ¹°Ç° °³¼ö ±¸ÇÏ±â */
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }

        /* ¹öºí Á¤·Ä */
        for (int i = count - 2; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (DateSortItem[j]->date > DateSortItem[j + 1]->date)
                {
                    temp[0] = DateSortItem[j];
                    DateSortItem[j] = DateSortItem[j + 1];
                    DateSortItem[j + 1] = temp[0];
                }
            }
        }
        system("cls");
        printf("¹°Ç°¸í, ¹°Ç° °¡°İ, µî·ÏÀÏ, Ä«Å×°í¸®\n");
        for (int i = 0; i < count - 1; i++)
        {
            /* Ä«Å×°í¸®°¡ À½·á¸é */
            if (DateSortItem[i]->category == 1)
            {
                printf("[%d]%s, %d, %02d-%02d-%02d, À½·á\n", i + 1,DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            /* Ä«Å×°í¸®°¡ °úÀÚ¸é */
            else if (DateSortItem[i]->category == 2)
            {
                printf("[%d]%s, %d, %02d-%02d-%02d, °úÀÚ\n",i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* Ä«Å×°í¸®°¡ °úÀÏÀÌ¸é */
            else if (DateSortItem[i]->category == 3)
            {
                printf("[%d]%s, %d, %02d-%02d-%02d, °úÀÏ\n",i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* Ä«Å×°í¸®°¡ °í±â¸é */
            else if (DateSortItem[i]->category == 4)
            {
                printf("[%d]%s, %d, %02d-%02d-%02d, °í±â\n",i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* Ä«Å×°í¸®°¡ ¶ó¸éÀÌ¸é */
            else if (DateSortItem[i]->category == 5)
            {
                printf("[%d]%s, %d, %02d-%02d-%02d, ¶ó¸é\n",i + 1, DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
        }

        printf("\n\n»èÁ¦ÇÏ°í ½ÍÀº »óÇ°ÀÇ ¹øÈ£¸¦ ¼±ÅÃÇØÁÖ¼¼¿ä\n");
        int index;
        scanf("%d", &index);

        if (index == 1)
        {
            Node* temp2 = head;
            head = head->next;
            free(temp2);
            return;
        }

    Node* temp1 = head;
	Node* prev = nullptr;
	for (int i = 0; i < index; i++)
	{
		prev = temp1;
		temp1 = temp1->next;
	}

	prev->next = temp1->next;
	free(temp1);
	}


Node *insertItem()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    system("cls");
    printf("\n¹°Ç° Ãß°¡ ¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n\n");

    try
    {
        printf("Ãß°¡ÇÒ ¹°Ç°¸íÀ» ÀÔ·ÂÇÏ¼¼¿ä : ");
        scanf("%s", (newNode->name));

        printf("¹°Ç°ÀÇ °¡°İÀ» ÀÔ·ÂÇÏ¼¼¿ä : ");
        scanf("%d", &(newNode->price));

        printf("¹°Ç°ÀÇ µî·ÏÀÏÀ» ÀÔ·ÂÇÏ¼¼¿ä (ex: 2022³â 11¿ù 7ÀÏ = 221107) : ");
        scanf("%d", &(newNode->date));

        printf("¹°Ç°ÀÇ Ä«Å×°í¸®¸¦ Á¤ÇØÁÖ¼¼¿ä :: \n");
        printf(" * À½·á ( 1À» ´©¸£¼¼¿ä )\n");
        printf(" * °úÀÚ ( 2¸¦ ´©¸£¼¼¿ä )\n");
        printf(" * °úÀÏ ( 3À» ´©¸£¼¼¿ä )\n");
        printf(" * °í±â ( 4¸¦ ´©¸£¼¼¿ä )\n");
        printf(" * ¶ó¸é ( 5¸¦ ´©¸£¼¼¿ä )\n");
        printf("Ä«Å×°í¸®¸¦ ¼±ÅÃÇÏ¼¼¿ä : ");
        scanf("%d", &(newNode->category));

        if ((newNode->category) <= 5 && (newNode->category) >= 1)
        {
            system("cls");
            printf("%s(ÀÌ)°¡ Ãß°¡µÇ¾ú½À´Ï´Ù!\n\n", (newNode->name));
        }
        else
        {
            throw -1;
        }
    }
    catch (int error)
    {
        printf("¿À·ù! Àß¸øµÈ ÀÔ·Â°ªÀÔ´Ï´Ù. ´Ù½Ã ½ÃµµÇØÁÖ¼¼¿ä.\n");
    }

    newNode->next = NULL;

=======

/* insert item function */

Node *insertItem()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    system("cls");
    printf("\në¬¼í’ˆ ì¶”ê°€ â”€â”€â”€â”€â”€â”€â”€\n\n");

    try
    {
        printf("ì¶”ê°€í•  ë¬¼í’ˆëª…ì„ ì…ë ¥í•˜ì„¸ìš” : ");
        scanf("%s", (newNode->name));

        printf("ë¬¼í’ˆì˜ ê°€ê²©ì„ ì…ë ¥í•˜ì„¸ìš” : ");
        scanf("%d", &(newNode->price));

        printf("ë¬¼í’ˆì˜ ë“±ë¡ì¼ì„ ì…ë ¥í•˜ì„¸ìš” (ex: 2022ë…„ 11ì›” 7ì¼ = 221107) : ");
        scanf("%d", &(newNode->date));

        printf("ë¬¼í’ˆì˜ ì¹´í…Œê³ ë¦¬ë¥¼ ì •í•´ì£¼ì„¸ìš” :: \n");
        printf(" * ìŒë£Œ ( 1ì„ ëˆ„ë¥´ì„¸ìš” )\n");
        printf(" * ê³¼ì ( 2ë¥¼ ëˆ„ë¥´ì„¸ìš” )\n");
        printf(" * ê³¼ì¼ ( 3ì„ ëˆ„ë¥´ì„¸ìš” )\n");
        printf(" * ê³ ê¸° ( 4ë¥¼ ëˆ„ë¥´ì„¸ìš” )\n");
        printf(" * ë¼ë©´ ( 5ë¥¼ ëˆ„ë¥´ì„¸ìš” )\n");
        printf("ì¹´í…Œê³ ë¦¬ë¥¼ ì„ íƒí•˜ì„¸ìš” : ");
        scanf("%d", &(newNode->category));

        if ((newNode->category) <= 5 && (newNode->category) >= 1)
        {
            system("cls");
            printf("%s(ì´)ê°€ ì¶”ê°€ë˜ì—ˆìŠµë‹ˆë‹¤!\n\n", (newNode->name));
        }
        else
        {
            throw 0;
        }
    }
    catch (int error)
    {
        printf("ì˜¤ë¥˜! ì˜ëª»ëœ ì…ë ¥ê°’ì…ë‹ˆë‹¤. ë‹¤ì‹œ ì‹œë„í•´ì£¼ì„¸ìš”.\n");
    }

    newNode->next = NULL;

>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
    if (head->next == NULL)
    {
        head->next = newNode;
    }
    else
    {
        Node *nextNode = head;
        while (nextNode->next != NULL)
            nextNode = nextNode->next;

        nextNode->next = newNode;
    }
    return newNode;
}

<<<<<<< HEAD
/* ¹°Ç° °Ë»ö ÇÔ¼ö */
=======
/* find item funtion */
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115

void findItem(Node *heads)
{
    system("cls");
    int choice = 0;
<<<<<<< HEAD
    printf("¹°Ç° °Ë»ö ÆäÀÌÁö ¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n\n");
    printf(" * µî·ÏÀÏ·Î °Ë»ö ( 1À» ´©¸£¼¼¿ä )\n");
    printf(" * °¡°İÀ¸·Î °Ë»ö ( 2¸¦ ´©¸£¼¼¿ä )\n\n");
    printf("¸Ş´º¸¦ ¼±ÅÃÇÏ¼¼¿ä : ");
    scanf("%d", &choice);
    system("cls");

    /* µî·ÏÀÏ·Î °Ë»ö */
    if (choice == 1)
    {
        int date = 0;
        printf("°Ë»öÇÒ µî·ÏÀÏÀ» ÀÔ·ÂÇÏ¼¼¿ä (ex: 2022³â 11¿ù 7ÀÏ = 221107) : ");
        scanf("%d", &date);
        system("cls");
        printf("¹°Ç°¸í, ¹°Ç° °¡°İ, µî·ÏÀÏ, Ä«Å×°í¸®\n");
=======
    printf("ë¬¼í’ˆ ê²€ìƒ‰ í˜ì´ì§€ â”€â”€â”€â”€â”€â”€â”€\n\n");
    printf(" * ë“±ë¡ì¼ë¡œ ê²€ìƒ‰ ( 1ì„ ëˆ„ë¥´ì„¸ìš” )\n");
    printf(" * ê°€ê²©ìœ¼ë¡œ ê²€ìƒ‰ ( 2ë¥¼ ëˆ„ë¥´ì„¸ìš” )\n\n");
    printf("ë©”ë‰´ë¥¼ ì„ íƒí•˜ì„¸ìš” : ");
    scanf("%d", &choice);
    system("cls");

    /* ë“±ë¡ì¼ë¡œ ê²€ìƒ‰ */
    if (choice == 1)
    {
        int date = 0;
        printf("ê²€ìƒ‰í•  ë“±ë¡ì¼ì„ ì…ë ¥í•˜ì„¸ìš” (ex: 2022ë…„ 11ì›” 7ì¼ = 221107) : ");
        scanf("%d", &date);
        system("cls");
        printf("ë¬¼í’ˆëª…, ë¬¼í’ˆ ê°€ê²©, ë“±ë¡ì¼, ì¹´í…Œê³ ë¦¬\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        Node *DateSearchItem[1000];
        int i = 0, count = 0;
        struct Node *countHead = head;
        heads = heads->next;
        while (heads != NULL)
        {
            DateSearchItem[i] = heads;
            heads = heads->next;
            i++;
        }
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }

        for (int i = 0; i < count - 1; i++)
        {
            if (DateSearchItem[i]->date == date)
            {
<<<<<<< HEAD
                printf("%s, %d, %02d-%02d-%02d, À½·á\n", DateSearchItem[i]->name, DateSearchItem[i]->price, DateSearchItem[i]->date / 10000, DateSearchItem[i]->date / 100 % 100, DateSearchItem[i]->date % 100, DateSearchItem[i]->category);
            }
        }
        printf("\n\n** È®ÀÎÇÏ¼Ì´Ù¸é ¾Æ¹« Å°³ª ÀÔ·ÂÇØÁÖ¼¼¿ä. **\n");
=======
                printf("%s, %d, %02d-%02d-%02d, ìŒë£Œ\n", DateSearchItem[i]->name, DateSearchItem[i]->price, DateSearchItem[i]->date / 10000, DateSearchItem[i]->date / 100 % 100, DateSearchItem[i]->date % 100, DateSearchItem[i]->category);
            }
        }
        printf("\n\n** í™•ì¸í•˜ì…¨ë‹¤ë©´ ì•„ë¬´ í‚¤ë‚˜ ì…ë ¥í•´ì£¼ì„¸ìš”. **\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
<<<<<<< HEAD
    /* °¡°İÀ¸·Î °Ë»ö */
    else if (choice == 2)
    {
        int price = 0;
        printf("°Ë»öÇÒ °¡°İÀ» ÀÔ·ÂÇÏ¼¼¿ä : ");
        scanf("%d", &price);
        system("cls");
        printf("¹°Ç°¸í, ¹°Ç° °¡°İ, µî·ÏÀÏ, Ä«Å×°í¸®\n");
=======
    else if (choice == 2)
    {
        /* ê°€ê²©ìœ¼ë¡œ ê²€ìƒ‰ */
        int price = 0;
        printf("ê²€ìƒ‰í•  ê°€ê²©ì„ ì…ë ¥í•˜ì„¸ìš” : ");
        scanf("%d", &price);
        system("cls");
        printf("ë¬¼í’ˆëª…, ë¬¼í’ˆ ê°€ê²©, ë“±ë¡ì¼, ì¹´í…Œê³ ë¦¬\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        Node *DatePriceItem[1000];
        int i = 0, count = 0;
        struct Node *countHead = head;
        heads = heads->next;
        while (heads != NULL)
        {
            DatePriceItem[i] = heads;
            heads = heads->next;
            i++;
        }
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }

        for (int i = 0; i < count - 1; i++)
        {
            if (DatePriceItem[i]->price == price)
            {
<<<<<<< HEAD
                printf("%s, %d, %02d-%02d-%02d, À½·á\n", DatePriceItem[i]->name, DatePriceItem[i]->price, DatePriceItem[i]->date / 10000, DatePriceItem[i]->date / 100 % 100, DatePriceItem[i]->date % 100, DatePriceItem[i]->category);
            }
        }
        printf("\n\n** È®ÀÎÇÏ¼Ì´Ù¸é ¾Æ¹« Å°³ª ÀÔ·ÂÇØÁÖ¼¼¿ä. **\n");
=======
                printf("%s, %d, %02d-%02d-%02d, ìŒë£Œ\n", DatePriceItem[i]->name, DatePriceItem[i]->price, DatePriceItem[i]->date / 10000, DatePriceItem[i]->date / 100 % 100, DatePriceItem[i]->date % 100, DatePriceItem[i]->category);
            }
        }
        printf("\n\n** í™•ì¸í•˜ì…¨ë‹¤ë©´ ì•„ë¬´ í‚¤ë‚˜ ì…ë ¥í•´ì£¼ì„¸ìš”. **\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
}

<<<<<<< HEAD
/* ¹°Ç° ¸ñ·Ï Á¶È¸ ÇÔ¼ö */
=======
/* show all item function */
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115

void showAllItem(Node *heads)
{
    system("cls");
    int choice = 0;
<<<<<<< HEAD
    printf("¹°Ç° Á¶È¸ ÆäÀÌÁö ¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n\n");
    printf(" * µî·ÏÀÏ¼ø Á¶È¸ ( 1À» ´©¸£¼¼¿ä )\n");
    printf(" * °¡°İ¼ø Á¶È¸ ( 2¸¦ ´©¸£¼¼¿ä )\n");
    printf(" * Ä«Å×°í¸®º° Á¶È¸ ( 3À» ´©¸£¼¼¿ä )\n\n");
    printf("¸Ş´º¸¦ ¼±ÅÃÇÏ¼¼¿ä : ");
    scanf("%d", &choice);
    system("cls");

    /* µî·ÏÀÏ¼ø Á¶È¸ */
=======
    printf("ë¬¼í’ˆ ì¡°íšŒ í˜ì´ì§€ â”€â”€â”€â”€â”€â”€â”€\n\n");
    printf(" * ë“±ë¡ì¼ìˆœ ì¡°íšŒ ( 1ì„ ëˆ„ë¥´ì„¸ìš” )\n");
    printf(" * ê°€ê²©ìˆœ ì¡°íšŒ ( 2ë¥¼ ëˆ„ë¥´ì„¸ìš” )\n");
    printf(" * ì¹´í…Œê³ ë¦¬ë³„ ì¡°íšŒ ( 3ì„ ëˆ„ë¥´ì„¸ìš” )\n\n");
    printf("ë©”ë‰´ë¥¼ ì„ íƒí•˜ì„¸ìš” : ");
    scanf("%d", &choice);
    system("cls");
    /* ë“±ë¡ì¼ìˆœ ì¡°íšŒ */
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115

    if (choice == 1)
    {
        Node *DateSortItem[1000];
        Node *temp[2];
        int i = 0, count = 0;
        struct Node *countHead = head;

        heads = heads->next;
<<<<<<< HEAD

        /* ¹è¿­¿¡ ¹°Ç° ¸ñ·Ï ´ã±â */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        while (heads != NULL)
        {
            DateSortItem[i] = heads;
            heads = heads->next;
            i++;
        }
<<<<<<< HEAD

        /* ¹°Ç° °³¼ö ±¸ÇÏ±â */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }
<<<<<<< HEAD

        /* ¹öºí Á¤·Ä */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        for (int i = count - 2; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (DateSortItem[j]->date > DateSortItem[j + 1]->date)
                {
                    temp[0] = DateSortItem[j];
                    DateSortItem[j] = DateSortItem[j + 1];
                    DateSortItem[j + 1] = temp[0];
                }
            }
        }
<<<<<<< HEAD
        printf("¹°Ç°¸í, ¹°Ç° °¡°İ, µî·ÏÀÏ, Ä«Å×°í¸®\n");
        for (int i = 0; i < count - 1; i++)
        {
            /* Ä«Å×°í¸®°¡ À½·á¸é */
            if (DateSortItem[i]->category == 1)
            {
                printf("%s, %d, %02d-%02d-%02d, À½·á\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            /* Ä«Å×°í¸®°¡ °úÀÚ¸é */
            else if (DateSortItem[i]->category == 2)
            {
                printf("%s, %d, %02d-%02d-%02d, °úÀÚ\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* Ä«Å×°í¸®°¡ °úÀÏÀÌ¸é */
            else if (DateSortItem[i]->category == 3)
            {
                printf("%s, %d, %02d-%02d-%02d, °úÀÏ\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* Ä«Å×°í¸®°¡ °í±â¸é */
            else if (DateSortItem[i]->category == 4)
            {
                printf("%s, %d, %02d-%02d-%02d, °í±â\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }

            /* Ä«Å×°í¸®°¡ ¶ó¸éÀÌ¸é */
            else if (DateSortItem[i]->category == 5)
            {
                printf("%s, %d, %02d-%02d-%02d, ¶ó¸é\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
        }

        printf("\n\n** È®ÀÎÇÏ¼Ì´Ù¸é ¾Æ¹« Å°³ª ÀÔ·ÂÇØÁÖ¼¼¿ä. **\n");
=======
        printf("ë¬¼í’ˆëª…, ë¬¼í’ˆ ê°€ê²©, ë“±ë¡ì¼, ì¹´í…Œê³ ë¦¬\n");
        for (int i = 0; i < count - 1; i++)
        {
            if (DateSortItem[i]->category == 1)
            {
                printf("%s, %d, %02d-%02d-%02d, ìŒë£Œ\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            else if (DateSortItem[i]->category == 2)
            {
                printf("%s, %d, %02d-%02d-%02d, ê³¼ì\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            else if (DateSortItem[i]->category == 3)
            {
                printf("%s, %d, %02d-%02d-%02d, ê³¼ì¼\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            else if (DateSortItem[i]->category == 4)
            {
                printf("%s, %d, %02d-%02d-%02d, ê³ ê¸°\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
            else if (DateSortItem[i]->category == 5)
            {
                printf("%s, %d, %02d-%02d-%02d, ë¼ë©´\n", DateSortItem[i]->name, DateSortItem[i]->price, DateSortItem[i]->date / 10000, DateSortItem[i]->date / 100 % 100, DateSortItem[i]->date % 100, DateSortItem[i]->category);
            }
        }
        printf("\n\n** í™•ì¸í•˜ì…¨ë‹¤ë©´ ì•„ë¬´ í‚¤ë‚˜ ì…ë ¥í•´ì£¼ì„¸ìš”. **\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
<<<<<<< HEAD

    /* °¡°İ¼ø Á¶È¸ */
=======
    /* ê°€ê²©ìˆœ ì¡°íšŒ */
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
    else if (choice == 2)
    {
        Node *PriceSortItem[1000];
        Node *temp[2];
        int i = 0, count = 0;
        struct Node *countHead = head;

<<<<<<< HEAD
        /* ¹è¿­¿¡ ¹°Ç° ¸ñ·Ï ´ã±â */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        heads = heads->next;
        while (heads != NULL)
        {
            PriceSortItem[i] = heads;
            heads = heads->next;
            i++;
        }
<<<<<<< HEAD
        /* ¹°Ç° °³¼ö ±¸ÇÏ±â */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }
<<<<<<< HEAD
        /* ¹öºí Á¤·Ä */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        for (int i = count - 2; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (PriceSortItem[j]->price > PriceSortItem[j + 1]->price)
                {
                    temp[0] = PriceSortItem[j];
                    PriceSortItem[j] = PriceSortItem[j + 1];
                    PriceSortItem[j + 1] = temp[0];
                }
            }
        }
<<<<<<< HEAD
        printf("¹°Ç°¸í, ¹°Ç° °¡°İ, µî·ÏÀÏ, Ä«Å×°í¸®\n");
        for (int i = 0; i < count - 1; i++)
        {
            /* Ä«Å×°í¸®°¡ À½·á¸é */
            if (PriceSortItem[i]->category == 1)
            {
                printf("%s, %d, %02d-%02d-%02d, À½·á\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            /* Ä«Å×°í¸®°¡ °úÀÚ¸é */
            else if (PriceSortItem[i]->category == 2)
            {
                printf("%s, %d, %02d-%02d-%02d, °úÀÚ\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            /* Ä«Å×°í¸®°¡ °úÀÏÀÌ¸é */
            else if (PriceSortItem[i]->category == 3)
            {
                printf("%s, %d, %02d-%02d-%02d, °úÀÏ\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            /* Ä«Å×°í¸®°¡ °í±â¸é */
            else if (PriceSortItem[i]->category == 4)
            {
                printf("%s, %d, %02d-%02d-%02d, °í±â\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            /* Ä«Å×°í¸®°¡ ¶ó¸éÀÌ¸é */
            else if (PriceSortItem[i]->category == 5)
            {
                printf("%s, %d, %02d-%02d-%02d, ¶ó¸é\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
        }

        printf("\n\n** È®ÀÎÇÏ¼Ì´Ù¸é ¾Æ¹« Å°³ª ÀÔ·ÂÇØÁÖ¼¼¿ä. **\n");
=======
        printf("ë¬¼í’ˆëª…, ë¬¼í’ˆ ê°€ê²©, ë“±ë¡ì¼, ì¹´í…Œê³ ë¦¬\n");
        for (int i = 0; i < count - 1; i++)
        {
            if (PriceSortItem[i]->category == 1)
            {
                printf("%s, %d, %02d-%02d-%02d, ìŒë£Œ\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            else if (PriceSortItem[i]->category == 2)
            {
                printf("%s, %d, %02d-%02d-%02d, ê³¼ì\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            else if (PriceSortItem[i]->category == 3)
            {
                printf("%s, %d, %02d-%02d-%02d, ê³¼ì¼\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            else if (PriceSortItem[i]->category == 4)
            {
                printf("%s, %d, %02d-%02d-%02d, ê³ ê¸°\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
            else if (PriceSortItem[i]->category == 5)
            {
                printf("%s, %d, %02d-%02d-%02d, ë¼ë©´\n", PriceSortItem[i]->name, PriceSortItem[i]->price, PriceSortItem[i]->date / 10000, PriceSortItem[i]->date / 100 % 100, PriceSortItem[i]->date % 100, PriceSortItem[i]->category);
            }
        }
        printf("\n\n** í™•ì¸í•˜ì…¨ë‹¤ë©´ ì•„ë¬´ í‚¤ë‚˜ ì…ë ¥í•´ì£¼ì„¸ìš”. **\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
<<<<<<< HEAD
    /* Ä«Å×°í¸®º° Á¶È¸ */
    else if (choice == 3)
    {
        int ctg = 0;
        printf("Á¶È¸ÇÏ½Ç Ä«Å×°í¸®¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä.\n");
        printf(" * À½·á ( 1À» ´©¸£¼¼¿ä )\n");
        printf(" * °úÀÚ ( 2¸¦ ´©¸£¼¼¿ä )\n");
        printf(" * °úÀÏ ( 3À» ´©¸£¼¼¿ä )\n");
        printf(" * °í±â ( 4¸¦ ´©¸£¼¼¿ä )\n");
        printf(" * ¶ó¸é ( 5¸¦ ´©¸£¼¼¿ä )\n\n");
        printf("Ä«Å×°í¸®¸¦ ¼±ÅÃÇÏ¼¼¿ä : ");
        scanf("%d", &ctg);
        system("cls");
        printf("¹°Ç°¸í, ¹°Ç° °¡°İ, µî·ÏÀÏ, Ä«Å×°í¸®\n");

        /* ¼øÂ÷ Å½»ö */
=======
    else if (choice == 3)
    {
        int ctg = 0;
        printf("ì¡°íšŒí•˜ì‹¤ ì¹´í…Œê³ ë¦¬ë¥¼ ì…ë ¥í•´ì£¼ì„¸ìš”.\n");
        printf(" * ìŒë£Œ ( 1ì„ ëˆ„ë¥´ì„¸ìš” )\n");
        printf(" * ê³¼ì ( 2ë¥¼ ëˆ„ë¥´ì„¸ìš” )\n");
        printf(" * ê³¼ì¼ ( 3ì„ ëˆ„ë¥´ì„¸ìš” )\n");
        printf(" * ê³ ê¸° ( 4ë¥¼ ëˆ„ë¥´ì„¸ìš” )\n");
        printf(" * ë¼ë©´ ( 5ë¥¼ ëˆ„ë¥´ì„¸ìš” )\n\n");
        printf("ì¹´í…Œê³ ë¦¬ë¥¼ ì„ íƒí•˜ì„¸ìš” : ");
        scanf("%d", &ctg);
        system("cls");
        printf("ë¬¼í’ˆëª…, ë¬¼í’ˆ ê°€ê²©, ë“±ë¡ì¼, ì¹´í…Œê³ ë¦¬\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        heads = heads->next;
        while (heads != NULL)
        {
            if (heads->category == ctg)
            {
<<<<<<< HEAD
                printf("%s, %d, %02d-%02d-%02d, À½·á\n", heads->name, heads->price, heads->date / 10000, heads->date / 100 % 100, heads->date % 100, heads->category);
            }
            heads = heads->next;
        }
        printf("\n\n** È®ÀÎÇÏ¼Ì´Ù¸é ¾Æ¹« Å°³ª ÀÔ·ÂÇØÁÖ¼¼¿ä. **\n");
=======
                printf("%s, %d, %02d-%02d-%02d, ìŒë£Œ\n", heads->name, heads->price, heads->date / 10000, heads->date / 100 % 100, heads->date % 100, heads->category);
            }
            heads = heads->next;
        }
        printf("\n\n** í™•ì¸í•˜ì…¨ë‹¤ë©´ ì•„ë¬´ í‚¤ë‚˜ ì…ë ¥í•´ì£¼ì„¸ìš”. **\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        char a[300];
        scanf("%s", &a);
        system("cls");
    }
    else
    {
<<<<<<< HEAD
        printf("¿À·ù! Àß¸øµÈ ÀÔ·Â°ªÀÔ´Ï´Ù. ´Ù½Ã ½ÃµµÇØÁÖ¼¼¿ä.\n");
=======
        printf("ì˜¤ë¥˜! ì˜ëª»ëœ ì…ë ¥ê°’ì…ë‹ˆë‹¤. ë‹¤ì‹œ ì‹œë„í•´ì£¼ì„¸ìš”.\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
    }
}

/* main function */

int main()
{
    init();
<<<<<<< HEAD
    printf("Nabin Market ¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n\n");
=======
    printf("Nabin Market â”€â”€â”€â”€â”€â”€â”€\n\n");
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115

    printf(" * ë‚˜ë¹ˆ ë§ˆì¼“ì— ì˜¤ì‹  ê²ƒì„ í™˜ì˜í•©ë‹ˆë‹¤. \n");
    printf(" * ë‚˜ë¹ˆ ë§ˆì¼“ì€ C++ë¡œ êµ¬í˜„í•œ ë§¤ì¥ ë¬¼í’ˆ ê´€ë¦¬ í”„ë¡œê·¸ë¨ì…ë‹ˆë‹¤. \n\n");

    while (1)
    {
<<<<<<< HEAD
        /* ¹°Ç° °³¼ö ±¸ÇÏ±â */
=======
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        int count = 0;
        struct Node *countHead = head;
        while (countHead != NULL)
        {
            count++;
            countHead = countHead->next;
        }

<<<<<<< HEAD
        printf("³ªºó ¸¶ÄÏ ÇöÈ² ¦¡¦¡¦¡¦¡¦¡\n\n");

        printf(" * ³ªºó ¸¶ÄÏ ÇöÀç ¹°Ç° °³¼ö (µ¥ÀÌÅÍ °³¼ö) : %d\n", count - 1);
        printf(" * ³ªºó ¸¶ÄÏ ÇöÀç Áø¿­ °ø°£ (¸Ş¸ğ¸® Å©±â) : %d\n\n", (count - 1) * (sizeof(head)));

        printf("³ªºó ¸¶ÄÏ ¸Ş´º ¦¡¦¡¦¡¦¡¦¡\n\n");

        printf(" * ¹°Ç° ¸ñ·Ï Á¶È¸ ( 1À» ´©¸£¼¼¿ä )\n");
        printf(" * Æ¯Á¤ ¹°Ç° °Ë»ö ( 2¸¦ ´©¸£¼¼¿ä )\n");
        printf(" * ¸¶ÄÏ ¹°Ç° Ãß°¡ ( 3¸¦ ´©¸£¼¼¿ä )\n");
        printf(" * ¸¶ÄÏ ¹°Ç° »èÁ¦ ( 4À» ´©¸£¼¼¿ä )\n");
        printf(" * ¹°Ç° Âò & ±¸¸Å ( 5¸¦ ´©¸£¼¼¿ä )\n\n");
        printf("¸Ş´º¸¦ ¼±ÅÃÇÏ¼¼¿ä : ");
        scanf("%d", &userselect);

        if (userselect == 1) // Á¶È¸
        {
            showAllItem(head);
        }
        else if (userselect == 2) // °Ë»ö
        {
            findItem(head);
        }
        else if (userselect == 3) // Ãß°¡
        {
            insertItem();
        }
        else if (userselect == 4) // »èÁ¦
        {
            deleteItem(head);
        }
        else if (userselect == 5) // ±¸¸Å
=======
        printf("ë‚˜ë¹ˆ ë§ˆì¼“ í˜„í™© â”€â”€â”€â”€â”€\n\n");

        printf(" * ë‚˜ë¹ˆ ë§ˆì¼“ í˜„ì¬ ë¬¼í’ˆ ê°œìˆ˜ (ë°ì´í„° ê°œìˆ˜) : %d\n", count - 1);
        printf(" * ë‚˜ë¹ˆ ë§ˆì¼“ í˜„ì¬ ì§„ì—´ ê³µê°„ (ë©”ëª¨ë¦¬ í¬ê¸°) : %d\n\n", (count - 1) * (sizeof(head)));

        printf("ë‚˜ë¹ˆ ë§ˆì¼“ ë©”ë‰´ â”€â”€â”€â”€â”€\n\n");

        printf(" * ë¬¼í’ˆ ëª©ë¡ ì¡°íšŒ ( 1ì„ ëˆ„ë¥´ì„¸ìš” )\n");
        printf(" * íŠ¹ì • ë¬¼í’ˆ ê²€ìƒ‰ ( 2ë¥¼ ëˆ„ë¥´ì„¸ìš” )\n");
        printf(" * ë§ˆì¼“ ë¬¼í’ˆ ì¶”ê°€ ( 3ë¥¼ ëˆ„ë¥´ì„¸ìš” )\n");
        printf(" * ë§ˆì¼“ ë¬¼í’ˆ ì‚­ì œ ( 4ì„ ëˆ„ë¥´ì„¸ìš” )\n");
        printf(" * ë¬¼í’ˆ ì°œ & êµ¬ë§¤ ( 5ë¥¼ ëˆ„ë¥´ì„¸ìš” )\n\n");
        printf("ë©”ë‰´ë¥¼ ì„ íƒí•˜ì„¸ìš” : ");
        scanf("%d", &userselect);

        if (userselect == 1)
        {
            showAllItem(head);
        }
        else if (userselect == 2)
        {
            findItem(head);
        }
        else if (userselect == 3)
        {
            insertItem();
        }
        else if (userselect == 4)
        {
            /* deleteItem(); */
        }
        else if (userselect == 5)
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
        {
            /* buyItem(); */
        }
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> 2573e5326daedbbf95e0e7bfb3ffd4b772f48115
