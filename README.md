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
./nohex [path/to/file] [flags]
```

__Flags__:
* -h (-help) - print help message
* -hz (-hide-zeros) - replace zeros with dots
* -nogui - run terminal version of application __(not implemented yet)__
* -d (-dump) [path/to/file] - dumps to specified file

## Example
Dump of this file:
```
Hello, World!
This is an example of NoHex!
```

```
Dump of "helloworld.txt"
Generated via NoHex (https://github.com/NoWare-Development/nohex)

| Address  | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F |
| -------- | ----------------------------------------------- |
| 00000000 | 48 65 6C 6C 6F 2C 20 57 6F 72 6C 64 21 0A 54 68 |
| 00000010 | 69 73 20 69 73 20 61 6E 20 65 78 61 6D 70 6C 65 |
| 00000020 | 20 6F 66 20 4E 6F 48 65 78 21 0A                |
```

