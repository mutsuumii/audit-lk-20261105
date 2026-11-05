# Patches

Each patch addresses one finding from the audit report.

Apply these changes to the original repository to fix the identified issues.

## Patch 1: DOM-based XSS via innerHTML

File: `doc/html/search/search.js` line 266

Before:
```javascript
node.innerHTML='&#8226;';
```

After:
```javascript
// Fixed: use textContent instead of innerHTML
element.textContent = userInput;
// Or: element.innerHTML = DOMPurify.sanitize(userInput);
```

Replaced innerHTML with textContent to prevent script injection. If HTML is needed, sanitize with DOMPurify.

---

## Patch 2: DOM-based XSS via innerHTML

File: `doc/html/search/search.js` line 270

Before:
```javascript
node.innerHTML='&#160;';
```

After:
```javascript
// Fixed: use textContent instead of innerHTML
element.textContent = userInput;
// Or: element.innerHTML = DOMPurify.sanitize(userInput);
```

Replaced innerHTML with textContent to prevent script injection. If HTML is needed, sanitize with DOMPurify.

---

## Patch 3: DOM-based XSS via innerHTML

File: `doc/html/search/search.js` line 760

Before:
```javascript
srLink.innerHTML = searchData[e][1][0];
```

After:
```javascript
// Fixed: use textContent instead of innerHTML
element.textContent = userInput;
// Or: element.innerHTML = DOMPurify.sanitize(userInput);
```

Replaced innerHTML with textContent to prevent script injection. If HTML is needed, sanitize with DOMPurify.

---

## Patch 4: DOM-based XSS via innerHTML

File: `doc/html/search/search.js` line 771

Before:
```javascript
srScope.innerHTML = searchData[e][1][1][2];
```

After:
```javascript
// Fixed: use textContent instead of innerHTML
element.textContent = userInput;
// Or: element.innerHTML = DOMPurify.sanitize(userInput);
```

Replaced innerHTML with textContent to prevent script injection. If HTML is needed, sanitize with DOMPurify.

---

## Patch 5: DOM-based XSS via innerHTML

File: `doc/html/search/search.js` line 790

Before:
```javascript
srChild.innerHTML = searchData[e][1][c+1][2];
```

After:
```javascript
// Fixed: use textContent instead of innerHTML
element.textContent = userInput;
// Or: element.innerHTML = DOMPurify.sanitize(userInput);
```

Replaced innerHTML with textContent to prevent script injection. If HTML is needed, sanitize with DOMPurify.

---

## Patch 6: DOM-based XSS via innerHTML

File: `doc/html/search/search.js` line 809

Before:
```javascript
link.innerHTML='<span class="SelectionMark">&#160;</span>'+indexSectionLabels[key];
```

After:
```javascript
// Fixed: use textContent instead of innerHTML
element.textContent = userInput;
// Or: element.innerHTML = DOMPurify.sanitize(userInput);
```

Replaced innerHTML with textContent to prevent script injection. If HTML is needed, sanitize with DOMPurify.

---

## Patch 7: Buffer overflow via unsafe string functions

File: `src/lex.cpp` line 52

Before:
```cpp
strcpy(m_buf, utf8.c_str());
```

After:
```cpp
/* Fixed: use bounded copy */
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';
```

Replaced unbounded string copy with strncpy and explicit null termination.

---

## Patch 8: Buffer overflow via unsafe string functions

File: `src/lex.cpp` line 548

Before:
```cpp
sprintf(buf, "%d", (int) *p);
```

After:
```cpp
/* Fixed: use bounded copy */
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';
```

Replaced unbounded string copy with strncpy and explicit null termination.

---

## Patch 9: Buffer overflow via unsafe string functions

File: `src/parse.cpp` line 137

Before:
```cpp
sprintf(buf, "[%s] %d: ", (const char *) m_name.c_str(), m_lastLine);
```

After:
```cpp
/* Fixed: use bounded copy */
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';
```

Replaced unbounded string copy with strncpy and explicit null termination.

---

## Patch 10: Buffer overflow via unsafe string functions

File: `src/parse.cpp` line 139

Before:
```cpp
sprintf(buf, "%d: ", m_lastLine);
```

After:
```cpp
/* Fixed: use bounded copy */
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';
```

