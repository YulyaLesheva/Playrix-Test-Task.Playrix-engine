#include "stdafx.h"
#include "Labels.h"

std::unique_ptr<Labels> Labels::CreateSprite(int time, IPoint position)
{
	return std::make_unique<Labels>(time, position);
}

Labels::Labels(int time, IPoint position) {
	
	call = std::unique_ptr<Call>(new Call);
	call->_time = time;
	call->_position = position;
}

Labels::~Labels() {

}

void Labels::Draw() {
	Render::BindFont("arial");
	Render::PrintString(call->_position, std::to_string(call->_time), 1.f, CenterAlign);
}

void Labels::Update(float dt) {

}