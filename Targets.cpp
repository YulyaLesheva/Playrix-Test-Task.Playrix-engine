#include "stdafx.h"
#include "Targets.h"

std::unique_ptr<Targets> Targets::createSprite(Render::Texture * tex, IPoint position, IPoint direction)
{
	return std::make_unique<Targets>(tex, position, direction);
}

Targets::Targets(Render::Texture *tex, IPoint position, IPoint direction) {
	call = std::unique_ptr<Call>(new Call);
	call->_tex = tex;
	call->_position = position;
	call->_direction = direction;


}

Targets::~Targets() {

}

void Targets::Draw() {
	Render::device.PushMatrix();
	Render::device.MatrixTranslate(call->_position.x, call->_position.y, 0);
	Render::device.MatrixScale(0.25f);
	Render::device.MatrixTranslate(-call->_tex->_rect_width * 0.5f, -call->_tex->_rect_height * 0.5f, 0);
	call->_tex->Draw();
	Render::device.PopMatrix();

}

void Targets::Update(float dt) {

	call->_position.x += call->_direction.x;
	call->_position.y += call->_direction.y;
	
	if (call->_position.x > 1024 - call->_tex->_rect_width *0.25*0.5 || call->_position.x < 0 + call->_tex->_rect_width *0.25*0.5) {
		call->_direction.x = -call->_direction.x;
	}

	if (call->_position.y > 768 - call->_tex->_rect_height*0.25*0.5 || call->_position.y < 0 + call->_tex->_rect_height*0.25*0.5) {
		call->_direction.y = -call->_direction.y;
	}

}