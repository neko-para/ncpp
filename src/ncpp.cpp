#include "ncpp.h"

namespace NCPP {

	bool Init() {
		return initscr();
	}

	void Exit() {
		endwin();
	}

}