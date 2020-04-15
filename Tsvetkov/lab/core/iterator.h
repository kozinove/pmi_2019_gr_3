#pragma once
class Iterator {
public:
	virtual bool hasNext() = 0;
	virtual int next() = 0;
};

