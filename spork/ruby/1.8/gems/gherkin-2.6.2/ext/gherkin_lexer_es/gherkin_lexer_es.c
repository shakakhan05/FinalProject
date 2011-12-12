
#line 1 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
#include <assert.h>
#include <ruby.h>

#if defined(_WIN32)
#include <stddef.h>
#endif

#ifdef HAVE_RUBY_RE_H
#include <ruby/re.h>
#else
#include <re.h>
#endif

#ifdef HAVE_RUBY_ENCODING_H
#include <ruby/encoding.h>
#define ENCODED_STR_NEW(ptr, len) \
    rb_enc_str_new(ptr, len, rb_utf8_encoding())
#else
#define ENCODED_STR_NEW(ptr, len) \
    rb_str_new(ptr, len)
#endif

#ifndef RSTRING_PTR
#define RSTRING_PTR(s) (RSTRING(s)->ptr)
#endif

#ifndef RSTRING_LEN
#define RSTRING_LEN(s) (RSTRING(s)->len)
#endif

#define DATA_GET(FROM, TYPE, NAME) \
  Data_Get_Struct(FROM, TYPE, NAME); \
  if (NAME == NULL) { \
    rb_raise(rb_eArgError, "NULL found for " # NAME " when it shouldn't be."); \
  }
 
typedef struct lexer_state {
  int content_len;
  int line_number;
  int current_line;
  int start_col;
  size_t mark;
  size_t keyword_start;
  size_t keyword_end;
  size_t next_keyword_start;
  size_t content_start;
  size_t content_end;
  size_t docstring_content_type_start;
  size_t docstring_content_type_end;
  size_t query_start;
  size_t last_newline;
  size_t final_newline;
} lexer_state;

static VALUE mGherkin;
static VALUE mGherkinLexer;
static VALUE mCLexer;
static VALUE cI18nLexer;
static VALUE rb_eGherkinLexingError;

#define LEN(AT, P) (P - data - lexer->AT)
#define MARK(M, P) (lexer->M = (P) - data)
#define PTR_TO(P) (data + lexer->P)

#define STORE_KW_END_CON(EVENT) \
  store_multiline_kw_con(listener, # EVENT, \
    PTR_TO(keyword_start), LEN(keyword_start, PTR_TO(keyword_end - 1)), \
    PTR_TO(content_start), LEN(content_start, PTR_TO(content_end)), \
    lexer->current_line, lexer->start_col); \
    if (lexer->content_end != 0) { \
      p = PTR_TO(content_end - 1); \
    } \
    lexer->content_end = 0

#define STORE_ATTR(ATTR) \
    store_attr(listener, # ATTR, \
      PTR_TO(content_start), LEN(content_start, p), \
      lexer->line_number)


#line 254 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"


/** Data **/

#line 89 "ext/gherkin_lexer_es/gherkin_lexer_es.c"
static const char _lexer_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7, 1, 8, 1, 9, 1, 10, 1, 
	11, 1, 12, 1, 13, 1, 16, 1, 
	17, 1, 18, 1, 19, 1, 20, 1, 
	21, 1, 22, 1, 23, 2, 1, 18, 
	2, 4, 5, 2, 13, 0, 2, 14, 
	15, 2, 17, 0, 2, 17, 2, 2, 
	17, 16, 2, 17, 19, 2, 18, 6, 
	2, 18, 7, 2, 18, 8, 2, 18, 
	9, 2, 18, 10, 2, 18, 16, 2, 
	20, 21, 2, 22, 0, 2, 22, 2, 
	2, 22, 16, 2, 22, 19, 3, 3, 
	14, 15, 3, 5, 14, 15, 3, 11, 
	14, 15, 3, 12, 14, 15, 3, 13, 
	14, 15, 3, 14, 15, 18, 3, 17, 
	14, 15, 4, 1, 14, 15, 18, 4, 
	4, 5, 14, 15, 4, 17, 0, 14, 
	15
};

static const short _lexer_key_offsets[] = {
	0, 0, 17, 18, 19, 35, 36, 37, 
	39, 41, 46, 51, 56, 61, 65, 69, 
	71, 72, 73, 74, 75, 76, 77, 78, 
	79, 80, 81, 82, 83, 84, 85, 86, 
	87, 88, 90, 95, 102, 107, 108, 109, 
	110, 111, 112, 113, 114, 115, 116, 117, 
	118, 119, 120, 121, 134, 136, 138, 140, 
	142, 144, 146, 148, 150, 152, 154, 156, 
	158, 160, 162, 164, 180, 182, 183, 184, 
	185, 186, 187, 188, 189, 190, 191, 192, 
	193, 194, 195, 196, 197, 198, 208, 210, 
	212, 214, 216, 218, 220, 222, 224, 226, 
	228, 230, 232, 234, 236, 238, 240, 242, 
	244, 246, 248, 250, 252, 254, 256, 258, 
	260, 262, 264, 266, 268, 270, 272, 274, 
	276, 278, 280, 282, 284, 286, 288, 291, 
	293, 295, 297, 299, 301, 304, 306, 308, 
	310, 312, 314, 316, 318, 320, 322, 324, 
	326, 328, 330, 332, 334, 336, 338, 340, 
	341, 342, 343, 344, 345, 346, 348, 350, 
	353, 354, 355, 356, 357, 358, 359, 360, 
	361, 362, 369, 371, 373, 375, 377, 379, 
	381, 383, 385, 387, 389, 391, 393, 395, 
	397, 399, 400, 401, 402, 403, 404, 405, 
	407, 408, 409, 410, 411, 412, 413, 414, 
	415, 416, 430, 432, 434, 436, 438, 440, 
	442, 444, 446, 448, 450, 452, 454, 456, 
	458, 460, 462, 464, 466, 468, 470, 472, 
	474, 476, 478, 480, 482, 484, 487, 489, 
	491, 493, 495, 497, 499, 501, 503, 505, 
	507, 509, 511, 513, 515, 517, 519, 521, 
	523, 525, 528, 531, 534, 536, 538, 540, 
	542, 544, 546, 549, 551, 553, 555, 557, 
	559, 561, 563, 565, 567, 569, 571, 573, 
	575, 577, 579, 581, 583, 585, 587, 589, 
	590, 591, 592, 593, 594, 595, 596, 597, 
	598, 599, 600, 601, 602, 603, 604, 605, 
	606, 607, 608, 609, 610, 623, 625, 627, 
	629, 631, 633, 635, 637, 639, 641, 643, 
	645, 647, 649, 651, 653, 656, 658, 660, 
	662, 664, 666, 668, 670, 672, 674, 676, 
	678, 680, 682, 684, 686, 688, 690, 692, 
	694, 696, 699, 702, 705, 707, 709, 711, 
	713, 715, 717, 719, 721, 723, 725, 727, 
	729, 731, 733, 735, 736, 737, 741, 747, 
	750, 752, 758, 774, 777, 779, 781, 783, 
	785, 787, 789, 791, 793, 795, 797, 799, 
	801, 803, 805, 807, 809, 811, 813, 815, 
	817, 820, 823, 826, 828, 830, 832, 834, 
	836, 838, 841, 843, 845, 847, 849, 851, 
	853, 855, 857, 859, 861, 863, 865, 867, 
	869, 871, 873, 875, 877, 879, 881
};

