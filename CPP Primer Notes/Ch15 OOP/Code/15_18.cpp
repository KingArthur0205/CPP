class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base {
    int getProtMem() { return prot_mem; }

    void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
    int getProtMem() const { return prot_mem; }

    void memfcn(Base &b) { b = *this; }

};

struct Derived_from_Public : public Pub_Derv {
    int use_base() { return prot_mem; }
};

struct Derived_from_Priv : private Priv_Derv {
        void memfcn(Base &b) { b = *this; }

};
