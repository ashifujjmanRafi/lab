#include <stdio.h>
#include <string.h>

char str[100];

int is_digit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}

int is_char(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return 1;
    if (ch >= 'a' && ch <= 'z')
        return 1;
    return 0;
}

int is_vowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return 1;
    return 0;
}

int isValidDelimiter(char ch) {
    if (ch == ' ' || ch == '+'  || ch == '*' ||
    ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
    ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
    ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (1);

   return (0);
}
//solving a
void ano(char str[]){
    printf("A\n");
    int len = strlen(str) , i , j , words = 1 , letter = 0 , digits = 0 , other = 0;
    for(i = 0 ; i < len ; i++){
        if(str[i] == ' ' && str[i+1] != ' ')
            words++;
        if(is_char(str[i]))
            letter++;
        else if(is_digit(str[i]))
            digits++;
        else if(str[i] != ' ')
            other++;
    }
    printf("Number of Words = %d, letters = %d, digits = %d and others = %d\n",words,letter,digits,other);
}

char letters[100],digit[100],others[100];
int inl=0,ind=0,ino=0;
int markl[300],markd[300],marko[300];

void bno(char str[]){
    printf("B\n");

    int len = strlen(str) , i , j= 0 , k = 0 , l = 0;
    char letter[50] , digit[50] , other[50];
    for(i = 0 ; i < len ; i++){
        if(is_char(str[i]))
            letter[j++] = str[i];
        else if(is_digit(str[i]))
            digit[k++] = str[i];
        else if(str[i] != ' ') 
            other[l++] = str[i];
    }
    letter[j] = digit[k] = other[l] = '\0';
    printf("Letters: %s\nDigits: %s\nOthers: %s\n",letter,digit,other);
}
//counting vowel and consonent


void cno (char str[]) {
    printf("c\n");

    int len = strlen(str), vowel =0, consonant = 0,i;
    for ( i = 0; i < len; i++)
    {
        if (!is_char(str[i]))
        {
            continue;
        }
        if(!is_vowel(str[i]))vowel++;
        else consonant++;
        
    }
    printf("number of vowel : %d and consonant : %d\n",vowel,consonant);
    
}
int mark[30];

void dno(char str[]){
    printf("D\n");
    
    int len = strlen(str), i , j = 0 , k = 0;
    char vowel[50] , consonant[50]  , ch;
    for(i = 0 ; i < len ; i++){
        if(!is_char(str[i]))
            continue;
        ch = str[i];
        if(ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';
        if(is_vowel(ch) && mark[ch-'a'] == 0){
            vowel[j++] = str[i];
            mark[ch-'a'] = 1;
        }
        else if(mark[ch-'a'] == 0){
            consonant[k++] = str[i];
            mark[ch-'a'] = 1;
        }
    }
    vowel[j] = consonant[k] = '\0';
    printf("Vowel: %s and Consonant: %s\n",vowel,consonant);
}

void eno(char str[]){
    printf("e\n");
    int len = strlen(str),i,j=0,k=1,v[50],vw=0,cs=0;
    char vowel[10],consonant[30];
    v[0] =0;
    for ( i = 0; i < len; i++)
    {
        if(str[i]==' '&& i+1<len)
            v[k++]=i+1;
    }
    for ( i = 0; i < k; i++)
    {
        if (is_vowel(str[v[i]]))
        {
            vowel[vw++]=str[v[i]];
            j=v[i]+1;
            while (j<len && str[j] != ' ')
            {
                vowel[vw++] = str[j++];
            }   
        }   
    }
    vowel[vw]='\0';
    for ( i = 0; i < k; i++)
    {
        if (!is_vowel(str[v[i]])&&!is_digit(str[v[i]]))
        {
            consonant[cs++]=str[v[i]];
            j=v[i]+1;
            while (j<len&&!isValidDelimiter(str[j]))
            {
                consonant[cs++]=str[j++];
            }
            consonant[cs++]=' ';
            
        }
        
    }
    consonant[cs]='\0';
    puts("starting with vowel :");
    puts(vowel);
    puts("starting with consonant :");
    puts(consonant);
}

int main(){
    char str[100]="Md. Tareq Zaman, Part-3, 2011";
    ano(str);
    bno(str);
    cno(str);
    dno(str);
    eno(str);
    return 0;
    
}