#include "TarotReading.h"
#include "ConsoleColor.h"
#include "Input.h"
#include "TarotConstants.h"

#include <ctime>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

TarotReading::TarotReading(TarotDeck& deck) : readingDeck(deck) {}

bool TarotReading::DetermineOrientation() const
{
	int randomValue = std::rand() % 2;
	if (randomValue == 0)
	{
		return true;
	}
	return false;
}
std::string TarotReading::GetOrientationText(bool isReversed) const
{
	if (isReversed)
	{
		return "REVERSED";
	}
	return "UPRIGHT";
}
void TarotReading::OneCardReading()
{
	ConsoleColor::Print("\n========================================\n", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("            ONE-CARD READING", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("\n========================================\n", ConsoleColor::Ink::Purple);
	
	std::cout << "Take a moment to consider your question.\n\n";
	std::string question = Input::GetString("Enter your question or intention:\n");
	ConsoleColor::Print("The cards are shuffling...\n", ConsoleColor::Ink::Purple);

	const TarotCard& card = readingDeck.DrawCard();
	bool isReversed = DetermineOrientation();

	ConsoleColor::Print("\nYour card is...\n", ConsoleColor::Ink::Cyan);
	ConsoleColor::Print(card.GetAsciiArt(), ConsoleColor::Ink::Purple);
	std::cout << "\n";
	card.DisplayReading(isReversed);
	ConsoleColor::Print("\nYour question:\n", ConsoleColor::Ink::Yellow);
	std::cout << question << "\n";
	ReadingRecord record("ONE-CARD READING", question, GetCurrentDate());
	record.AddCard("", card.GetName(), isReversed);
	history.push_back(record);
	SaveHistory("data/reading_history.txt");
}

void TarotReading::ThreeCardReading()
{
	ConsoleColor::Print("\n========================================\n", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("       PAST - PRESENT - FUTURE\n", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("========================================\n\n", ConsoleColor::Ink::Purple);

	std::cout << "Think about the situation you would like the cards to explore.\n\n";
	std::string question = Input::GetString("Enter your question or intention:\n");
	ConsoleColor::Print("The cards are shuffling...\n", ConsoleColor::Ink::Purple);

	std::vector<int> selectedCards = readingDeck.DrawUniqueCards(3);

	const TarotCard& past = readingDeck.GetCard(selectedCards[0]);
	const TarotCard& present = readingDeck.GetCard(selectedCards[1]);
	const TarotCard& future = readingDeck.GetCard(selectedCards[2]);

	bool pastReversed = DetermineOrientation();
	bool presentReversed = DetermineOrientation();
	bool futureReversed = DetermineOrientation();

	DisplayThreeCardSpread(past, pastReversed, present, presentReversed, future, futureReversed);

	DisplayMeaning("PAST", past, pastReversed);
	DisplayMeaning("PRESENT", present, presentReversed);
	DisplayMeaning("FUTURE", future, futureReversed);
	ConsoleColor::Print("\n========================================\n", ConsoleColor::Ink::Purple);

	ConsoleColor::Print("Your question:\n", ConsoleColor::Ink::Yellow);
	std::cout << question << "\n";

	ReadingRecord record("PAST - PRESENT - FUTURE", question, GetCurrentDate());
	record.AddCard("PAST", past.GetName(), pastReversed);
	record.AddCard("PRESENT", present.GetName(), presentReversed);
	record.AddCard("FUTURE", future.GetName(), futureReversed);
	history.push_back(record);
	SaveHistory("data/reading_history.txt");
}

void TarotReading::DisplayMeaning(const std::string& position, const TarotCard& card, bool isReversed) const
{
	ConsoleColor::Print("\n----------------------------------------\n", ConsoleColor::Ink::Purple);

	ConsoleColor::Print(position + " - " + card.GetName() + "\n", ConsoleColor::Ink::Yellow);

	if (isReversed)
	{
		ConsoleColor::Print("REVERSED\n", ConsoleColor::Ink::Red);
	}
	else
	{
		ConsoleColor::Print("UPRIGHT\n", ConsoleColor::Ink::Green);
	}
	ConsoleColor::Print("Keywords: ", ConsoleColor::Ink::Cyan);
	std::cout << card.GetKeywords() << "\n\n";
	ConsoleColor::Print("Meaning: ", ConsoleColor::Ink::Cyan);
	if (isReversed)
	{
		std::cout << card.GetReversedMeaning() << "\n";
	}
	else
	{
		std::cout << card.GetUprightMeaning() << "\n";
	}
}

void TarotReading::DisplayThreeCardSpread(const TarotCard& past, bool pastReversed, const TarotCard& present, bool presentReversed, const TarotCard& future, bool futureReversed) const
{
	std::vector<std::string> pastArt = past.GetAsciiLines();
	std::vector<std::string> presentArt = present.GetAsciiLines();
	std::vector<std::string> futureArt = future.GetAsciiLines();
	

	const int columnWidth = 30;

	ConsoleColor::Print("\n==========================================================================================\n", ConsoleColor::Ink::Purple);
	std::cout
		<< std::setw(columnWidth)
		<< std::left
		<< "          PAST"

		<< std::setw(columnWidth)
		<< "        PRESENT"

		<< std::setw(columnWidth)
		<< "         FUTURE"

		<< "\n";
	ConsoleColor::Print("\n==========================================================================================\n", ConsoleColor::Ink::Purple);
	for (int i = 0; i < static_cast<int>(pastArt.size()); i++)
	{
		std::cout
			<< std::setw(columnWidth)
			<< std::left
			<< pastArt[i]

			<< std::setw(columnWidth)
			<< presentArt[i]

			<< std::setw(columnWidth)
			<< futureArt[i]
			<< "\n";
	}
	std::cout << "\n";
	std::string pastOrientation = "UPRIGHT";
	if (pastReversed) pastOrientation = "REVERSED";

	std::string presentOrientation = "UPRIGHT";
	if (presentReversed) presentOrientation = "REVERSED";

	std::string futureOrientation = "UPRIGHT";
	if (futureReversed) futureOrientation = "REVERSED";

	std::cout
		<< std::setw(columnWidth)
		<< std::left
		<< pastOrientation

		<< std::setw(columnWidth)
		<< presentOrientation

		<< std::setw(columnWidth)
		<< futureOrientation
		<< "\n";
}

void TarotReading::DisplayHistory() const
{
	ConsoleColor::Print("\n========================================\n", ConsoleColor::Ink::Purple);

	ConsoleColor::Print("             READING HISTORY\n", ConsoleColor::Ink::Purple);
	
	ConsoleColor::Print("\n========================================\n", ConsoleColor::Ink::Purple);

	if (history.empty())
	{
		ConsoleColor::Print("\nThe cards have no stories to remember yet...\n", ConsoleColor::Ink::Cyan);
		return;
	}
	for (std::size_t i = 0; i < history.size(); i++)
	{
		std::cout << "\n";
		ConsoleColor::Print("Reading " + std::to_string(i + 1) + "\n", ConsoleColor::Ink::Yellow);
		history[i].Display();
		std::cout << "\n";
	}
}
std::string TarotReading::GetCurrentDate() const
{
	std::time_t currentTime =
		std::time(nullptr);

	std::tm localTime{};

	localtime_s(
		&localTime,
		&currentTime
	);

	std::ostringstream date;

	date
		<< std::setfill('0')
		<< std::setw(2)
		<< localTime.tm_mon + 1
		<< "/"
		<< std::setw(2)
		<< localTime.tm_mday
		<< "/"
		<< localTime.tm_year + 1900;

	return date.str();
}


void TarotReading::SaveHistory(const std::string& fileName) const
{
	std::ofstream outputFile(fileName);
	if (!outputFile.is_open())
	{
		ConsoleColor::Print("\nThe reading history could not be saved.\n", ConsoleColor::Ink::Red);
		return;
	}
	for (const ReadingRecord& record : history)
	{
		outputFile << "READING\n";
		outputFile << record.GetReadingType() << "\n";
		outputFile << record.GetDate() << "\n";
		outputFile << record.GetQuestion() << "\n";
		outputFile << record.GetCardCount() << "\n";
		for (int i = 0; i < record.GetCardCount(); i++)
		{
			outputFile
				<< record.GetPosition(i)
				<< "|"
				<< record.GetCardName(i)
				<< "|"
				<< record.GetReversedState(i)
				<< "\n";
		}
		outputFile << "END\n";
	}
	outputFile.close();
}
void TarotReading::LoadHistory(const std::string& fileName) 
{
	std::ifstream inputFile(fileName);

	if (!inputFile.is_open())
	{
		return;
	}
	history.clear();
	std::string line;

	while (std::getline(inputFile, line))
	{
		if (line != "READING")
		{
			continue;
		}
		std::string readingType;
		std::string date;
		std::string question;
		std::string cardCountText;

		if (!std::getline(inputFile,readingType) ||!std::getline(inputFile,date) ||!std::getline(inputFile,question) ||!std::getline(inputFile,cardCountText))
		{
			break;
		}
		int cardCount = 0;
		try
		{
			cardCount = std::stoi(cardCountText);
		}
		catch (...)
		{
			continue;
		}
		ReadingRecord record(readingType, question, date);
		bool validRecord = true;
		for (int i = 0; i < cardCount; i++)
		{
			std::string cardLine;
			if (!std::getline(inputFile, cardLine))
			{
				validRecord = false;
				break;
			}
			std::stringstream stream(cardLine);
			std::string position;
			std::string cardName;
			std::string reversedText;
			if (!std::getline(stream, position, '|') || !std::getline(stream, cardName, '|') || !std::getline(stream, reversedText, '|'))
			{
				validRecord = false;
				break;
			}
			bool isReversed = reversedText == "1";
			record.AddCard(position, cardName, isReversed);
		}
		std::string endMarker;
		if (!std::getline(inputFile, endMarker))
		{
			break;
		}

		if (validRecord && endMarker == "END")
		{
			history.push_back(record);
		}
	}
	inputFile.close();
}