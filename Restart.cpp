#include "stdafx.h"
#include "Restart.h"

std::unique_ptr<Restart> Restart::CreateSprite(Render::Texture *tex, IPoint position){
	
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
		Render::device.MatrixTranslate(-call->_tex->_rect_width * 0.5f, -call->_tex->_rect_height * 0.5f, 0);
		call->_tex->Draw();
		Render::device.PopMatrix();
	}
}

void Restart::Update(float dt) {

}

void Restart::MakeActive() {

	call->_active = true;
}

bool Restart::MouseDown(const IPoint& mouse_pos) {
	
	if (Core::mainInput.GetMouseRightButton())
	{
		if (!call->_active) return false;

		IRect rect = call->_tex->getBitmapRect();
		call->_rect = IRect(call->_position.x - rect.width * 0.5f, call->_position.y - rect.height * 0.5f, rect.width, rect.height);
		if (call->_rect.Contains(mouse_pos))
			return true;
	}
	return false;
}

void Restart::MakeDisactive() {

	call->_active = false;
}

bool Restart::IsActive() {

	return call->_active;
}