#include <iostream>
#include <string>
#include <vector>


void removeCopies(std::vector<int>& data)
{
    // This makes sure it stops if the vector has no values.
    if (data.size() == 0)
    {
        return;
    }

    // This will stores where the next unique value should be going.
    int uniquePosition = 1;

    // Checks each value in the sorted vector.
    for (int currentPosition = 1; currentPosition < data.size(); currentPosition++)
    {
        // Only move values different from the previous value.
        if (data[currentPosition] != data[currentPosition - 1])
        {
            data[uniquePosition] = data[currentPosition];
            uniquePosition++;
        }
    }

    // Removes the leftover duplicate values at the end.
    data.resize(uniquePosition);
}

void isAnagram(std::string officer_name, std::string spy_name)
{
    // Different lengths means they cannot be anagrams.
    if (officer_name.length() != spy_name.length())
    {
        std::cout << "IMPOSTER! IMPOSTER!" << std::endl;
        return;
    }

    // Each index represents a lowercase letter from a to z.
    std::vector<int> letterCounts(26, 0);

    // Add officer letters and subtract spy letters.
    for (int i = 0; i < officer_name.length(); i++)
    {
        letterCounts[officer_name[i] - 'a']++;
        letterCounts[spy_name[i] - 'a']--;
    }

    // Any nonzero value means the names use different letters.
    for (int i = 0; i < 26; i++)
    {
        if (letterCounts[i] != 0)
        {
            std::cout << "IMPOSTER! IMPOSTER!" << std::endl;
            return;
        }
    }
    std::cout << "No imposter detected!" << std::endl;
}

int main()
{
    std::vector<int> server = {1, 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 6};

    // Prints the original server logs
    for (auto data : server)
    {
        std::cout << data << " ";
    }
    std::cout << std::endl;

    removeCopies(server);

    // Prints the cleaned server log
    for (auto data : server)
    {
        std::cout << data << " ";
    }
    std::cout << std::endl;

    isAnagram("syeda", "aysed");
    isAnagram("angelo", "annabeth");

    return 0;
}
