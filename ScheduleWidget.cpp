#include "stdafx.h"
#include "ScheduleWidget.h"
#include "Score.h"
#include "Restart.h"
#include "Timer.h"


ScheduleWidget::ScheduleWidget(const std::string& name, rapidxml::xml_node<>* elem)
	: Widget(name)
{
	Init();
}

void ScheduleWidget::Init() {
	_score = Score::CreateScore(IPoint(70, 750));
	_restart = Restart::CreateSprite(Core::resourceManager.Get<Render::Texture>("Restart"), IPoint(Render::device.Width() * 0.5f, Render::device.Height() * 0.5f));
	_timer = Timer::CreateSprite(30, IPoint(975, 750));
}

ScheduleWidget::~ScheduleWidget()
{
}

void ScheduleWidget::Draw() {
	
	_score->Draw();
	_restart->Draw();
	_timer->Draw();
}

void ScheduleWidget::Update(float dt) {
	
	_timer->Update(dt);
	if (_score->GetCurrentScore() >= 300 || _timer->GetCurrentTimer() <=0) {
		Core::guiManager.getLayer("TestLayer")->getWidget("TestWidget")->AcceptMessage(Message("StopGame", "StopGame"));
		_timer->makeDisactive();
		_restart->MakeActive();
	}

}

void ScheduleWidget::AcceptMessage(const Message & message){
	
	const std::string& publisher = message.getPublisher();
	const std::string& data = message.getData();
	
	if (data == "AddScore") {
		_score->IncreaseScore(100);
	}
}

bool ScheduleWidget::MouseDown(const IPoint & mouse_pos){
	if (_restart->MouseDown(mouse_pos)) {
		_restart->MakeDisactive();
		///_score->IncreaseScore(1000);
		_score->ResetScore();
		_timer->ResetTimer();
		Core::guiManager.getLayer("TestLayer")->getWidget("TestWidget")->AcceptMessage(Message("RestartGame", "RestartGame"));
	}
	return false;
}

