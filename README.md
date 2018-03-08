# sorcery
Card Game written in C++ </br> </br>

To build this program, go to Sorcery directory and run
```
g++ -std=c++14 *.cc -o sorcery.exe
```
Then run ./sorcery.exe [fileName1] [fileName2] [-testing] [-graphics]  

```
fileName1 : deck list of player 1, if not specified, default will be used and shuffled.  

fileName2 : deck list of player 2, if not specified, default will be used and shuffled.  

-testing : testing is for debugging purposes. Deck is not shuffled and you have infinity mana.  

-graphics : for non-terminal graphics output.  
```

This game is single player.  
The goal is to make this a multiplayer game and make it easy for users to add customized cards.  

GamePlay for now:  

<a href="url"><img src="https://github.com/marksim5/sorcery/blob/master/Images/Example.png" align="left" height="300" width="500" ></a>
