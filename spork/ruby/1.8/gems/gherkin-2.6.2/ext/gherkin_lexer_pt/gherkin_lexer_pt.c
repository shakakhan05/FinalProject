
#line 1 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
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


#line 254 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"


/** Data **/

#line 89 "ext/gherkin_lexer_pt/gherkin_lexer_pt.c"
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
	87, 88, 90, 95, 102, 107, 109, 110, 
	112, 113, 114, 115, 116, 117, 118, 119, 
	133, 135, 137, 139, 141, 143, 145, 147, 
	149, 151, 153, 155, 157, 159, 161, 163, 
	179, 180, 181, 183, 185, 189, 190, 192, 
	193, 194, 195, 196, 197, 198, 199, 200, 
	201, 202, 203, 204, 205, 206, 208, 209, 
	210, 211, 212, 213, 214, 215, 229, 231, 
	233, 235, 237, 239, 241, 243, 245, 247, 
	249, 251, 253, 255, 257, 259, 261, 263, 
	266, 268, 270, 272, 274, 276, 278, 280, 
	283, 286, 289, 291, 294, 296, 298, 300, 
	302, 304, 306, 308, 310, 312, 314, 316, 
	318, 320, 322, 324, 326, 328, 330, 332, 
	334, 336, 337, 338, 339, 340, 341, 342, 
	343, 344, 345, 352, 354, 356, 358, 360, 
	362, 364, 366, 368, 370, 372, 374, 376, 
	378, 380, 381, 382, 383, 384, 385, 386, 
	387, 388, 389, 390, 391, 392, 393, 394, 
	395, 396, 406, 408, 410, 412, 414, 416, 
	418, 420, 422, 424, 426, 428, 430, 432, 
	434, 437, 439, 442, 444, 446, 448, 450, 
	452, 454, 456, 458, 460, 462, 465, 467, 
	469, 471, 473, 475, 477, 479, 481, 483, 
	485, 487, 489, 491, 493, 495, 497, 499, 
	501, 503, 505, 507, 509, 511, 513, 515, 
	517, 519, 521, 523, 525, 526, 527, 528, 
	529, 530, 531, 535, 541, 544, 546, 552, 
	568, 571, 573, 576, 578, 580, 582, 584, 
	586, 588, 590, 592, 594, 596, 598, 600, 
	603, 606, 610, 612, 615, 617, 619, 621, 
	623, 625, 627, 629, 631, 633, 635, 637, 
	639, 641, 643, 645, 647, 649, 651, 653, 
	655, 657, 659, 661, 663, 665, 667, 669, 
	671, 673, 675, 677, 679, 680, 681, 682, 
	683, 684, 685, 686, 687, 688, 702, 704, 
	706, 708, 710, 712, 714, 716, 718, 720, 
	722, 724, 726, 728, 730, 732, 734, 736, 
	739, 741, 743, 745, 747, 749, 751, 753, 
	756, 759, 763, 765, 768, 770, 772, 774, 
	776, 778, 780, 782, 784, 786, 788, 790, 
	792, 794, 796, 798, 800, 802, 804, 806, 
	808, 810, 812, 814, 816, 818, 820, 822, 
	824, 826, 828, 830
};

