#include "main.h"

typedef struct _Man{ 
    uint64_t first;
    uint64_t second;
    uint64_t symmetry;
}Man;

#define G 2
#define P 101

void privatekey(uint64_t *a, uint64_t *b){
    System.out.printf("Input Private Key A: ");
    scanf("%lld", a);
    System.out.printf("Input Private Key B: ");
    scanf("%lld", b);
}

uint64_t squared(uint64_t i){
    if(!i) return 1 % P;
    else return (G << (i - 1)) % P;
}

uint64_t hellman(uint64_t i, uint64_t j){
    uint64_t r;
    r = j;
    for(int a = 0; a < i; a++){
        r *= j;
    }
    return (r % P);
}

void replay_Request(boolean *loop){
    char a;
    printf("Would you like to do it again? (Y/N) ");
    scanf("%c", &a);
    getchar();
    if(a == 'N' || a == 'n') *loop = false;
    else *loop = true;
}

int main(void){
    boolean loop = true;
    Man a, b;

    while(loop){
        privatekey(&a.first, &b.first);
        b.second = squared(a.first);
        a.second = squared(b.first);
        a.symmetry = hellman(a.first, a.second);
        b.symmetry = hellman(b.first, b.second);
        System.out.println("A:%lld B:%lld", a.symmetry, b.symmetry);
        replay_Request(&loop);
    }

    return 0;
}
