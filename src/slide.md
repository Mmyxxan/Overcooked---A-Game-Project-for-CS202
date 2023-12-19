---
marp: true
title: Proxy design pattern
theme: uncover
_class: invert
---

# Proxy

## Design pattern

---

# Intention

**Proxy** is a structural design pattern that lets you provide a substitute or placeholder for another object. A proxy controls access to the original object, allowing you to perform something either before or after the request gets through to the original object.

---

# Real World Problem

## Customer Information Access

---

### Problem

Some clients are supposed to view and change certain confidential client information that is private for other clients. One thing that comes to mind is to do an access check directly in the code that gets the details of customers. Nevertheless, such an approach also involves a lot of flaws.

---

### Naive solution

Whenever we have to read sensitive client data, we directly validate the user’s role/permissions within business logic

---

### Naive Implementation

```C++
// include headers and define exception class...

// Our service that is used to interact with the database
class CustomerService {
private:
    // ... contains database and other members...
public:
    Customer getCustomerDetails(int customerId, User currentUser) {
        if (currentUser.hasPermission(Permission::ACCESS_SENSITIVE_INFO)) {
            // Retrieve and return sensitive customer information
            return database.getCustomerDetails(customerId);
        }
        throw UnauthorizedAccessException();
    }
};

int main() {
    try {
        User user;
        CustomerService customerService;
        Customer customer = customerService.getCustomerDetails(123, user);
        std::cout << "Customer details retrieved successfully." << std::endl;
        std::cout << "Customer 123: " << customer << std::endl;
    } catch (const UnauthorizedAccessException& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
```

---

### Problem with Naive Solution

1. **Code Duplication**
2. **Violation of Single Responsibility Principle (SRP)**
3. **Scalability Issues**

---

# Proxy Pattern Solution (Protection Proxy)

---

## Solution

In this case, the Proxy pattern will help to resolve these problems. We develop a **Protection Proxy** that protects the `CustomerService` class.

---

### Protection Proxy Implementation

```C++
// include headers and define exception class...

class CustomerSerivce {
public:
    virtual Customer getCustomerDetails(int customerId) = 0;
};

class RealCustomerService: public CustomerService {
private:
    // ... contains database and other members...

public:
    Customer getCustomerDetails(int customerId) {
        // Retrieve and return sensitive customer information
        return database.getCustomerDetails(customerId);
    }
};

class ProxyCustomerService : public CustomerService {
private:
    RealCustomerService realCustomerService{};
    User currentUser{};

public:
    ProxyCustomerService(RealCustomerService realService, User cUser):
        realCustomerService{realService}, currentUser{cUser} {}

    Customer getCustomerDetails(int customerId) {
        if (currentUser.hasPermission(Permission::ACCESS_SENSITIVE_INFO)) {
            // Retrieve and return sensitive customer information
            return realCustomerService.getCustomerDetails(customerId);
        }
        throw UnauthorizedAccessException();
    }
};
```

---

#### Benefits of Proxy Solution

1. **Code Seperation**
2. **Single Responsibility**
3. **Scalability**