static const char _lexer_trans_keys[] = {
	-17, 10, 32, 34, 35, 37, 42, 64, 
	67, 68, 69, 70, 77, 81, 124, 9, 
	13, -69, -65, 10, 32, 34, 35, 37, 
	42, 64, 67, 68, 69, 70, 77, 81, 
	124, 9, 13, 34, 34, 10, 13, 10, 
	13, 10, 32, 34, 9, 13, 10, 32, 
	34, 9, 13, 10, 32, 34, 9, 13, 
	10, 32, 34, 9, 13, 10, 32, 9, 
	13, 10, 32, 9, 13, 10, 13, 10, 
	95, 70, 69, 65, 84, 85, 82, 69, 
	95, 69, 78, 68, 95, 37, 32, 10, 
	10, 13, 13, 32, 64, 9, 10, 9, 
	10, 13, 32, 64, 11, 12, 10, 32, 
	64, 9, 13, 101, 111, 110, -61, 97, 
	-95, 114, 105, 111, 58, 10, 10, 10, 
	32, 35, 37, 42, 64, 67, 68, 69, 
	70, 77, 81, 9, 13, 10, 95, 10, 
	70, 10, 69, 10, 65, 10, 84, 10, 
	85, 10, 82, 10, 69, 10, 95, 10, 
	69, 10, 78, 10, 68, 10, 95, 10, 
	37, 10, 32, 10, 32, 34, 35, 37, 
	42, 64, 67, 68, 69, 70, 77, 81, 
	124, 9, 13, 97, 100, 97, 111, 32, 
	115, 32, 110, 115, 120, 116, -61, 97, 
	-93, 111, 113, 117, 101, 109, 97, 32, 
	100, 111, 32, 67, 101, 110, -61, 97, 
	-95, 114, 105, 111, 58, 10, 10, 10, 
	32, 35, 37, 42, 64, 67, 68, 69, 
	70, 77, 81, 9, 13, 10, 95, 10, 
	70, 10, 69, 10, 65, 10, 84, 10, 
	85, 10, 82, 10, 69, 10, 95, 10, 
	69, 10, 78, 10, 68, 10, 95, 10, 
	37, 10, 32, 10, 101, 10, 110, -61, 
	10, 97, -95, 10, 10, 114, 10, 105, 
	10, 111, 10, 58, 10, 97, 10, 100, 
	10, 97, 111, 10, 32, 115, 10, 32, 
	110, 10, 116, -61, 10, 97, -93, 10, 
	10, 111, 10, 117, 10, 110, 10, 99, 
	10, 105, 10, 111, 10, 110, 10, 97, 
	10, 108, 10, 105, 10, 100, 10, 97, 
	10, 100, 10, 101, 10, 97, 10, 115, 
	10, 117, 10, 97, 10, 110, 10, 100, 
	101, 109, 112, 108, 111, 115, 58, 10, 
	10, 10, 32, 35, 70, 124, 9, 13, 
	10, 117, 10, 110, 10, 99, 10, 105, 
	10, 111, 10, 110, 10, 97, 10, 108, 
	10, 105, 10, 100, 10, 97, 10, 100, 
	10, 101, 10, 58, 117, 110, 99, 105, 
	111, 110, 97, 108, 105, 100, 97, 100, 
	101, 58, 10, 10, 10, 32, 35, 37, 
	64, 67, 69, 70, 9, 13, 10, 95, 
	10, 70, 10, 69, 10, 65, 10, 84, 
	10, 85, 10, 82, 10, 69, 10, 95, 
	10, 69, 10, 78, 10, 68, 10, 95, 
	10, 37, 10, 101, 111, 10, 110, -61, 
	10, 97, -95, 10, 10, 114, 10, 105, 
	10, 111, 10, 58, 10, 110, 10, 116, 
	10, 101, 10, 120, 10, 116, 10, 115, 
	120, 10, 113, 10, 117, 10, 101, 10, 
	109, 10, 97, 10, 32, 10, 100, 10, 
	111, 10, 32, 10, 67, 10, 101, 10, 
	101, 10, 109, 10, 112, 10, 108, 10, 
	111, 10, 115, 10, 117, 10, 110, 10, 
	99, 10, 105, 10, 111, 10, 110, 10, 
	97, 10, 108, 10, 105, 10, 100, 10, 
	97, 10, 100, 10, 101, 97, 115, 117, 
	97, 110, 100, 32, 124, 9, 13, 10, 
	32, 92, 124, 9, 13, 10, 92, 124, 
	10, 92, 10, 32, 92, 124, 9, 13, 
	10, 32, 34, 35, 37, 42, 64, 67, 
	68, 69, 70, 77, 81, 124, 9, 13, 
	10, 101, 111, 10, 110, -61, 10, 97, 
	-95, 10, 10, 114, 10, 105, 10, 111, 
	10, 58, 10, 110, 10, 116, 10, 101, 
	10, 120, 10, 116, 10, 97, 10, 100, 
	10, 97, 111, 10, 32, 115, 10, 32, 
	110, 115, 10, 116, -61, 10, 97, -93, 
	10, 10, 111, 10, 113, 10, 117, 10, 
	101, 10, 109, 10, 97, 10, 32, 10, 
	100, 10, 111, 10, 32, 10, 67, 10, 
	101, 10, 117, 10, 110, 10, 99, 10, 
	105, 10, 111, 10, 110, 10, 97, 10, 
	108, 10, 105, 10, 100, 10, 97, 10, 
	100, 10, 101, 10, 97, 10, 115, 10, 
	117, 10, 97, 10, 110, 10, 100, 110, 
	116, 101, 120, 116, 111, 58, 10, 10, 
	10, 32, 35, 37, 42, 64, 67, 68, 
	69, 70, 77, 81, 9, 13, 10, 95, 
	10, 70, 10, 69, 10, 65, 10, 84, 
	10, 85, 10, 82, 10, 69, 10, 95, 
	10, 69, 10, 78, 10, 68, 10, 95, 
	10, 37, 10, 32, 10, 101, 10, 110, 
	-61, 10, 97, -95, 10, 10, 114, 10, 
	105, 10, 111, 10, 58, 10, 97, 10, 
	100, 10, 97, 111, 10, 32, 115, 10, 
	32, 110, 115, 10, 116, -61, 10, 97, 
	-93, 10, 10, 111, 10, 113, 10, 117, 
	10, 101, 10, 109, 10, 97, 10, 32, 
	10, 100, 10, 111, 10, 32, 10, 67, 
	10, 117, 10, 110, 10, 99, 10, 105, 
	10, 111, 10, 110, 10, 97, 10, 108, 
	10, 105, 10, 100, 10, 97, 10, 100, 
	10, 101, 10, 97, 10, 115, 10, 117, 
	10, 97, 10, 110, 10, 100, 0
};