static const char _lexer_trans_keys[] = {
	-17, 10, 32, 34, 35, 37, 42, 64, 
	65, 67, 68, 69, 80, 89, 124, 9, 
	13, -69, -65, 10, 32, 34, 35, 37, 
	42, 64, 65, 67, 68, 69, 80, 89, 
	124, 9, 13, 34, 34, 10, 13, 10, 
	13, 10, 32, 34, 9, 13, 10, 32, 
	34, 9, 13, 10, 32, 34, 9, 13, 
	10, 32, 34, 9, 13, 10, 32, 9, 
	13, 10, 32, 9, 13, 10, 13, 10, 
	95, 70, 69, 65, 84, 85, 82, 69, 
	95, 69, 78, 68, 95, 37, 32, 10, 
	10, 13, 13, 32, 64, 9, 10, 9, 
	10, 13, 32, 64, 11, 12, 10, 32, 
	64, 9, 13, 110, 116, 101, 99, 101, 
	100, 101, 110, 116, 101, 115, 58, 10, 
	10, 10, 32, 35, 37, 42, 64, 67, 
	68, 69, 80, 89, 9, 13, 10, 95, 
	10, 70, 10, 69, 10, 65, 10, 84, 
	10, 85, 10, 82, 10, 69, 10, 95, 
	10, 69, 10, 78, 10, 68, 10, 95, 
	10, 37, 10, 32, 10, 32, 34, 35, 
	37, 42, 64, 65, 67, 68, 69, 80, 
	89, 124, 9, 13, 97, 117, 114, 97, 
	99, 116, 101, 114, -61, -83, 115, 116, 
	105, 99, 97, 58, 10, 10, 10, 32, 
	35, 37, 64, 65, 67, 69, 9, 13, 
	10, 95, 10, 70, 10, 69, 10, 65, 
	10, 84, 10, 85, 10, 82, 10, 69, 
	10, 95, 10, 69, 10, 78, 10, 68, 
	10, 95, 10, 37, 10, 110, 10, 116, 
	10, 101, 10, 99, 10, 101, 10, 100, 
	10, 101, 10, 110, 10, 116, 10, 101, 
	10, 115, 10, 58, 10, 97, 10, 114, 
	10, 97, 10, 99, 10, 116, 10, 101, 
	10, 114, -61, 10, -83, 10, 10, 115, 
	10, 116, 10, 105, 10, 99, 10, 97, 
	10, 106, 115, 10, 101, 10, 109, 10, 
	112, 10, 108, 10, 111, 10, 99, 113, 
	10, 101, 10, 110, 10, 97, 10, 114, 
	10, 105, 10, 111, 10, 117, 10, 101, 
	10, 109, 10, 97, 10, 32, 10, 100, 
	10, 101, 10, 108, 10, 32, 10, 101, 
	10, 115, 10, 99, 97, 110, 100, 111, 
	97, 100, 97, 111, 32, 115, 106, 110, 
	115, 101, 109, 112, 108, 111, 115, 58, 
	10, 10, 10, 32, 35, 67, 124, 9, 
	13, 10, 97, 10, 114, 10, 97, 10, 
	99, 10, 116, 10, 101, 10, 114, -61, 
	10, -83, 10, 10, 115, 10, 116, 10, 
	105, 10, 99, 10, 97, 10, 58, 116, 
	111, 110, 99, 101, 115, 99, 113, 101, 
	110, 97, 114, 105, 111, 58, 10, 10, 
	10, 32, 35, 37, 42, 64, 65, 67, 
	68, 69, 80, 89, 9, 13, 10, 95, 
	10, 70, 10, 69, 10, 65, 10, 84, 
	10, 85, 10, 82, 10, 69, 10, 95, 
	10, 69, 10, 78, 10, 68, 10, 95, 
	10, 37, 10, 32, 10, 110, 10, 116, 
	10, 101, 10, 99, 10, 101, 10, 100, 
	10, 101, 10, 110, 10, 116, 10, 101, 
	10, 115, 10, 58, 10, 97, 117, 10, 
	114, 10, 97, 10, 99, 10, 116, 10, 
	101, 10, 114, -61, 10, -83, 10, 10, 
	115, 10, 116, 10, 105, 10, 99, 10, 
	97, 10, 97, 10, 110, 10, 100, 10, 
	111, 10, 97, 10, 100, 10, 97, 111, 
	10, 32, 115, 10, 110, 115, 10, 116, 
	10, 111, 10, 110, 10, 99, 10, 101, 
	10, 115, 10, 99, 113, 10, 101, 10, 
	110, 10, 97, 10, 114, 10, 105, 10, 
	111, 10, 117, 10, 101, 10, 109, 10, 
	97, 10, 32, 10, 100, 10, 101, 10, 
	108, 10, 32, 10, 101, 10, 115, 10, 
	99, 10, 101, 10, 114, 117, 101, 109, 
	97, 32, 100, 101, 108, 32, 101, 115, 
	99, 101, 110, 97, 114, 105, 111, 58, 
	10, 10, 10, 32, 35, 37, 42, 64, 
	67, 68, 69, 80, 89, 9, 13, 10, 
	95, 10, 70, 10, 69, 10, 65, 10, 
	84, 10, 85, 10, 82, 10, 69, 10, 
	95, 10, 69, 10, 78, 10, 68, 10, 
	95, 10, 37, 10, 32, 10, 97, 117, 
	10, 114, 10, 97, 10, 99, 10, 116, 
	10, 101, 10, 114, -61, 10, -83, 10, 
	10, 115, 10, 116, 10, 105, 10, 99, 
	10, 97, 10, 58, 10, 97, 10, 110, 
	10, 100, 10, 111, 10, 97, 10, 100, 
	10, 97, 111, 10, 32, 115, 10, 110, 
	115, 10, 116, 10, 111, 10, 110, 10, 
	99, 10, 101, 10, 115, 10, 99, 10, 
	101, 10, 110, 10, 97, 10, 114, 10, 
	105, 10, 111, 10, 101, 10, 114, 101, 
	114, 32, 124, 9, 13, 10, 32, 92, 
	124, 9, 13, 10, 92, 124, 10, 92, 
	10, 32, 92, 124, 9, 13, 10, 32, 
	34, 35, 37, 42, 64, 65, 67, 68, 
	69, 80, 89, 124, 9, 13, 10, 97, 
	117, 10, 114, 10, 97, 10, 99, 10, 
	116, 10, 101, 10, 114, -61, 10, -83, 
	10, 10, 115, 10, 116, 10, 105, 10, 
	99, 10, 97, 10, 58, 10, 97, 10, 
	110, 10, 100, 10, 111, 10, 97, 10, 
	100, 10, 97, 111, 10, 32, 115, 10, 
	110, 115, 10, 116, 10, 111, 10, 110, 
	10, 99, 10, 101, 10, 115, 10, 99, 
	113, 10, 101, 10, 110, 10, 97, 10, 
	114, 10, 105, 10, 111, 10, 117, 10, 
	101, 10, 109, 10, 97, 10, 32, 10, 
	100, 10, 101, 10, 108, 10, 32, 10, 
	101, 10, 115, 10, 99, 10, 101, 10, 
	114, 0
};

