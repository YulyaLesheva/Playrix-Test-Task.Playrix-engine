#include "stdafx.h"
#include "Targets.h"

std::unique_ptr<Targets> Targets::createSprite(Render::Texture * tex, IPoint position)
{
	return std::make_unique<Targets>(tex, position);
}

Targets::Targets(Render::Texture *tex, IPoint position) {
	call = std::unique_ptr<Call>(new Call);
	call->_tex = tex;
	call->_position = position;


}

Targets::~Targets() {

}

void Targets::Draw() {
	Render::device.PushMatrix();
	Render::device.MatrixTranslate(call->_position.x, call->_position.y, 0);
	call->_tex->Draw();
	Render::device.PopMatrix();

}