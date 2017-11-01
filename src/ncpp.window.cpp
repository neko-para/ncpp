#include "ncpp.window.h"
namespace NCPP {
	class _Window : public Window {
	public:
		_Window(WINDOW* wnd) : Window(wnd) {}
		void Update(WINDOW* wnd) {
			Wnd = wnd;
		}
	};
	_Window _StdWnd(stdscr);
	_Window _NewWnd(newscr);
	_Window _CurWnd(curscr);

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