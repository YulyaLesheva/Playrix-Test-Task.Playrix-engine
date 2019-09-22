#include "stdafx.h"
#include "Aim.h"

Aim::Aim(Render::Texture *tex) {

	call = std::unique_ptr<Call>(new Call);
	call->_tex = tex;
}

Aim::~Aim() {

}

void Aim::Draw() {
	
	IPoint mouse_pos = Core::mainInput.GetMousePos();
	Render::device.PushMatrix();
	Render::device.MatrixTranslate(mouse_pos.x, mouse_pos.y, 0);
	Render::device.MatrixScale(0.5f);
	Render::device.MatrixTranslate(-call->_tex->_rect_width * 0.5f, -call->_tex->_rect_height * 0.5f, 0);
	call->_tex->Draw();
	Render::device.PopMatrix();
}

void Aim::Update(float dt) {

}

std::unique_ptr<Aim> Aim::CreateSprite(Render::Texture *tex){

	return std::make_unique<Aim>(tex);
}
