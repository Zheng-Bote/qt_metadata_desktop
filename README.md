<div id="top" align="center">
<h1>Metadata Tags Editor</h1>

<p>Desktop app to manage Exif/IPTC/XMP metadata tags</p>

[Report Issue](https://github.com/Zheng-Bote/qt_metadata_desktop/issues) [Request Feature](https://github.com/Zheng-Bote/qt_metadata_desktop/pulls)

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/Zheng-Bote/qt_metadata_desktop?logo=GitHub)](https://github.com/Zheng-Bote/qt_metadata_desktop/releases)

</div>

<hr>

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->

**Table of Contents**

- [Description](#description)
  - [Features](#features)
- [Status](#status)
  - [Documentation](#documentation)
    - [README](#readme)
    - [other Markdown files](#other-markdown-files)
- [Installation](#installation)
  - [Dependencies](#dependencies)
  - [folder structure](#folder-structure)
  - [Usage/Examples/Tests](#usageexamplestests)
- [API Reference](#api-reference)
  - [Inputs](#inputs)
  - [Outputs](#outputs)
  - [Parameters](#parameters)
- [Documentation](#documentation-1)
  - [Architecture](#architecture)
    - [Github](#github)
      - [Github Repo](#github-repo)
      - [Github Actions / Workflows](#github-actions--workflows)
  - [Application](#application)
  - [DevOps](#devops)
  - [Github Page](#github-page)
  - [Github Wiki](#github-wiki)
  - [Comments](#comments)
  - [Screenshots](#screenshots)
- [Authors and License](#authors-and-license)
  - [License](#license)
  - [Authors](#authors)
    - [Code Contributors](#code-contributors)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<hr>

# Description

![QT](https://img.shields.io/badge/Community-6-41CD52?logo=qt)
![CXX](https://img.shields.io/badge/C++-23-blue?logo=cplusplus)
![SQLite3](https://img.shields.io/badge/SQLite3-003B57?logo=sqlite)

Desktop app to manage Exif/IPTC/XMP metadata tags.

Metadata are stored within a SQLite3 database (default: `qt_metadata_desktop.sqlite`)

### Features

- \[ ] advanced-super-extra-special feature xyz

  <br>

- \[x] OSS and license
- \[x] works as designed
- \[ ] no bugs

<br>

- \[x] some more or less usefull Github Actions for GH-repo, GH-pages, GH-wiki, CI/CD-Pipelines
- \[ ] Packagemanager
- \[ ] Installation routine
- \[ ] portable application

<br>

- \[X] runs on DOS/Windows
- \[X] runs on MacOS
- \[X] runs on Linux
- \[ ] runs on iOS
- \[ ] runs on Android
- \[ ] runs on HarmonyOS

<p align="right">(<a href="#top">back to top</a>)</p>

# Status

![GitHub Created At](https://img.shields.io/github/created-at/Zheng-Bote/qt_metadata_desktop)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/Zheng-Bote/qt_metadata_desktop?logo=GitHub)](https://github.com/Zheng-Bote/qt_metadata_desktop/releases)
![GitHub Release Date](https://img.shields.io/github/release-date/Zheng-Bote/qt_metadata_desktop)
![Status](https://img.shields.io/badge/Status-stable-green)

![GitHub Issues](https://img.shields.io/github/issues/Zheng-Bote/qt_metadata_desktop)
![GitHub Pull Requests](https://img.shields.io/github/issues-pr/Zheng-Bote/qt_metadata_desktop)

### Documentation

_see also:_ [Application Documentation](#documentation)

#### README

[![Repo - create Repo-Tree in README.md](https://github.com/Zheng-Bote/qt_metadata_desktop/actions/workflows/repo-create_tree_readme.yml/badge.svg)](https://github.com/Zheng-Bote/qt_metadata_desktop/actions/workflows/repo-create_tree_readme.yml)
[![Repo - add Actions In/Out to README](https://github.com/Zheng-Bote/qt_metadata_desktop/actions/workflows/repo-actions_docu.yml/badge.svg)](https://github.com/Zheng-Bote/qt_metadata_desktop/actions/workflows/repo-actions_docu.yml)

[![Repo - update Readme](https://github.com/Zheng-Bote/qt_metadata_desktop/actions/workflows/repo-call_Readme.yml/badge.svg)](https://github.com/Zheng-Bote/qt_metadata_desktop/actions/workflows/repo-call_Readme.yml)

#### other Markdown files

[![Repo - create TOC of Markdown files](https://github.com/Zheng-Bote/qt_metadata_desktop/actions/workflows/repo-create_doctoc_md.yml/badge.svg)](https://github.com/Zheng-Bote/qt_metadata_desktop/actions/workflows/repo-create_doctoc_md.yml)

create ToC in Markdown files in folders

- .github/actions/\*\*
- .github/workflows/\*\*
- dist/\*\*
- docs/\*\*

<p align="right">(<a href="#top">back to top</a>)</p>

# Installation

```bash
cd src & conan install
```

## Dependencies

### Conan

Conan, software package manager for C and C++ developers

[![Conan](https://img.shields.io/badge/Conan-v2+-6699CB?logo=conan)](https://github.com/conan-io/conan)
[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

### CMake

CMake: A Powerful Software Build System

[![CMake](https://img.shields.io/badge/CMake-v3.23+-064F8C?logo=cmake)](https://github.com/conan-io/conan)
[![BSD-3 License](https://img.shields.io/badge/License-BSD_3-green.svg)](https://choosealicense.com/licenses/bsd-3-clause/)

### QT

> \[!NOTE]
> _QT6 - Community Edition_ >= 6.10

The Qt framework contains a comprehensive set of highly intuitive and modularized C++ library classes and is loaded with APIs to simplify your application development. Qt produces highly readable, easily maintainable and reusable code with high runtime performance and small footprint – and it's cross-platform.

[![QT](https://img.shields.io/badge/Community-for_Open_Source_Development-black?logo=qt)](https://www.qt.io/download-open-source)
[![LGPL](https://img.shields.io/badge/License-LGPL_v3-green.svg)](https://choosealicense.com/licenses/lgpl-3.0/) _see also:_[Obligations of the GPL and LGPL](https://www.qt.io/licensing/open-source-lgpl-obligations)

### SQLite3

SQLite is a C-language library that implements a small, fast, self-contained, high-reliability, full-featured, SQL database engine.

[![SQLite3](https://img.shields.io/badge/SQLite3-003B57?logo=sqlite)](https://sqlite.org/)
[![Public Domain License](https://img.shields.io/badge/License-Public_Domain-green)](https://en.wikipedia.org/wiki/Public_domain)

## folder structure

<!-- readme-tree start -->

```
.
├── .github
│   ├── actions
│   │   └── doctoc
│   │       ├── README.md
│   │       ├── action.yml
│   │       └── dist
│   │           ├── index.js
│   │           ├── index.js.map
│   │           ├── licenses.txt
│   │           └── sourcemap-register.js
│   └── workflows
│       ├── ghp-call_Readme.yml
│       ├── ghp-create_doctoc.yml
│       ├── ghp-markdown_index.yml
│       ├── repo-actions_docu.yml
│       ├── repo-call_Readme.yml
│       ├── repo-create_doctoc.yml_
│       ├── repo-create_doctoc_md.yml
│       └── repo-create_tree_readme.yml
├── .gitignore
├── LICENSE
├── README.md
├── src
│   ├── CMakeLists.txt
│   ├── CMakeLists.txt.user
│   ├── configure
│   │   └── rz_config.h.in
│   ├── includes
│   │   ├── database.cpp
│   │   ├── database.hpp
│   │   ├── rz_config.h
│   │   ├── rz_qt_metatags.cpp
│   │   ├── rz_qt_metatags.hpp
│   │   ├── sqlite3.cpp
│   │   └── sqlite3.hpp
│   ├── main.cpp
│   ├── mainwindow.cpp
│   ├── mainwindow.hpp
│   ├── mainwindow.ui
│   └── res.qrc
└── tree.bak

9 directories, 33 files
```

<!-- readme-tree end -->

<p align="right">(<a href="#top">back to top</a>)</p>

## Usage/Examples/Tests

- on appliaction start, the default database will be loaded. If the db doesn't exists, a new new one will be created.

- default tables and default metadata will be created, if not exist yet.
  <br/><br/>
- click into a cell to edit/modify the content.

- choose from the menu `DB -> save db` or use `<STRG>+<S>` to save the metadata to the db

<p align="right">(<a href="#top">back to top</a>)</p>

# Documentation

## Screenshots

> \[!TIP]
> click into a cell to edit / modify\
> `<STRG>+<S>` to safe into db

![App Screenshot](https://github.com/Zheng-Bote/qt_metadata_desktop/blob/main/docs/img/exif.png)

![App Screenshot](https://github.com/Zheng-Bote/qt_metadata_desktop/blob/main/docs/img/iptc.png)

![App Screenshot](https://github.com/Zheng-Bote/qt_metadata_desktop/blob/main/docs/img/xmp.png)

<p align="right">(<a href="#top">back to top</a>)</p>

# Authors and License

## License

**This qt_metadata_desktop is using the MIT-License**

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

Copyright (c) 2025 ZHENG Robert

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Authors

- [![Zheng Robert](https://img.shields.io/badge/Github-Zheng_Robert-black?logo=github)](https://www.github.com/Zheng-Bote)

### Code Contributors

![Contributors](https://img.shields.io/github/contributors/Zheng-Bote/qt_metadata_desktop?color=dark-green)

[![Zheng Robert](https://img.shields.io/badge/Github-Zheng_Robert-black?logo=github)](https://www.github.com/Zheng-Bote)

<hr>

:vulcan_salute:

<p align="right">(<a href="#top">back to top</a>)</p>
