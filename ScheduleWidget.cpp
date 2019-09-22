#include "stdafx.h"
#include "ScheduleWidget.h"
#include "Score.h"
#include "Restart.h"
#include "Timer.h"
#include "StaticObjects.h"

ScheduleWidget::ScheduleWidget(const std::string& name, rapidxml::xml_node<>* elem)
	: Widget(name),
	_bombIsKilled(false)
{
	Init();
}

void ScheduleWidget::Init() {

	_score = Score::CreateScore(IPoint(70, 750));
	_restart = Restart::CreateSprite(Core::resourceManager.Get<Render::Texture>("Restart"), IPoint(Render::device.Width() * 0.5f, Render::device.Height() * 0.5f));
	_timer = Timer::CreateSprite(20, IPoint(975, 750));
	_clock = StaticObjects::createSprite(Core::resourceManager.Get<Render::Texture>("Clock"), IPoint(Render::device.Width() * 0.5f + 120, 445), 0.5f);
}

ScheduleWidget::~ScheduleWidget()
{
}

void ScheduleWidget::Draw() {
	
	_score->Draw();
	_restart->Draw();
	_timer->Draw();
	_clock->Draw();
}

void ScheduleWidget::Update(float dt) {
	
	_timer->Update(dt);
	if (_score->GetCurrentScore() >= 350 || _timer->GetCurrentTimer() <=0 || _bombIsKilled) {
		Core::guiManager.getLayer("TestLayer")->getWidget("TestWidget")->AcceptMessage(Message("StopGame", "StopGame"));
		_timer->makeDisactive();
		_restart->MakeActive();
		_bombIsKilled = false;
	}
}

void ScheduleWidget::AcceptMessage(const Message & message){
	
	const std::string& publisher = message.getPublisher();
	const std::string& data = message.getData();
	
	if (data == "Yellow") {
		_score->IncreaseScore(20);
	}
	else if (data == "Pink") {
		_score->IncreaseScore(50);
	}
	else if (data == "Bomb") {
		_bombIsKilled = true;
	}
}

bool ScheduleWidget::MouseDown(const IPoint & mouse_pos){
	if (_restart->MouseDown(mouse_pos)) {
		_restart->MakeDisactive();
		_score->ResetScore();
		_timer->ResetTimer();
		Core::guiManager.getLayer("TestLayer")->getWidget("TestWidget")->AcceptMessage(Message("RestartGame", "RestartGame"));
	}
	return false;
}

