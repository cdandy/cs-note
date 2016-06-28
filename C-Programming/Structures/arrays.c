/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arrays.c
 * Author: changdi
 *
 * Created on 2016年6月28日, 下午5:34
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

char *keyword[NKEYS];
int keyword[NKEYS];

#define MAXWORD 100
int getword(char *, int);
int binsearch(char *, struct key *, int);

//char *word;
//int count;

/*
struct key{
    char *word;
    int count;
} keytab[NKEYS];
 */

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    /* ... */
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

/*
 * 
 * getword 每调用一次该函数，将读入一个单词，并将其复制到名字为该函数的第一个参数的数组中.
 */
int main(int argc, char** argv) {
    int n;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n",
                keytab[n].count, keytab[n].word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n) {
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
} 