#include "./hash_table_tests.h"

void run_all_tests() {
    test_add_exists();
    test_probing();
    test_get();
    test_remove();
}

void test_add_exists() {
    common::HashTable states(100);

    common::HashObject tx;
    tx.SetKey("Texas");
    tx.SetValue("Austin");

    states.Add(&tx);

    assert(states.Exists("Texas"));
}

void test_probing() {
    common::HashTable states(8);

    common::HashObject tx;
    tx.SetKey("Texas");
    tx.SetValue("Austin");

    common::HashObject ca;
    ca.SetKey("California");
    ca.SetValue("Sacramento");

    common::HashObject nm;
    nm.SetKey("New Mexico");
    nm.SetValue("Santa Fe");

    common::HashObject fl;
    fl.SetKey("Florida");
    fl.SetValue("Tallahassee");

    common::HashObject oregon;
    oregon.SetKey("Oregon");
    oregon.SetValue("Salem");

    states.Add(&tx);
    states.Add(&ca);
    states.Add(&nm);
    states.Add(&fl);
    states.Add(&oregon);


    states.PringDebug();

    assert(states.Exists("California"));
    assert(states.Exists("New Mexico"));
    assert(states.Exists("Florida"));
    assert(states.Exists("Oregon"));
}

void test_get() {
    common::HashTable states(100);

    common::HashObject tx;
    tx.SetKey("Texas");
    tx.SetValue("Austin");

    states.Add(&tx);

    assert(states.Get("Texas") == "Austin");
}

void test_remove() {
    common::HashTable states(3);

    common::HashObject tx;
    tx.SetKey("Texas");
    tx.SetValue("Austin");

    states.Add(&tx);

    assert(states.Exists("Texas"));

    states.Remove("Texas");

    assert(!states.Exists("Texas"));

    states.PringDebug();
}
