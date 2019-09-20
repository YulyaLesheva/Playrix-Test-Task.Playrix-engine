#include "stdafx.h"
#include "Effect.h"

std::unique_ptr<Effect> Effect::CreateEffect(std::string name, FPoint position)
{
	return std::make_unique<Effect>(name, position);
}

Effect::Effect(std::string name, FPoint position) {

	call = std::unique_ptr<Call>(new Call);
	call->_position = position;
	call->_eff = call->_effCont.AddEffect(name, position);
	call->_startPosition = position;
}

Effect::~Effect() {


}

void Effect::Draw() {
	call->_effCont.Draw();
}

void Effect::Update(float dt) {
	
	call->_effCont.Update(dt);	
	call->_eff->posX += call->_dt.x;
	call->_eff->posY += call->_dt.y;
}

void Effect::FinishEffect() {
	call->_eff->Finish();
}

bool Effect::MoveTo(const IPoint & mouse_pos)
{
	float angle = atan2(mouse_pos.y, mouse_pos.x);
	call->_scalePix = call->_startPosition + FPoint(cos(angle), sin(angle));
	call->_dt = call->_scalePix - mouse_pos;
	float theta = atan(call->_dt.y / call->_dt.x);
	call->_dt.x = 15 * cos(theta);
	call->_dt.y = 15 * sin(theta);

	if (mouse_pos.x < call->_position.x) {
		call->_dt.x = -call->_dt.x;
		call->_dt.y = -call->_dt.y;
	}

	call->_position = call->_scalePix + 1 * call->_dt;

	return false;
}

