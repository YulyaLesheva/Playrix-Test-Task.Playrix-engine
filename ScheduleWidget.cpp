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
	_restart = Restart::CreateSprite(Core::resourceManager.Get<Render::Texture>("Restart"), IPoint(Render::device.Width() * 0.5f, 100));
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

}