static const char _lexer_single_lengths[] = {
	0, 15, 1, 1, 14, 1, 1, 2, 
	2, 3, 3, 3, 3, 2, 2, 2, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 2, 3, 5, 3, 2, 1, 2, 
	1, 1, 1, 1, 1, 1, 1, 12, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 14, 
	1, 1, 2, 2, 4, 1, 2, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 2, 1, 1, 
	1, 1, 1, 1, 1, 12, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 3, 
	2, 2, 2, 2, 2, 2, 2, 3, 
	3, 3, 2, 3, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 5, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 8, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	3, 2, 3, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 3, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 1, 1, 1, 1, 
	1, 1, 2, 4, 3, 2, 4, 14, 
	3, 2, 3, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 3, 
	3, 4, 2, 3, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 12, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 3, 
	2, 2, 2, 2, 2, 2, 2, 3, 
	3, 4, 2, 3, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 0
};

static const char _lexer_range_lengths[] = {
	0, 1, 0, 0, 1, 0, 0, 0, 
	0, 1, 1, 1, 1, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 1, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 0, 0, 0, 0, 0, 
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
	0, 0, 1, 1, 0, 0, 1, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0
};

static const short _lexer_index_offsets[] = {
	0, 0, 17, 19, 21, 37, 39, 41, 
	44, 47, 52, 57, 62, 67, 71, 75, 
	78, 80, 82, 84, 86, 88, 90, 92, 
	94, 96, 98, 100, 102, 104, 106, 108, 
	110, 112, 115, 120, 127, 132, 135, 137, 
	140, 142, 144, 146, 148, 150, 152, 154, 
	168, 171, 174, 177, 180, 183, 186, 189, 
	192, 195, 198, 201, 204, 207, 210, 213, 
	229, 231, 233, 236, 239, 244, 246, 249, 
	251, 253, 255, 257, 259, 261, 263, 265, 
	267, 269, 271, 273, 275, 277, 280, 282, 
	284, 286, 288, 290, 292, 294, 308, 311, 
	314, 317, 320, 323, 326, 329, 332, 335, 
	338, 341, 344, 347, 350, 353, 356, 359, 
	363, 366, 369, 372, 375, 378, 381, 384, 
	388, 392, 396, 399, 403, 406, 409, 412, 
	415, 418, 421, 424, 427, 430, 433, 436, 
	439, 442, 445, 448, 451, 454, 457, 460, 
	463, 466, 468, 470, 472, 474, 476, 478, 
	480, 482, 484, 491, 494, 497, 500, 503, 
	506, 509, 512, 515, 518, 521, 524, 527, 
	530, 533, 535, 537, 539, 541, 543, 545, 
	547, 549, 551, 553, 555, 557, 559, 561, 
	563, 565, 575, 578, 581, 584, 587, 590, 
	593, 596, 599, 602, 605, 608, 611, 614, 
	617, 621, 624, 628, 631, 634, 637, 640, 
	643, 646, 649, 652, 655, 658, 662, 665, 
	668, 671, 674, 677, 680, 683, 686, 689, 
	692, 695, 698, 701, 704, 707, 710, 713, 
	716, 719, 722, 725, 728, 731, 734, 737, 
	740, 743, 746, 749, 752, 754, 756, 758, 
	760, 762, 764, 768, 774, 778, 781, 787, 
	803, 807, 810, 814, 817, 820, 823, 826, 
	829, 832, 835, 838, 841, 844, 847, 850, 
	854, 858, 863, 866, 870, 873, 876, 879, 
	882, 885, 888, 891, 894, 897, 900, 903, 
	906, 909, 912, 915, 918, 921, 924, 927, 
	930, 933, 936, 939, 942, 945, 948, 951, 
	954, 957, 960, 963, 966, 968, 970, 972, 
	974, 976, 978, 980, 982, 984, 998, 1001, 
	1004, 1007, 1010, 1013, 1016, 1019, 1022, 1025, 
	1028, 1031, 1034, 1037, 1040, 1043, 1046, 1049, 
	1053, 1056, 1059, 1062, 1065, 1068, 1071, 1074, 
	1078, 1082, 1087, 1090, 1094, 1097, 1100, 1103, 
	1106, 1109, 1112, 1115, 1118, 1121, 1124, 1127, 
	1130, 1133, 1136, 1139, 1142, 1145, 1148, 1151, 
	1154, 1157, 1160, 1163, 1166, 1169, 1172, 1175, 
	1178, 1181, 1184, 1187
};

