#include "LogicComponents.h"

/*
 * Created by Stuart Irwin on 4/23/2019.
 * Check for activation in specific sequence
 */

class KeyNode : public LogicReciever, public LogicSender {
private:
	bool activated = false;
public:
	//Mark as activated
	void activate() {
		activated = true;
		send();
	}

	UseAmount is_singleton() {
		return MULTI;
	}

	//Clear value and return
	bool is_activated() {
		if(activated) {
			activated = false;
			return true;
		}
		activated = false;
		return false;
	}
};

class LogicCode : public LogicSender, public LogicReciever {
private:
	KeyNode keys[4];
	int i = 0;

public:
	//Get next key to link to
	LogicReciever *get_key() {
		i--;
		keys[(-i) - 1].add_channel(this);
		return &(keys[(-i) - 1]);
	}

	//Check if proper key activated
	void activate() {
		if(i < 0)
			i = 0;

		//Check current key
		if(keys[i].is_activated()) {
			i++;

			//Check if final key
			if(i == 4) {
				send();
				i = 0;
			}
		} else {
			//Clear other keys
			for(i = 3; i >= 0; i--)
				keys[i].is_activated();
		}
	}

	UseAmount is_singleton() {
		return MULTI;
	}
};