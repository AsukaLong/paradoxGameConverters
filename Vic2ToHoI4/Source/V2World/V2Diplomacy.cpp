/*Copyright (c) 2016 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/



#include "V2Diplomacy.h"
#include "Log.h"



V2Agreement::V2Agreement(Object *obj)
{
	type = obj->getKey();

	std::vector<Object*> objFirst = obj->getValue(L"first");
	if (objFirst.size() > 0)
	{
		country1 = objFirst[0]->getLeaf();
	}
	else
	{
		LOG(LogLevel::Warning) << "Diplomatic agreement (L" << type << ") has no first party";
	}

	std::vector<Object*> objSecond = obj->getValue(L"second");
	if (objSecond.size() > 0)
	{
		country2 = objSecond[0]->getLeaf();
	}
	else
	{
		LOG(LogLevel::Warning) << "Diplomatic agreement (L" << type << ") has no second party";
	}

	std::vector<Object*> objDate = obj->getValue(L"start_date");
	if (objDate.size() > 0)
	{
		start_date = date(objDate[0]->getLeaf());
	}
}


V2Diplomacy::V2Diplomacy(Object *obj)
{
	std::vector<Object*> objVassals = obj->getValue(L"vassal");
	for (auto itr: objVassals)
	{
		V2Agreement agr(itr);
		agreements.push_back(agr);
	}

	std::vector<Object*> objAlliances = obj->getValue(L"alliance");
	for (auto itr: objAlliances)
	{
		V2Agreement agr(itr);
		agreements.push_back(agr);
	}

	std::vector<Object*> objCBs = obj->getValue(L"causus_belli");
	for (auto itr: objCBs)
	{
		V2Agreement agr(itr);
		agreements.push_back(agr);
	}

	std::vector<Object*> objSubsidies = obj->getValue(L"warsubsidy");
	for (auto itr: objSubsidies)
	{
		V2Agreement agr(itr);
		agreements.push_back(agr);
	}
}