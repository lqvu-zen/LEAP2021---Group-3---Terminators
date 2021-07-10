#include "Character.h"
#include "Mission.h"
#include "Definitions.h"

USING_NS_CC;

Mission::Mission() {
	std::string str = FileUtils::getInstance()->getStringFromFile("res/mission.json");
	CCLOG("s", str.c_str());
	rapidjson::Document doc;
	doc.Parse<0>(str.c_str());
	if (doc.HasParseError()) {
		CCLOG("ERROR!!");
	}
	else {
		if (doc.HasMember("MISSION")) {
			rapidjson::Value& mission = doc["MISSION"];
			for (rapidjson::SizeType i = 0; i < mission.Size(); i++) {
				//CCLOG("ID: %i, Name: %s, State: %d", mission[i]["ID"].GetInt(), mission[i]["NAME"].GetString(), mission[i]["STATE"].GetBool());
				Data tmp;
				tmp.id = mission[i]["ID"].GetInt();
				tmp.request = mission[i]["REQUEST"].GetString();
				tmp.name = mission[i]["NAME"].GetString();
				tmp.begin = mission[i]["BEGIN"].GetInt();
				tmp.end = mission[i]["END"].GetInt();
				tmp.state = mission[i]["STATE"].GetBool();
				tmp.type = mission[i]["TYPE"].GetInt();
				data.push_back(tmp);
			}
		}
	}
	hasMission = false;
<<<<<<< HEAD
=======

>>>>>>> 9a01d1d9d890fb3cbd5e9bbbd9d7365dcbbdba67
	index = 0;
}

void Mission::updateMission(int type) {
	if (mission.type == type) {
		mission.begin++;
		data.at(index).begin++;
	}
	submitMission();
}

void Mission::cancelMission() {
	mission.state = true;
	data.at(index).state = true;
	hasMission = false;
}

void Mission::agreeMission() {
	hasMission = true;
}

void Mission::submitMission() {
	if (mission.begin == mission.end) {
		mission.state = true;
		data.at(index).state = true;
	}
}
