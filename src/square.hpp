#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>
#include <tuple>

template<class T>
struct TSquare {
	/* Cords of left bottom corner, side */
	std::pair<T, T> Cord;
	T Side;

	TSquare(const std::pair<T, T> & cord, T side) : Cord(cord), Side(side) {}
};

template<class T>
T CalcSquare(const TSquare<T> & Sq) {
	return Sq.Side * Sq.Side;
}

template<class T>
std::ostream & operator << (std::ostream & out, const TSquare<T> & sq) {
	out << "Square {";
	out << std::pair<T, T>(sq.Cord.first, sq.Cord.second) << ", ";
	out << std::pair<T, T>(sq.Cord.first, sq.Cord.second + sq.Side) << ", ";
	out << std::pair<T, T>(sq.Cord.first + sq.Side, sq.Cord.second + sq.Side) << ", ";
	out << std::pair<T, T>(sq.Cord.first + sq.Side, sq.Cord.second);
	out << "}";
	return out;
}

template<class T1, class T2>
std::ostream & operator << (std::ostream & out, const std::pair<T1, T2> & p) {
	out << "(" << p.first << ", " << p.second << ")";
	return out;
}

#endif /* SQUARE_HPP */