static const char _lexer_single_lengths[] = {
	0, 15, 1, 1, 14, 1, 1, 2, 
	2, 3, 3, 3, 3, 2, 2, 2, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 2, 3, 5, 3, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 11, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 14, 2, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 8, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 3, 2, 
	2, 2, 2, 2, 3, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 1, 
	1, 1, 1, 1, 1, 2, 2, 3, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 5, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 1, 1, 1, 1, 1, 1, 2, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 12, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 3, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 3, 3, 3, 2, 2, 2, 2, 
	2, 2, 3, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 11, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 3, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 3, 3, 3, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 1, 1, 2, 4, 3, 
	2, 4, 14, 3, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	3, 3, 3, 2, 2, 2, 2, 2, 
	2, 3, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 0
};

static const char _lexer_range_lengths[] = {
	0, 1, 0, 0, 1, 0, 0, 0, 
	0, 1, 1, 1, 1, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 1, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 1, 0, 
	0, 1, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0
};

static const short _lexer_index_offsets[] = {
	0, 0, 17, 19, 21, 37, 39, 41, 
	44, 47, 52, 57, 62, 67, 71, 75, 
	78, 80, 82, 84, 86, 88, 90, 92, 
	94, 96, 98, 100, 102, 104, 106, 108, 
	110, 112, 115, 120, 127, 132, 134, 136, 
	138, 140, 142, 144, 146, 148, 150, 152, 
	154, 156, 158, 160, 173, 176, 179, 182, 
	185, 188, 191, 194, 197, 200, 203, 206, 
	209, 212, 215, 218, 234, 237, 239, 241, 
	243, 245, 247, 249, 251, 253, 255, 257, 
	259, 261, 263, 265, 267, 269, 279, 282, 
	285, 288, 291, 294, 297, 300, 303, 306, 
	309, 312, 315, 318, 321, 324, 327, 330, 
	333, 336, 339, 342, 345, 348, 351, 354, 
	357, 360, 363, 366, 369, 372, 375, 378, 
	381, 384, 387, 390, 393, 396, 399, 403, 
	406, 409, 412, 415, 418, 422, 425, 428, 
	431, 434, 437, 440, 443, 446, 449, 452, 
	455, 458, 461, 464, 467, 470, 473, 476, 
	478, 480, 482, 484, 486, 488, 491, 494, 
	498, 500, 502, 504, 506, 508, 510, 512, 
	514, 516, 523, 526, 529, 532, 535, 538, 
	541, 544, 547, 550, 553, 556, 559, 562, 
	565, 568, 570, 572, 574, 576, 578, 580, 
	583, 585, 587, 589, 591, 593, 595, 597, 
	599, 601, 615, 618, 621, 624, 627, 630, 
	633, 636, 639, 642, 645, 648, 651, 654, 
	657, 660, 663, 666, 669, 672, 675, 678, 
	681, 684, 687, 690, 693, 696, 700, 703, 
	706, 709, 712, 715, 718, 721, 724, 727, 
	730, 733, 736, 739, 742, 745, 748, 751, 
	754, 757, 761, 765, 769, 772, 775, 778, 
	781, 784, 787, 791, 794, 797, 800, 803, 
	806, 809, 812, 815, 818, 821, 824, 827, 
	830, 833, 836, 839, 842, 845, 848, 851, 
	853, 855, 857, 859, 861, 863, 865, 867, 
	869, 871, 873, 875, 877, 879, 881, 883, 
	885, 887, 889, 891, 893, 906, 909, 912, 
	915, 918, 921, 924, 927, 930, 933, 936, 
	939, 942, 945, 948, 951, 955, 958, 961, 
	964, 967, 970, 973, 976, 979, 982, 985, 
	988, 991, 994, 997, 1000, 1003, 1006, 1009, 
	1012, 1015, 1019, 1023, 1027, 1030, 1033, 1036, 
	1039, 1042, 1045, 1048, 1051, 1054, 1057, 1060, 
	1063, 1066, 1069, 1072, 1074, 1076, 1080, 1086, 
	1090, 1093, 1099, 1115, 1119, 1122, 1125, 1128, 
	1131, 1134, 1137, 1140, 1143, 1146, 1149, 1152, 
	1155, 1158, 1161, 1164, 1167, 1170, 1173, 1176, 
	1179, 1183, 1187, 1191, 1194, 1197, 1200, 1203, 
	1206, 1209, 1213, 1216, 1219, 1222, 1225, 1228, 
	1231, 1234, 1237, 1240, 1243, 1246, 1249, 1252, 
	1255, 1258, 1261, 1264, 1267, 1270, 1273
};

