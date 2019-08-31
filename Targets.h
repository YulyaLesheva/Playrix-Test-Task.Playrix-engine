#pragma once

class Targets 
{
public:
	Targets(Render::Texture *tex, IPoint position);
	~Targets();
	void Draw();
	static std::unique_ptr<Targets> createSprite(Render::Texture *tex, IPoint position);
private:
	class Call
	{
	public:
		Render::Texture* _tex;
		IPoint _position;
	};

	std::unique_ptr<Call> call;
};

