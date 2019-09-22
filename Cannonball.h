#pragma once

class Cannonball
{
public:
	Cannonball(Render::Texture *tex, const IPoint &position);
	~Cannonball();
	
	static std::unique_ptr<Cannonball> createSprite(Render::Texture *tex, const IPoint &position);
	
	void Update(float dt);
	void Draw();
	void MoveTo(const IPoint &mouse_pos);
	void MakeNeedToRemoveTrue();

	bool IsNeededToRemove() const;

	IRect GetRectangle();
	FPoint GetCurrentPosition();

private:
	class Call
	{
	public:
		Render::Texture *_tex;
		
		FPoint _position;
		FPoint _dt;
		FPoint _startPosition; 
		FPoint _scalePix;

		IRect _rect;
		
		bool _needToRemove;
	};
	std::unique_ptr<Call> call;
};