static const short _lexer_trans_targs[] = {
	2, 4, 4, 5, 15, 17, 31, 34, 
	37, 68, 155, 159, 355, 31, 357, 4, 
	0, 3, 0, 4, 0, 4, 4, 5, 
	15, 17, 31, 34, 37, 68, 155, 159, 
	355, 31, 357, 4, 0, 6, 0, 7, 
	0, 9, 8, 8, 9, 8, 8, 10, 
	10, 11, 10, 10, 10, 10, 11, 10, 
	10, 10, 10, 12, 10, 10, 10, 10, 
	13, 10, 10, 4, 14, 14, 0, 4, 
	14, 14, 0, 4, 16, 15, 4, 0, 
	18, 0, 19, 0, 20, 0, 21, 0, 
	22, 0, 23, 0, 24, 0, 25, 0, 
	26, 0, 27, 0, 28, 0, 29, 0, 
	30, 0, 414, 0, 32, 0, 0, 33, 
	4, 16, 33, 0, 0, 0, 0, 35, 
	36, 4, 36, 36, 34, 35, 35, 4, 
	36, 34, 36, 0, 38, 0, 39, 0, 
	40, 0, 41, 0, 42, 0, 43, 0, 
	44, 0, 45, 0, 46, 0, 47, 0, 
	48, 0, 49, 0, 51, 50, 51, 50, 
	51, 51, 4, 52, 66, 4, 363, 382, 
	386, 412, 66, 51, 50, 51, 53, 50, 
	51, 54, 50, 51, 55, 50, 51, 56, 
	50, 51, 57, 50, 51, 58, 50, 51, 
	59, 50, 51, 60, 50, 51, 61, 50, 
	51, 62, 50, 51, 63, 50, 51, 64, 
	50, 51, 65, 50, 51, 4, 50, 51, 
	67, 50, 4, 4, 5, 15, 17, 31, 
	34, 37, 68, 155, 159, 355, 31, 357, 
	4, 0, 69, 151, 0, 70, 0, 71, 
	0, 72, 0, 73, 0, 74, 0, 75, 
	0, 76, 0, 77, 0, 78, 0, 79, 
	0, 80, 0, 81, 0, 82, 0, 83, 
	0, 85, 84, 85, 84, 85, 85, 4, 
	86, 4, 100, 112, 126, 85, 84, 85, 
	87, 84, 85, 88, 84, 85, 89, 84, 
	85, 90, 84, 85, 91, 84, 85, 92, 
	84, 85, 93, 84, 85, 94, 84, 85, 
	95, 84, 85, 96, 84, 85, 97, 84, 
	85, 98, 84, 85, 99, 84, 85, 4, 
	84, 85, 101, 84, 85, 102, 84, 85, 
	103, 84, 85, 104, 84, 85, 105, 84, 
	85, 106, 84, 85, 107, 84, 85, 108, 
	84, 85, 109, 84, 85, 110, 84, 85, 
	111, 84, 85, 67, 84, 85, 113, 84, 
	85, 114, 84, 85, 115, 84, 85, 116, 
	84, 85, 117, 84, 85, 118, 84, 85, 
	119, 84, 120, 85, 84, 121, 85, 84, 
	85, 122, 84, 85, 123, 84, 85, 124, 
	84, 85, 125, 84, 85, 111, 84, 85, 
	127, 132, 84, 85, 128, 84, 85, 129, 
	84, 85, 130, 84, 85, 131, 84, 85, 
	110, 84, 85, 133, 139, 84, 85, 134, 
	84, 85, 135, 84, 85, 136, 84, 85, 
	137, 84, 85, 138, 84, 85, 111, 84, 
	85, 140, 84, 85, 141, 84, 85, 142, 
	84, 85, 143, 84, 85, 144, 84, 85, 
	145, 84, 85, 146, 84, 85, 147, 84, 
	85, 148, 84, 85, 149, 84, 85, 150, 
	84, 85, 133, 84, 152, 0, 153, 0, 
	154, 0, 31, 0, 156, 0, 157, 0, 
	158, 158, 0, 32, 31, 0, 160, 185, 
	191, 0, 161, 0, 162, 0, 163, 0, 
	164, 0, 165, 0, 166, 0, 167, 0, 
	169, 168, 169, 168, 169, 169, 4, 170, 
	4, 169, 168, 169, 171, 168, 169, 172, 
	168, 169, 173, 168, 169, 174, 168, 169, 
	175, 168, 169, 176, 168, 169, 177, 168, 
	178, 169, 168, 179, 169, 168, 169, 180, 
	168, 169, 181, 168, 169, 182, 168, 169, 
	183, 168, 169, 184, 168, 169, 67, 168, 
	186, 0, 187, 0, 188, 0, 189, 0, 
	190, 0, 31, 0, 192, 279, 0, 193, 
	0, 194, 0, 195, 0, 196, 0, 197, 
	0, 198, 0, 199, 0, 201, 200, 201, 
	200, 201, 201, 4, 202, 216, 4, 217, 
	229, 247, 251, 277, 216, 201, 200, 201, 
	203, 200, 201, 204, 200, 201, 205, 200, 
	201, 206, 200, 201, 207, 200, 201, 208, 
	200, 201, 209, 200, 201, 210, 200, 201, 
	211, 200, 201, 212, 200, 201, 213, 200, 
	201, 214, 200, 201, 215, 200, 201, 4, 
	200, 201, 67, 200, 201, 218, 200, 201, 
	219, 200, 201, 220, 200, 201, 221, 200, 
	201, 222, 200, 201, 223, 200, 201, 224, 
	200, 201, 225, 200, 201, 226, 200, 201, 
	227, 200, 201, 228, 200, 201, 67, 200, 
	201, 230, 243, 200, 201, 231, 200, 201, 
	232, 200, 201, 233, 200, 201, 234, 200, 
	201, 235, 200, 201, 236, 200, 237, 201, 
	200, 238, 201, 200, 201, 239, 200, 201, 
	240, 200, 201, 241, 200, 201, 242, 200, 
	201, 228, 200, 201, 244, 200, 201, 245, 
	200, 201, 246, 200, 201, 216, 200, 201, 
	248, 200, 201, 249, 200, 201, 250, 250, 
	200, 201, 67, 216, 200, 201, 252, 258, 
	200, 201, 253, 200, 201, 254, 200, 201, 
	255, 200, 201, 256, 200, 201, 257, 200, 
	201, 216, 200, 201, 259, 265, 200, 201, 
	260, 200, 201, 261, 200, 201, 262, 200, 
	201, 263, 200, 201, 264, 200, 201, 228, 
	200, 201, 266, 200, 201, 267, 200, 201, 
	268, 200, 201, 269, 200, 201, 270, 200, 
	201, 271, 200, 201, 272, 200, 201, 273, 
	200, 201, 274, 200, 201, 275, 200, 201, 
	276, 200, 201, 259, 200, 201, 278, 200, 
	201, 246, 200, 280, 0, 281, 0, 282, 
	0, 283, 0, 284, 0, 285, 0, 286, 
	0, 287, 0, 288, 0, 289, 0, 290, 
	0, 291, 0, 292, 0, 293, 0, 294, 
	0, 295, 0, 296, 0, 297, 0, 298, 
	0, 300, 299, 300, 299, 300, 300, 4, 
	301, 315, 4, 316, 335, 339, 353, 315, 
	300, 299, 300, 302, 299, 300, 303, 299, 
	300, 304, 299, 300, 305, 299, 300, 306, 
	299, 300, 307, 299, 300, 308, 299, 300, 
	309, 299, 300, 310, 299, 300, 311, 299, 
	300, 312, 299, 300, 313, 299, 300, 314, 
	299, 300, 4, 299, 300, 67, 299, 300, 
	317, 331, 299, 300, 318, 299, 300, 319, 
	299, 300, 320, 299, 300, 321, 299, 300, 
	322, 299, 300, 323, 299, 324, 300, 299, 
	325, 300, 299, 300, 326, 299, 300, 327, 
	299, 300, 328, 299, 300, 329, 299, 300, 
	330, 299, 300, 67, 299, 300, 332, 299, 
	300, 333, 299, 300, 334, 299, 300, 315, 
	299, 300, 336, 299, 300, 337, 299, 300, 
	338, 338, 299, 300, 67, 315, 299, 300, 
	340, 346, 299, 300, 341, 299, 300, 342, 
	299, 300, 343, 299, 300, 344, 299, 300, 
	345, 299, 300, 315, 299, 300, 347, 299, 
	300, 348, 299, 300, 349, 299, 300, 350, 
	299, 300, 351, 299, 300, 352, 299, 300, 
	330, 299, 300, 354, 299, 300, 334, 299, 
	356, 0, 154, 0, 357, 358, 357, 0, 
	362, 361, 360, 358, 361, 359, 0, 360, 
	358, 359, 0, 360, 359, 362, 361, 360, 
	358, 361, 359, 362, 362, 5, 15, 17, 
	31, 34, 37, 68, 155, 159, 355, 31, 
	357, 362, 0, 51, 364, 378, 50, 51, 
	365, 50, 51, 366, 50, 51, 367, 50, 
	51, 368, 50, 51, 369, 50, 51, 370, 
	50, 371, 51, 50, 372, 51, 50, 51, 
	373, 50, 51, 374, 50, 51, 375, 50, 
	51, 376, 50, 51, 377, 50, 51, 67, 
	50, 51, 379, 50, 51, 380, 50, 51, 
	381, 50, 51, 66, 50, 51, 383, 50, 
	51, 384, 50, 51, 385, 385, 50, 51, 
	67, 66, 50, 51, 387, 393, 50, 51, 
	388, 50, 51, 389, 50, 51, 390, 50, 
	51, 391, 50, 51, 392, 50, 51, 66, 
	50, 51, 394, 400, 50, 51, 395, 50, 
	51, 396, 50, 51, 397, 50, 51, 398, 
	50, 51, 399, 50, 51, 377, 50, 51, 
	401, 50, 51, 402, 50, 51, 403, 50, 
	51, 404, 50, 51, 405, 50, 51, 406, 
	50, 51, 407, 50, 51, 408, 50, 51, 
	409, 50, 51, 410, 50, 51, 411, 50, 
	51, 394, 50, 51, 413, 50, 51, 381, 
	50, 0, 0
};

