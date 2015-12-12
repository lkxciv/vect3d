#define PI 3.14159265

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

class Vect3d
{
public:
	float vect[3];

	Vect3d();

	Vect3d(float x, float y, float z);

	~Vect3d();

	//Berechnet den Flächeninhalt des aufgespannten Spats
	static float Area(Vect3d v1, Vect3d v2);

	//Berechnet Volumen des Aufgespannten Polytops
	//V = |(v1 x v2) * v3|
	static float Volume(Vect3d v1, Vect3d v2, Vect3d v3);

	//Berechnet betrag von Projektion auf v2
	float AbsProjectOn(Vect3d v2);

	//Berechnet Vektor von Projetion auf v2
	Vect3d ProjectOn(Vect3d v2);

	//Berechnet Vektorbetrag
	float AbsV();

	//Berechnet Skalarprodukt
	static float DotP(Vect3d v1, Vect3d v2);

	//Berechnet Kreuzprodukt
	static Vect3d CrossP(Vect3d v1, Vect3d v2);

	//Vektor wird als String ausgegeben
	std::string ToString();

	//Prüft Linearabhängigkeit
	static bool LinDep(Vect3d v1, Vect3d v2);

	//Berechnet Winkel zw. 2 Vektoren
	static double Angle(Vect3d v1, Vect3d v2);

	//Berechnet Winkel zw. 2 Vektoren mit Betrag im Zähler für Objekte
	static double AngleAbs(Vect3d v1, Vect3d v2);

	//Berechnet Einheitsvektor
	static Vect3d UnitV(Vect3d v1);

	//Überladung addition
	Vect3d operator+(Vect3d v2);

	//Überladung +=
	Vect3d operator+=(Vect3d v2);

	//Überladunng subtraktion
	Vect3d operator-(Vect3d v2);

	//Überladung -=
	Vect3d operator-=(Vect3d v2);

	//Überladung multiplikation mit skalar
	Vect3d operator*(float skalar);

	//Überladung multiplikation mit skalar
	Vect3d operator*=(float skalar);

	//Überladung division mit skalar
	Vect3d operator/(float skalar);

	//Überladung division mit skalar
	Vect3d operator/=(float skalar);

	//Überladung multiplikation durch skalaprodukt zweier vektoren
	float operator*(Vect3d v2);
};

//methodendefinitionen von Vect3d

Vect3d::Vect3d()
{
	vect[0] = NULL;
	vect[1] = NULL;
	vect[2] = NULL;
}

Vect3d::Vect3d(float x, float y, float z)
{
	vect[0] = x;
	vect[1] = y;
	vect[2] = z;
}

Vect3d::~Vect3d()
{
}

//Berechnet den Flächeninhalt des aufgespannten Spats
float Vect3d::Area(Vect3d v1, Vect3d v2)
{
	return(CrossP(v1, v2).AbsV());
}

//Berechnet Volumen des Aufgespannten Polytops
//V = |(v1 x v2) * v3|
float Vect3d::Volume(Vect3d v1, Vect3d v2, Vect3d v3)
{
	return(abs(DotP(CrossP(v1, v2), v3)));
}

//Berechnet betrag von Projektion auf v2
float Vect3d::AbsProjectOn(Vect3d v2)
{
	return(DotP(*this, v2) / (*this).AbsV());
}

//Berechnet Vektor von Projetion auf v2
Vect3d Vect3d::ProjectOn(Vect3d v2)
{
	return(v2 * ((*this).AbsProjectOn(v2) * (*this).AbsV()));
}

//Berechnet Vektorbetrag
float Vect3d::AbsV()
{
	return(sqrt(vect[0] * vect[0] + vect[1] * vect[1] + vect[2] * vect[1]));

}

//Berechnet Skalarprodukt
float Vect3d::DotP(Vect3d v1, Vect3d v2)
{
	return(v1.vect[0] * v2.vect[0] + v1.vect[1] * v2.vect[1] + v1.vect[2] * v2.vect[2]);
}

//Berechnet Kreuzprodukt
Vect3d Vect3d::CrossP(Vect3d v1, Vect3d v2)
{
	Vect3d vR;

	vR.vect[0] = v1.vect[1] * v2.vect[2] - v1.vect[2] * v2.vect[1];
	vR.vect[1] = v1.vect[2] * v2.vect[0] - v1.vect[0] * v2.vect[2];
	vR.vect[2] = v1.vect[0] * v2.vect[1] - v1.vect[1] * v2.vect[0];

	return vR;
}

//Vektor wird als String ausgegeben
std::string Vect3d::ToString()
{
	std::ostringstream oss;
	std::string sR = "{";

	for (int i = 0; i <= 2; i++)
	{
		oss << vect[i];
		sR += oss.str();
		oss.str("");//Wird zurückgesetzt

		if (i < 2)
		{
			sR += ", ";
		}
	}
	sR += "}";
	return sR;
}

