# Patch for: Insecure random number generation
# CWE-338 | MEDIUM
# Original file: include/lk/mtrand.h line 111
# rand() is not cryptographically secure and uses a predictable seed. Tokens generated this way can be reproduced.

# VULNERABLE (original):
# double operator()();                  // same as rand()

# PATCHED (fixed):
// Fixed: see CWE-338 remediation guide
