#ifndef _NCPP_WINDOW_H_
#define _NCPP_WINDOW_H_
#include "ncpp.share.h"
#include <stdarg.h>
#include <ncurses.h>

namespace NCPP {

	class Window {
	private:
		struct WindowShare : public ShareData<WINDOW> {
			virtual ~WindowShare() {
				if (ptr) {
					delwin(ptr);
				}
			}
		};
	protected:
		Share<WindowShare> Wnd;
		Window(WINDOW* wnd = 0) : Wnd(wnd) {}
	public:
		Window CreateSub(int h, int w, int y, int x) const {
			return Window(subwin(Wnd, h, w, y, x));
		}
		Window CreateDer(int h, int w, int y, int x) const {
			return Window(derwin(Wnd, h, w, y, x));
		}
		int Width() const {
			return getmaxx(Wnd);
		}
		int Height() const {
			return getmaxy(Wnd);
		}
		int CurX() const {
			return getcurx(Wnd);
		}
		int CurY() const {
			return getcury(Wnd);
		}
		void print(const char* format, ...) const {
			va_list lst;
			va_start(lst, format);
			vwprintw(Wnd, format, lst);
			va_end(lst);
		}
		int get() const {
			return wgetch(Wnd);
		}
	};

	Window StdWnd();
	Window CurWnd();
	Window NewWnd();

}

#endif