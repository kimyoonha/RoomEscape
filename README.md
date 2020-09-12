## 객.지.프 2주차 퀴즈

방탈 라이브러리를 사용해서 다음 요구사항을 만족하는 간단한 방탈출 게임을 만들어보았습니다.

* 요구사항
  * 2개 이상의 장면
  * 2개 이상의 장면이 문으로 연결
  * 숨겨진 문을 클릭하면 게임 종료

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
