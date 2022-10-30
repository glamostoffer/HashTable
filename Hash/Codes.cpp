#include "Codes.h"

void Codes::printFile(string filename) { //������� ������ ���������� ����� � �������
	ifstream fin(filename);
	if (!fin.is_open()) //�������� ������������� �������� �����
		cout << "There is no such file\n";
	else {
		string values;
		if (!fin.eof()) {
			while (getline(fin, values)) { //���������� ����� ����������� �����
				cout << values << endl;
			}
		}
		fin.close();
	}
}

void Codes::printBin(string filename) { //������� ������ ��������� ����� � �������
	ifstream bin(filename, ios::binary | ios::in); //�������� ����� � �������� �������
	diallingCodes diallingCode;
	
	while (bin.read((char*)&diallingCode, sizeof(diallingCodes))) { //������ �� �����(���������� true � ������ ������ � false � ������ ��������� �����
		cout << diallingCode.code << " " << diallingCode.city << " " << diallingCode.country << endl;
	}
	if (bin.good()) bin.close();
}

bool Codes::doesExist(string name) { //�������� ������������� �����
	ifstream check(name);
	return check.is_open();
}

void Codes::fromTextToBinary(string fileText, string fileBin) { //�������������� �������� ������ �� ���������� ����� � �������� ����
	ifstream txt(fileText);
	ofstream bin(fileBin, ios::binary);
	diallingCodes diallingCode;
	while (true) {
		txt >> diallingCode.code; //������ ������ �� ����� � ���������
		if (!txt.eof()) {
			txt >> diallingCode.city >> diallingCode.country;
			bin.write((char*)&diallingCode, sizeof(diallingCodes));
		}
		else {
			break;
		}
	}
	if (txt.good() && bin.good()) { //�������� ���������� ������ ����� � ������
		txt.close();
		bin.close();
	}
}

void Codes::fromBinToText(string fileText, string fileBin) { //�������������� ������ �� ��������� ����� � ���������
	ifstream bin(fileBin, ios::binary | ios::in);
	ofstream txt(fileText);
	diallingCodes diallingCode;
	while (bin.read((char*)&diallingCode, sizeof(diallingCodes))) { //��������� ���������� �� ��������� �����
		txt << diallingCode.code << " " << diallingCode.city << " " << diallingCode.country << endl; //���������� � � ���������
	}
	if (txt.good() && bin.good()) {
		txt.close();
		bin.close();
	}
}

Codes::diallingCodes Codes::getCurrentCode(string filename, int position) { //������ � ������ �� �� ����������� ������ � �����
	ifstream bin(filename, ios::binary | ios::in);
	diallingCodes diallingCode;
	if (position == -1) bin.seekg(-1 * sizeof(diallingCodes), ios::end); //����� ��������� ������
	else bin.seekg((position - 1) * sizeof(diallingCodes)); //���������� ������ � ����� �� ������ ��� �������
	bin.read((char*)&diallingCode, sizeof(diallingCodes)); //��������� ������
	if (bin.good()) bin.close();
	return diallingCode;
}

void Codes::remove(string filename, int key) { //�������� ������ � �������� ��������� ����� ����� ������ �� ��������� ������
	diallingCodes record, replace;
	replace = getCurrentCode(filename, -1);
	ifstream bin(filename, ios::binary | ios::in);
	ofstream tmp("removed.txt"); //�������� ���������� �����-������ 
	while (bin.read((char*)&record, sizeof(diallingCodes))) { //���������� �� ��������� ���� ��������� ����������
		if (record.code != key)
			tmp << record.code << " " << record.city << " " << record.country << endl;
	}
	if (tmp.good() && bin.good()) {
		tmp.close();
		bin.close();
	}
	this->fromTextToBinary("removed.txt", filename);//�������������� ������� ����
	std::remove("removed.txt"); // �������� ���������� �����
}

void Codes::add(string filename, int code, const char city[], const char country[]) { //���������� ����� ������ � ����� �����
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

void Codes::filterCodesByCountry(string filename, string country) { //������������ � ��������� ����� ������� ����� ��������� ������
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

void Codes::uploadCityCode(string filename, string city, string newCode) { //���������� ���� ������ �� �������� ������
	diallingCodes cityCode;
	ifstream bin(filename, ios::binary | ios::in);
	ofstream tmp("buff.txt"); //�������� ���������� �����-������ 
	while (bin.read((char*)&cityCode, sizeof(diallingCodes))) { //���������� �� ��������� ���� ��������� ����������
		if (cityCode.city == city)
			tmp << newCode << " " << cityCode.city << " " << cityCode.country << endl; //��������� ��� ������
		else
			tmp << cityCode.code << " " << cityCode.city << " " << cityCode.country << endl;
	}
	if (tmp.good() && bin.good()) {
		tmp.close();
		bin.close();
	}
	this->fromTextToBinary("buff.txt", filename);//�������������� ������� ����
	std::remove("buff.txt"); // �������� ���������� �����
}