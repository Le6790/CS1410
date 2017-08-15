#ifndef _ABSTRACT_HPP_
#define _ABSTRACT_HPP_
#include <string>

class Geometry 
{
public:

	std::string getName() { return m_name; }
	std::string getType() { return m_type; }
	virtual double computeVolume() = 0; //abstracts
	virtual double computeSurface() = 0; //abstracts
	
protected:
	std::string m_name; //stores ta description of the object
	std::string m_type; // stores the type of the object (box or sphere)

};

class Box : public Geometry 
{
public: 
	Box(std::string name, double a, double b, double c) { //box constructor
		std::string type = "Box"; //if it is using the class box, then the type is box
		m_name = name;
		m_type = type;
		m_height = a;
		m_length = b;
		m_width = c;

	}
	virtual double computeVolume() 
	{
		m_volume = m_height * m_length * m_width;

		return m_volume;
	}

	virtual double computeSurface() 
	{
		m_surface = 2 * (m_height*m_width) + 2 * (m_height*m_length) + 2 * (m_width*m_length);
		return m_surface;
	}

private:
	double m_volume;
	double m_surface;
	double m_height;
	double m_length;
	double m_width;
	
	
};

class Sphere : public Geometry
{
public:
	Sphere(std::string name, double r) //sphere constructor
	{
		std::string type = "Sphere"; //if it is using the class sphere, then the type is sphere
		m_type = type;
		m_name = name;
		m_radius = r;
	}
	virtual double computeVolume() 
	{
		m_volume = 1.33333333* (3.14159 * (m_radius*m_radius*m_radius));
		
		return m_volume;
	}

	virtual double computeSurface()
	{
		m_surface = 4 * 3.14159 * (m_radius*m_radius);

		return m_surface;
	}
private:
	double m_volume;
	double m_surface;
	double m_radius;
};

void report(Geometry* geo) 
{
	std::cout << "----- Geometry Report -----" << std::endl;
	std::cout << "type: " << geo->getType() << std::endl;
	std::cout << "Name: " << geo->getName() << std::endl;
	std::cout << "Volume: " << geo->computeVolume() << std::endl;
	std::cout << "Surface Area: " << geo->computeSurface() << std::endl << std::endl;
	
}

#endif // !_Abstract_HPP_