static const unsigned char _lexer_trans_actions[] = {
	0, 54, 0, 5, 1, 0, 29, 1, 
	29, 29, 29, 29, 29, 29, 35, 0, 
	43, 0, 43, 0, 43, 54, 0, 5, 
	1, 0, 29, 1, 29, 29, 29, 29, 
	29, 29, 35, 0, 43, 0, 43, 0, 
	43, 135, 48, 9, 106, 11, 0, 130, 
	45, 45, 45, 3, 122, 33, 33, 33, 
	0, 122, 33, 33, 33, 0, 122, 33, 
	0, 33, 0, 102, 7, 7, 43, 54, 
	0, 0, 43, 114, 25, 0, 54, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 43, 57, 
	110, 23, 0, 43, 43, 43, 43, 0, 
	27, 118, 27, 27, 51, 27, 0, 54, 
	0, 1, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 140, 57, 54, 0, 
	54, 0, 72, 33, 84, 72, 84, 84, 
	84, 84, 84, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 15, 0, 54, 
	15, 0, 126, 31, 60, 57, 31, 63, 
	57, 63, 63, 63, 63, 63, 63, 66, 
	31, 43, 0, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 140, 57, 54, 0, 54, 0, 69, 
	33, 69, 84, 84, 84, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 13, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 13, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 0, 54, 0, 0, 54, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 0, 43, 0, 0, 43, 0, 0, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	140, 57, 54, 0, 54, 0, 81, 84, 
	81, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	0, 54, 0, 0, 54, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 21, 0, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 140, 57, 54, 
	0, 54, 0, 75, 33, 84, 75, 84, 
	84, 84, 84, 84, 84, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 17, 
	0, 54, 17, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 17, 0, 
	54, 0, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 0, 54, 
	0, 0, 54, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	0, 54, 17, 0, 0, 54, 0, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 140, 57, 54, 0, 54, 0, 78, 
	33, 84, 78, 84, 84, 84, 84, 84, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 19, 0, 54, 19, 0, 54, 
	0, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 0, 54, 0, 
	0, 54, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 19, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 0, 54, 19, 0, 0, 54, 
	0, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	0, 43, 0, 43, 0, 0, 0, 43, 
	54, 37, 37, 87, 37, 37, 43, 0, 
	39, 0, 43, 0, 0, 54, 0, 0, 
	39, 0, 0, 54, 0, 93, 90, 41, 
	96, 90, 96, 96, 96, 96, 96, 96, 
	99, 0, 43, 54, 0, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 0, 54, 0, 0, 54, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 15, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 0, 54, 
	15, 0, 0, 54, 0, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 0, 0
};

