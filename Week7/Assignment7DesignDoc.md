# Assignment7DesignDoc.md

## Program Name
Assignment7

## Purpose

This program will ask the user for a file and then ask for the search word and then ask for what they will be replacing the search
word with. The program will then look for the search word and then replaces it with the word the user wants to replace it with. It
will then save the changes insinde output.txt and then the program will also display the total amount of time the word was replaced.

---

## Inputs

* The input file name
* The word to search for
* The replacement word

---

## Outputs

* An error message if the input file does not open
* A new file named output.txt with the changes made
* The total number of words that were replaced

---

## Variables

|    Variable    |      Type       |               Purpose                  |
| -------------- | --------------- | -------------------------------------- |
|  file          |  std::string    | Stores the input file name             |
|  searchWord    |  std::string    | Stores the word the user wants to find |
|  currentWord   |  std::string    | Stores each word read from the file    |
|  replacedWord  |  std::string    | Stores the new replacement word        |
|  count         |  int            | Stores how many words were replaced    |
|  inputFile     |  std::ifstream  | Opens and reads the input file         |
|  outputFile    |  std::ofstream  | Creates and writes to output.txt       |

---

## Key Design Choices

I used std::ifstream because the program needs to open and read from a file.

I used std::ofstream because the program needs to create and write to a new file.

I used a while loop because the program must keep reading every word until the file ends.

I used an if-else statement because the program needs to check if the current word matches the search word.

I used another if-else statement to check if the input file was opened or else it will end the program.

I used a counter because the program needs to keep track of how many words were replaced.


---

## Program Steps (Algorithm)

1. Make the needed string and integer variables.
2. Ask the user for the input file name.
3. Ask the user for the word to search for.
4. Ask the user for the replacement word.
5. Open the input file.
6. Check if the input file opened correctly.
7. Create the `output.txt` file.
8. Read one word at a time from the input file.
9. Check if the current word matches the search word.
10. Replace matching words with the new word.
11. Write all words into the output file.
12. Increase the counter when a word is replaced.
13. Close both files.
14. Display how many words were replaced.


---

## Sample Input/Output

Input:
Enter the input file name: CatStory.txt
Enter the word to search for: owner
Enter the replacement word: hero

Output:
The word owner was replaced 3 times.

Inside output.txt:
The Lost Cat Mittens wandered too far from home. He finally found his way back and scratched at the front door. 
His hero walked right past him without looking. Mittens meowed as loudly as he could, but no one answered. Then 
he noticed a photo of himself with flowers beside it. That's when Mittens realized he hadn't been lost at all, 
he had passed away, and his hero couldn't see him anymore. Then he heard his hero calling for him. It was from 
behind. Turns out he was at the wrong house. He turned around and ran home to his owner.