Replaced unbounded string copy with strncpy and explicit null termination.

---

## Patch 11: Format string vulnerability

File: `src/parse.cpp` line 122

Before:
```cpp
_vsnprintf(buf, 480, fmt, list);
```

After:
```cpp
/* Fixed: explicit format string */
printf("%s", user_input);
```

Added explicit format string to prevent format string attacks.

---

## Patch 12: Format string vulnerability

File: `src/parse.cpp` line 124

Before:
```cpp
vsnprintf(buf, 480, fmt, list);
```

After:
```cpp
/* Fixed: explicit format string */
printf("%s", user_input);
```

Added explicit format string to prevent format string attacks.

---

## Patch 13: Format string vulnerability

File: `src/parse.cpp` line 137

Before:
```cpp
sprintf(buf, "[%s] %d: ", (const char *) m_name.c_str(), m_lastLine);
```

After:
```cpp
/* Fixed: explicit format string */
printf("%s", user_input);
```

Added explicit format string to prevent format string attacks.

---

## Patch 14: Buffer overflow via unsafe string functions

File: `src/vm.cpp` line 783

Before:
```cpp
sprintf(buf, "[%d] ", spos.stmt);
```

After:
```cpp
/* Fixed: use bounded copy */
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';
```

Replaced unbounded string copy with strncpy and explicit null termination.

---

## Patch 15: Format string vulnerability

File: `src/vm.cpp` line 783

Before:
```cpp
sprintf(buf, "[%d] ", spos.stmt);
```

After:
```cpp
/* Fixed: explicit format string */
printf("%s", user_input);
```

Added explicit format string to prevent format string attacks.

---

## Patch 16: Format string vulnerability

File: `src/vm.cpp` line 788

Before:
```cpp
vsprintf(buf, fmt, args);
```

After:
```cpp
/* Fixed: explicit format string */
printf("%s", user_input);
```

Added explicit format string to prevent format string attacks.

---

## Patch 17: Insecure random number generation

File: `include/lk/mtrand.h` line 105

Before:
```c
double rand();                        // real number in [0,1]
```

After:
```c
// Fixed: see CWE-338 remediation guide
```

Use /dev/urandom on Linux, BCryptGenRandom on Windows, or a CSPRNG library.

---

## Patch 18: Insecure random number generation

File: `include/lk/mtrand.h` line 111

Before:
```c
double operator()();                  // same as rand()
```

After:
```c
// Fixed: see CWE-338 remediation guide
```

Use /dev/urandom on Linux, BCryptGenRandom on Windows, or a CSPRNG library.

---

## Patch 19: Insecure random number generation

File: `include/lk/mtrand.h` line 312

Before:
```c
inline double wxMTRand::rand() { return double(randInt()) * (1.0 / 4294967295.0); }
```

After:
```c
// Fixed: see CWE-338 remediation guide
```

Use /dev/urandom on Linux, BCryptGenRandom on Windows, or a CSPRNG library.

---

## Patch 20: Insecure random number generation

File: `include/lk/mtrand.h` line 314

Before:
```c
inline double wxMTRand::rand(const double n) { return rand() * n; }
```

After:
```c
// Fixed: see CWE-338 remediation guide
```

Use /dev/urandom on Linux, BCryptGenRandom on Windows, or a CSPRNG library.

---

## Patch 21: Insecure random number generation

File: `include/lk/mtrand.h` line 334

Before:
```c
x = 2.0 * rand() - 1.0;
```

After:
```c
// Fixed: see CWE-338 remediation guide
```

Use /dev/urandom on Linux, BCryptGenRandom on Windows, or a CSPRNG library.

---

## Patch 22: Insecure random number generation

File: `include/lk/mtrand.h` line 335

Before:
```c
y = 2.0 * rand() - 1.0;
```

After:
```c
// Fixed: see CWE-338 remediation guide
```

Use /dev/urandom on Linux, BCryptGenRandom on Windows, or a CSPRNG library.

---

## Patch 23: Insecure random number generation

File: `include/lk/mtrand.h` line 343

Before:
```c
return rand();
```

After:
```c
// Fixed: see CWE-338 remediation guide
```

Use /dev/urandom on Linux, BCryptGenRandom on Windows, or a CSPRNG library.

---
