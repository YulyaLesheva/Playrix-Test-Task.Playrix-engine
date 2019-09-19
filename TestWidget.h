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
class Effect;

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
	void AcceptMessage(const Message& message) override;
	void CheckCollisions();
	void CreateTargets();
	bool _running;
	std::unique_ptr <Background> _bg;
	std::unique_ptr <StaticObjects> _stand;
	std::unique_ptr <StaticObjects> _clock;
	std::unique_ptr <Cannon> _cannon;
	std::unique_ptr <Aim> _aim;
	std::unique_ptr <Effect> _effect;

	Render::Texture* fuck;
	void ObjectsRemoving();

	EffectsContainer _effCont;
	ParticleEffectPtr _eff;

private:
	void Init();

private:

};
