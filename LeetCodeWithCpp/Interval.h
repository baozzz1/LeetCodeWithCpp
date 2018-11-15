#pragma once
#ifndef INTERVAL_H
#define INTERVAL_H

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

#endif