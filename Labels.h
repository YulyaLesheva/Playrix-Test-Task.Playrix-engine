#pragma once

class Labels
{
public:
	Labels(int time, IPoint position);
	~Labels();
	static std::unique_ptr <Labels> CreateSprite(int time, IPoint position );
	void Draw();
	void Update(float dt);
private:
	class Call
	{
	public:
		IPoint _position;
		int _time;
	};
	std::unique_ptr <Call> call;
};
