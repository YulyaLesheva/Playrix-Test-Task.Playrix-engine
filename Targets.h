#pragma once

class Targets 
{
public:
	Targets(Render::Texture *tex, IPoint position, IPoint direction);
	~Targets();
	
	void Draw();
	void MakeNeedToRemoveTrue();
	void Update(float dt);
	
	bool IsNeededToRemove() const;

	static std::unique_ptr<Targets> createSprite(Render::Texture *tex, IPoint position, IPoint direction);

	IRect GetRectangle();
	
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

