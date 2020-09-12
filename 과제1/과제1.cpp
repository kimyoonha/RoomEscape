#include <bangtal.h>
using namespace bangtal;


int main()
{
	// 1. 장면을 생성한다.
	ScenePtr scene1 = Scene::create("룸1", "Images/배경-1.png");
	auto scene2 = Scene::create("룸2", "Images/배경-2.png");

	// 3. 문을 생성한다.
	auto open1 = false;
	auto door1 = Object::create("Images/문-오른쪽-닫힘.png", scene1, 800, 270);

	// 4. 문을 클릭하면 이동한다.	// lambda function 람다함수 (따로 함수 정의하지 않고 필요한 곳에 함수 선언)
	door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2->enter();
		return true;
	});

	auto door2 = Object::create("Images/문-왼쪽-열림.png", scene2, 320, 270);
	door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		return true;
	});

	auto lighted = true; //불이 켜진 상태
	auto button = Object::create("Images/스위치.png", scene2, 880, 440);
	button->setScale(2.0f);

	auto door3_shown = false;
	auto door3 = Object::create("Images/문-오른쪽-닫힘.png", scene2, 900, 270, false);

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
		else {			//꺼진 상태
			scene2->setLight(1.0f);
			door3->hide();
			lighted = true;
		}
		return true;
	});


			// 2. 게임을 시작한다.
			startGame(scene1);

			return 0;
}