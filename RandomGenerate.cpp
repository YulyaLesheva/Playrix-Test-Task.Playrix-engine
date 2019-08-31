#include "stdafx.h"
#include "Background.h"

Background::Background(Render::Texture* tex, IPoint position){
	
	call = std::unique_ptr<Call>(new Call);
	call->_tex = tex;
	call->_position = position;
}
///�� �������� � ����, ��� ��������� �����������, ������� ��������� ����������
///��������. � ������������, ������������������ ��� �������� ������ � ����
/// ���, ������� ��������� �� ������ ������ � ���� �������� � ��� ������
///�������� � ������ ���� ������������������ �������� ����� ��������, ������� ��������� �����������


Background::~Background()
{

}

std::unique_ptr<Background> Background::createSprite(Render::Texture * tex, IPoint position){
	
	return std::make_unique<Background>(tex, position);
}
////��� ������� ������ ������, ������� ������ ��������� �������� � ���������� 
//// ��������� �� ������ ������ ������ ������, ������� ����� ��������, �������
/// �� ������� ��� ������ ����� ������
///
///


void Background::Draw(){

	Render::device.PushMatrix();
	call->_tex->Draw();
	Render::device.PopMatrix();
}

void Background::DrawStand() {

	Render::device.PushMatrix();
	Render::device.MatrixTranslate(call->_position.x, call->_position.y - 100, 0);
	Render::device.MatrixScale(0.2);
	Render::device.MatrixTranslate(-call->_tex->_rect_width * 0.5f, 10, 0);
	call->_tex->Draw();
	Render::device.PopMatrix();
}