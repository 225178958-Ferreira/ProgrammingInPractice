// suppliers.h
#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 50

typedef struct {
    int id;
    char name[50];
    char town[50];
} Supplier;

void manageSuppliers(void);

#endif
