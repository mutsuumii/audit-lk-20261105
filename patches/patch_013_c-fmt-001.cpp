# Patch for: Format string vulnerability
# CWE-134 | CRITICAL
# Original file: src/parse.cpp line 137
# User-controlled string passed as format argument to printf-family. An attacker can read/write arbitrary memory.

# VULNERABLE (original):
# sprintf(buf, "[%s] %d: ", (const char *) m_name.c_str(), m_lastLine);

# PATCHED (fixed):
/* Fixed: explicit format string */
printf("%s", user_input);
