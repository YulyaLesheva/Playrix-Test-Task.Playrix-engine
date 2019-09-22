#include "stdafx.h"
#include "Cannon.h"

std::unique_ptr<Cannon> Cannon::createSprite(Render::Texture * tex, IPoint position, float angle) {
	
	return std::make_unique<Cannon>(tex, position, angle);
}

Cannon::Cannon(Render::Texture* tex, IPoint position, float angle) {
	
	call = std::unique_ptr<Call>(new Call);
	call->_tex = tex;
	call->_position = position;
	call->_angle = angle;
}

Cannon::~Cannon() {

}

void Cannon::Draw() {

	Render::device.PushMatrix();
	Render::device.MatrixTranslate(call->_position.x, call->_position.y, 0);
	Render::device.MatrixScale(0.25);
	Render::device.MatrixRotate(math::Vector3(0, 0, 1), call->_angle);
	Render::device.MatrixTranslate(-call->_tex->_rect_width * 0.5f, 0, 0);
	
	call->_tex->Draw();
	Render::device.PopMatrix();
}

void Cannon::Update(float dt) {

}

bool Cannon::MouseDown() {

	if (Core::mainInput.GetMouseRightButton())
	{
		call->_angle += 25;
	}

	return false;
}

void Cannon::Rotate() {

	IPoint mouse_position = Core::mainInput.GetMousePos();
	IPoint offset = IPoint(mouse_position.x - call->_position.x, mouse_position.y - call->_position.y);
	float angleRadians = atan2f(offset.x, offset.y);
	angleRadians = angleRadians * (180.0 / math::PI);
	
	if (offset.y < call->_position.y) {
		return;
	}

	call->_angle = - angleRadians;
}