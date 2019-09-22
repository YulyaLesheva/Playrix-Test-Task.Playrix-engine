#pragma once

class Background 
{
public:
	Background(Render::Texture* tex, IPoint position);
	~Background();
	
	static std::unique_ptr<Background> Background::createSprite(Render::Texture* tex, IPoint position = IPoint(0, 0));
	
	void Draw();

private:

	class Call
	{
	public:
	Render::Texture* _tex;
	IPoint _position;
	};
	
	std::unique_ptr<Call> call;
};

