# encoder
A simple string encoder, written in c++.

# How it works
## Encoding Algorithm (alg function):
User Input:

The program prompts the user to enter a string (str), the encoding mode (1 for encoding, 2 for decoding), the number of algorithm repetitions (algReps), and whether to output to a file and log all repetitions.
Base64 Encoding:

The input string str is encoded using the base64_encode function.
Insertion of Random Character:

If the length of the encoded string is even, a random character between ASCII values 33 ('!') and 126 ('~') is inserted at the middle position.
If the length is odd, the random character is inserted at the beginning.
Character Increment:

Each character in the encoded string is incremented by 1. If a character is originally '~' (ASCII 126), it is wrapped around to '!' (ASCII 33).
Output:

The resulting string is returned.
## Decoding Algorithm (algReverse function):
Character Decrement:

Each character in the input string str is decremented by 1. If a character is originally '!' (ASCII 33), it is wrapped around to '~' (ASCII 126).
Random Character Removal:

If the length of the decoded string is even, the first inserted random character is removed.
If the length is odd, the middle inserted random character is removed.
Base64 Decoding:

The decoded string is then passed through the base64_decode function.
Output:

The resulting decoded string is returned.
Logging and Output:
User Preferences:

The program checks if the user wants to log all repetitions and if the output should be written to a file.
Repetitive Execution:

The algorithm is repeated according to the specified number of repetitions (algReps).
Output to Console/File:

The results of each repetition are either printed to the console or written to an "output.txt" file, based on user preferences.
Final Message:

The program prints "Done!" when all repetitions are complete.
Additional Notes:
The program uses Windows-specific functions for setting the console code page.
The random character generation function (getRandom) is not provided, but it is assumed to generate a random integer between the specified minimum and maximum values.
