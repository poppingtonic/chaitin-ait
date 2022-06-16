[ test new lisp ]
’ (ab c d)
’(ab cd )
car ’(aa bb cc)
cdr ’(aa bb cc)
cadr ’(aa bb cc)
caddr ’(aa bb cc)
cons ’(aa bb cc) ’(dd ee ff)
car aa
cdr aa
cons aa bb
("cons aa)
("cons ’(aa) ’(bb) ’(cc))
let x a x
x
atom ’ aa
atom ’(aa)
if true x y
if false x y
if xxx x y
let (f x) if atom display x x (f car x)
(f ’(((a)b)c))
f
let (cat x y) if atom x y cons car x (cat cdr x y)
(cat ’(a b c) ’(d e f))
cat
define (cat x y) if atom x y cons car x (cat cdr x y)
cat
(cat ’(a b c) ’(d e f))
define x cadr ’(a b c)
x
define x caddr ’(a b c)
x
length display
bits ’ a
length display
bits ’ abc
nil
length display
bits nil
length display
bits ’ (a)
size abc
size ’ ( a b c )
length ’ ( a b c )
+ abc 15
+ ’(abc) 15
+ 10 15
- 10 15
- 15 10
* 10 15
^ 10 15
< 10 15
< 10 10
> 10 15
> 10 10