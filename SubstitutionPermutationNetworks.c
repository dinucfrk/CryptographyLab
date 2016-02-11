#include<stdio.h>
#include<math.h>

int main() {
    int key[3][16] = {{0,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0}, {1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0}, {0,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1}};
    int perm[16] = {3,2,16,1,15,11,4,7,8,13,9,10,14,5,12,6};
    int subs[16] = {14,4,13,1,2,15,11,8,9,10,6,12,5,9,0,7};
    int msg[16]; //={0,0,1,0,0,1,1,0,1,0,1,1,0,1,1,1};
    int i,j,k,n,xored[16],pxored[16],hex[4],subbed[4],l,bin[16];

    printf("Enter plaintext (16 integers) : ");
    for(i=0;i<16;i++)
        scanf("%d", &msg[i]);
    printf("\nEnter no. of iterations : ");
    scanf("%d", &n);

    for(i=0;i<n;i++) {

        printf("\n#%d:",i);
        //xor with key
        for(j=0;j<16;j++){
            xored[j] = msg[j] ^ key[i][j];
        }
        printf("\nXOR : ");
        for(j=0;j<16;j++) {
            printf("%d",xored[j]);
        }
        //convert to hexadecimal
        for(j=0;j<16;j=j+4) {
            hex[j/4]=0;
            for(k=0;k<4;k++) {
                hex[j/4] += xored[j+k] * pow(2,(3-k));
            }
        }
        printf("\nHEX : ");
        for(j=0;j<4;j++) {
            printf("%d ", hex[j]);
        }
        //substitue
        for(j=0;j<4;j++) {
            subbed[j] = subs[hex[j]];
        }
        printf("\nSUBSTITUTED : ");
        for(j=0;j<4;j++) {
            printf("%d ", subbed[j]);
        }
        //convert to binary
        for(j=0,k=0;j<4;j++) {
            for (l = 1 << 3; l > 0; l = l / 2) {
                if(subbed[j] & l)
                    bin[k++]=1;
                else
                    bin[k++]=0;
            }
        }
        printf("\nCONVERTED : ");
        for(j=0;j<16;j++) {
            printf("%d", bin[j]);
            if((j+1)%4==0)
                printf(" ");
        }
        //permute
        for(j=0;j<16;j++) {
            pxored[j] = bin[perm[j]-1];
        }
        printf("\nPERMUTATED : ");
        for(j=0;j<16;j++){
            printf("%d",pxored[j]);
            if((j+1)%4==0)
                printf(" ");
        }


    }
    printf("\nPlain text : ");
    for(i=0;i<16;i++)
        printf("%d", msg[i]);
    printf("\nCiphertext : ");
    for(i=0;i<16;i++)
        printf("%d", pxored[i]);
    return 0;
}
