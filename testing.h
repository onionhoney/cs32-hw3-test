// testing.h


#define check(EX) (handle(#EX, EX))

std::string message;

inline bool handle(const char *msg, bool result) {
    if (result) {
        message = "Success";
        return true;
    } else {
        message = msg;
        return false;
    }
}
