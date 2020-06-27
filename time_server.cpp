#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

string AskTimeServer() {
	srand(time(NULL));
	int r = rand()%3;
	if(r == 0)
		throw system_error();
	else if (r == 1)
	{
		int t = rand()%5;
		if (t == 0)
			return "10:12:53";
		if (t == 1)
			return "23:11:15";
		if (t == 2)
			return "15:14:22";
		return "16:33:08";
	}else
		throw invalid_argument("Lol. Ne to");

    /* ƒл€ тестировани€ повставл€йте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значени€
       * выброс исключени€ system_error
       * выброс другого исключени€ с сообщением.
    */
}

class TimeServer {
public:
    string GetCurrentTime() {
    	try{
    		last_fetched_time = AskTimeServer();
    	}catch (const system_error& ex){
    		return last_fetched_time;
    		throw ex;
    	}
    	return last_fetched_time;

        /* –еализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            пол€ last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
