#include<iostream>
using namespace std;

#define MIN_TANK_VOLUME 40
#define MAX_TANK_VOLUME 80
#define MIN_ENGINE_CONSUMPTION 4
#define MAX_ENGINE_CONSUMPTION 40


class Tank
{
	const unsigned int VOLUME;
	double fuel_level;
public:
	const unsigned int get_VOLUME()const
	{
		return VOLUME;
	}
	double get_fuel_level()const
	{
		return fuel_level;
	}
	double fill(double fuel) //сколько можно залить в бак (слить с бака)
	{
		if (fuel_level + fuel < 0)return fuel_level = 0;
		if (fuel_level + fuel > VOLUME)return fuel_level = VOLUME;
		if (fuel_level + fuel >= 0 && fuel_level + fuel <= VOLUME)fuel_level += fuel;
		return fuel_level;
	}
	double give_fuel(double fuel) //позвол€ет только брать бензин с бака
	{
		fuel_level -= fuel;
		if (fuel_level < 0)fuel_level = 0;
		return fuel_level; //возвращает тот уровень топлива, который осталс€
	}
	// онструктор
	Tank(unsigned int volume)
		:VOLUME(volume >= MIN_TANK_VOLUME && volume < +MAX_TANK_VOLUME ? volume : MAX_TANK_VOLUME), fuel_level(0)
		//инициализируем и производим фильтрацию(проверить и выбрать чем
	{
		//this->VOLUME = volume;
		cout << "Tank is ready\t" << this << endl;
	}
	~Tank()
	{
		cout << "Tank is gone\t" << this << endl;
	}
	void info()const
	{
		cout << "Tank volume:\t " << VOLUME << endl;
		cout << "Fuel level:\t " << fuel_level << endl;
	}
};

class Engine
{
	double consumption; //расход топлива
	double consumption_per_second; //расход топлива в секунду
	bool is_started;
public:
	double get_consumption()const
	{
		return consumption;
	}
	double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	bool get_started()const
	{
		return is_started;
	}
	bool start()
	{
		is_started = true;
	}
	bool stop()
	{
		is_started = false;
	}
	void set_consumption(double consumption)
	{
		if (consumption >= MIN_ENGINE_CONSUMPTION && consumption <= MAX_ENGINE_CONSUMPTION)
			this->consumption = consumption;
		else
			this->consumption = MAX_ENGINE_CONSUMPTION / 2;
		consumption_per_second = consumption * .3e-4;
	}
	//constructor
	Engine(double consumption)
	{
		set_consumption(consumption);
		is_started = false;
		cout << "Engine is ready: \t" << this << endl;
	}
	~Engine()
	{
		cout << "Engine is gone: \t" << this << endl;
	}
	void info()const
	{
		cout << "Consumption: \t" << consumption << endl;
		cout << "Consumption per second: \t" << consumption_per_second << endl;
		cout << "Engine is " << (is_started ? "started" : "stopped") << endl;
	}
};

//#define TANK_CHECK

void main()
{
	setlocale(LC_ALL, "ru");
#ifdef TANK_CHECK
	Tank tank(120);
	tank.info();
	int fuel;
	while (true)
	{
		cout << "¬ведите объем: "; cin >> fuel;
		tank.fill(fuel);
		tank.info();
	}
#endif // TANK_CHECK

	Engine engine(9);
	engine.info();
}