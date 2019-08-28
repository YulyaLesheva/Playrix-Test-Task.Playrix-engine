#include "stdafx.h"
#include "StaticObjects.h"

StaticObjects::StaticObjects(Render::Texture* tex)
{
	call = std::unique_ptr<Call>(new Call);
	call->_tex = tex;
}

StaticObjects::~StaticObjects()
{

}

std::unique_ptr<StaticObjects> StaticObjects::createSprite(Render::Texture * tex)
{
	return std::make_unique<StaticObjects>(tex);
}

void StaticObjects::Draw()
{
	Render::device.PushMatrix();
	call->_tex->Draw();
	Render::device.PopMatrix();
}
