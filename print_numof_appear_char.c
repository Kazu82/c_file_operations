/*一つのファイルをコマンド引数として受け取り、そのファイルに含まれる文字の出現回数の一覧を表示します。*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *f;
  int c,i;
  int count[260];

  if(argc != 2) {
    fprintf(stderr, "number of command arguments should be 1\n");
    exit(1);
  }

  f = fopen(argv[1], "r");
  if(f == NULL) {
    fprintf(stderr, "%s cannot be opened\n", argv[1]);
    exit(1);
  }

  for(i = 0;i < 256; i++)
    count[i] = 0;

  c = getc(f);
  while( c != EOF) {
    count[c] ++;
    c = getc(f);
  }

  fclose(f);
  printf("文字の出現回数一覧表\n");
  for(i = 0;i < 32; i++) {
    printf("a[%3d]    : %d 回  ",i,count[i]);
    if((i + 1) % 4 == 0) {
      printf("\n");
    }
  }
  for(i = 32;i < 127; i++) {
    printf("a[%3d](%c) : %d 回  ",i,i,count[i]);
    if((i+1) % 4 == 0) {
      printf("\n");
    }
  }
  for(i = 127;i < 256; i++) {
    printf("a[%3d]    : %d 回  ",i,count[i]);
    if((i+1) % 4 == 0) {
      printf("\n");
    }
  }
  printf("\n");
  return 0;
}
    