static const unsigned char _lexer_eof_actions[] = {
	0, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43
};

static const int lexer_start = 1;
static const int lexer_first_final = 414;
static const int lexer_error = 0;

static const int lexer_en_main = 1;


#line 258 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"

static VALUE 
unindent(VALUE con, int start_col)
{
  VALUE re;
  // Gherkin will crash gracefully if the string representation of start_col pushes the pattern past 32 characters
  char pat[32]; 
  snprintf(pat, 32, "^[\t ]{0,%d}", start_col); 
  re = rb_reg_regcomp(rb_str_new2(pat));
  rb_funcall(con, rb_intern("gsub!"), 2, re, rb_str_new2(""));

  return Qnil;

}

static void 
store_kw_con(VALUE listener, const char * event_name, 
             const char * keyword_at, size_t keyword_length, 
             const char * at,         size_t length, 
             int current_line)
{
  VALUE con = Qnil, kw = Qnil;
  kw = ENCODED_STR_NEW(keyword_at, keyword_length);
  con = ENCODED_STR_NEW(at, length);
  rb_funcall(con, rb_intern("strip!"), 0);
  rb_funcall(listener, rb_intern(event_name), 3, kw, con, INT2FIX(current_line)); 
}

static void
store_multiline_kw_con(VALUE listener, const char * event_name,
                      const char * keyword_at, size_t keyword_length,
                      const char * at,         size_t length,
                      int current_line, int start_col)
{
  VALUE split;
  VALUE con = Qnil, kw = Qnil, name = Qnil, desc = Qnil;

  kw = ENCODED_STR_NEW(keyword_at, keyword_length);
  con = ENCODED_STR_NEW(at, length);

  unindent(con, start_col);
  
  split = rb_str_split(con, "\n");

  name = rb_funcall(split, rb_intern("shift"), 0);
  desc = rb_ary_join(split, rb_str_new2( "\n" ));

  if( name == Qnil ) 
  {
    name = rb_str_new2("");
  }
  if( rb_funcall(desc, rb_intern("size"), 0) == 0) 
  {
    desc = rb_str_new2("");
  }
  rb_funcall(name, rb_intern("strip!"), 0);
  rb_funcall(desc, rb_intern("rstrip!"), 0);
  rb_funcall(listener, rb_intern(event_name), 4, kw, name, desc, INT2FIX(current_line)); 
}

