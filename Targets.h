#pragma once

class Targets 
{
public:
	Targets(Render::Texture *tex, IPoint position, IPoint direction);
	~Targets();
	void Draw();
	void Update(float dt);
	static std::unique_ptr<Targets> createSprite(Render::Texture *tex, IPoint position, IPoint direction);
private:
	class Call
	{
	public:
		Render::Texture* _tex;
		IPoint _position;
		IPoint _direction;
	};

	std::unique_ptr<Call> call;
};

