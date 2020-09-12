## 객.지.프 2주차 퀴즈

방탈 라이브러리를 사용해서 다음 요구사항을 만족하는 간단한 방탈출 게임을 만들어보았습니다.

* 요구사항
  * 2개 이상의 장면
  * 2개 이상의 장면이 문으로 연결
  * 숨겨진 문을 클릭하면 게임 종료
  
**1. 첫 번째 방**
![image](https://user-images.githubusercontent.com/70989454/92996035-4fe14a00-f543-11ea-8920-f0d9d8b80804.png)
 첫 번째 방은 아무런 함정이 구현되어 있지 않은 방입니다.
 바로 보이는 문을 통해 두 번째 방으로 들어가면 됩니다.


**2. 두 번째 방**
![image](https://user-images.githubusercontent.com/70989454/92996080-9f277a80-f543-11ea-8c8e-a45d8c0d0390.png)
두 번째 방의 정중앙에서 약간 오른쪽을 보시면 스위치가 있습니다.
이 스위치를 누르면 불이 꺼지게 되고,
![image](https://user-images.githubusercontent.com/70989454/92996090-b8302b80-f543-11ea-8cf8-2cc7704d61d9.png)
불이 꺼지면 다음과 같이 숨겨진 문이 나타나 이 문을 열고 나가게 되면 게임은 끝이 납니다.

 
스위치를 눌렀을 때의 상황을 나타내는 코드는 다음과 같습니다.

```c++
   button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
      if (lighted) { //켜진 상태
         scene2->setLight(0.2f);
         door3->show();
         lighted = false;
         door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            showMessage("철커덕~~~");
            endGame();
            return true;
         });
      }
      else {         //꺼진 상태
         scene2->setLight(1.0f);
         door3->hide();
         lighted = true;
      }
      return true;
   });
  ```
  
 위 코드를 통해 버튼을 눌러 **불을 껐을 때** 숨겨진 문이 나타나도록 설정을 하였고, 
 
 이 때 문을 클릭하면 "철커덕~~~ " 이라는 메세지와 함께 게임이 종료되도록 하였습니다.
