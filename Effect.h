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
private:
	class Call
	{
	public:
		FPoint _position;
		EffectsContainer _effCont;
		ParticleEffectPtr _eff;
		char _name;
	};
	std::unique_ptr <Call> call;
};

