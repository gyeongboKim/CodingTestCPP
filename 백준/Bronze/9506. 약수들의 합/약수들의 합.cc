#include <iostream>
#include <list>
#include <vector>
#include <numeric>



int main(){
  // 한 줄간격으로 n을 입력
  // 입력마다 한줄에 하나 씩 출력
  // 1. n이 완전수라면 n을 n이 아닌 약수들의 합으로 오름차순 나열하여 출력
  // 2. n이 완전수가 아닐 경우 n is NOT perfect 출력.
  
  int NaturalNum = 0;
  while(1){
    std::cin>>NaturalNum;

    //-1 입력 시 종료
    if(NaturalNum == -1){
      break;
    }


    //약수들을 저장할 리스트 선언
    std::list<int> Divisor;
    std::list<int>::iterator DivisorIterator;
    Divisor.push_front(1);
    for(int i = 2; i < NaturalNum ; i++){
      //i가 NaturalNum의 약수일 경우
      if(NaturalNum%i == 0){
        Divisor.push_back(i);
      }
    }

    
    //약수들의 합 계산
    int sum = std::accumulate(Divisor.begin(), Divisor.end(), 0);
    

    //Divisor 가 완전수가 아닌 경우
    if(NaturalNum != sum){
      std::cout<<NaturalNum<<" is NOT perfect.";
    //Divisor가 완전수인 경우
    }else if(NaturalNum == sum){
      std::cout<<NaturalNum<<" = ";
      for(DivisorIterator = Divisor.begin(); DivisorIterator != Divisor.end() ; ++DivisorIterator){
        if(DivisorIterator != Divisor.begin()) std::cout<<" + ";
        std::cout<<*DivisorIterator;
      }
    }
    std::cout<<"\n";
  }
  
}