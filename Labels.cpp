#include "stdafx.h"
#include "Labels.h"

std::unique_ptr<Labels> Labels::CreateSprite(int time, IPoint position)
{
	return std::make_unique<Labels>(time, position);
}

Labels::Labels(int time, IPoint position) {
	
	call = std::unique_ptr<Call>(new Call);
	call->_time = time;
	call->_position = position;
	call->_score = 0;
	call->eventTimer = 1.f;
	call->currentCounter = 0.f;
	call->frameCounter = 0;

}

Labels::~Labels() {

}

void Labels::Draw() {
	Render::BindFont("arial");
	Render::PrintString(call->_position, std::to_string(call->_time), 1.f, CenterAlign);
}

void Labels::Update(float dt) {
	///call->_time += 1000.0 / 60.0;
	call->_score = call->_score;

	call->currentCounter += dt;
	call->frameCounter++;

	if (call->currentCounter >= call->eventTimer) {
		call->currentCounter = call->currentCounter - call->eventTimer;
		timerEvent1();
	}
}

void Labels::timerEvent1() {
	call->frameCounter = 0;
	call->_time ++;
}

void Labels::increaseScore(int x) {

	call->_score += x;
}

/*# 60 updates a second

GAME_STEP_TIME_MSS = 1000.0 / 60.0



running = true

accumulator = 0

previous = currentTimeMilliseconds()

while running

now = currentTimeMilliseconds()

elapsed = now - previous

accumulator += elapsed

# while loop here to "catch up" if we fall multiple game steps behind

while accumulator >= GAME_STEP_TIME_MS

gameLogic()

accumulator -= GAME_STEP_TIME_MS



drawGame(elapsed)

*/