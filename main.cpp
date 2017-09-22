#include <iostream>
#include <stdlib.h>
#include <ctime>



#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif

  
int main (int argc, char* argv[]) {

  if (argc < 6) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  }
  
  int id = atoi(argv[1]),
      intense = atoi(argv[5]);
  float a = atof(argv[2]),
        b = atof(argv[3]),
        n = atof(argv[4]),
        sum = 0;
  
  clock_t begin = clock();
  
  switch(id) {
    case 1:
      for(int i = 0; i < n; i++) {
        sum += f1((a + (i + .5)) * ((b - a) / n), intense) * ((b - a) / n);
      }
      break;
    case 2:
      for(int i = 0; i < n; i++) {
        sum += f2((a + (i + .5)) * ((b - a) / n), intense) * ((b - a) / n);
      }
      break;
    case 3:
      for(int i = 0; i < n; i++) {
        sum += f3((a + (i + .5)) * ((b - a) / n), intense) * ((b - a) / n);
      }
      break;
    case 4:
      for(int i = 0; i < n; i++) {
        sum += f4((a + (i + .5)) * ((b - a) / n), intense) * ((b - a) / n);
      }
      break;
  }
  
  clock_t end = clock();
  double duration = double(end - begin);
  
  std::cout << sum << std::endl;
  std::cerr<< duration << std::endl;
  
  return 0;
}
