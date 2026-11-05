# Patch for: DOM-based XSS via innerHTML
# CWE-79 | HIGH
# Original file: doc/html/search/search.js line 760
# Setting innerHTML with user-controlled data allows script injection.

# VULNERABLE (original):
# srLink.innerHTML = searchData[e][1][0];

# PATCHED (fixed):
// Fixed: use textContent instead of innerHTML
element.textContent = userInput;
// Or: element.innerHTML = DOMPurify.sanitize(userInput);
