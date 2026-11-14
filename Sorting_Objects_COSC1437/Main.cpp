#define NOMINMAX            // stops windows.h from breaking std::min / std::max
#include <windows.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>

#include "Item.h"
#include "RandomXorShift.h"

int getConsoleBufferWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return csbi.dwSize.X;
    }
    return 0;
}

namespace
{
    constexpr size_t BOX_INNER_WIDTH = 28;
    constexpr size_t BOX_WIDTH = BOX_INNER_WIDTH + 4;  // "| " + text + " |"
    constexpr size_t BOX_GAP = 1;                    // spaces between boxes

    // Splits text on spaces into lines no longer than `width`
    std::vector<std::string> wrapText(const std::string& text, size_t width)
    {
        std::vector<std::string> lines;
        std::istringstream words(text);
        std::string word, current;

        while (words >> word)
        {
            if (!current.empty() && current.size() + 1 + word.size() > width)
            {
                lines.push_back(current);
                current.clear();
            }
            if (!current.empty()) current += ' ';
            current += word;
        }
        if (!current.empty()) lines.push_back(current);
        return lines;
    }

    // The text lines that go inside one item's box
    std::vector<std::string> itemLines(const Item& item)
    {
        std::vector<std::string> lines = wrapText(item.getName(), BOX_INNER_WIDTH);
        lines.push_back("");
        lines.push_back("Atk:   " + std::to_string(item.getAtk()));
        lines.push_back("Dmg:   " + std::to_string(item.getDmg()));
        lines.push_back("Def:   " + std::to_string(item.getDef()));
        if (item.getSpec() != 0)
            lines.push_back("Spec:  " + std::to_string(item.getSpec()));
        lines.push_back("Price: " + std::to_string(item.getPrice()));
        return lines;
    }

    std::string padRight(const std::string& s, size_t width)
    {
        return s + std::string(width > s.size() ? width - s.size() : 0, ' ');
    }
}

void printItems(const std::vector<Item*>& items)
{
    // Leave the last column free so the console doesn't wrap early
    const int width = getConsoleBufferWidth();
    const size_t usable = width > 1 ? static_cast<size_t>(width) - 1 : 80;

    // As many boxes as fit in one row (always at least one)
    const size_t perRow = std::max<size_t>(1, (usable + BOX_GAP) / (BOX_WIDTH + BOX_GAP));

    const std::string border = "+" + std::string(BOX_INNER_WIDTH + 2, '-') + "+";
    const std::string gap(BOX_GAP, ' ');

    for (size_t start = 0; start < items.size(); start += perRow)
    {
        const size_t end = std::min(start + perRow, items.size());
        const size_t count = end - start;

        // Center this row based on how many boxes it actually has
        const size_t rowWidth = count * BOX_WIDTH + (count - 1) * BOX_GAP;
        const size_t margin = usable > rowWidth ? (usable - rowWidth) / 2 : 0;
        const std::string pad(margin, ' ');

        std::vector<std::vector<std::string>> boxes;
        size_t height = 0;
        for (size_t i = start; i < end; ++i)
        {
            boxes.push_back(itemLines(*items[i]));
            height = std::max(height, boxes.back().size());
        }

        // Top borders
        std::cout << pad;
        for (size_t b = 0; b < boxes.size(); ++b)
            std::cout << (b ? gap : "") << border;
        std::cout << '\n';

        // Content lines
        for (size_t line = 0; line < height; ++line)
        {
            std::cout << pad;
            for (size_t b = 0; b < boxes.size(); ++b)
            {
                const std::string& text = line < boxes[b].size() ? boxes[b][line] : "";
                std::cout << (b ? gap : "") << "| " << padRight(text, BOX_INNER_WIDTH) << " |";
            }
            std::cout << '\n';
        }

        // Bottom borders
        std::cout << pad;
        for (size_t b = 0; b < boxes.size(); ++b)
            std::cout << (b ? gap : "") << border;
        std::cout << "\n\n";
    }
}

void printMenu(std::string name, std::vector<std::string> items, int collumns = 1)
{
    const int width = getConsoleBufferWidth();
    const size_t total = width > 0 ? static_cast<size_t>(width) : 80;
    const std::string line(total, '=');

    // Returns the left padding that centers something `w` characters wide
    auto indent = [&](size_t w) {
        return std::string(total > w ? (total - w) / 2 : 0, ' ');
        };

    // Number each entry: "1. Start Game"
    std::vector<std::string> labels;
    size_t labelWidth = 0;
    for (size_t i = 0; i < items.size(); ++i)
    {
        labels.push_back(std::to_string(i + 1) + ". " + items[i]);
        labelWidth = std::max(labelWidth, labels.back().size());
    }

    // Never use more columns than there are items (and always at least one)
    size_t cols = static_cast<size_t>(std::max(1, collumns));
    if (!labels.empty()) cols = std::min(cols, labels.size());

    constexpr size_t COLUMN_GAP = 4;
    const size_t blockWidth = cols * labelWidth + (cols - 1) * COLUMN_GAP;
    const std::string blockIndent = indent(blockWidth);

    // Top line + title
    std::cout << line << '\n';
    std::cout << indent(name.size()) << name << "\n\n";

    // Items, filled left to right, top to bottom; the block is centered as a whole
    for (size_t i = 0; i < labels.size(); i += cols)
    {
        std::cout << blockIndent;
        for (size_t c = 0; c < cols && i + c < labels.size(); ++c)
        {
            const std::string& label = labels[i + c];
            std::cout << label;

            // Pad every column except the last one in the row
            if (c + 1 < cols && i + c + 1 < labels.size())
                std::cout << std::string(labelWidth - label.size() + COLUMN_GAP, ' ');
        }
        std::cout << '\n';
    }

    // Bottom line
    std::cout << '\n' << line << '\n';
}

