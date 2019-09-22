#pragma once

class Cannon
{
public:
	Cannon(Render::Texture* tex, IPoint position, float angle);
	~Cannon();
	static std::unique_ptr<Cannon>createSprite(Render::Texture* tex, IPoint position, float angle);

	void Draw();
	void Update(float dt);
	void Rotate();

	bool MouseDown();

private:
	class Call
	{
	public:
		Render::Texture* _tex;
		
		IPoint _position;
		
		float _angle;
	};
	std::unique_ptr<Call> call;
};
