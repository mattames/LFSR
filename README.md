# lfsr
Simple LFSR implementation

This is a simple bit of code that implements a maximal length 64-bit LFSR. The polynomial is one that is defined in the standards document TIA.102-AAAD-A.

The code is designed to provide an initialisation vector (or pseudo-random nonce) which in the context of TIA.102-AAAD-A is called a MI or "Message Indicator".
