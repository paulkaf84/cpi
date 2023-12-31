//
// Created by lux on 8/28/23.
//

#ifndef CPI_UTILS_H
#define CPI_UTILS_H
#include <stdbool.h>
#include <stdlib.h>
#include "../vendor/cli/include/cli.h"


#define PACKAGE_FOLDER "/home/lux/CLionProjects/cpi/package"
#define INCLUDE_FOLDER "include"
#define SRC_FOLDER "src"
#define PACMAN "pacman.cpi"
#define VENDOR "vendor"
#define INSTALL "-i"
#define INSTALL_FULL "--install"
#define UNINSTALL "-u"
#define UNINSTALL_FULL "--uninstall"
#define LIST "-l"
#define LIST_FULL "--list"
#define LIST_ALL "-la"
#define LIST_ALL_FULL "--list_all"
#define HELP "-h"
#define HELP_FULL "--help"


typedef struct Package {
    char name[100];
    struct dependencies{
        struct{
            char c[50][100];
            int size;
        }src;

        struct{
            char h[50][100];
            int size;
        }header;
    } *dependencies;
}Package;


bool generatePacman();

/*
 * Show the help message
 */
void help();

/*
 * Check if a package is a valid package
 * all package have to follow the structure:
 * package
 *     - include
 *     - src
 *
 * @param packageName: the name of the package to check
 * @return true if the package is valid, false otherwise
 */
bool isPackage(char *packageName);

/*
 * Check if a package is installed
 * @param packageName: the name of the package to install
 * @return true if the package is installed, false otherwise
 */
bool isInstalled(char *packageName);

bool addToPacman(Package * package);

bool removeFromPacman(char *packageName);

struct dependencies *hydrateDependencies(char *packageName);

bool install(char * packageName);

bool uninstall(char * packageName);

void list();

/*
 * List all package installed in /home/lux/CLionProjects/cpi/package
 */
void listAll();

void unknown_command(char * command);
void package_not_found(char * package);
void package_not_installed(char * package);
#endif //CPI_UTILS_H
