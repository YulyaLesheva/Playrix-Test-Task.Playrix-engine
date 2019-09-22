#include "stdafx.h"
#include "Background.h"

Background::Background(Render::Texture* tex, IPoint position){
	
	call = std::unique_ptr<Call>(new Call);
	call->_tex = tex;
	call->_position = position;
}

Background::~Background()
{

}

std::unique_ptr<Background> Background::createSprite(Render::Texture * tex, IPoint position){
	
	return std::make_unique<Background>(tex, position);
}

void Background::Draw(){

	Render::device.PushMatrix();
	call->_tex->Draw();
	Render::device.PopMatrix();
}