static const short _lexer_trans_targs[] = {
	2, 4, 4, 5, 15, 17, 31, 34, 
	37, 64, 68, 169, 244, 246, 250, 4, 
	0, 3, 0, 4, 0, 4, 4, 5, 
	15, 17, 31, 34, 37, 64, 68, 169, 
	244, 246, 250, 4, 0, 6, 0, 7, 
	0, 9, 8, 8, 9, 8, 8, 10, 
	10, 11, 10, 10, 10, 10, 11, 10, 
	10, 10, 10, 12, 10, 10, 10, 10, 
	13, 10, 10, 4, 14, 14, 0, 4, 
	14, 14, 0, 4, 16, 15, 4, 0, 
	18, 0, 19, 0, 20, 0, 21, 0, 
	22, 0, 23, 0, 24, 0, 25, 0, 
	26, 0, 27, 0, 28, 0, 29, 0, 
	30, 0, 379, 0, 32, 0, 0, 33, 
	4, 16, 33, 0, 0, 0, 0, 35, 
	36, 4, 36, 36, 34, 35, 35, 4, 
	36, 34, 36, 0, 38, 308, 0, 39, 
	0, 40, 41, 0, 41, 0, 42, 0, 
	43, 0, 44, 0, 45, 0, 47, 46, 
	47, 46, 47, 47, 4, 48, 62, 4, 
	256, 269, 273, 289, 302, 304, 47, 46, 
	47, 49, 46, 47, 50, 46, 47, 51, 
	46, 47, 52, 46, 47, 53, 46, 47, 
	54, 46, 47, 55, 46, 47, 56, 46, 
	47, 57, 46, 47, 58, 46, 47, 59, 
	46, 47, 60, 46, 47, 61, 46, 47, 
	4, 46, 47, 63, 46, 4, 4, 5, 
	15, 17, 31, 34, 37, 64, 68, 169, 
	244, 246, 250, 4, 0, 65, 0, 66, 
	0, 67, 67, 0, 32, 31, 0, 32, 
	69, 73, 145, 0, 70, 0, 71, 72, 
	0, 72, 0, 31, 0, 74, 0, 75, 
	0, 76, 0, 77, 0, 78, 0, 79, 
	0, 80, 0, 81, 0, 82, 0, 83, 
	0, 84, 0, 85, 0, 86, 87, 0, 
	87, 0, 88, 0, 89, 0, 90, 0, 
	91, 0, 93, 92, 93, 92, 93, 93, 
	4, 94, 108, 4, 109, 117, 121, 126, 
	139, 141, 93, 92, 93, 95, 92, 93, 
	96, 92, 93, 97, 92, 93, 98, 92, 
	93, 99, 92, 93, 100, 92, 93, 101, 
	92, 93, 102, 92, 93, 103, 92, 93, 
	104, 92, 93, 105, 92, 93, 106, 92, 
	93, 107, 92, 93, 4, 92, 93, 63, 
	92, 93, 110, 92, 93, 111, 92, 112, 
	93, 113, 92, 113, 93, 92, 93, 114, 
	92, 93, 115, 92, 93, 116, 92, 93, 
	63, 92, 93, 118, 92, 93, 119, 92, 
	93, 120, 120, 92, 93, 63, 108, 92, 
	93, 63, 122, 92, 93, 123, 92, 124, 
	93, 125, 92, 125, 93, 92, 93, 108, 
	92, 93, 127, 92, 93, 128, 92, 93, 
	129, 92, 93, 130, 92, 93, 131, 92, 
	93, 132, 92, 93, 133, 92, 93, 134, 
	92, 93, 135, 92, 93, 136, 92, 93, 
	137, 92, 93, 138, 92, 93, 116, 92, 
	93, 140, 92, 93, 108, 92, 93, 142, 
	92, 93, 143, 92, 93, 144, 92, 93, 
	125, 92, 146, 0, 147, 0, 148, 0, 
	149, 0, 150, 0, 151, 0, 152, 0, 
	154, 153, 154, 153, 154, 154, 4, 155, 
	4, 154, 153, 154, 156, 153, 154, 157, 
	153, 154, 158, 153, 154, 159, 153, 154, 
	160, 153, 154, 161, 153, 154, 162, 153, 
	154, 163, 153, 154, 164, 153, 154, 165, 
	153, 154, 166, 153, 154, 167, 153, 154, 
	168, 153, 154, 63, 153, 170, 0, 171, 
	0, 172, 0, 173, 0, 174, 0, 175, 
	0, 176, 0, 177, 0, 178, 0, 179, 
	0, 180, 0, 181, 0, 182, 0, 183, 
	0, 185, 184, 185, 184, 185, 185, 4, 
	186, 4, 200, 213, 231, 185, 184, 185, 
	187, 184, 185, 188, 184, 185, 189, 184, 
	185, 190, 184, 185, 191, 184, 185, 192, 
	184, 185, 193, 184, 185, 194, 184, 185, 
	195, 184, 185, 196, 184, 185, 197, 184, 
	185, 198, 184, 185, 199, 184, 185, 4, 
	184, 185, 201, 208, 184, 185, 202, 184, 
	203, 185, 204, 184, 204, 185, 184, 185, 
	205, 184, 185, 206, 184, 185, 207, 184, 
	185, 63, 184, 185, 209, 184, 185, 210, 
	184, 185, 211, 184, 185, 212, 184, 185, 
	206, 184, 185, 214, 225, 184, 185, 215, 
	184, 185, 216, 184, 185, 217, 184, 185, 
	218, 184, 185, 219, 184, 185, 220, 184, 
	185, 221, 184, 185, 222, 184, 185, 223, 
	184, 185, 224, 184, 185, 201, 184, 185, 
	226, 184, 185, 227, 184, 185, 228, 184, 
	185, 229, 184, 185, 230, 184, 185, 207, 
	184, 185, 232, 184, 185, 233, 184, 185, 
	234, 184, 185, 235, 184, 185, 236, 184, 
	185, 237, 184, 185, 238, 184, 185, 239, 
	184, 185, 240, 184, 185, 241, 184, 185, 
	242, 184, 185, 243, 184, 185, 207, 184, 
	245, 0, 31, 0, 247, 0, 248, 0, 
	249, 0, 72, 0, 250, 251, 250, 0, 
	255, 254, 253, 251, 254, 252, 0, 253, 
	251, 252, 0, 253, 252, 255, 254, 253, 
	251, 254, 252, 255, 255, 5, 15, 17, 
	31, 34, 37, 64, 68, 169, 244, 246, 
	250, 255, 0, 47, 257, 264, 46, 47, 
	258, 46, 259, 47, 260, 46, 260, 47, 
	46, 47, 261, 46, 47, 262, 46, 47, 
	263, 46, 47, 63, 46, 47, 265, 46, 
	47, 266, 46, 47, 267, 46, 47, 268, 
	46, 47, 262, 46, 47, 270, 46, 47, 
	271, 46, 47, 272, 272, 46, 47, 63, 
	62, 46, 47, 63, 274, 278, 46, 47, 
	275, 46, 276, 47, 277, 46, 277, 47, 
	46, 47, 62, 46, 47, 279, 46, 47, 
	280, 46, 47, 281, 46, 47, 282, 46, 
	47, 283, 46, 47, 284, 46, 47, 285, 
	46, 47, 286, 46, 47, 287, 46, 47, 
	288, 46, 47, 257, 46, 47, 290, 46, 
	47, 291, 46, 47, 292, 46, 47, 293, 
	46, 47, 294, 46, 47, 295, 46, 47, 
	296, 46, 47, 297, 46, 47, 298, 46, 
	47, 299, 46, 47, 300, 46, 47, 301, 
	46, 47, 263, 46, 47, 303, 46, 47, 
	62, 46, 47, 305, 46, 47, 306, 46, 
	47, 307, 46, 47, 277, 46, 309, 0, 
	310, 0, 311, 0, 312, 0, 313, 0, 
	314, 0, 315, 0, 317, 316, 317, 316, 
	317, 317, 4, 318, 332, 4, 333, 341, 
	345, 360, 373, 375, 317, 316, 317, 319, 
	316, 317, 320, 316, 317, 321, 316, 317, 
	322, 316, 317, 323, 316, 317, 324, 316, 
	317, 325, 316, 317, 326, 316, 317, 327, 
	316, 317, 328, 316, 317, 329, 316, 317, 
	330, 316, 317, 331, 316, 317, 4, 316, 
	317, 63, 316, 317, 334, 316, 317, 335, 
	316, 336, 317, 337, 316, 337, 317, 316, 
	317, 338, 316, 317, 339, 316, 317, 340, 
	316, 317, 63, 316, 317, 342, 316, 317, 
	343, 316, 317, 344, 344, 316, 317, 63, 
	332, 316, 317, 63, 346, 350, 316, 317, 
	347, 316, 348, 317, 349, 316, 349, 317, 
	316, 317, 332, 316, 317, 351, 316, 317, 
	352, 316, 317, 353, 316, 317, 354, 316, 
	317, 355, 316, 317, 356, 316, 317, 357, 
	316, 317, 358, 316, 317, 359, 316, 317, 
	333, 316, 317, 361, 316, 317, 362, 316, 
	317, 363, 316, 317, 364, 316, 317, 365, 
	316, 317, 366, 316, 317, 367, 316, 317, 
	368, 316, 317, 369, 316, 317, 370, 316, 
	317, 371, 316, 317, 372, 316, 317, 340, 
	316, 317, 374, 316, 317, 332, 316, 317, 
	376, 316, 317, 377, 316, 317, 378, 316, 
	317, 349, 316, 0, 0
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
	0, 1, 0, 43, 0, 0, 43, 0, 
	43, 0, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 140, 57, 
	54, 0, 54, 0, 75, 33, 84, 75, 
	84, 84, 84, 84, 84, 84, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	17, 0, 54, 17, 0, 126, 31, 60, 
	57, 31, 63, 57, 63, 63, 63, 63, 
	63, 63, 66, 31, 43, 0, 43, 0, 
	43, 0, 0, 43, 0, 0, 43, 0, 
	0, 0, 0, 43, 0, 43, 0, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 140, 57, 54, 0, 54, 0, 
	78, 33, 84, 78, 84, 84, 84, 84, 
	84, 84, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 19, 0, 54, 19, 
	0, 54, 0, 0, 54, 0, 0, 0, 
	54, 0, 0, 0, 54, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	19, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 0, 54, 19, 0, 0, 
	54, 19, 0, 0, 54, 0, 0, 0, 
	54, 0, 0, 0, 54, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	140, 57, 54, 0, 54, 0, 81, 84, 
	81, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 21, 0, 0, 43, 0, 
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
	0, 54, 0, 0, 0, 54, 0, 0, 
	0, 54, 0, 0, 0, 54, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 13, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 0, 0, 43, 
	54, 37, 37, 87, 37, 37, 43, 0, 
	39, 0, 43, 0, 0, 54, 0, 0, 
	39, 0, 0, 54, 0, 93, 90, 41, 
	96, 90, 96, 96, 96, 96, 96, 96, 
	99, 0, 43, 54, 0, 0, 0, 54, 
	0, 0, 0, 54, 0, 0, 0, 54, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 17, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 0, 54, 17, 
	0, 0, 54, 17, 0, 0, 0, 54, 
	0, 0, 0, 54, 0, 0, 0, 54, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 140, 57, 54, 0, 
	54, 0, 72, 33, 84, 72, 84, 84, 
	84, 84, 84, 84, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 15, 0, 
	54, 15, 0, 54, 0, 0, 54, 0, 
	0, 0, 54, 0, 0, 0, 54, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 15, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 0, 54, 15, 
	0, 0, 54, 15, 0, 0, 0, 54, 
	0, 0, 0, 54, 0, 0, 0, 54, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 0, 0
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
	43, 43, 43, 43
};

