#include "ncpp.window.h"
namespace NCPP {
	class _Window : public Window {
	public:
		_Window() : Window(0) {}
		void Update(WINDOW* wnd) {
			Wnd = wnd;
		}
	};
	_Window _StdWnd;
	_Window _NewWnd;
	_Window _CurWnd;

	Window StdWnd() {
		_StdWnd.Update(stdscr);
		return _StdWnd;
	}
	Window CurWnd() {
		_CurWnd.Update(curscr);
		return _CurWnd;
	}
	Window NewWnd() {
		_NewWnd.Update(newscr);
		return _NewWnd;
	}
}