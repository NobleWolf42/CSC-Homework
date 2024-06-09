/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "Customers.h"
#include <string>

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void setUp() {
        contact1 = Contact("John Doe", "456 AAAAAAA St.", "jdoe@gmail.com");
        contact2 = Contact("Jane Smith", "123 Wheee Ave.", "jsmioth@gmail.com");

        charge1 = Charge("Hello World Inc.", 100.0);
        charge2 = Charge("World Inc.", 200.0);
        charge3 = Charge("Inc.", 300.0);
        charge4 = Charge("H Inc.", 400.0);

        list1.push_back(charge3);
        list2.push_back(charge4);

        customer1 = new Customer("123", contact1, 500.0, list1);
        customer2 = new Customer("456", contact2, 1000.0, list2);

        customer1->push_back(charge1);
        customer2->push_back(charge2);

        customers.insert(*customer1);
        customers.insert(*customer2);
    }

    void tearDown() {
        delete customer1;
        delete customer2;
        customer1 = NULL;
        customer2 = NULL;
        customers = Customers<Customer>();
        list1.pop_back();
        list2.pop_back();
    }

    // Test cases
    void testFindCustomer() {
        const Customer* foundCustomer = customers.find("123");
        TS_ASSERT(foundCustomer != nullptr);
        TS_ASSERT_EQUALS(foundCustomer->GetContact().getName(), "John Doe");
    }

    void testInsertCustomer() {
        Customer newCustomer("789", contact1, 1500.0, list3);
        bool inserted = customers.insert(newCustomer);
        TS_ASSERT(inserted);
        const Customer* foundCustomer = customers.find("789");
        TS_ASSERT(foundCustomer != nullptr);
        TS_ASSERT_EQUALS(foundCustomer->GetContact().getName(), "John Doe");
        Customer newCustomer2("789", contact1, 1500.0, list3);
        bool inserted2 = customers.insert(newCustomer2);
        TS_ASSERT(!inserted2);
    }

    void testEraseCustomer() {
        bool erased = customers.erase(Customer("123", contact1, 500.0, list1));
        TS_ASSERT(erased);

        const Customer* foundCustomer = customers.find("123");
        TS_ASSERT(foundCustomer == nullptr);

        customers.insert(*customer1);

        Customer newCustomer("012", contact1, 1500.0, list3);
        bool inserted = customers.insert(newCustomer);
        TS_ASSERT(inserted);

        bool erased2 = customers.erase(Customer("012", contact1, 1500.0, list3));
        TS_ASSERT(erased2);

        Customer newCustomer2("789", contact1, 1500.0, list3);
        bool inserted2 = customers.insert(newCustomer2);
        TS_ASSERT(inserted2);

        bool erased3 = customers.erase(Customer("456", contact2, 1000.0, list2));
        TS_ASSERT(erased3);

        Customer newCustomer3("012", contact1, 1500.0, list3);
        bool inserted3 = customers.insert(newCustomer3);
        TS_ASSERT(inserted3);

        Customer newCustomer4("001", contact1, 1500.0, list3);
        bool inserted4 = customers.insert(newCustomer4);
        TS_ASSERT(inserted4);

        Customer newCustomer5("015", contact1, 1500.0, list3);
        bool inserted5 = customers.insert(newCustomer5);
        TS_ASSERT(inserted5);

        bool erased4 = customers.erase(Customer("001", contact1, 1500.0, list3));
        TS_ASSERT(erased4);

        bool inserted6 = customers.insert(newCustomer4);
        TS_ASSERT(inserted6);

        bool erased5 = customers.erase(Customer("015", contact1, 1500.0, list3));
        TS_ASSERT(erased5);

    }

    void testAnyOverLimit() {
        bool overLimit = customers.any_over_limit();
        TS_ASSERT(!overLimit);

        Customer newCustomer("789", contact1, 500.0, list3);
        newCustomer.push_back(Charge("O Inc.", 900.0));
        bool inserted = customers.insert(newCustomer);
        overLimit = customers.any_over_limit();
        TS_ASSERT(overLimit);
    }

    void testCountBigLimits() {
        int count = customers.count_big_limits(600.0);
        TS_ASSERT_EQUALS(count, 1);

        count = customers.count_big_limits(200.0);
        TS_ASSERT_EQUALS(count, 2);

        count = customers.count_big_limits(2000.0);
        TS_ASSERT_EQUALS(count, 0);
    }

    void testIncrease_limit() {
        Customer* cust1 = customers.increase_limit("456",10000);
        TS_ASSERT_EQUALS(customers.find("456")->GetLimit(), 11000);
        TS_ASSERT_EQUALS(customers.increase_limit("78896",10000), nullptr);

        Customer newCustomer("012", contact1, 1500.0, list3);
        bool inserted = customers.insert(newCustomer);
        TS_ASSERT(inserted);

        Customer* cust2 = customers.increase_limit("012",10000);
        TS_ASSERT_EQUALS(customers.find("012")->GetLimit(), 11500);
    }

    void testErrorThrowsAndConstructors() {
        TS_ASSERT_THROWS_ANYTHING(nullTest.get_left_subtree());
        TS_ASSERT_THROWS_ANYTHING(nullTest.get_right_subtree());
        TS_ASSERT_THROWS_ANYTHING(nullTest.get_data());
        
        bool erased = nullTest.erase(Customer("123", contact1, 500.0, list1));
        TS_ASSERT(!erased);

        Customer* nullTesting = new Customer();
        TS_ASSERT_EQUALS(nullTesting->GetCard_number(), "");

        nullTesting->SetCharges(list1);
        nullTesting->SetContact(contact1);
        nullTesting->SetCard_number("555");

        TS_ASSERT_EQUALS(nullTesting->GetCharges().front().GetBusiness(), list1.front().GetBusiness());
        TS_ASSERT_EQUALS(nullTesting->GetContact().getEmail(), contact1.getEmail());
        TS_ASSERT_EQUALS(nullTesting->GetCard_number(), "555");

        Contact nullTest1 = Contact();

        TS_ASSERT_EQUALS(nullTest1.getName(), "");

        nullTest1.setName("NULLIES");
        nullTest1.setAddress("Whitehouse");
        nullTest1.setEmail("nope@notta.com");

        TS_ASSERT_EQUALS(nullTest1.getName(), "NULLIES");
        TS_ASSERT_EQUALS(nullTest1.getAddress(), "Whitehouse");
        TS_ASSERT_EQUALS(nullTest1.getEmail(), "nope@notta.com");

    }

    void testString() {
        cout << customers.to_string() << endl;
    }

private:
    Customer* customer1;
    Customer* customer2;
    Contact contact1;
    Contact contact2;
    Charge charge1;
    Charge charge2;
    Charge charge3;
    Charge charge4;
    list<Charge> list1;
    list<Charge> list2;
    list<Charge> list3;
    Customers<Customer> customers;
    Customers<Customer> nullTest;

};
#endif /* TESTCASES_H */
