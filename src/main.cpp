#include <algorithm>
#include "stack.hpp"
#include "square.hpp"

/*
 * Инютин М А М8О-207Б-19
 * Создать шаблон динамической коллекцию, согласно варианту
 * задания:
 * 1. Коллекция должна быть реализована с помощью умных указателей
 * (std::shared_ptr, std::weak_ptr). Опционально использование
 * std::unique_ptr;
 * 2. В качестве параметра шаблона коллекция должна принимать тип
 * данных – фигуры;
 * 3. Реализовать forward_iterator по коллекции;
 * 4. Коллекция должны возвращать итераторы begin() и  end();
 * 5. Коллекция должна содержать метод вставки на позицию
 * итератора insert(iterator);
 * 6. Коллекция должна содержать метод удаления из позиции
 * итератора erase(iterator);
 * 7. При выполнении недопустимых операций (например выход аз
 * границы коллекции или удаление несуществующего элемента)
 * необходимо генерировать исключения;
 * 8. Итератор должен быть совместим со стандартными алгоритмами
 * (например, std::count_if)
 * 9. Коллекция должна содержать метод доступа: pop, push, top;
 * 10. Реализовать программу, которая:
 * - позволяет вводить с клавиатуры фигуры (с типом int в качестве
 *   параметра шаблона фигуры) и добавлять в коллекцию;
 * - позволяет удалять элемент из коллекции по номеру элемента;
 * - выводит на экран введенные фигуры c помощью std::for_each;
 * - выводит на экран количество объектов, у которых площадь
 *   меньше заданной (с помощью  std::count_if).
 */

int main() {
	size_t n;
	auto Print = [](const TStackNode< TSquare<int> > & sq) {
		std::cout << sq << std::endl;
	};
	std::cout << "Input number of squares in stack" << std::endl;
	std::cin >> n;
	int cordX, cordY, side;
	TStack< TSquare<int> > st;
	for (size_t i = 0; i < n; ++i) {
		size_t n;
		std::cout << "Input index to insert a square" << std::endl;
		std::cin >> n;
		std::cout << "Input square as follows: x y a" << std::endl;
		std::cout << "x, y is a left bottom corner cords" << std::endl;
		std::cout << "a is square side" << std::endl;
		std::cin >> cordX >> cordY >> side;
		try {
			TStack< TSquare<int> >::iterator it = st.begin();
			while (n--) {
				++it;
			}
			st.Insert(it, TSquare<int>(std::pair<int, int>(cordX, cordY), side));
		} catch (std::runtime_error & exception) {
			std::cout << exception.what() << std::endl;
		}
	}
	std::cout << "Your input:" << std::endl;
	std::for_each(st.begin(), st.end(), Print);
	std::cout << "Input index to erase from stack" << std::endl;
	std::cin >> n;
	try {
		TStack< TSquare<int> >::iterator it = st.begin();
		while (n > 1) {
			++it;
			--n;
		}
		st.Erase(it);
	} catch (std::runtime_error & exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << "After erase:" << std::endl;
	std::for_each(st.begin(), st.end(), Print);
	int minimalSquare;
	std::cout << "Input minimal square" << std::endl;
	std::cin >> minimalSquare;
	auto MatchSqaure = [minimalSquare](const TStackNode< TSquare<int> > & sq) {
		return !(CalcSquare(sq.Data) < minimalSquare);
	};
	std::cout << "Number of figures with square greater or equal, than " << minimalSquare << ": ";
	std::cout << std::count_if(st.begin(), st.end(), MatchSqaure) << std::endl;
	return 0;
}