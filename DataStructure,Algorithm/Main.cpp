#include "stdafx.h"
#include "LinkedListStack.h"

using namespace std;

int main()
{
    LinkedListStack* Stack;

    LLS_CreateStack(&Stack);
    LLS_Push(Stack, LLS_CreateNode((char*)"taewf"));
    LLS_Push(Stack, LLS_CreateNode((char*)"asdfe"));
    LLS_Push(Stack, LLS_CreateNode((char*)"as"));

    int count = LLS_GetSize(Stack);


    printf("size : %d, Top: %s\n\n", count, LLS_Top(Stack)->Data);

    return 0;
}

