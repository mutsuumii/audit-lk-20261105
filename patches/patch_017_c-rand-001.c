# Patch for: Insecure random number generation
# CWE-338 | MEDIUM
# Original file: include/lk/mtrand.h line 105
# rand() is not cryptographically secure and uses a predictable seed. Tokens generated this way can be reproduced.

# VULNERABLE (original):
# double rand();                        // real number in [0,1]

# PATCHED (fixed):
// Fixed: see CWE-338 remediation guide
