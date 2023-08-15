#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class CArray
{
private:
  int *ary;
  int count;
public:
  CArray(int num) :count(num) //CArray Ary1(3); 값을 받아오는 기능이다. 3이 num에 들어가서 작동. count = num
  {
    ary = new int[count]; //배열에 새로운 값을 생성 3칸 생성
    for (int i = 0; i < count; i++) //3번 반복
      ary[i] = rand() % 10 + 1 ; // ary[i]번째 칸에 rand()함수 사용. 그 함수 값에 10을 나누고 남은 나머지 값에 1을 더함. 1을 더하는 이유는 0을 만들지 않기 위함.
  }
  ~CArray() //소멸자
  {
    delete [] ary; //새롭게 생성된 ary함수를 소멸.
  }
  CArray(const CArray &copy) //복사 생성자 //복사할 배열을 매개변수로 받는 방법.
  {
    count = copy.count; // 복사한 배열의 count 값을 받는다. 
    ary = new int[count]; // 그 count로 새로운 배열을 만든다. 
    for (int i = 0; i < count; i++) // count 값만큼 반복해서 값 할당
      ary[i] = copy.ary[i]; // 새로운 ary[i]에 복사할 이전 배열의 값을 그대로 자리마다 복사. 
      //비어있는 5칸 배열을 생성한 뒤, 복사해야할 배열을 반복문으로 붙여 넣음.
  }
  CArray &operator=(const CArray &copy)
  {
    delete[]ary;
    count = copy.count;
    ary = new int[count];
    for (int i = 0; i < count; i++)
      ary[i] = copy.ary[i];
    return (*this);
  }
  friend ostream &operator<<(ostream &out, const CArray Ao); //전역 함수에 의한 연산자 오버로딩
}; //출력연산자라서 const 붙이는 것 가능. 값을 바꿀 필요가 없기 때문. 입력연산자는 const X
//입출력 연산자는 전역함수로만 구현될 수 있다. 
ostream &operator<<(ostream &out, const CArray Ao)
{
  for (int i = 0; i < Ao.count; i++)
    out << Ao.ary[i] << "\t";
  return out;
}

int main(void)
{
  srand((unsigned)time(NULL));
  CArray Ary1(3);
  CArray Ary2(5);

  cout << Ary1 << endl;
  cout << Ary2 << endl;
  
  Ary1 = Ary2;

  cout << Ary1 << endl;
  cout << Ary2 << endl;

  return 0;
}