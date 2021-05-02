/*コマンド引数としていくつかのファイルを受け取り、受け取ったファイルを順に標準出力に表示します。*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *f;
  int c, i;

  if(argc < 2) {
    fprintf(stderr, "number of command arguments should be more 2\n");
    exit(1);
  }

  for(i = 1; i < argc; i++) {
    f = fopen(argv[i], "r");
    if(f == NULL) {
      fprintf(stderr, "%s cannot be opened\n", argv[i]);
      exit(1);
    }
    c = getc(f);
    while (c != EOF) {
      putchar(c);
      c = getc(f);
    }
    fclose(f);
  }
  
  return 0;
}
