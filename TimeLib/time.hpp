#include <string>

struct Time {
    private:
        int hours = 0;
        int minutes = 0;
        int seconds = 0;
        bool flag;
        static unsigned count;
    public:
        Time(bool flag = true);
        Time(int h, int m = 0, int s = 0, bool flag = true);
        ~Time();
        Time(const Time& t);

        void PrintTime();
        std::string toString();

        void SetHours(int hours);
        void SetMinutes(int minutes);
        void SetSeconds(int seconds);
        
        int GetHours() const;
        int GetMinutes() const;
        int GetSeconds() const;

        int ToSeconds() const;
        Time Normalize ();

        Time& operator= (const Time& other);
        Time& operator += (int s);
        Time& operator -= (int s);
        Time& operator += (const Time& a);
        Time& operator -= (const Time& a);
        bool operator == (const Time& other);

        friend std::ostream& operator<<(std::ostream& os, const Time& time);
};

Time operator+ (const Time& t, int s);
Time operator- (const Time& t, int s);
namespace TimeNameSpace {
    std::string to_string(const Time& a);
}
