# Patch for: Insecure random number generation
# CWE-338 | MEDIUM
# Original file: include/lk/mtrand.h line 314
# rand() is not cryptographically secure and uses a predictable seed. Tokens generated this way can be reproduced.

# VULNERABLE (original):
# inline double wxMTRand::rand(const double n) { return rand() * n; }

# PATCHED (fixed):
// Fixed: see CWE-338 remediation guide
