#include<stdio.h>
/*Cac ham co ban giong nhau ta se su dung con tro ham, 
Con tro ham la mot con tro ban chat luu dia chi cua ham */
void sum(int a, int b){
    printf("\nDay la chuong trinh tinh tong hai so\n");
    printf("tong a va b %d + %d= %d\n", a, b, a+b);
}

void subtract(int a, int b){
    printf("\nDay la chuong trinh tinh hieu hai so\n");
    printf("hieu %d va %d = %d\n", a, b, a-b);
}

int multiplication(int a, int b){
    printf("\nDay la chuong trinh tinh tich hai so\n");
    printf("tich %d va %d = %d\n", a, b, a*b);
    return (a*b);
}

//Ta co the su dung mot ham lam input parameter cua ham khac 
void Caculation(int a, int b, void(*ptr_ham(int, int))){    
    printf("Day la chuong trinh tinh toan dai so!!");
    ptr_ham(a,b);
}

typedef struct 
{
    int x;
    int y;
    void (*type)(int, int); /* Con tro ham dong vai tro la mot member cua struct */
}cacl;


int main(int argc, char const *argv[])
{
    void (*ptr_ham)(int, int);//////DAY LA CON TRO HAM
    int (*ptrham)(int, int);   // Co the tro den cac ham co kieu tra ve ve int

    ptr_ham = &sum;         ///Khong goi  ham tong, ta goi ham tong thong qua con tro ham
    ptrham = &multiplication;

    ptr_ham(1,7);
    ptrham (2,5);

    Caculation(7,2, &subtract);

    cacl tinh = {5, 6, &sum};
    tinh.type(tinh.x, tinh.y);
    return 0;
}
