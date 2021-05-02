/*コマンド引数として１つのファイルを受け取り、そのファイルから整数を次々と読み込んでいきます。受け取ったファイルに整数以外の空白や改行があった場合には読み飛ばします。１つの整数を読み込んだらその値とそれまでの入力回数、総和を出力します。また、表示する整数の値はすべて桁が揃えられた状態で出力されます。*/

#include <stdio.h>
#include <stdlib.h>

int maxDigit(int numArr[], int n);
int digitCount(int num);
int main(int argc, char *argv[])
{
  FILE *f;
  int i, j = 0 , k,c;
  int numArr[100];
  int sum[1000], integerCount = 0, tmp = 0, sign = 1;
  int diff,maxdigit;

  if(argc != 2) {
    fprintf(stderr,"number of command arguments should be 2\n");
    exit(1);
  }
  
  f = fopen("integers.txt","r");
  if(f == NULL) {
    fprintf(stderr, "%s cannot be opend\n",argv[1]);
    exit(1);
  }

  for(i = 0; i < 1000; i++) {
    numArr[i] = 0;
  }
  for(i = 0; i < 1000; i++) {
    sum[i] = 0;
  }

  c = getc(f);
  while(c != EOF) {
    if(c == 45) {
      sign = -1;
    }
    if(c > 47 && c < 58) {
      tmp *= 10;
      tmp += c - 48;
    }
    if( c == 32 || c == 10) {
      numArr[j] = tmp * sign;
      j++;
      sign = 1;
      tmp = 0;
      integerCount++;
      sum[integerCount] = sum[integerCount - 1] + numArr[j-1];
      while(c == 32 || c == 10) {
	c = getc(f);
      }
      if(c == 45) {
	sign = -1;
      }
      if(c > 47 && c < 58) {
	tmp *= 10;
	tmp += c-48;
      }
    }
    c = getc(f);
  }

  
  maxdigit = maxDigit(numArr,integerCount);
  
  for(i = 0; i < integerCount; i++) {
    diff = maxdigit - digitCount(numArr[i]);
    for(k = 0; k < diff; k++) {
      printf(" ");
    }
    printf("%d\n",numArr[i]);
    printf("入力中の整数の個数 : %d\n",i+1);
    printf("入力中の整数の総和 : %d\n",sum[i+1]);
  }
  
  fclose(f);
  return 0;
}

int maxDigit(int numArr[], int n)
{
  int  max = 0, digit = 0;
  int i, tmp;

  for(i = 0; i < n; i++) {
    tmp = numArr[i];
    while(tmp != 0) {
      tmp = tmp / 10;
      digit++;
    }
    if(numArr[i] < 0) {
      digit++;
    }
    if(digit > max) {
      max = digit;
    }
    digit = 0;
  }

  return max;
}

int digitCount(int num) {
  int  digit = 0;
  if(num < 0) {
    digit++;
  }
  while(num != 0) {
    num = num / 10;
    digit++;
  }
  return digit;
}
