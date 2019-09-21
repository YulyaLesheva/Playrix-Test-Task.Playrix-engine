#pragma once
class Score;
class Restart;
class Timer;
class StaticObjects;

class ScheduleWidget : public GUI::Widget
{
public:
	ScheduleWidget(const std::string& name, rapidxml::xml_node<>* elem);
	~ScheduleWidget();
	void Draw() override;
	void Update(float dt) override;
	void AcceptMessage(const Message& message) override;
	bool MouseDown(const IPoint& mouse_pos) override;
	bool _bombIsKilled;
	///	void MouseMove(const IPoint& mouse_pos) override;
	///void MouseUp(const IPoint& mouse_pos) override;
	std::unique_ptr <Score> _score;
	std::unique_ptr <Restart> _restart;
	std::unique_ptr <Timer> _timer;
	std::unique_ptr <StaticObjects> _stand;
	std::unique_ptr <StaticObjects> _clock;


private:
	void Init();
};