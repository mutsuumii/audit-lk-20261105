# Patch for: Format string vulnerability
# CWE-134 | CRITICAL
# Original file: src/parse.cpp line 124
# User-controlled string passed as format argument to printf-family. An attacker can read/write arbitrary memory.

# VULNERABLE (original):
# vsnprintf(buf, 480, fmt, list);

# PATCHED (fixed):
/* Fixed: explicit format string */
printf("%s", user_input);
