#include "stdafx.h"
#include "TestWidget.h"
#include "Background.h"
#include "StaticObjects.h"
#include "Targets.h"
#include "RandomGenerate.h"
#include "Cannon.h"
#include "Cannonball.h"

TestWidget::TestWidget(const std::string& name, rapidxml::xml_node<>* elem)
	: Widget(name)
{
	Init();
}

using TargetVector = std::vector<std::unique_ptr<Targets>>;
TargetVector _targets;

using CannonballVector = std::vector<std::unique_ptr<Cannonball>>;
CannonballVector _cannonballs;


void TestWidget::Init()
{
	_bg = Background::createSprite(Core::resourceManager.Get<Render::Texture>("Background"));
	_stand = StaticObjects::createSprite(Core::resourceManager.Get<Render::Texture>("Stand"), IPoint(Render::device.Width() * 0.5f, 0.f), 0.17f);
	_clock = StaticObjects::createSprite(Core::resourceManager.Get<Render::Texture>("Clock"), IPoint(Render::device.Width() * 0.5f+120, 445), 0.5f);
	_cannon = Cannon::createSprite(Core::resourceManager.Get<Render::Texture>("Cannon"), IPoint(Render::device.Width() * 0.5f, 50), 1.0f);
	_cannonball = Cannonball::createSprite(Core::resourceManager.Get<Render::Texture>("Cannonball"), IPoint(Render::device.Width() * 0.5f, Render::device.Height() * 0.5f));

	for (int i = 0; i < 5; i++) {
		_targets.push_back(Targets::createSprite(Core::resourceManager.Get<Render::Texture>("YellowTarget"),
			IPoint(RandomGenerate::RandomInteger(Render::device.Width()), RandomGenerate::RandomInteger(Render::device.Height())),
			IPoint(RandomGenerate::RandomVector(), RandomGenerate::RandomVector())));
		_targets.push_back(Targets::createSprite(Core::resourceManager.Get<Render::Texture>("PinkTarget"),
			IPoint(RandomGenerate::RandomInteger(Render::device.Width()), RandomGenerate::RandomInteger(Render::device.Height())),
			IPoint(RandomGenerate::RandomVector(), RandomGenerate::RandomVector())));
		_targets.push_back(Targets::createSprite(Core::resourceManager.Get<Render::Texture>("Bomb"),
			IPoint(RandomGenerate::RandomInteger(Render::device.Width()), RandomGenerate::RandomInteger(Render::device.Height())),
			IPoint(RandomGenerate::RandomVector(), RandomGenerate::RandomVector())));
	}


}

void TestWidget::Draw()
{

	_bg->Draw();
	_clock->Draw();
	_stand->Draw();
	_cannon->Draw();

	for (auto& target : _targets) {
		target->Draw();
	}


	for (auto& cannonball : _cannonballs) {
		cannonball->Draw();
	}
}

void TestWidget::Update(float dt)
{	
	for (auto& target : _targets) {
		target->Update(dt);
	}

	for (auto& cannonball : _cannonballs) {
		cannonball->Update(dt);
	}
	
}

bool TestWidget::MouseDown(const IPoint &mouse_pos)
{

	///if (mouse_pos.x > 300 && mouse_pos.x < 600) return true;

	_cannonballs.push_back(Cannonball::createSprite(Core::resourceManager.Get<Render::Texture>("Cannonball"), IPoint(Render::device.Width() * 0.5f, 35)));
	_cannonballs.back()->MoveTo(mouse_pos);
	return false;
}

void TestWidget::MouseMove(const IPoint &mouse_pos)
{
	_cannon->Rotate();
}

void TestWidget::MouseUp(const IPoint &mouse_pos)
{
	
}

void TestWidget::createTargets() {

	
	
}
