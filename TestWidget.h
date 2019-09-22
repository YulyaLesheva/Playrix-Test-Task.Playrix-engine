#pragma once

///
/// Виджет - основной визуальный элемент на экране.
/// Он отрисовывает себя, а также может содержать другие виджеты.
///
class Background;
class Targets;
class Cannon;
class Cannonball;
class Aim;
class Effect;
class StaticObjects;
class TestWidget : public GUI::Widget
{
public:
	TestWidget(const std::string& name, rapidxml::xml_node<>* elem);
	
	void Draw() override;
	void Update(float dt) override;
	void MouseMove(const IPoint& mouse_pos) override;
	void MouseUp(const IPoint& mouse_pos) override;
	void AcceptMessage(const Message& message) override;

	bool MouseDown(const IPoint& mouse_pos) override;

private:
	void Init();
	void CheckCollisions();
	void CreateTargets();
	void ObjectsRemoving();

	bool _running;

	std::unique_ptr <Background> _bg;
	std::unique_ptr <Cannon> _cannon;
	std::unique_ptr <Aim> _aim;
	std::unique_ptr <Effect> _effect;
	std::unique_ptr <StaticObjects> _stand;

	using PinkTargetVector = std::vector<std::unique_ptr<Targets>>;
	PinkTargetVector _pinkTargets;

	using YellowTargetVector = std::vector<std::unique_ptr<Targets>>;
	YellowTargetVector _yellowTargets;

	using BombTargetVector = std::vector<std::unique_ptr<Targets>>;
	BombTargetVector _bombTargets;

	using CannonballVector = std::vector<std::unique_ptr<Cannonball>>;
	CannonballVector _cannonballs;

	using EffectVector = std::vector<std::unique_ptr<Effect>>;
	EffectVector _effects;

	using EffectPlumeVector = std::vector<std::unique_ptr<Effect>>;
	EffectVector _plumeEffects;
};
