/*コマンドcmpと同じような機能を持つプログラムコードを作成しました。*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *f1, *f2;
  int c1, c2, count = 0;

  if( argc != 3) {
    fprintf(stderr, "number of command arguments should be 2\n");
    exit(1);
  }
  f1 = fopen(argv[1], "r");
  if(f1 == NULL) {
    fprintf(stderr, "%s cannot be opend\n", argv[1]);
    exit(1);
  }

  f2 = fopen(argv[2], "r");
  if(f2 == NULL) {
    fprintf(stderr, "%s cannot be opend\n", argv[2]);
    exit(1);
  }

  c1 = getc(f1);
  c2 = getc(f2);
  while(1) {
    if( c1 != c2) {
      printf("先頭からの %d バイトは等しいが %d バイト目が等しくない\n",count,count+1);
      break;
    }
    else if( c1 == EOF && c2 == EOF) {
      printf("等しい\n");
      break;
    }
    else if(c1 == EOF) {
      printf("%sファイルの終わりまでは一致\n",argv[1]);
      break;
    }
    else if(c2 == EOF) {
      printf("%sファイルの終わりまでは一致\n",argv[2]);
      break;
    }
    count++;
    c1 = getc(f1);
    c2 = getc(f2);
  }
  fclose(f1);
  fclose(f2);
  return 0;
}

  
