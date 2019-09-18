#include "stdafx.h"
#include "Timer.h"

std::unique_ptr<Timer> Timer::CreateSprite(int time, IPoint position)
{
	return std::make_unique<Timer>(time, position);
}

Timer::Timer(int time, IPoint position) {
	
	call = std::unique_ptr<Call>(new Call);
	call->_time = time;
	call->_position = position;
	call->eventTimer = 1.f;
	call->currentCounter = 0.f;
	call->_active = true;

}

Timer::~Timer() {

}

void Timer::Draw() {
	if (call->_active) {
		Render::BindFont("Fulbo");
		Render::PrintString(call->_position, std::to_string(call->_time), 1.f, CenterAlign);
	}
}

void Timer::Update(float dt) {
	
	call->currentCounter += dt;

	if (call->currentCounter >= call->eventTimer) {
		call->currentCounter = call->currentCounter - call->eventTimer;
		call->_time--;
	}
}

void Timer::ResetTimer() {
	if(!call->_active){
	call->_active = true;
	call->_time = 30;
	}

}

void Timer::makeDisactive() {
	
	call->_active = false;
}

int Timer::GetCurrentTimer() {

	return call->_time;
}