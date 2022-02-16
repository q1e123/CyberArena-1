// Flash.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

void nothing_here(void)

{
    srand(0xa8);
    return;
}


void guessing(void)

{
    unsigned int uVar1;
    int iVar2;
    int iVar3;
    unsigned int uVar4;
    unsigned int local_c=0;

    nothing_here();
    uVar1 = rand();
    iVar2 = rand();
    iVar3 = rand();
    uVar4 = rand();
    while(uVar4 != (local_c ^ uVar1 ^ iVar3 + iVar2 ^ 0x237))
    {
        local_c += 1;
    }
    printf("sol: %u\n", local_c);
    if (uVar4 == (local_c ^ uVar1 ^ iVar3 + iVar2 ^ 0x237)) {
        puts(
            "Password Accepted, welcome to srand() FUNCTION ! Submit input as flag! (Don\'t forget to wrap it in CTF{sha256(number)})"
        );
    }
    else {
        puts("That\'s incorrect. Try going to find the right value.");
    }
    return;
}


int main()
{
    guessing();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
