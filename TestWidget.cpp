#include "stdafx.h"
#include "TestWidget.h"
#include "Background.h"
#include "Targets.h"
#include "RandomGenerate.h"
#include "Cannon.h"
#include "Cannonball.h"
#include "Aim.h"
#include "Effect.h"
#include "StaticObjects.h"

TestWidget::TestWidget(const std::string& name, rapidxml::xml_node<>* elem)
	: Widget(name),
	_running(true)
{
	Init();
}

void TestWidget::Init()
{
	_bg = Background::createSprite(Core::resourceManager.Get<Render::Texture>("Background"));
	_aim = Aim::CreateSprite(Core::resourceManager.Get<Render::Texture>("Aim"));
	_stand = StaticObjects::createSprite(Core::resourceManager.Get<Render::Texture>("Stand"), IPoint(Render::device.Width() * 0.5f, 0.f), 0.17f);
	_cannon = Cannon::createSprite(Core::resourceManager.Get<Render::Texture>("Cannon"), IPoint(Render::device.Width() * 0.5f, 60), 1.0f);

	CreateTargets();
}

void TestWidget::CreateTargets() {

	for (int i = 0; i < 5; i++) {
		_yellowTargets.push_back(Targets::createSprite(Core::resourceManager.Get<Render::Texture>("YellowTarget"),
			IPoint(RandomGenerate::RandomInteger(Render::device.Width()), RandomGenerate::RandomInteger(Render::device.Height())),
			IPoint(RandomGenerate::RandomVector(), RandomGenerate::RandomVector())));
		_pinkTargets.push_back(Targets::createSprite(Core::resourceManager.Get<Render::Texture>("PinkTarget"),
			IPoint(RandomGenerate::RandomInteger(Render::device.Width()), RandomGenerate::RandomInteger(Render::device.Height())),
			IPoint(RandomGenerate::RandomVector(), RandomGenerate::RandomVector())));
	}
	for (int i = 0; i < RandomGenerate::RandomBomb(); i++) {

		_bombTargets.push_back(Targets::createSprite(Core::resourceManager.Get<Render::Texture>("Bomb"),
			IPoint(RandomGenerate::RandomInteger(Render::device.Width()), RandomGenerate::RandomInteger(Render::device.Height())),
			IPoint(RandomGenerate::RandomVector(), RandomGenerate::RandomVector())));
	}
}

void TestWidget::Draw()
{
	_bg->Draw();
	_aim->Draw();
	_stand->Draw();
	_cannon->Draw();
	
	for (auto& target : _yellowTargets) {
		target->Draw();
	}

	for (auto& target : _bombTargets) {
		target->Draw();
	}

	for (auto& target : _pinkTargets) {
		target->Draw();
	}

	for (auto& cannonball : _cannonballs) {
		cannonball->Draw();
	}

	for (auto& eff : _effects) {
		eff->Draw();
	}

	for (auto& eff : _plumeEffects) {
		eff->Draw();
	}
}

void TestWidget::Update(float dt)
{	
	for (auto& target : _yellowTargets) {
		target->Update(dt);
	}

	for (auto& target : _pinkTargets) {
		target->Update(dt);
	}

	for (auto& target : _bombTargets) {
		target->Update(dt);
	}

	for (auto& cannonball : _cannonballs) {
		cannonball->Update(dt);
	}

	for (auto& eff : _effects) {
		eff->Update(dt);
	}

	for (auto& eff : _plumeEffects) {
		eff->Update(dt);
	}

	CheckCollisions();
	ObjectsRemoving();
}

bool TestWidget::MouseDown(const IPoint &mouse_pos)
{
	if (_running) {
		if (Core::mainInput.GetMouseLeftButton())
		{
			if (mouse_pos.y <= 60) return false;

			_cannonballs.push_back(Cannonball::createSprite(Core::resourceManager.Get<Render::Texture>("Cannonball"), IPoint(Render::device.Width() * 0.5f, 35)));
			_cannonballs.back()->MoveTo(mouse_pos);
			
			_plumeEffects.push_back(Effect::CreateEffect("Iskra", _cannonballs.back()->GetCurrentPosition()));
			_plumeEffects.back()->MoveTo(mouse_pos);
		}
	}
	return false;
}


