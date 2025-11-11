#pragma once

template<class T>
class HashEntidad {
private:
	int key;
	T value;
public:
	HashEntidad(int key, T value) {
		this->key = key;
		this->value = value;
	}

	int getKey() const {
		return key;
	}

	T getValue() const {
		return value;
	}
};