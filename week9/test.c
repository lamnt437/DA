#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100

struct tnode {
	char *word;
   int count;
   struct tnode *left;
   struct tnode *right;
};

struct tnode *talloc(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}
void tree_write(FILE *fp,struct tnode *p)
{
     if (p != NULL){
           fwrite(p->word,MAXWORD,1,fp);
           fwrite(&p->count,sizeof(int),1,fp);
           tree_write(fp,p->left);
           tree_write(fp,p->right);
     }
}

struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL) {
    p = talloc();
      p->word = strdup(w);
      p->count = 1;
      p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;
  else if (cond < 0)
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);
  return p;
}

int main (int argc, char *argv[])
{
       struct tnode *root = NULL;
       char word[MAXWORD];
         FILE *fin,*fout;
         int count,i;
         if (argc < 3){
            fprintf(stderr,"Program requires at least 1 input and     1 output file!\n");
            exit(1);
         }
         else {
              if ((fout = fopen(argv[argc-1], "rb")) != NULL){
                 fread(word,MAXWORD,1,fout);
                 fread(&count,sizeof(int),1,fout);
                 while (!feof(fout)){
                       root = ins_tree(root, word, count);
                       fread(word,MAXWORD,1,fout);
                       fread(&count,sizeof(int),1,fout);
                 }
                 fclose(fout);
              }
         }
        for(i=1; i<argc-1; i++) {
             if ((fin = fopen(argv[i], "r")) == NULL)
                  printf("File %s cannot be opened!\n",argv[i]);
             else {
               while (getword(fin, word, MAXWORD) != EOF)
                    if (isalpha(word[0]))
                           root = addtree(root, word);
                      fclose(fin);
             }
        }
        if ((fout = fopen(argv[argc-1], "wb")) == NULL) {
           fprintf(stderr,"File %s cannot be opened!\n",argv[argc-1]);
           exit(2);
        }
        else {
            tree_write(fout,root);
            fclose(fout);
        }
        return 0;
}