static const int lexer_start = 1;
static const int lexer_first_final = 379;
static const int lexer_error = 0;

static const int lexer_en_main = 1;


#line 258 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"

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
    
    
#line 953 "ext/gherkin_lexer_pt/gherkin_lexer_pt.c"
	{
	cs = lexer_start;
	}

#line 425 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
    
#line 960 "ext/gherkin_lexer_pt/gherkin_lexer_pt.c"
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
#line 83 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
		MARK(content_start, p);
    lexer->current_line = lexer->line_number;
    lexer->start_col = lexer->content_start - lexer->last_newline - (lexer->keyword_end - lexer->keyword_start) + 2;
  }
	break;
	case 1:
#line 89 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    MARK(content_start, p);
  }
	break;
	case 2:
#line 93 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    lexer->current_line = lexer->line_number;
    lexer->start_col = p - data - lexer->last_newline;
  }
	break;
	case 3:
#line 98 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    int len = LEN(content_start, PTR_TO(final_newline));
    int type_len = LEN(docstring_content_type_start, PTR_TO(docstring_content_type_end));

    if (len < 0) len = 0;
    if (type_len < 0) len = 0;

    store_docstring_content(listener, lexer->start_col, PTR_TO(docstring_content_type_start), type_len, PTR_TO(content_start), len, lexer->current_line);
  }
	break;
	case 4:
