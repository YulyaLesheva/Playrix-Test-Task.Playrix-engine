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

void TestWidget::Init()
{
	_bg = Background::createSprite(Core::resourceManager.Get<Render::Texture>("Background"));
	_stand = StaticObjects::createSprite(Core::resourceManager.Get<Render::Texture>("Stand"), IPoint(Render::device.Width() * 0.5f, 0.f), 0.17f);
	_clock = StaticObjects::createSprite(Core::resourceManager.Get<Render::Texture>("Clock"), IPoint(Render::device.Width() * 0.5f+120, 445), 0.5f);
	auto test = Render::device.Width();
	///_target = Targets::createSprite(Core::resourceManager.Get<Render::Texture>("Target"), IPoint(RandomInteger(Render::device.Width()), RandomInteger(Render::device.Height())));
	_target1 = Targets::createSprite(Core::resourceManager.Get<Render::Texture>("Target"), IPoint(RandomInteger(), RandomInteger()));
}

void TestWidget::Draw()
{
	_bg->Draw();
	_clock->Draw();
	_stand->Draw();
	///_target->Draw();
	_target1->Draw();

}

void TestWidget::Update(float dt)
{
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

