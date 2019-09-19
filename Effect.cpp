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
}

Effect::~Effect() {


}

void Effect::Draw() {
	call->_effCont.Draw();
}

void Effect::Update(float dt) {
	call->_effCont.Update(dt);
}

void Effect::FinishEffect() {
	call->_eff->Finish();
}