void TestWidget::CheckCollisions() {
	
	for (auto& cannonball : _cannonballs) {
		auto rectC = cannonball->GetRectangle();

		for (auto i = _yellowTargets.begin(); i!= _yellowTargets.end(); i++)
			if (rectC.Intersects((*i)->GetRectangle())) {
				cannonball->MakeNeedToRemoveTrue();
				(*i)->MakeNeedToRemoveTrue();
				Core::guiManager.getLayer("TestLayer")->getWidget("ScheduleWidget")->AcceptMessage(Message("Yellow", "Yellow"));
				_effects.push_back(Effect::CreateEffect("BigBoom", cannonball->GetCurrentPosition()));
				_effects.back()->FinishEffect();
				_plumeEffects.back()->FinishEffect();
			}
			
		for (auto i = _pinkTargets.begin(); i != _pinkTargets.end(); i++)
			if (rectC.Intersects((*i)->GetRectangle())) {
				cannonball->MakeNeedToRemoveTrue();
				(*i)->MakeNeedToRemoveTrue();
				Core::guiManager.getLayer("TestLayer")->getWidget("ScheduleWidget")->AcceptMessage(Message("Pink", "Pink"));
				_effects.push_back(Effect::CreateEffect("BigBoom", cannonball->GetCurrentPosition()));
				_effects.back()->FinishEffect();
				_plumeEffects.back()->FinishEffect();
			}

		for (auto i = _bombTargets.begin(); i != _bombTargets.end(); i++)
			if (rectC.Intersects((*i)->GetRectangle())) {
				cannonball->MakeNeedToRemoveTrue();
				(*i)->MakeNeedToRemoveTrue();
				Core::guiManager.getLayer("TestLayer")->getWidget("ScheduleWidget")->AcceptMessage(Message("Bomb", "Bomb"));
				_effects.push_back(Effect::CreateEffect("BigBoom", cannonball->GetCurrentPosition()));
				_effects.back()->FinishEffect();
				_plumeEffects.back()->FinishEffect();
			}
	}
}

void TestWidget::ObjectsRemoving() {

	auto newEnd = std::remove_if(_yellowTargets.begin(), _yellowTargets.end(), [&](const std::unique_ptr<Targets>& targetPtr) {
		return targetPtr->IsNeededToRemove();
	});
	if (newEnd != _yellowTargets.end())
		_yellowTargets.resize(newEnd - _yellowTargets.begin());

	auto newEnd2 = std::remove_if(_pinkTargets.begin(), _pinkTargets.end(), [&](const std::unique_ptr<Targets>& targetPtr) {
		return targetPtr->IsNeededToRemove();
	});
	if (newEnd2 != _pinkTargets.end())
		_pinkTargets.resize(newEnd2 - _pinkTargets.begin());

	auto newEnd3 = std::remove_if(_bombTargets.begin(), _bombTargets.end(), [&](const std::unique_ptr<Targets>& targetPtr) {
		return targetPtr->IsNeededToRemove();
	});
	
	if (newEnd3 != _bombTargets.end())
		_bombTargets.resize(newEnd3 - _bombTargets.begin());


	auto newEnd1 = std::remove_if(_cannonballs.begin(), _cannonballs.end(), [&](const std::unique_ptr<Cannonball>& cbPtr) {
		return cbPtr->IsNeededToRemove();
	});
	if (newEnd1 != _cannonballs.end())
		_cannonballs.resize(newEnd1 - _cannonballs.begin());
}

void TestWidget::MouseMove(const IPoint &mouse_pos) {

	_cannon->Rotate();
}

void TestWidget::MouseUp(const IPoint &mouse_pos)
{

}

void TestWidget::AcceptMessage(const Message & message) {

	const std::string& publisher = message.getPublisher();
	const std::string& data = message.getData();

	if (data == "StopGame") {
		_running = false;
		_yellowTargets.clear();
		_pinkTargets.clear();
		_bombTargets.clear();
		_cannonballs.clear();
	}
	else if (data == "RestartGame") {
		_running = true;
		CreateTargets();
		_effects.clear();
		_plumeEffects.clear();
	}
}
