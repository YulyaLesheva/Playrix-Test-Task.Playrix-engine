#include "stdafx.h"
#include "StaticObjects.h"

StaticObjects::StaticObjects(Render::Texture* tex, IPoint &position, float scale){
	
	call = std::unique_ptr<Call>(new Call);
	call->_tex = tex;
	call->_position = position;
	call->_scale = scale;
}

StaticObjects::~StaticObjects()
{

}

std::unique_ptr<StaticObjects> StaticObjects::createSprite(Render::Texture* tex, IPoint &position, float scale){
	
	return std::make_unique<StaticObjects>(tex, position, scale);
}



void StaticObjects::Draw(){

	Render::device.PushMatrix();
	Render::device.MatrixTranslate(call->_position.x, call->_position.y, 0);
	Render::device.MatrixScale(call->_scale);
	Render::device.MatrixTranslate(call->_position.x-call->_tex->_rect_width, call->_position.y, 0);
	call->_tex->Draw();
	Render::device.PopMatrix();
}

