#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

typedef struct {
    int id;
    char name[50];
    char town[50];
} Supplier;

extern Supplier suppliers[MAX_SUPPLIERS];
extern int supplierCount;

void manageSuppliers(void);
void saveSuppliersText(void);
void loadSuppliersText(void);

#endif
