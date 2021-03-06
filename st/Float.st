"
Copyright (c) 2008 Vincent Geddes
Copyright (c) 2007 Luca Bruno

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the 'Software'), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
"

"coercing"

Float method!
asFloat
    ^ self!

Float method!
unity
    ^ 1.0!

Float method!
generality
    ^ 50!

Float method!
zero
    ^ 0.0!

Float method!
coerce: aNumber
    ^ aNumber asFloat!


"testing"

Float method!
isFloat
    ^ true!


"comparing"

Float method!
< aNumber
     <primitive: 'Float_lt'>
	 ^ super < aNumber!

Float method!
> aNumber
     <primitive: 'Float_gt'>
	 ^ super > aNumber!

Float method!
<= aNumber
     <primitive: 'Float_le'>
	 ^ super <= aNumber!

Float method!
>= aNumber
     <primitive: 'Float_ge'>
	 ^ super >= aNumber!

Float method!
= aNumber
     <primitive: 'Float_eq'>
	 ^ super = aNumber!

Float method!
~= aNumber
     <primitive: 'Float_ne'>
	 ^ super ~= aNumber!


"arithmetic"

Float method!
+ aNumber
     <primitive: 'Float_add'>
	 ^ super + aNumber!

Float method!
- aNumber
     <primitive: 'Float_sub'>
	 ^ super - aNumber!

Float method!
* aNumber
     <primitive: 'Float_mul'>
	 ^ super * aNumber!

Float method!
/ aNumber
	<primitive: 'Float_div'>
	^ super / aNumber!

Float method!
\\ aNumber
     self notYetImplemented!

Float method!
hash
	<primitive: 'Float_hash'>
	self primitiveFailed!


"printing"

Float method!
printStringBase: anInteger
	<primitive: 'Float_printStringBase'>
	self primitiveFailed!

Float method!
printOn: aStream base: anInteger
	aStream nextPutAll: (self printStringBase: anInteger)!

"rounding & truncation"

Float method!
truncated
	<primitive: 'Float_truncated'>
	self primitiveFailed!

Float method!
fractionPart
	<primitive: 'Float_fractionPart'>
	self primitiveFailed!

Float method!
integerPart
	<primitive: 'Float_integerPart'>
	self primitiveFailed!


"mathematics"

Float method!
sin
	<primitive: 'Float_sin'>
	self primitiveFailed!

Float method!
cos
	<primitive: 'Float_cos'>
	self primitiveFailed!

Float method!
tan
	<primitive: 'Float_tan'>
	self primitiveFailed!

Float method!
arcSin
	<primitive: 'Float_arcSin'>
	self primitiveFailed!

Float method!
arcCos
	<primitive: 'Float_arcSin'>
	self primitiveFailed!

Float method!
arcTan
	<primitive: 'Float_arcTan'>
	self primitiveFailed!

Float method!
exp
	<primitive: 'Float_exp'>
	self primitiveFailed!

Float method!
ln
	<primitive: 'Float_ln'>
	self primitiveFailed!

Float method!
log
	<primitive: 'Float_log'>
	self primitiveFailed!

Float method!
sqrt
	<primitive: 'Float_sqrt'>
	self primitiveFailed!
