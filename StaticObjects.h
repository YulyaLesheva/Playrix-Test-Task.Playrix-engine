#pragma once

class StaticObjects
{
public:
	StaticObjects(Render::Texture* tex, IPoint &position, float scale);
	~StaticObjects();
	
	static std::unique_ptr<StaticObjects> StaticObjects::createSprite(Render::Texture* tex, IPoint &position, float scale);
	void Draw();
private:

	class Call
	{
	public:
		Render::Texture* _tex;
		IPoint _position;
		float _scale;
	};
	
	std::unique_ptr<Call> call;

};

