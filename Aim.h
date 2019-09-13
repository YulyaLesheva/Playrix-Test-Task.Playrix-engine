#pragma once

class Aim
{
public:
	Aim(Render::Texture *tex);
	~Aim();
	void Draw();
	void Update(float dt);
	static std::unique_ptr <Aim> CreateSprite(Render::Texture *tex);

private:
	class Call {
	public:
		Render::Texture* _tex;
		IPoint _position;

	};
	
	std::unique_ptr <Call> call;

};

