#include <stdio.h>

int main(int argc, char *argv[]){
  // (28/4) = 7
  int arr[7];
  arr[0] = 100; // [esp+1Ch]

  if(arr[0] <= 999){
    // [esp+18h]
    arr[1] =(((1374389535 * (long long)arr[0]))
                    >> 32) // only consider top 32 bits of product (EDX)
                    >> 5; // bitshift by 5
    // printf("[-40] = %d, should be 1\n", arr[1]);

    // [esp+14h]
    arr[2] = ((((long unsigned)((arr[1]*(unsigned)(-100))^100)*1717986919)
                    >> 32) // only consider top 32 bits
                    >> 2) // bitshift by 2
              - (((arr[1]*(unsigned)(-100))^100)>> 31);
    // printf("[-44] = %d, should be 429496727\n", arr[2]);

    // [esp+10h]
    arr[3] = arr[0] - (((((((1717986919 * (long)arr[0])
                          >> 32) // only consider top 32 bits
                          >> 2) // bitshift by 2
                          - ((long)arr[0] >> 31))
                          << 2)
                          + (((1717986919 * (long)arr[0]) >> 32)>> 2))
                          *2);
    // printf("[-48] = %d, should be 0\n", arr[3]);
    
		if(arr[0] != ((arr[1]*arr[1]*arr[1])
									* ((((unsigned long)(arr[2]*arr[2]))*(unsigned long)arr[2]) >> 32) // EDX
                      +(((unsigned)((unsigned long)(arr[2]*arr[2])))*arr[2]) // EAX
									+(arr[3]*arr[3]*arr[3])))
    {
			arr[0] += 1;
		}
		printf("%d", arr[0]);
  }
  return 0;
}
