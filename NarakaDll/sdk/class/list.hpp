#pragma once

template <class T>
class List : public Object {
public:
	int Count() {
		return this->GetField("_size")->GetValue<int>(this);
	}

	Array<T>* GetValues() {
		return this->GetField("_items")->GetValue<Array<T>*>(this);
	}
};

template <typename T>
struct Slot {
	int hashCode;
	int next;
	T value;
};

template <class T>
class HashSet : public Object {
public:
	int Count() {
		return this->GetField("_count")->GetValue<int>(this);
	}

	Array<int>* GetBuckets() {
		return this->GetField("_buckets")->GetValue<Array<int>*>(this);
	}

	Array<Slot<T>>* GetSlots() {
		return this->GetField("_slots")->GetValue<Array<Slot<T>>*>(this);
	}
};