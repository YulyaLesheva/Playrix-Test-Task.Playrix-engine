#pragma once

class Targets 
{
public:
	Targets(Render::Texture *tex, IPoint position, IPoint direction);
	~Targets();
	void Draw();
	void Update(float dt);
	IRect GetRectangle();
	static std::unique_ptr<Targets> createSprite(Render::Texture *tex, IPoint position, IPoint direction);
	void MakeNeedToRemoveTrue();
	bool IsNeededToRemove() const;
private:
	class Call
	{
	public:
		Render::Texture* _tex;
		IPoint _position;
		IPoint _direction;
		IRect _rect;
		bool _needToRemove;
	};

	std::unique_ptr<Call> call;
};

