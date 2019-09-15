#pragma once

///
/// Виджет - основной визуальный элемент на экране.
/// Он отрисовывает себя, а также может содержать другие виджеты.
///
class Background;
class StaticObjects;
class Targets;
class Cannon;
class Cannonball;
class Aim;
class Labels;

class TestWidget : public GUI::Widget
{
public:
	TestWidget(const std::string& name, rapidxml::xml_node<>* elem);
	IPoint fuckPosition;
	void Draw() override;
	void Update(float dt) override;
	bool MouseDown(const IPoint& mouse_pos) override;
	void MouseMove(const IPoint& mouse_pos) override;
	void MouseUp(const IPoint& mouse_pos) override;
	void CheckCollisions();
	std::unique_ptr <Background> _bg;
	std::unique_ptr <StaticObjects> _stand;
	std::unique_ptr <StaticObjects> _clock;
	std::unique_ptr <Cannon> _cannon;
	std::unique_ptr <Aim> _aim;
	std::unique_ptr <Labels> _timer;
	Render::Texture* fuck;
	bool check;
	void ObjectsRemoving();
	int fuckyou;
	void timerEvent();

	float eventTimer;
	float currentCounter;
	int frameCounter;
private:
	void Init();

private:
	int _screenWidth;

};
