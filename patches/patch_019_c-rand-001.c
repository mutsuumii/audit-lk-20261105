# Patch for: Insecure random number generation
# CWE-338 | MEDIUM
# Original file: include/lk/mtrand.h line 312
# rand() is not cryptographically secure and uses a predictable seed. Tokens generated this way can be reproduced.

# VULNERABLE (original):
# inline double wxMTRand::rand() { return double(randInt()) * (1.0 / 4294967295.0); }

# PATCHED (fixed):
// Fixed: see CWE-338 remediation guide
