#include "stdafx.h"
#include "Background.h"

Background::Background(Render::Texture* tex, IPoint position){
	
	call = std::unique_ptr<Call>(new Call);
	call->_tex = tex;
	call->_position = position;
}
///мы начинаем с того, что создается конструктор, который принимает параметром
///текстуру. в конструкторе, инициализированный кол выделяет память в куче
/// кол, который указывает на ячейку памяти в куче помещает в эту ячейку
///текстуру и теперь наша инициализированная текстура равна текстуре, которую принимает конструктор


Background::~Background()
{

}

std::unique_ptr<Background> Background::createSprite(Render::Texture * tex, IPoint position){
	
	return std::make_unique<Background>(tex, position);
}
////это функция креете спрайт, которая должна принимать текстуру и возвращает 
//// указатель на объект класса статик обжект, который равен текстуре, которую
/// мы создали при вызове этого метода
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