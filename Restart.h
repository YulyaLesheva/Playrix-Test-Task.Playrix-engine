#pragma once

class Restart
{
public:
	Restart(Render::Texture *tex, IPoint position);
	~Restart();
	static std::unique_ptr <Restart> CreateSprite(Render::Texture *tex, IPoint position);
	void Draw();
	void Update(float dt);
	void MakeActive();
private:
	class Call
	{
	public:
		IPoint _position;
		Render::Texture* _tex;
		bool _active;
		

	};
	std::unique_ptr <Call> call;
};
