#ifndef EU3WORLD_H_
#define EU3WORLD_H_


#include <fstream>
#include "..\Mappers.h"
#include "..\Date.h"



class CK2Province;
class CK2World;
class EU3Country;
class EU3Province;
class EU3Advisor;
class EU3Tech;
class EU3Diplomacy;



enum options
{
	ADVISORS	= 0,
	LEADERS,
	COLONISTS,
	MERCHANTS,
	MISSIONARIES,
	INFLATION,
	COLONIST_SIZE,
	DIFFICULTY,
	AI_AGGRESSIVENESS,
	LAND_SPREAD,
	SEA_SPREAD,
	SPIES,
	LUCKY_NATIONS,
	OPTIONS_END
};



class EU3World
{
	public:
		EU3World(CK2World*, EU3Tech*);

		void	output(FILE*);
		
		void	addHistoricalCountries();
		void	setupProvinces(provinceMapping& provinceMap);

		void	convertCountries(map<string, CK2Title*> CK2Titles, const religionMapping& religionMap, const cultureMapping& cultureMap, const provinceMapping provinceMap);
		void	convertProvinces(provinceMapping&, map<int, CK2Province*>&, cultureMapping& cultureMap, religionMapping& religionMap, continentMapping& continentMap, adjacencyMapping& adjacencyMap, const tradeGoodMapping& tradeGoodMap, const religionGroupMapping& EU3ReligionGroup);
		void	addAcceptedCultures();
		void	convertAdvisors(inverseProvinceMapping&, provinceMapping&, CK2World&);
		void	convertTech(const religionGroupMapping& religionGroupMap, const CK2World& srcWorld);
		void	convertGovernments(const religionGroupMapping& religionGroupMap);
		void	convertEconomies(const cultureGroupMapping& cultureGroups, const tradeGoodMapping& tradeGoodMap);	
		int	assignTags(Object* rulesObj, vector<string>& blockedNations, const provinceMapping& provinceMap);

		void	setJapaneseEmperor(EU3Country* emperor)	{ japaneseEmperor = emperor; };
		void	addDamiyo(EU3Country* daimyo)					{ daimyos.push_back(daimyo); };
		void	setShogun(EU3Country* _shogun)				{ shogun = _shogun; };
		void	setShogunPower(double power)					{ shogunPower = power; };
		
		map<string, EU3Country*>	getCountries() const { return countries; };
	private:
		int									options[OPTIONS_END];
		date									startDate;
		EU3Tech*								techData;

		map<int, EU3Province*>			provinces;
		map<string, EU3Country*>		countries;
		vector<EU3Country*>				convertedCountries;
		vector<EU3Advisor*>				advisors;
		map< string, vector<string> >	mapSpreadStrings;
		EU3Diplomacy*						diplomacy;

		EU3Country*				japaneseEmperor;
		vector<EU3Country*>	daimyos;
		EU3Country*				shogun;
		double					shogunPower;
};



#endif	// EU3WORLD_H_