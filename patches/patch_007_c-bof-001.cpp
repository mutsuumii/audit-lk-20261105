# Patch for: Buffer overflow via unsafe string functions
# CWE-120 | CRITICAL
# Original file: src/lex.cpp line 52
# Use of strcpy/strcat/sprintf/gets without bounds checking. Writing past buffer boundaries leads to code execution.

# VULNERABLE (original):
# strcpy(m_buf, utf8.c_str());

# PATCHED (fixed):
/* Fixed: use bounded copy */
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';
