#include "Codes.h"

void Codes::printFile(string filename) { //функция вывода текстового файла в консоль
	ifstream fin(filename);
	if (!fin.is_open()) //проверка существования целевого файла
		cout << "There is no such file\n";
	else {
		string values;
		if (!fin.eof()) {
			while (getline(fin, values)) { //построчный вывод содержимого файла
				cout << values << endl;
			}
		}
		fin.close();
	}
}

void Codes::printBin(string filename) { //функция вывода двоичного файла в консоль
	ifstream bin(filename, ios::binary | ios::in); //открытие файла в двоичном формате
	diallingCodes diallingCode;
	
	while (bin.read((char*)&diallingCode, sizeof(diallingCodes))) { //чтение из файла(возвращает true в случае чтения и false в случае окончания файла
		cout << diallingCode.code << " " << diallingCode.city << " " << diallingCode.country << endl;
	}
	if (bin.good()) bin.close();
}

bool Codes::doesExist(string name) { //проверка существования файла
	ifstream check(name);
	return check.is_open();
}

void Codes::fromTextToBinary(string fileText, string fileBin) { //преобразование тестовых данных из текстового файла в двоичный файл
	ifstream txt(fileText);
	ofstream bin(fileBin, ios::binary);
	diallingCodes diallingCode;
	while (true) {
		txt >> diallingCode.code; //запись данных из файла в структуру
		if (!txt.eof()) {
			txt >> diallingCode.city >> diallingCode.country;
			bin.write((char*)&diallingCode, sizeof(diallingCodes));
		}
		else {
			break;
		}
	}
	if (txt.good() && bin.good()) { //проверка отсутствия ошибок ввода и вывода
		txt.close();
		bin.close();
	}
}

void Codes::fromBinToText(string fileText, string fileBin) { //преобразование данных из двоичного файла в текстовый
	ifstream bin(fileBin, ios::binary | ios::in);
	ofstream txt(fileText);
	diallingCodes diallingCode;
	while (bin.read((char*)&diallingCode, sizeof(diallingCodes))) { //считываем информацию из бинарного файла
		txt << diallingCode.code << " " << diallingCode.city << " " << diallingCode.country << endl; //записываем её в текстовый
	}
	if (txt.good() && bin.good()) {
		txt.close();
		bin.close();
	}
}

Codes::diallingCodes Codes::getCurrentCode(string filename, int position) { //доступ к записи по ее порядковому номеру в файле
	ifstream bin(filename, ios::binary | ios::in);
	diallingCodes diallingCode;
	if (position == -1) bin.seekg(-1 * sizeof(diallingCodes), ios::end); //поиск последней записи
	else bin.seekg((position - 1) * sizeof(diallingCodes)); //перемещаем курсор в файле на нужную нам позицию
	bin.read((char*)&diallingCode, sizeof(diallingCodes)); //считываем данные
	if (bin.good()) bin.close();
	return diallingCode;
}

void Codes::remove(string filename, int key) { //удаление записи с заданным значением ключа путем замены на последнюю запись
	diallingCodes record, replace;
	replace = getCurrentCode(filename, -1);
	ifstream bin(filename, ios::binary | ios::in);
	ofstream tmp("removed.txt"); //создание временного файла-буфера 
	while (bin.read((char*)&record, sizeof(diallingCodes))) { //записываем во временный файл изменённое наполнение
		if (record.code != key)
			tmp << record.code << " " << record.city << " " << record.country << endl;
	}
	if (tmp.good() && bin.good()) {
		tmp.close();
		bin.close();
	}
	this->fromTextToBinary("removed.txt", filename);//перезаписываем целевой файл
	std::remove("removed.txt"); // удаление временного файла
}

void Codes::add(string filename, int code, const char city[], const char country[]) { //добавление новой записи в конец файла
	ofstream bin(filename, ios::binary | ios::app);
	diallingCodes diallingCode;
	diallingCode.code = code;
	for (int i = 0; i < 20; i++) {
		diallingCode.city[i] = city[i];
	}
	for (int i = 0; i < 20; i++) {
		diallingCode.country[i] = country[i];
	}
	bin.write((char*)&diallingCode, sizeof(diallingCodes));
}

void Codes::filterCodesByCountry(string filename, string country) { //формирование в текстовом файле таблицы кодов указанной страны
	ifstream bin(filename, ios::binary | ios::in);
	ofstream tmp("selected_country_codes.txt");
	diallingCodes diallingCode;
	while (bin.read((char*)&diallingCode, sizeof(diallingCodes))) {
		if (diallingCode.country == country) {
			tmp << diallingCode.city << " " << diallingCode.code << endl;
		}
	}
	if (tmp.good() && bin.good()) {
		tmp.close();
		bin.close();
	}
}

void Codes::uploadCityCode(string filename, string city, string newCode) { //обновление кода города по названию города
	diallingCodes cityCode;
	ifstream bin(filename, ios::binary | ios::in);
	ofstream tmp("buff.txt"); //создание временного файла-буфера 
	while (bin.read((char*)&cityCode, sizeof(diallingCodes))) { //записываем во временный файл изменённое наполнение
		if (cityCode.city == city)
			tmp << newCode << " " << cityCode.city << " " << cityCode.country << endl; //обновляем код города
		else
			tmp << cityCode.code << " " << cityCode.city << " " << cityCode.country << endl;
	}
	if (tmp.good() && bin.good()) {
		tmp.close();
		bin.close();
	}
	this->fromTextToBinary("buff.txt", filename);//перезаписываем целевой файл
	std::remove("buff.txt"); // удаление временного файла
}