std::vector<Item*> itemList;
const std::vector<std::string> menuOptions = {"Name A-Z", "Name Z-A", "Atk Max-Min", "Atk Min-Max", "Def Max-Min", "Def Min-Max", "Dmg Max-Min", "Dmg Min-Max", "Price Max-Min", "Price Min-Max", "Type"};

bool running = true;

void filterByName(std::vector<Item*>& list, bool Decending = false);
void filterByType(std::vector<Item*>& list);
void filterByStat(std::vector<Item*>& list, int stat = 1, bool Decending = false);
void filterByPrice(std::vector<Item*>& list, bool Decending = false);

int main()
{
    RandomXorShift rng;

    for (int i = 0; i < 12; i++)
    {
        Item* itemPtr = new Item(rng);
        itemList.push_back(itemPtr);
    }

    int menuChoice = 1;

    while (running)
    {
        printMenu("Filter Items By", menuOptions, 2);
        printItems(itemList);

        std::string prompt = "Enter your desired filter (1-9: 0 to exit): ";
        prompt = std::string((getConsoleBufferWidth()/2)-(prompt.size()/2), ' ') + prompt;
        
        std::string currentFilter = "Current filter is: " + menuOptions[menuChoice - 1];
        currentFilter = std::string((getConsoleBufferWidth() / 2) - (currentFilter.size() / 2), ' ') + currentFilter;

        std::cout << std::string(getConsoleBufferWidth(), '=') << "\n\n" << currentFilter << '\n' << prompt;

        std::cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            filterByName(itemList);
            break;
        case 2:
            filterByName(itemList, true);
            break;
        case 3:
            filterByStat(itemList, 1);
            break;
        case 4:
            filterByStat(itemList, 1, true);
            break;
        case 5:
            filterByStat(itemList, 2);
            break;
        case 6:
            filterByStat(itemList, 2, true);
            break;
        case 7:
            filterByStat(itemList, 3);
            break;
        case 8:
            filterByStat(itemList, 3, true);
            break;
        case 9:
            filterByPrice(itemList);
            break;
        case 10:
            filterByPrice(itemList, true);
            break;
        case 11:
            filterByType(itemList);
            break;
        default:
            running = false;
            break;
        }

        system("cls");
    }

    for (Item* item : itemList)
    {
        delete item;
    }

    return 0;
}


//==========================================================================================================
//                                    START HERE FOR ASSIGNMENT CODE
//==========================================================================================================
void filterByName(std::vector<Item*>& list, bool Decending)
{
    std::sort(list.begin(), list.end(), [](Item* a, Item* b) {return a->getName()[0] < b->getName()[0]; });
    if (Decending) std::reverse(list.begin(), list.end());
}

void filterByType(std::vector<Item*>&list)
{
    std::sort(list.begin(), list.end(), [](Item* a, Item* b) { return a->getType() > b->getType(); });
}

void filterByStat(std::vector<Item*>&list, int stat, bool Decending)
{
    switch(stat)
    {
    case 1:
        std::sort(list.begin(), list.end(), [](Item* a, Item* b) {return a->getAtk() > b->getAtk(); });
        break;
    case 2:
        std::sort(list.begin(), list.end(), [](Item* a, Item* b) {return a->getDef() > b->getDef(); });
        break;
    case 3:
        std::sort(list.begin(), list.end(), [](Item* a, Item* b) {return a->getDmg() > b->getDmg(); });
        break;
    default:
        return;
    }

    if (Decending) std::reverse(list.begin(), list.end());
}

void filterByPrice(std::vector<Item*>& list, bool Decending)
{
    std::sort(list.begin(), list.end(), [](Item* a, Item* b) {return a->getPrice() > b->getPrice(); });
    if (Decending) std::reverse(list.begin(), list.end());
}

//==========================================================================================================
//  Wow thats not a lot of code. Have I over done it once again?
//  I don't know, I feel like my design is scalable. You can add a new filter with a simple function
//  and adding it to the menu vector. I like it.
//  To bad you're never going to run it.
//==========================================================================================================