#line 108 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{ 
    MARK(docstring_content_type_start, p);
  }
	break;
	case 5:
#line 112 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{ 
    MARK(docstring_content_type_end, p);
  }
	break;
	case 6:
#line 116 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    STORE_KW_END_CON(feature);
  }
	break;
	case 7:
#line 120 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    STORE_KW_END_CON(background);
  }
	break;
	case 8:
#line 124 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    STORE_KW_END_CON(scenario);
  }
	break;
	case 9:
#line 128 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    STORE_KW_END_CON(scenario_outline);
  }
	break;
	case 10:
#line 132 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    STORE_KW_END_CON(examples);
  }
	break;
	case 11:
#line 136 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    store_kw_con(listener, "step",
      PTR_TO(keyword_start), LEN(keyword_start, PTR_TO(keyword_end)),
      PTR_TO(content_start), LEN(content_start, p), 
      lexer->current_line);
  }
	break;
	case 12:
#line 143 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    STORE_ATTR(comment);
    lexer->mark = 0;
  }
	break;
	case 13:
#line 148 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    STORE_ATTR(tag);
    lexer->mark = 0;
  }
	break;
	case 14:
#line 153 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    lexer->line_number += 1;
    MARK(final_newline, p);
  }
	break;
	case 15:
#line 158 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    MARK(last_newline, p + 1);
  }
	break;
	case 16:
