#pragma once

class Score
{
public:
	Score(IPoint position);
	~Score();
	static std::unique_ptr <Score> CreateScore(IPoint position);
	void Draw();
	void Update(float dt);
	void IncreaseScore(int value);
private:
	class Call
	{
	public:
		IPoint _position;
		int _score;
		float eventTimer;
		

	};
	std::unique_ptr <Call> call;
};