//Prüft Linearabhängigkeit
bool Vect3d::LinDep(Vect3d v1, Vect3d v2)
{
	if (v1.vect[0] / v2.vect[0] == v1.vect[1] / v2.vect[1] && v1.vect[1] / v2.vect[1] == v1.vect[2] / v2.vect[2])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Berechnet Winkel zw. 2 Vektoren
double Vect3d::Angle(Vect3d v1, Vect3d v2)
{
	return(acos(DotP(v1, v2) / (v1.AbsV() * v2.AbsV()) * 180 / PI));
}

//Berechnet Winkel zw. 2 Vektoren mit Betrag im Zähler für Objekte
double Vect3d::AngleAbs(Vect3d v1, Vect3d v2)
{
	return(acos(abs(DotP(v1, v2)) / (v1.AbsV() * v2.AbsV()) * 180 / PI));
}

//Berechnet Einheitsvektor, ist static
Vect3d Vect3d::UnitV(Vect3d v1)
{
	float b = v1.AbsV();
	for (int i = 0; i <= 2; i++)
	{
		v1.vect[i] /= b;
	}
	return v1;
}

//Überladung addition
Vect3d Vect3d::operator+(Vect3d v2)
{
	Vect3d res;
	for (int i = 0; i <= 2; i++)
	{
		res.vect[i] = vect[i] + v2.vect[i];
	}
	return res;
}

//Überladung +=
Vect3d Vect3d::operator+=(Vect3d v2)
{
	for (int i = 0; i <= 2; i++)
	{
		vect[i] += v2.vect[i];
	}
	//this ist Zeiger auf Objekt, *this returnt Wert
	return *this;
}

//Überladunng subtraktion
Vect3d Vect3d::operator-(Vect3d v2)
{
	Vect3d res;
	for (int i = 0; i <= 2; i++)
	{
		res.vect[i] = vect[i] - v2.vect[i];
	}
	return res;
}

//Überladung -=
Vect3d Vect3d::operator-=(Vect3d v2)
{
	for (int i = 0; i <= 2; i++)
	{
		vect[i] -= v2.vect[i];
	}
	//this ist Zeiger auf Objekt, *this returnt Wert
	return *this;
}

//Überladung multiplikation mit skalar
Vect3d Vect3d::operator*(float skalar)
{
	Vect3d res;
	for (int i = 0; i <= 2; i++)
	{
		res.vect[i] = vect[i] * skalar;
	}
	return res;
}

//Überladung multiplikation mit skalar
Vect3d Vect3d::operator*=(float skalar)
{
	for (int i = 0; i <= 2; i++)
	{
		vect[i] *= skalar;
	}
	return *this;
}

//Überladung division mit skalar
Vect3d Vect3d::operator/(float skalar)
{
	Vect3d res;
	for (int i = 0; i <= 2; i++)
	{
		res.vect[i] = vect[i] / skalar;
	}
	return res;
}

//Überladung division mit skalar
Vect3d Vect3d::operator/=(float skalar)
{
	for (int i = 0; i <= 2; i++)
	{
		vect[i] /= skalar;
	}
	return *this;
}

//Überladung multiplikation durch skalaprodukt zweier vektoren
float Vect3d::operator*(Vect3d v2)
{
	return DotP(*this, v2);
}

class Line3d
{
public:
	Vect3d pV;//Stützvektor
	Vect3d rV;//Richtungsvektor

	Line3d(Vect3d pV, Vect3d rV);

	~Line3d();

	//Prüft Parallelität der Geraden
	static bool IsParallel(const Line3d & g1, const Line3d & g2);

	static float Angle(const Line3d & g1, const Line3d & g2);

	//Prüft, ob zwei Geraden Identisch sind
	static bool IsIdentical(const Line3d & g1, const Line3d & g2);
};

//methodendefinitionen von Line3d

Line3d::Line3d(Vect3d pV, Vect3d rV)
{
	this->pV = pV;
	this->rV = rV;
}

Line3d::~Line3d()
{
}

//Prüft Parallelität der Geraden
bool Line3d::IsParallel(const Line3d & g1, const Line3d & g2)
{
	return(Vect3d::LinDep(g1.rV, g2.rV));
}

float Line3d::Angle(const Line3d & g1, const Line3d & g2)
{
	return(Vect3d::AngleAbs(g1.rV, g2.rV));
}

//Prüft, ob zwei Geraden Identisch sind
bool Line3d::IsIdentical(const Line3d & g1, const Line3d & g2)
{
	if (IsParallel(g1, g2) == 1)
	{
		/*Wenn sie parallel sind muss stützp. von g2 auf gerade g1 liegen.
		d.h. der Parameter von g1 muss beim stützp. g2 für die
		x gleichung, y gleichung und z gleichung gleich sein*/
		float par[3];
		for (int i = 0; i <= 2; i++)
		{
			//r = (s2 - s1) / v1; da s2 = s1 + r * v1
			par[i] = (g2.pV.vect[i] - g1.pV.vect[i]) / g1.rV.vect[i];
		}
		if (par[0] == par[1] && par[1] == par[2])
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	Vect3d v1(1, 2, 3);
	Vect3d v2(3, 2, 1);
	Vect3d res = Vect3d::UnitV(v1);

	std::cout << res.ToString();
}