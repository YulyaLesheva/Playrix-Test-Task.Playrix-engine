#include "stdafx.h"
#include "Cannonball.h"

std::unique_ptr<Cannonball> Cannonball::createSprite(Render::Texture *tex, const IPoint &position){
	
	return std::make_unique<Cannonball>(tex, position);
}

Cannonball::Cannonball(Render::Texture *tex, const IPoint &position) {

	call = std::unique_ptr<Call>(new Call);
	call->_tex = tex;
	call->_position = position;
	call->_startPosition = position;

}

Cannonball::~Cannonball() {

}

void Cannonball::Draw() {
	
	Render::device.PushMatrix();
	Render::device.MatrixTranslate(call->_position.x, call->_position.y, 0);
	Render::device.MatrixScale(0.25);
	Render::device.MatrixTranslate(-call->_tex->_rect_width * 0.5, -call->_tex->_rect_height * 0.5, 0);
	call->_tex->Draw();
	Render::device.PopMatrix();
}

void Cannonball::Update(float dt) {

	call->_position += call->_dt;
}

void Cannonball::MoveTo(const IPoint &mouse_pos) {
	
	float angle = atan2(mouse_pos.y,mouse_pos.x);
	call->_scalePix = call->_startPosition + FPoint(cos(angle), sin(angle));
	call->_dt = call->_scalePix - mouse_pos;
	float theta = atan(call->_dt.y/call->_dt.x);
	call->_dt.x = 15 * cos(theta);
	call->_dt.y = 15 * sin(theta);

	if (mouse_pos.x < call->_position.x) {
		call->_dt.x = -call->_dt.x;
		call->_dt.y = -call->_dt.y;
	}

	call->_position = call->_scalePix + 1 * call->_dt;
}
