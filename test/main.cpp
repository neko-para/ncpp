#include "../src/ncpp.h"

int main() {
	NCPP::Init();
	NCPP::Window stdw = NCPP::StdWnd();
	stdw.print("Hello!");
	stdw.get();
	NCPP::Exit();
}