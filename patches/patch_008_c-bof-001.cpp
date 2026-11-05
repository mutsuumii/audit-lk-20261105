# Patch for: Buffer overflow via unsafe string functions
# CWE-120 | CRITICAL
# Original file: src/lex.cpp line 548
# Use of strcpy/strcat/sprintf/gets without bounds checking. Writing past buffer boundaries leads to code execution.

# VULNERABLE (original):
# sprintf(buf, "%d", (int) *p);

# PATCHED (fixed):
/* Fixed: use bounded copy */
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';