static void 
store_attr(VALUE listener, const char * attr_type,
           const char * at, size_t length, 
           int line)
{
  VALUE val = ENCODED_STR_NEW(at, length);
  rb_funcall(listener, rb_intern(attr_type), 2, val, INT2FIX(line));
}
static void 
store_docstring_content(VALUE listener, 
          int start_col, 
          const char *type_at, size_t type_length,
          const char *at, size_t length, 
          int current_line)
{
  VALUE re2;
  VALUE unescape_escaped_quotes;
  VALUE con = ENCODED_STR_NEW(at, length);
  VALUE con_type = ENCODED_STR_NEW(type_at, type_length);

  unindent(con, start_col);

  re2 = rb_reg_regcomp(rb_str_new2("\r\\Z"));
  unescape_escaped_quotes = rb_reg_regcomp(rb_str_new2("\\\\\"\\\\\"\\\\\""));
  rb_funcall(con, rb_intern("sub!"), 2, re2, rb_str_new2(""));
  rb_funcall(con_type, rb_intern("strip!"), 0);
  rb_funcall(con, rb_intern("gsub!"), 2, unescape_escaped_quotes, rb_str_new2("\"\"\""));
  rb_funcall(listener, rb_intern("doc_string"), 3, con_type, con, INT2FIX(current_line));
}
static void 
raise_lexer_error(const char * at, int line)
{ 
  rb_raise(rb_eGherkinLexingError, "Lexing error on line %d: '%s'. See http://wiki.github.com/cucumber/gherkin/lexingerror for more information.", line, at);
}

static void lexer_init(lexer_state *lexer) {
  lexer->content_start = 0;
  lexer->content_end = 0;
  lexer->content_len = 0;
  lexer->docstring_content_type_start = 0;
  lexer->docstring_content_type_end = 0;
  lexer->mark = 0;
  lexer->keyword_start = 0;
  lexer->keyword_end = 0;
  lexer->next_keyword_start = 0;
  lexer->line_number = 1;
  lexer->last_newline = 0;
  lexer->final_newline = 0;
  lexer->start_col = 0;
}

static VALUE CLexer_alloc(VALUE klass)
{
  VALUE obj;
  lexer_state *lxr = ALLOC(lexer_state);
  lexer_init(lxr);

  obj = Data_Wrap_Struct(klass, NULL, -1, lxr);

  return obj;
}

static VALUE CLexer_init(VALUE self, VALUE listener)
{
  lexer_state *lxr; 
  rb_iv_set(self, "@listener", listener);
  
  lxr = NULL;
  DATA_GET(self, lexer_state, lxr);
  lexer_init(lxr);
  
  return self;
}

static VALUE CLexer_scan(VALUE self, VALUE input)
{
  VALUE input_copy;
  char *data;
  size_t len;
  VALUE listener = rb_iv_get(self, "@listener");

  lexer_state *lexer;
  lexer = NULL;
  DATA_GET(self, lexer_state, lexer);

  input_copy = rb_str_dup(input);

  rb_str_append(input_copy, rb_str_new2("\n%_FEATURE_END_%"));
  data = RSTRING_PTR(input_copy);
  len = RSTRING_LEN(input_copy);
  
  if (len == 0) { 
    rb_raise(rb_eGherkinLexingError, "No content to lex.");
  } else {

    const char *p, *pe, *eof;
    int cs = 0;
    
    VALUE current_row = Qnil;

    p = data;
    pe = data + len;
    eof = pe;
    
    assert(*pe == '\0' && "pointer does not end on NULL");
    
    
#line 1002 "ext/gherkin_lexer_es/gherkin_lexer_es.c"
	{
	cs = lexer_start;
	}

#line 425 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
    
#line 1009 "ext/gherkin_lexer_es/gherkin_lexer_es.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _lexer_trans_keys + _lexer_key_offsets[cs];
	_trans = _lexer_index_offsets[cs];

	_klen = _lexer_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _lexer_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	cs = _lexer_trans_targs[_trans];

	if ( _lexer_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _lexer_actions + _lexer_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 83 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
		MARK(content_start, p);
    lexer->current_line = lexer->line_number;
    lexer->start_col = lexer->content_start - lexer->last_newline - (lexer->keyword_end - lexer->keyword_start) + 2;
  }
	break;
	case 1:
#line 89 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    MARK(content_start, p);
  }
	break;
	case 2:
#line 93 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    lexer->current_line = lexer->line_number;
    lexer->start_col = p - data - lexer->last_newline;
  }
	break;
	case 3:
#line 98 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    int len = LEN(content_start, PTR_TO(final_newline));
    int type_len = LEN(docstring_content_type_start, PTR_TO(docstring_content_type_end));

    if (len < 0) len = 0;
    if (type_len < 0) len = 0;

    store_docstring_content(listener, lexer->start_col, PTR_TO(docstring_content_type_start), type_len, PTR_TO(content_start), len, lexer->current_line);
  }
	break;
	case 4:
#line 108 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{ 
    MARK(docstring_content_type_start, p);
  }
	break;
	case 5:
#line 112 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{ 
    MARK(docstring_content_type_end, p);
  }
	break;
	case 6:
#line 116 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    STORE_KW_END_CON(feature);
  }
	break;
	case 7:
#line 120 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    STORE_KW_END_CON(background);
  }
	break;
	case 8:
#line 124 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    STORE_KW_END_CON(scenario);
  }
	break;
	case 9:
#line 128 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    STORE_KW_END_CON(scenario_outline);
  }
	break;
	case 10:
#line 132 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    STORE_KW_END_CON(examples);
  }
	break;
	case 11:
#line 136 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    store_kw_con(listener, "step",
      PTR_TO(keyword_start), LEN(keyword_start, PTR_TO(keyword_end)),
      PTR_TO(content_start), LEN(content_start, p), 
      lexer->current_line);
  }
	break;
	case 12:
#line 143 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    STORE_ATTR(comment);
    lexer->mark = 0;
  }
	break;
	case 13:
#line 148 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    STORE_ATTR(tag);
    lexer->mark = 0;
  }
	break;
	case 14:
