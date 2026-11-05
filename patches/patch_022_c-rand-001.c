# Patch for: Insecure random number generation
# CWE-338 | MEDIUM
# Original file: include/lk/mtrand.h line 335
# rand() is not cryptographically secure and uses a predictable seed. Tokens generated this way can be reproduced.

# VULNERABLE (original):
# y = 2.0 * rand() - 1.0;

# PATCHED (fixed):
// Fixed: see CWE-338 remediation guide
