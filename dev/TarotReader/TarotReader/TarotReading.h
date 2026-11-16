#pragma once
#include <string>
#include <vector>

#include "ReadingRecord.h"
#include "TarotDeck.h"
class TarotReading
{
public:
	TarotReading(TarotDeck& deck);

	void OneCardReading();
	void ThreeCardReading();
	void DisplayHistory() const;

	void SaveHistory(const std::string& fileName) const;
	void LoadHistory(const std::string& fileName);
private:
	TarotDeck& readingDeck;
	std::vector<ReadingRecord> history;

	bool DetermineOrientation() const;
	std::string GetOrientationText(bool isReversed) const;
	std::string GetCurrentDate() const;

	void DisplayThreeCardSpread(const TarotCard& past, bool pastReversed, const TarotCard& present, bool presentReversed, const TarotCard& future, bool futureReversed) const;
	void DisplayMeaning(const std::string& position, const TarotCard& card, bool isReversed) const;
};