#line 153 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    lexer->line_number += 1;
    MARK(final_newline, p);
  }
	break;
	case 15:
#line 158 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    MARK(last_newline, p + 1);
  }
	break;
	case 16:
#line 162 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    if (lexer->mark == 0) {
      MARK(mark, p);
    }
  }
	break;
	case 17:
#line 168 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    MARK(keyword_end, p);
    MARK(keyword_start, PTR_TO(mark));
    MARK(content_start, p + 1);
    lexer->mark = 0;
  }
	break;
	case 18:
#line 175 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    MARK(content_end, p);
  }
	break;
	case 19:
#line 179 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    p = p - 1;
    lexer->current_line = lexer->line_number;
    current_row = rb_ary_new();
  }
	break;
	case 20:
#line 185 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
		MARK(content_start, p);
  }
	break;
	case 21:
#line 189 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    VALUE re_pipe, re_newline, re_backslash;
    VALUE con = ENCODED_STR_NEW(PTR_TO(content_start), LEN(content_start, p));
    rb_funcall(con, rb_intern("strip!"), 0);
    re_pipe      = rb_reg_regcomp(rb_str_new2("\\\\\\|"));
    re_newline   = rb_reg_regcomp(rb_str_new2("\\\\n"));
    re_backslash = rb_reg_regcomp(rb_str_new2("\\\\\\\\"));
    rb_funcall(con, rb_intern("gsub!"), 2, re_pipe,      rb_str_new2("|"));
    rb_funcall(con, rb_intern("gsub!"), 2, re_newline,   rb_str_new2("\n"));
    rb_funcall(con, rb_intern("gsub!"), 2, re_backslash, rb_str_new2("\\"));

    rb_ary_push(current_row, con);
  }
	break;
	case 22:
#line 203 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    rb_funcall(listener, rb_intern("row"), 2, current_row, INT2FIX(lexer->current_line));
  }
	break;
	case 23:
#line 207 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    int line;
    if (cs < lexer_first_final) {
      size_t count = 0;
      VALUE newstr_val;
      char *newstr;
      int newstr_count = 0;        
      size_t len;
      const char *buff;
      if (lexer->last_newline != 0) {
        len = LEN(last_newline, eof);
        buff = PTR_TO(last_newline);
      } else {
        len = strlen(data);
        buff = data;
      }

      // Allocate as a ruby string so that it gets cleaned up by GC
      newstr_val = rb_str_new(buff, len);
      newstr = RSTRING_PTR(newstr_val);


      for (count = 0; count < len; count++) {
        if(buff[count] == 10) {
          newstr[newstr_count] = '\0'; // terminate new string at first newline found
          break;
        } else {
          if (buff[count] == '%') {
            newstr[newstr_count++] = buff[count];
            newstr[newstr_count] = buff[count];
          } else {
            newstr[newstr_count] = buff[count];
          }
        }
        newstr_count++;
      }

      line = lexer->line_number;
      lexer_init(lexer); // Re-initialize so we can scan again with the same lexer
      raise_lexer_error(newstr, line);
    } else {
      rb_funcall(listener, rb_intern("eof"), 0);
    }
  }
	break;
#line 1299 "ext/gherkin_lexer_es/gherkin_lexer_es.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _lexer_actions + _lexer_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 23:
#line 207 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"
	{
    int line;
    if (cs < lexer_first_final) {
      size_t count = 0;
      VALUE newstr_val;
      char *newstr;
      int newstr_count = 0;        
      size_t len;
      const char *buff;
      if (lexer->last_newline != 0) {
        len = LEN(last_newline, eof);
        buff = PTR_TO(last_newline);
      } else {
        len = strlen(data);
        buff = data;
      }

      // Allocate as a ruby string so that it gets cleaned up by GC
      newstr_val = rb_str_new(buff, len);
      newstr = RSTRING_PTR(newstr_val);


      for (count = 0; count < len; count++) {
        if(buff[count] == 10) {
          newstr[newstr_count] = '\0'; // terminate new string at first newline found
          break;
        } else {
          if (buff[count] == '%') {
            newstr[newstr_count++] = buff[count];
            newstr[newstr_count] = buff[count];
          } else {
            newstr[newstr_count] = buff[count];
          }
        }
        newstr_count++;
      }

      line = lexer->line_number;
      lexer_init(lexer); // Re-initialize so we can scan again with the same lexer
      raise_lexer_error(newstr, line);
    } else {
      rb_funcall(listener, rb_intern("eof"), 0);
    }
  }
	break;
#line 1362 "ext/gherkin_lexer_es/gherkin_lexer_es.c"
		}
	}
	}

	_out: {}
	}

#line 426 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/es.c.rl"

    assert(p <= pe && "data overflow after parsing execute");
    assert(lexer->content_start <= len && "content starts after data end");
    assert(lexer->mark < len && "mark is after data end");
    
    // Reset lexer by re-initializing the whole thing
    lexer_init(lexer);

    if (cs == lexer_error) {
      rb_raise(rb_eGherkinLexingError, "Invalid format, lexing fails.");
    } else {
      return Qtrue;
    }
  }
}

void Init_gherkin_lexer_es()
{
  mGherkin = rb_define_module("Gherkin");
  mGherkinLexer = rb_define_module_under(mGherkin, "Lexer");
  rb_eGherkinLexingError = rb_const_get(mGherkinLexer, rb_intern("LexingError"));

  mCLexer = rb_define_module_under(mGherkin, "CLexer");
  cI18nLexer = rb_define_class_under(mCLexer, "Es", rb_cObject);
  rb_define_alloc_func(cI18nLexer, CLexer_alloc);
  rb_define_method(cI18nLexer, "initialize", CLexer_init, 1);
  rb_define_method(cI18nLexer, "scan", CLexer_scan, 1);
}

