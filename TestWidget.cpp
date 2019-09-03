#include "stdafx.h"
#include "TestWidget.h"
#include "Background.h"
#include "StaticObjects.h"
#include "Targets.h"
#include "RandomGenerate.h"
TestWidget::TestWidget(const std::string& name, rapidxml::xml_node<>* elem)
	: Widget(name)
{
	Init();
}

using TargetVector = std::vector<std::unique_ptr<Targets>>;
TargetVector _targets;

void TestWidget::Init()
{
	createTargets();
	_bg = Background::createSprite(Core::resourceManager.Get<Render::Texture>("Background"));
	_stand = StaticObjects::createSprite(Core::resourceManager.Get<Render::Texture>("Stand"), IPoint(Render::device.Width() * 0.5f, 0.f), 0.17f);
	_clock = StaticObjects::createSprite(Core::resourceManager.Get<Render::Texture>("Clock"), IPoint(Render::device.Width() * 0.5f+120, 445), 0.5f);
}

void TestWidget::Draw()
{
	_bg->Draw();
	_clock->Draw();
	_stand->Draw();
	for (auto& target : _targets) {
		target->Draw();
	}

	///_target->Draw();
	///_target1->Draw();

}

void TestWidget::Update(float dt)
{	
	for (auto& target : _targets) {
		target->Update(dt);
	}

	///_timer += dt * 1;
}

bool TestWidget::MouseDown(const IPoint &mouse_pos)
{
	
	return false;
}

void TestWidget::MouseMove(const IPoint &mouse_pos)
{
	
}

void TestWidget::MouseUp(const IPoint &mouse_pos)
{
	
}

void TestWidget::createTargets() {

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
