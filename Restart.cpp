#include "stdafx.h"
#include "Restart.h"

std::unique_ptr<Restart> Restart::CreateSprite(Render::Texture *tex, IPoint position)
{
	return std::make_unique<Restart>(tex, position);
}

Restart::Restart(Render::Texture *tex, IPoint position) {
	
	call = std::unique_ptr<Call>(new Call);
	call->_position = position;
	call->_tex = tex;
	call->_active = false;

}

Restart::~Restart() {

}

void Restart::Draw() {
	
	if (call->_active) {
		Render::device.PushMatrix();
		Render::device.MatrixTranslate(call->_position.x, call->_position.y, 0);
		///Render::device.MatrixScale(0.5f);
		Render::device.MatrixTranslate(-call->_tex->_rect_width * 0.5f, 0, 0);
		call->_tex->Draw();
		Render::device.PopMatrix();
	}
}

void Restart::Update(float dt) {

}

void Restart::MakeActive() {

	call->_active = true;
}
