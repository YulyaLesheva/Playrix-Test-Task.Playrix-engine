#pragma once

class Timer
{
public:
	Timer(int time, IPoint position);
	~Timer();
	static std::unique_ptr <Timer> CreateSprite(int time, IPoint position);
	void Draw();
	void Update(float dt);
private:
	class Call
	{
	public:
		IPoint _position;
		int _time;
		float eventTimer;
		float currentCounter;
		

	};
	std::unique_ptr <Call> call;
};
