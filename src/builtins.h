/* Copyright © 2015 Vibhav Pant <vibhavp@gmail.com>

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef BUILTINS_H
#define BUILTINS_H
#include "types.h"
#include <setjmp.h>

#define OPERATOR(o) ((o)+WHILE+EQUAL_P+2)
#define PREDICATE(p) ((p)+WHILE+1)
#define _INTEGER_P(n)  ((n)->type == INTEGER)
#define _FLOAT_P(n)    ((n)->type == FLOAT)
#define _NUMBER_P(n)   (_INTEGER_P((n)) || _FLOAT_P((n)))
#define _STRING_P(n)   ((n)->type == STRING)
#define _SYMBOL_P(n)   ((n)->type == SYMBOL)
#define _LIST_P(n)     ((n)->type == LIST)
#define _LAMBDA_P(n)   (_LIST_P((n))                            \
                        && (n)->cell->car->type == BUILTIN      \
                        && (n)->cell->car->builtin == LAMBDA)
#define _BOOLEAN_P(n) ((n)->type == BOOLEAN)

extern object_t *add(object_t *n1, object_t *n2);
extern object_t *subtract(object_t *n1, object_t *n2);
extern object_t *cond(cons_t *clauses);
extern object_t *quote(object_t *object);
extern object_t *cond(struct cons *clauses);
extern object_t *and(object_t *cond1, object_t *cond2);
extern object_t *or(object_t *cond1, object_t *cond2);
extern object_t *not(object_t *cond);
extern object_t *quote(object_t *obj);
extern object_t *print(object_t *obj);
extern object_t *apply(object_t *function, cons_t *args);
extern object_t *eval(object_t *obj);
extern object_t *define(object_t *sym, object_t *val);
extern object_t *dup_obj(object_t *obj);
extern object_t *divide(object_t *n1, object_t *n2);
extern object_t *multiply(object_t *n1, object_t *n2);
extern object_t *cons(object_t *car, object_t *cdr);
extern void builtins_init();
extern bool equal(object_t *obj1, object_t *obj2);
extern bool eqv(object_t *obj1, object_t *obj2);
extern object_t *call_predicate(cons_t *obj, predicate_t pred);

object_t *builtins[BUILTIN_LEN+4];
object_t *CONST_TRUE;
object_t *CONST_FALSE;
object_t *EMPTY_LIST;

#endif
