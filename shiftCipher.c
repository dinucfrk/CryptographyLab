#include<stdio.h>
#include<string.h>

char sletters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char cletters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void encrypt(){
    char msg[256], enc[256];
    int key,i,j;
    printf("\nEnter plaintext (w/o spaces) : ");
    scanf("%s", &msg);
    printf("\nEnter key : ");
    scanf("%d", &key);
    for(i=0;i<strlen(msg); i++) {
        if(msg[i]>=97 && msg[i]<=122){
            for(j=0;j<26;j++) {
                if(sletters[j]==msg[i])
                    enc[i]=sletters[((j+key)%26)];
            }
        }
        else if(msg[i]>=65 && msg[i]<=90) {
            for(j=0;j<26;j++) {
                if(cletters[j]==msg[i])
                    enc[i]=cletters[((j+key)%26)];
            }
        }
        else {
            enc[i]=msg[i];
        }
    }
    enc[i]='\0';
    printf("\nCiphertext : %s", enc);
}

void decrypt() {
    char enc[256], dec[256];
    int key,i,j;
    printf("\nEnter ciphertext (w/o spaces) : ");
    scanf("%s", &enc);
    printf("\nEnter key : ");
    scanf("%d", &key);
    for(i=0;i<strlen(enc); i++) {
        if(enc[i]>=97 && enc[i]<=122){
            for(j=0;j<26;j++) {
                if(sletters[j]==enc[i])
                    dec[i]=sletters[((j+key)%26)];
            }
        }
        else if(enc[i]>=65 && enc[i]<=90) {
            for(j=0;j<26;j++) {
                if(cletters[j]==enc[i])
                    dec[i]=cletters[((j+key)%26)];
            }
        }
        else {
            dec[i]=enc[i];
        }
    }
    dec[i]='\0';
    printf("\nPlaintext : %s", dec);
}

int main() {
    int ch;
    printf("Menu :\n1. Encrypt\n2. Decrypt\nChoose : ");
    scanf("%d", &ch);
    switch(ch) {
        case 1:     encrypt();
                    break;
        case 2:     decrypt();
                    break;
        default:    printf("\nWrong choice\n");
                    break;
    }
    return 0;
}
