
#define SIZE 1000000 /* numbers of nodes of tree storage */
#define nil 0 /* end of list marker */

extern long car[SIZE];
extern long cdr[SIZE]; /* tree storage */
extern short atom[SIZE]; /* is it an atom? */
extern short numb[SIZE]; /* is it a number? */
/* The following is only used for atoms */
extern long vlst[SIZE]; /* bindings for each atom */
extern long pname[SIZE]; /* print name for each atom = list of characters in reverse */
/* The following is only used for atoms that are the names of primitive functions */
extern short pf_numb[SIZE]; /* primitive function number (for interpreter switch) */
extern short pf_args[SIZE]; /* number of arguments + 1 (for input parser) */

extern long obj_list; /* list of all atoms (& every other tokens read except numbers) */

/* locations of atoms in tree storage */
extern long wrd_nil, wrd_true, wrd_false, wrd_define, wrd_let, wrd_lambda, wrd_quote, wrd_if;
extern long wrd_car, wrd_cdr, wrd_cadr, wrd_caddr, wrd_eval, wrd_try;
extern long wrd_no_time_limit, wrd_out_of_time, wrd_out_of_data, wrd_success, wrd_failure;
extern long left_bracket, right_bracket, left_paren, right_paren, double_quote;
extern long wrd_zero, wrd_one;

extern long next = 0; /* next free node */
extern long col = 0; /* column in each 50-char chunk of output (preceded by 12-char prefix) */
extern time_t time1; /* clock at time of execution */
extern time_t time2; /* clock at the end of execution */
extern long turing_machine_tapes; /* stack of binary data for try's */
extern long display_enabled; /* stack of flags whether to capture displays or not */
extern long captured_displays; /* stack of stubs to collect captured displays on */
extern long q; /* for converting s-expressions into lists of bits */
extern long buffer2; /* buffer for converting lists of bits into s-expressions
                contains a list of all the words in an input record */
void initialize_atoms(void);
long mk_atom(long number, char *name, long args); /* make an atom */
long mk_numb(long value); /* make a number */
long mk_string(char *p); /* make list of characters */
long eq_wrd(long x, long y); /* are two lists of characters equal? */
long lookup_word(long x); /* look up word in object list? */
long cons(long x, long y); /* get free node & stuff x & y in it */
long out(char *x, long y); /* output expression */
void out_lst(long x); /* output list */
void out_atm(long x); /* output atom */
void out_chr(long x); /* output character */
long in_word2(void); /* read word */
long in_word(void); /* read word -  skip comments */
long in(long mexp, long rparenokay); /* input m-expression */
long only_digits(long x); /* check if list of characters are exclusively digits */
long ev(long e); /* initialize and evaluate expression */
long eval(long e, long d); /* evaluate list of expressions */
long evalst(long e, long d); /* evaluate list of expressions */
void clean_env(void); /* clean environment */
void restore_env(void); /* restore unclean environment */
void bind(long vars, long args); /* bind values of arguments to formal parameters */
long append(long x, long y); /* append two lists */
long eq(long x, long y); /* equal predicate */
long length(long x); /* number of elements in list */
long compare(long x, long y); /* compare two decimal numbers */
long add1(long x); /* number of elements in list */
long sub1(long x); /* subtract 1 from decimal number */
long nmb(long x); /* pick-up decimal number from atom & convert non-number to zero */
long remove_leading_zeros(long x); /* from reversed list of digits of decimal number */
long add(long x, long y, long carry_in); /* add two decimal numbers */
long mult(long x, long y); /* multiply two decimal numbers */
long expon(long base, long exponent); /* base raised to the power exponent */
long sub(long x, long y, long borrow_in); /* x - y assumes x >= y */
long base2to10(long x); /* convert bit string to decimal number */
long halve(long x); /* used to convert decimal number to bit string */
long base10to2(long x); /* convert decimal number to bit string */
long size(long x); /* number of chars in print representation */
long read_bit(void); /* read one square of Turing machine tape */
void write_chr(long x); /* convert character into 8 bits */
void write_atm(long x); /* convert atom into 8 bits per char */
void write_lst(long x); /* convert s-exp into list of bits */
long read_record(void); /* read record from Turing machine tape */
long read_char(void); /* read one char from Turing machine tape */
long read_word(void); /* read word from Turing machine tape */
long read_expr(long rparenokay); /* read s-exp from Turing machine tape */
