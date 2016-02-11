#include<stdio.h>
#include<string.h>

char sletters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char cletters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void encrypt() {
    char msg[256], enc[256],key[256];
    int key_len,i,j,x,y;
    printf("\nEnter plaintext (w/o spaces) : ");
    scanf("%s", &msg);
    printf("\nEnter key (w/o spaces) : ");
    scanf("%s", &key);
    key_len=strlen(key);
    if(key_len<256) {
        for(i=key_len,j=0;i<strlen(msg);i++,j++)
            key[i]=key[j];
    }
    for(i=0;i<strlen(msg);i++)
        key[i]=tolower(key[i]);
    for(i=0;i<strlen(msg); i++) {
        if(msg[i]>=97 && msg[i]<=122){
            for(j=0;j<26;j++) {
                if(sletters[j]==msg[i])
                    x=j;
                if(sletters[j]==key[i])
                    y=j;
            }
            enc[i]=sletters[((x+y)%26)];
        }
        else if(msg[i]>=65 && msg[i]<=90) {
            for(j=0;j<26;j++) {
                if(cletters[j]==msg[i])
                    x=j;
                if(sletters[j]==key[i])
                    y=j;
            }
            enc[i]=cletters[((x+y)%26)];
        }
        else {
            enc[i]=msg[i];
        }
    }
    enc[i]='\0';
    printf("\nCiphertext : %s", enc);
}

void decrypt() {
    char enc[256], dec[256],key[256];
    int key_len,i,j,x,y;
    printf("\nEnter ciphertext (w/o spaces) : ");
    scanf("%s", &enc);
    printf("\nEnter key (w/o spaces) : ");
    scanf("%s", &key);
    key_len=strlen(key);
    if(key_len<256) {
        for(i=key_len,j=0;i<strlen(enc);i++,j++)
            key[i]=key[j];
    }
    for(i=0;i<strlen(enc);i++)
        key[i]=tolower(key[i]);
    for(i=0;i<strlen(enc); i++) {
        if(enc[i]>=97 && enc[i]<=122){
            for(j=0;j<26;j++) {
                if(sletters[j]==enc[i])
                    x=j;
                if(sletters[j]==key[i])
                    y=j;
            }
            dec[i]=sletters[((x+y)%26)];
        }
        else if(enc[i]>=65 && enc[i]<=90) {
            for(j=0;j<26;j++) {
                if(cletters[j]==enc[i])
                    x=j;
                if(sletters[j]==key[i])
                    y=j;
            }
            dec[i]=cletters[((x+y)%26)];
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
