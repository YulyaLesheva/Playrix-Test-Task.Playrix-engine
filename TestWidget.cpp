#include "stdafx.h"
#include "TestWidget.h"
#include "Background.h"
#include "StaticObjects.h"
#include "Targets.h"
#include "RandomGenerate.h"
#include "Cannon.h"
#include "Cannonball.h"
#include "Aim.h"
#include "Effect.h"


TestWidget::TestWidget(const std::string& name, rapidxml::xml_node<>* elem)
	: Widget(name),
	_running(true),
	_eff(NULL)
{
	Init();
}

using TargetVector = std::vector<std::unique_ptr<Targets>>;
TargetVector _targets;

using CannonballVector = std::vector<std::unique_ptr<Cannonball>>;
CannonballVector _cannonballs;

using EffectVector = std::vector<std::unique_ptr<Effect>>;
EffectVector _effects;

void TestWidget::Init()
{
	_bg = Background::createSprite(Core::resourceManager.Get<Render::Texture>("Background"));
	_stand = StaticObjects::createSprite(Core::resourceManager.Get<Render::Texture>("Stand"), IPoint(Render::device.Width() * 0.5f, 0.f), 0.17f);
	_clock = StaticObjects::createSprite(Core::resourceManager.Get<Render::Texture>("Clock"), IPoint(Render::device.Width() * 0.5f+120, 445), 0.5f);
	_cannon = Cannon::createSprite(Core::resourceManager.Get<Render::Texture>("Cannon"), IPoint(Render::device.Width() * 0.5f, 50), 1.0f);
	_aim = Aim::CreateSprite(Core::resourceManager.Get<Render::Texture>("Aim"));

	CreateTargets();
	

	fuck = Core::resourceManager.Get<Render::Texture>("YellowTarget");
}

void TestWidget::Draw()
{
	_bg->Draw();
	_clock->Draw();
	_stand->Draw();
	_cannon->Draw();
	_aim->Draw();

	for (auto& target : _targets) {
		target->Draw();
	}

	for (auto& cannonball : _cannonballs) {
		cannonball->Draw();
	}
	
	IPoint mouse_pos = Core::mainInput.GetMousePos();
	Render::BindFont("arial");
	Render::PrintString(924 + 100 / 2, 35, utils::lexical_cast(mouse_pos.x) + ", " + utils::lexical_cast(mouse_pos.y), 1.f, CenterAlign);

	///_effCont.Draw();

	for (auto& eff : _effects) {
		eff->Draw();
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

	for (auto& eff : _effects) {
		eff->Update(dt);
	}

	CheckCollisions();

	ObjectsRemoving();
	///_effCont.Update(dt);
}

bool TestWidget::MouseDown(const IPoint &mouse_pos)
{
	if (_running) {
		if (Core::mainInput.GetMouseLeftButton())
		{
			_cannonballs.push_back(Cannonball::createSprite(Core::resourceManager.Get<Render::Texture>("Cannonball"), IPoint(Render::device.Width() * 0.5f, 35)));
			_cannonballs.back()->MoveTo(mouse_pos);

		}
	}
	return false;

}

void TestWidget::MouseMove(const IPoint &mouse_pos){

		_cannon->Rotate();
}

void TestWidget::MouseUp(const IPoint &mouse_pos)
{
	
}

void TestWidget::AcceptMessage(const Message & message){
	
	const std::string& publisher = message.getPublisher();
	const std::string& data = message.getData();

	if (data == "StopGame") {
		_running = false;
		_targets.clear();
		_cannonballs.clear();
	}
	else if (data == "RestartGame") {
		_running = true;
		CreateTargets();
	}

}

void TestWidget::CheckCollisions() {
	
	for (auto& cannonball : _cannonballs) {
		auto rectC = cannonball->GetRectangle();
		for (auto i = _targets.begin(); i!= _targets.end(); ++i)
			if (rectC.Intersects((*i)->GetRectangle())) {
				cannonball->MakeNeedToRemoveTrue();
				(*i)->MakeNeedToRemoveTrue();
				Core::guiManager.getLayer("TestLayer")->getWidget("ScheduleWidget")->AcceptMessage(Message("AddScore", "AddScore"));
				///_eff = _effCont.AddEffect("BigBoom", cannonball->GetCurrentPosition());
				///_eff->Finish();
				_effects.push_back(Effect::CreateEffect("BigBoom", cannonball->GetCurrentPosition()));
				_effects.back()->FinishEffect();

			}
	}
}

void TestWidget::ObjectsRemoving() {
	
	//��������� ��������� �������
	///���� ������ ����� ����� �� �����
		///�����
	auto newEnd = std::remove_if(_targets.begin(), _targets.end(), [&](const std::unique_ptr<Targets>& targetPtr) {
		return targetPtr->IsNeededToRemove();
	});
	if (newEnd != _targets.end())
		_targets.resize(newEnd - _targets.begin());

	auto newEnd1 = std::remove_if(_cannonballs.begin(), _cannonballs.end(), [&](const std::unique_ptr<Cannonball>& cbPtr) {
		return cbPtr->IsNeededToRemove();
	});
	if (newEnd1 != _cannonballs.end())
		_cannonballs.resize(newEnd1 - _cannonballs.begin());
}


void TestWidget::CreateTargets() {
	
	for (int i = 0; i < 1; i++) {
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

