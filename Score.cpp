#include "stdafx.h"
#include "Score.h"

std::unique_ptr<Score> Score::CreateScore(IPoint position)
{
	return std::make_unique<Score>(position);
}

Score::Score(IPoint position) {
	
	call = std::unique_ptr<Call>(new Call);
	call->_position = position;
	call->_score = 0;

}

Score::~Score() {

}

void Score::Draw() {
	
	Render::BindFont("Fulbo");
	Render::PrintString(call->_position, std::to_string(call->_score), 1.f, CenterAlign);
	
}

void Score::Update(float dt) {
	
	
}

void Score::IncreaseScore(int value) {

	call->_score += value;
}

