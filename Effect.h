#pragma once

class Effect
{
public:
	Effect(std::string name, FPoint position);
	~Effect();
	
	static std::unique_ptr<Effect>CreateEffect(std::string name, FPoint position);
	
	void Draw();
	void Update(float dt);
	void FinishEffect();
	
	bool MoveTo(const IPoint &mouse_pos);
	
private:
	class Call
	{
	public:
		FPoint _position;
		FPoint _dt;
		FPoint _startPosition;
		FPoint _scalePix;

		EffectsContainer _effCont;
		ParticleEffectPtr _eff;
	};
	
	std::unique_ptr <Call> call;
};

