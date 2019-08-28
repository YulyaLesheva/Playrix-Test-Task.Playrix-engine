#pragma once

class StaticObjects 
{
public:
	StaticObjects(Render::Texture* tex);
	~StaticObjects();
	
	static std::unique_ptr<StaticObjects> StaticObjects::createSprite(Render::Texture* tex);
	void Draw();
private:

	class Call
	{
	public:
		Render::Texture* _tex;
	private:
		
	};
	
	std::unique_ptr<Call> call;

};

