#include <stdio.h>

int main(int argc, char *argv[]){

  // FIRST

  // vars a through h, no difference in how asm interprets them.
  int arr[] = {12, 15, 221, 3, 432, 52, 16, 67};
  int i = 0;
  int k = 0;

  // SECOND
  if(k <= 7){
    // THIRD
    if(arr[k] <= i){
      // UNUSED
      k += 1;
    }
    i = arr[k];
  }
  printf("%d", i);

  return 0;
}
