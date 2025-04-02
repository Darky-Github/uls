# uls - Ultra List Command

`uls` is a powerful replacement for `ls`, providing additional features like colorized output, file permissions, and hidden file visibility.

## Features

- **Colorized Output**: Different colors for files, directories, and executables.
- **Hidden Files Toggle**: Show or hide hidden files (`uls -a`).
- **File Permissions View**: Display file permissions (`uls -perm`).
- **Sorting Options** (Coming Soon): Sort by name, size, date, or type.
- **Tree View** (Coming Soon): Display directory structure in a tree format.
- **JSON Output Mode** (Coming Soon): Export directory structure as JSON.

## Installation

```sh
git clone https://github.com/Darky-Github/uls.git
cd uls
make
sudo make install
```

## Usage

### List Files in Current Directory
```sh
uls
```

### Show Hidden Files
```sh
uls -a
```

### Show File Permissions
```sh
uls -perm
```

### List Files in a Specific Directory
```sh
uls /path/to/directory
```

## Uninstallation
```sh
sudo make uninstall
```

## License
MIT License
