#pragma once

class Labels
{
public:
	Labels(int time, IPoint position);
	~Labels();
	static std::unique_ptr <Labels> CreateSprite(int time, IPoint position);
	void Draw();
	void Update(float dt);
	void increaseScore(int x);
	void timerEvent1();
private:
	class Call
	{
	public:
		IPoint _position;
		int _time;
		int _score;
		float eventTimer;
		float currentCounter;
		int frameCounter;
		

	};
	std::unique_ptr <Call> call;
};
