#include "stdafx.h"
#include "TestWidget.h"
#include "StaticObjects.h"

TestWidget::TestWidget(const std::string& name, rapidxml::xml_node<>* elem)
	: Widget(name)
	, _timer(0)

{
	Init();
}

void TestWidget::Init()
{
	_bg = StaticObjects::createSprite(Core::resourceManager.Get<Render::Texture>("Background"));
	///_background = Core::resourceManager.Get<Render::Texture>("Background");
}

void TestWidget::Draw()
{
	//_background->Draw(0,0);
	_bg->Draw();
	
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

