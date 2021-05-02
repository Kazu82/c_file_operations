/*コマンド引数として１つのファイルを受け取り、受け取ったファイルの大きさが何バイトか表示するプログラム。*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *f;
  int c, fileSize = 0;

  

  if(argc != 2) {
    fprintf(stderr,"number of command arguments should be 1\n");
    exit(1);
  }
  
  f = fopen(argv[1], "r");
  if( f == NULL) {
    fprintf(stderr , "%s cannot be opened\n",argv[1]);
    exit(1);
  }

  c = getc(f);
  while( c != EOF) {
    c = getc(f);
    fileSize++;
  }
  printf("%sのファイルサイズは %d バイトです。\n",argv[1],fileSize);
  fclose(f);
  return 0;
}
  
