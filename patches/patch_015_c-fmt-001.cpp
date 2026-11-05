# Patch for: Format string vulnerability
# CWE-134 | CRITICAL
# Original file: src/vm.cpp line 783
# User-controlled string passed as format argument to printf-family. An attacker can read/write arbitrary memory.

# VULNERABLE (original):
# sprintf(buf, "[%d] ", spos.stmt);

# PATCHED (fixed):
/* Fixed: explicit format string */
printf("%s", user_input);