#line 162 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    if (lexer->mark == 0) {
      MARK(mark, p);
    }
  }
	break;
	case 17:
#line 168 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    MARK(keyword_end, p);
    MARK(keyword_start, PTR_TO(mark));
    MARK(content_start, p + 1);
    lexer->mark = 0;
  }
	break;
	case 18:
#line 175 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    MARK(content_end, p);
  }
	break;
	case 19:
#line 179 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    p = p - 1;
    lexer->current_line = lexer->line_number;
    current_row = rb_ary_new();
  }
	break;
	case 20:
#line 185 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
		MARK(content_start, p);
  }
	break;
	case 21:
#line 189 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
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
#line 203 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
	{
    rb_funcall(listener, rb_intern("row"), 2, current_row, INT2FIX(lexer->current_line));
  }
	break;
	case 23:
#line 207 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
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
#line 1250 "ext/gherkin_lexer_pt/gherkin_lexer_pt.c"
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
#line 207 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"
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
#line 1313 "ext/gherkin_lexer_pt/gherkin_lexer_pt.c"
		}
	}
	}

	_out: {}
	}

#line 426 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/pt.c.rl"

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

void Init_gherkin_lexer_pt()
{
  mGherkin = rb_define_module("Gherkin");
  mGherkinLexer = rb_define_module_under(mGherkin, "Lexer");
  rb_eGherkinLexingError = rb_const_get(mGherkinLexer, rb_intern("LexingError"));

  mCLexer = rb_define_module_under(mGherkin, "CLexer");
  cI18nLexer = rb_define_class_under(mCLexer, "Pt", rb_cObject);
  rb_define_alloc_func(cI18nLexer, CLexer_alloc);
  rb_define_method(cI18nLexer, "initialize", CLexer_init, 1);
  rb_define_method(cI18nLexer, "scan", CLexer_scan, 1);
}

