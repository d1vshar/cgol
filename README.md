# cgol - A Conway's Game of Life simulator - WIP

cgol is a simulator written in C using raylib graphics library. 

### Conway's Game of Life

https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

There are hundred of videos on youtube showing different algorithms and patterns.

### Building

Create a `config.txt` file in the root folder for initial grid config.

syntax: `x,y` on each line
```
1,10
2,4
2,6
```

Open your the project root in terminal and type in

```
make && ./build/cgol
```

You can use the debug target too

```
make debug && ./debug_build/cgol
```

## Contribution

You can start a pull request directly to master branch as this project is still no where near completion.

If you want some features to implement, feel free to ask for it in an Issue. 