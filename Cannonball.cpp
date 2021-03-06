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
	call->_needToRemove = false;
}

Cannonball::~Cannonball() {

}

void Cannonball::Draw() {
	
	Render::device.PushMatrix();
	Render::device.MatrixTranslate(call->_position.x, call->_position.y, 0);
	Render::device.MatrixScale(0.2);
	Render::device.MatrixTranslate(-call->_tex->_rect_width * 0.5, -call->_tex->_rect_height * 0.5, 0);
	call->_tex->Draw();
	Render::device.PopMatrix();
}

void Cannonball::Update(float dt) {

	if (call->_position.x > Render::device.Width() + call->_tex->_bitmap_width*0.25 || call->_position.x < - call->_tex->_bitmap_width*0.25) {
		call->_needToRemove = true;
	}

	if (call->_position.y > Render::device.Height() + call->_tex->_bitmap_height*0.25 || call->_position.y < -call->_tex->_bitmap_height*0.25) {
		call->_needToRemove = true;
	}
	call->_position += call->_dt;
}

void Cannonball::MoveTo(const IPoint &mouse_pos) {

	if (call->_needToRemove = true) {
		call->_needToRemove = false;

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
	}
}

IRect Cannonball::GetRectangle() {
	
	IRect rect = call->_tex->getBitmapRect();
	call->_rect = IRect(call->_position.x, call->_position.y, call->_tex->Width()*0.15, call->_tex->Height()*0.15);

	return call->_rect;
}



void Cannonball::MakeNeedToRemoveTrue() {
	
	call->_needToRemove = true;
}

bool Cannonball::IsNeededToRemove() const {
	
	return call->_needToRemove;
}

FPoint Cannonball::GetCurrentPosition() {

	return call->_position;
}