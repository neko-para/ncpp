#ifndef _NCPP_SHARE_H_
#define _NCPP_SHARE_H_

namespace NCPP {

	template <typename T>
	struct ShareData {
		typedef T DataType;

		DataType* ptr;
		unsigned long ref;
		virtual ~ShareData() {}
	};

	template <typename SD>
	class Share {
		typedef typename SD::DataType DataType;
		SD* sd;
	public:
		Share(DataType* t = 0) {
			sd = new SD;
			sd->ptr = t;
			sd->ref = 1;
		}
		Share(const Share& share) {
			sd = share.sd;
			++sd->ref;
		}
		~Share() {
			--sd->ref;
			if (!sd->ref) {
				delete sd;
			}
		}
		Share& operator=(const Share& share) {
			if (sd == share.sd) {
				return *this;
			}
			--sd->ref;
			if (!sd->ref) {
				delete sd;
			}
			sd = share.sd;
			++sd->ref;
			return *this;
		}
		DataType* operator->() const {
			return sd->ptr;
		}
		operator DataType*() const {
			return sd->ptr;
		}
	};

}

#endif