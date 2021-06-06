# Connect4Bot
Scans board for potential 4 in rows and blocks them. For codingame.com

This code can be used in the connect 4 game at https://www.codingame.com/multiplayer/bot-programming/connect-4.
It accepts a 9x7 connect 4 board as a string input in the format as follows:
```
"........."
"........."
"........."
"........."
"........."
"...10...."
"...011..."
```
where 0 represents player who went first and 1 represents 2nd player.

The bot attempts to scan horizontally, vertically, and in diagnols for potential 4 in a rows to either block the opponent or take the next optimal move.

