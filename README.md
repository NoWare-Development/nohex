# NoHex
__NoHex__ - simple HEX dumper

## Manual build
``` sh
git clone https://github.com/NoWare-Development/nohex.git
cd nohex/build
cmake --build .
```

`nohex` executable file will appear in `build/` folder

## Usage
``` sh
./nohex [file] [flags]
```

__Flags__:
* -h (-help) - print help message
* -hz (-hide-zeros) - replace zeros with dots
* -nogui - run terminal version of application __(not implemented yet)__
* -d (-dump) [file] - dumps to specified file
