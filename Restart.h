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
	void MakeDisactive();
	bool MouseDown(const IPoint& mouse_pos);
	bool IsActive();

private:
	class Call
	{
	public:
		IPoint _position;
		Render::Texture* _tex;
		bool _active;
		IRect _rect;

	};
	std::unique_ptr <Call> call;
};
