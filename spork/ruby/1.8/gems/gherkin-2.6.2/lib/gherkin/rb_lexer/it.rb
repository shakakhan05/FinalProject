
# line 1 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
require 'gherkin/lexer/i18n_lexer'

module Gherkin
  module RbLexer
    class It #:nodoc:
      
# line 123 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"

 
      def initialize(listener)
        @listener = listener
        
# line 16 "lib/gherkin/rb_lexer/it.rb"
class << self
	attr_accessor :_lexer_actions
	private :_lexer_actions, :_lexer_actions=
end
self._lexer_actions = [
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7, 1, 8, 1, 9, 1, 10, 1, 
	11, 1, 12, 1, 13, 1, 16, 1, 
	17, 1, 18, 1, 19, 1, 20, 1, 
	21, 1, 22, 1, 23, 2, 2, 18, 
	2, 3, 4, 2, 13, 0, 2, 14, 
	15, 2, 17, 0, 2, 17, 1, 2, 
	17, 16, 2, 17, 19, 2, 18, 6, 
	2, 18, 7, 2, 18, 8, 2, 18, 
	9, 2, 18, 10, 2, 18, 16, 2, 
	20, 21, 2, 22, 0, 2, 22, 1, 
	2, 22, 16, 2, 22, 19, 3, 4, 
	14, 15, 3, 5, 14, 15, 3, 11, 
	14, 15, 3, 12, 14, 15, 3, 13, 
	14, 15, 3, 14, 15, 18, 3, 17, 
	14, 15, 4, 2, 14, 15, 18, 4, 
	3, 4, 14, 15, 4, 17, 0, 14, 
	15
]

class << self
	attr_accessor :_lexer_key_offsets
	private :_lexer_key_offsets, :_lexer_key_offsets=
end
self._lexer_key_offsets = [
	0, 0, 19, 20, 21, 39, 40, 41, 
	43, 45, 50, 55, 60, 65, 69, 73, 
	75, 76, 77, 78, 79, 80, 81, 82, 
	83, 84, 85, 86, 87, 88, 89, 90, 
	91, 92, 94, 99, 106, 111, 112, 113, 
	114, 115, 116, 117, 118, 119, 120, 121, 
	122, 123, 124, 125, 126, 141, 143, 145, 
	147, 149, 151, 153, 155, 157, 159, 161, 
	163, 165, 167, 169, 171, 189, 190, 191, 
	195, 197, 198, 199, 200, 201, 202, 203, 
	204, 211, 213, 215, 217, 219, 221, 223, 
	225, 227, 229, 231, 233, 235, 237, 238, 
	239, 240, 241, 242, 243, 244, 245, 246, 
	247, 248, 249, 250, 251, 252, 263, 265, 
	267, 269, 271, 273, 275, 277, 279, 281, 
	283, 285, 287, 289, 291, 293, 295, 297, 
	299, 301, 303, 305, 307, 309, 311, 313, 
	315, 317, 319, 321, 323, 325, 327, 329, 
	331, 333, 335, 337, 339, 341, 343, 346, 
	348, 350, 352, 354, 356, 358, 360, 362, 
	364, 366, 368, 370, 372, 374, 376, 378, 
	380, 381, 382, 383, 384, 385, 386, 388, 
	389, 390, 391, 392, 393, 394, 395, 396, 
	412, 414, 416, 418, 420, 422, 424, 426, 
	428, 430, 432, 434, 436, 438, 440, 442, 
	444, 446, 448, 450, 452, 454, 456, 458, 
	460, 462, 464, 466, 468, 470, 472, 477, 
	479, 481, 483, 485, 487, 489, 491, 493, 
	495, 497, 499, 501, 503, 505, 507, 509, 
	511, 513, 516, 518, 520, 522, 524, 526, 
	528, 530, 532, 534, 536, 538, 540, 542, 
	544, 546, 548, 550, 551, 552, 553, 554, 
	555, 556, 557, 558, 559, 560, 561, 562, 
	563, 564, 565, 566, 567, 568, 569, 570, 
	571, 586, 588, 590, 592, 594, 596, 598, 
	600, 602, 604, 606, 608, 610, 612, 614, 
	616, 618, 620, 622, 624, 626, 628, 630, 
	635, 637, 639, 641, 643, 645, 647, 649, 
	651, 653, 655, 657, 659, 661, 663, 665, 
	667, 669, 671, 673, 675, 677, 679, 681, 
	683, 685, 689, 695, 698, 700, 706, 724, 
	726, 728, 730, 732, 734, 736, 738, 743, 
	745, 747, 749, 751, 753, 755, 757, 759, 
	761, 763, 765, 767, 769, 771, 773, 775, 
	777, 779, 781, 784, 786, 788, 790, 792, 
	794, 796, 798, 800, 802, 804, 806, 808, 
	810, 812, 814, 816, 818, 820
]

class << self
	attr_accessor :_lexer_trans_keys
	private :_lexer_trans_keys, :_lexer_trans_keys=
end
self._lexer_trans_keys = [
	-17, 10, 32, 34, 35, 37, 42, 64, 
	65, 67, 68, 69, 70, 77, 81, 83, 
	124, 9, 13, -69, -65, 10, 32, 34, 
	35, 37, 42, 64, 65, 67, 68, 69, 
	70, 77, 81, 83, 124, 9, 13, 34, 
	34, 10, 13, 10, 13, 10, 32, 34, 
	9, 13, 10, 32, 34, 9, 13, 10, 
	32, 34, 9, 13, 10, 32, 34, 9, 
	13, 10, 32, 9, 13, 10, 32, 9, 
	13, 10, 13, 10, 95, 70, 69, 65, 
	84, 85, 82, 69, 95, 69, 78, 68, 
	95, 37, 32, 10, 10, 13, 13, 32, 
	64, 9, 10, 9, 10, 13, 32, 64, 
	11, 12, 10, 32, 64, 9, 13, 108, 
	108, 111, 114, 97, 111, 110, 116, 101, 
	115, 116, 111, 58, 10, 10, 10, 32, 
	35, 37, 42, 64, 65, 68, 69, 70, 
	77, 81, 83, 9, 13, 10, 95, 10, 
	70, 10, 69, 10, 65, 10, 84, 10, 
	85, 10, 82, 10, 69, 10, 95, 10, 
	69, 10, 78, 10, 68, 10, 95, 10, 
	37, 10, 32, 10, 32, 34, 35, 37, 
	42, 64, 65, 67, 68, 69, 70, 77, 
	81, 83, 124, 9, 13, 97, 116, 97, 
	101, 105, 111, 32, 115, 101, 109, 112, 
	105, 58, 10, 10, 10, 32, 35, 70, 
	124, 9, 13, 10, 117, 10, 110, 10, 
	122, 10, 105, 10, 111, 10, 110, 10, 
	97, 10, 108, 10, 105, 10, 116, -61, 
	10, -96, 10, 10, 58, 117, 110, 122, 
	105, 111, 110, 97, 108, 105, 116, -61, 
	-96, 58, 10, 10, 10, 32, 35, 37, 
	64, 67, 69, 70, 83, 9, 13, 10, 
	95, 10, 70, 10, 69, 10, 65, 10, 
	84, 10, 85, 10, 82, 10, 69, 10, 
	95, 10, 69, 10, 78, 10, 68, 10, 
	95, 10, 37, 10, 111, 10, 110, 10, 
	116, 10, 101, 10, 115, 10, 116, 10, 
	111, 10, 58, 10, 115, 10, 101, 10, 
	109, 10, 112, 10, 105, 10, 117, 10, 
	110, 10, 122, 10, 105, 10, 111, 10, 
	110, 10, 97, 10, 108, 10, 105, 10, 
	116, -61, 10, -96, 10, 10, 99, 10, 
	101, 104, 10, 110, 10, 97, 10, 114, 
	10, 105, 10, 101, 10, 109, 10, 97, 
	10, 32, 10, 100, 10, 101, 10, 108, 
	10, 108, 10, 111, 10, 32, 10, 115, 
	10, 99, 10, 101, 117, 97, 110, 100, 
	111, 99, 101, 104, 110, 97, 114, 105, 
	111, 58, 10, 10, 10, 32, 35, 37, 
	42, 64, 65, 67, 68, 69, 70, 77, 
	81, 83, 9, 13, 10, 95, 10, 70, 
	10, 69, 10, 65, 10, 84, 10, 85, 
	10, 82, 10, 69, 10, 95, 10, 69, 
	10, 78, 10, 68, 10, 95, 10, 37, 
	10, 32, 10, 108, 10, 108, 10, 111, 
	10, 114, 10, 97, 10, 111, 10, 110, 
	10, 116, 10, 101, 10, 115, 10, 116, 
	10, 111, 10, 58, 10, 97, 10, 116, 
	10, 97, 101, 105, 111, 10, 117, 10, 
	110, 10, 122, 10, 105, 10, 111, 10, 
	110, 10, 97, 10, 108, 10, 105, 10, 
	116, -61, 10, -96, 10, 10, 117, 10, 
	97, 10, 110, 10, 100, 10, 111, 10, 
	99, 10, 101, 104, 10, 110, 10, 97, 
	10, 114, 10, 105, 10, 101, 10, 109, 
	10, 97, 10, 32, 10, 100, 10, 101, 
	10, 108, 10, 108, 10, 111, 10, 32, 
	10, 115, 10, 99, 10, 101, 101, 109, 
	97, 32, 100, 101, 108, 108, 111, 32, 
	115, 99, 101, 110, 97, 114, 105, 111, 
	58, 10, 10, 10, 32, 35, 37, 42, 
	64, 65, 68, 69, 70, 77, 81, 83, 
	9, 13, 10, 95, 10, 70, 10, 69, 
	10, 65, 10, 84, 10, 85, 10, 82, 
	10, 69, 10, 95, 10, 69, 10, 78, 
	10, 68, 10, 95, 10, 37, 10, 32, 
	10, 108, 10, 108, 10, 111, 10, 114, 
	10, 97, 10, 97, 10, 116, 10, 97, 
	101, 105, 111, 10, 117, 10, 110, 10, 
	122, 10, 105, 10, 111, 10, 110, 10, 
	97, 10, 108, 10, 105, 10, 116, -61, 
	10, -96, 10, 10, 58, 10, 117, 10, 
	97, 10, 110, 10, 100, 10, 111, 10, 
	99, 10, 101, 10, 110, 10, 97, 10, 
	114, 10, 105, 10, 111, 32, 124, 9, 
	13, 10, 32, 92, 124, 9, 13, 10, 
	92, 124, 10, 92, 10, 32, 92, 124, 
	9, 13, 10, 32, 34, 35, 37, 42, 
	64, 65, 67, 68, 69, 70, 77, 81, 
	83, 124, 9, 13, 10, 108, 10, 108, 
	10, 111, 10, 114, 10, 97, 10, 97, 
	10, 116, 10, 97, 101, 105, 111, 10, 
	117, 10, 110, 10, 122, 10, 105, 10, 
	111, 10, 110, 10, 97, 10, 108, 10, 
	105, 10, 116, -61, 10, -96, 10, 10, 
	58, 10, 117, 10, 97, 10, 110, 10, 
	100, 10, 111, 10, 99, 10, 101, 104, 
	10, 110, 10, 97, 10, 114, 10, 105, 
	10, 111, 10, 101, 10, 109, 10, 97, 
	10, 32, 10, 100, 10, 101, 10, 108, 
	10, 108, 10, 111, 10, 32, 10, 115, 
	10, 99, 10, 101, 0
]

class << self
	attr_accessor :_lexer_single_lengths
	private :_lexer_single_lengths, :_lexer_single_lengths=
end
self._lexer_single_lengths = [
	0, 17, 1, 1, 16, 1, 1, 2, 
	2, 3, 3, 3, 3, 2, 2, 2, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 2, 3, 5, 3, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 13, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 16, 1, 1, 4, 
	2, 1, 1, 1, 1, 1, 1, 1, 
	5, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 9, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 3, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	1, 1, 1, 1, 1, 1, 2, 1, 
	1, 1, 1, 1, 1, 1, 1, 14, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 5, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 3, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	13, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 5, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 4, 3, 2, 4, 16, 2, 
	2, 2, 2, 2, 2, 2, 5, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 3, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 0
]

class << self
	attr_accessor :_lexer_range_lengths
	private :_lexer_range_lengths, :_lexer_range_lengths=
end
self._lexer_range_lengths = [
	0, 1, 0, 0, 1, 0, 0, 0, 
	0, 1, 1, 1, 1, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 1, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 0, 0, 0, 0, 0, 0, 0, 
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
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
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
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 1, 1, 0, 0, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0
]

class << self
	attr_accessor :_lexer_index_offsets
	private :_lexer_index_offsets, :_lexer_index_offsets=
end
self._lexer_index_offsets = [
	0, 0, 19, 21, 23, 41, 43, 45, 
	48, 51, 56, 61, 66, 71, 75, 79, 
	82, 84, 86, 88, 90, 92, 94, 96, 
	98, 100, 102, 104, 106, 108, 110, 112, 
	114, 116, 119, 124, 131, 136, 138, 140, 
	142, 144, 146, 148, 150, 152, 154, 156, 
	158, 160, 162, 164, 166, 181, 184, 187, 
	190, 193, 196, 199, 202, 205, 208, 211, 
	214, 217, 220, 223, 226, 244, 246, 248, 
	253, 256, 258, 260, 262, 264, 266, 268, 
	270, 277, 280, 283, 286, 289, 292, 295, 
	298, 301, 304, 307, 310, 313, 316, 318, 
	320, 322, 324, 326, 328, 330, 332, 334, 
	336, 338, 340, 342, 344, 346, 357, 360, 
	363, 366, 369, 372, 375, 378, 381, 384, 
	387, 390, 393, 396, 399, 402, 405, 408, 
	411, 414, 417, 420, 423, 426, 429, 432, 
	435, 438, 441, 444, 447, 450, 453, 456, 
	459, 462, 465, 468, 471, 474, 477, 481, 
	484, 487, 490, 493, 496, 499, 502, 505, 
	508, 511, 514, 517, 520, 523, 526, 529, 
	532, 534, 536, 538, 540, 542, 544, 547, 
	549, 551, 553, 555, 557, 559, 561, 563, 
	579, 582, 585, 588, 591, 594, 597, 600, 
	603, 606, 609, 612, 615, 618, 621, 624, 
	627, 630, 633, 636, 639, 642, 645, 648, 
	651, 654, 657, 660, 663, 666, 669, 675, 
	678, 681, 684, 687, 690, 693, 696, 699, 
	702, 705, 708, 711, 714, 717, 720, 723, 
	726, 729, 733, 736, 739, 742, 745, 748, 
	751, 754, 757, 760, 763, 766, 769, 772, 
	775, 778, 781, 784, 786, 788, 790, 792, 
	794, 796, 798, 800, 802, 804, 806, 808, 
	810, 812, 814, 816, 818, 820, 822, 824, 
	826, 841, 844, 847, 850, 853, 856, 859, 
	862, 865, 868, 871, 874, 877, 880, 883, 
	886, 889, 892, 895, 898, 901, 904, 907, 
	913, 916, 919, 922, 925, 928, 931, 934, 
	937, 940, 943, 946, 949, 952, 955, 958, 
	961, 964, 967, 970, 973, 976, 979, 982, 
	985, 988, 992, 998, 1002, 1005, 1011, 1029, 
	1032, 1035, 1038, 1041, 1044, 1047, 1050, 1056, 
	1059, 1062, 1065, 1068, 1071, 1074, 1077, 1080, 
	1083, 1086, 1089, 1092, 1095, 1098, 1101, 1104, 
	1107, 1110, 1113, 1117, 1120, 1123, 1126, 1129, 
	1132, 1135, 1138, 1141, 1144, 1147, 1150, 1153, 
	1156, 1159, 1162, 1165, 1168, 1171
]

class << self
	attr_accessor :_lexer_indicies
	private :_lexer_indicies, :_lexer_indicies=
end
self._lexer_indicies = [
	1, 3, 2, 4, 5, 6, 7, 8, 
	9, 10, 11, 12, 13, 14, 15, 16, 
	17, 2, 0, 18, 0, 2, 0, 3, 
	2, 4, 5, 6, 7, 8, 9, 10, 
	11, 12, 13, 14, 15, 16, 17, 2, 
	0, 19, 0, 20, 0, 22, 23, 21, 
	25, 26, 24, 29, 28, 30, 28, 27, 
	33, 32, 34, 32, 31, 33, 32, 35, 
	32, 31, 33, 32, 36, 32, 31, 38, 
	37, 37, 0, 3, 39, 39, 0, 41, 
	42, 40, 3, 0, 43, 0, 44, 0, 
	45, 0, 46, 0, 47, 0, 48, 0, 
	49, 0, 50, 0, 51, 0, 52, 0, 
	53, 0, 54, 0, 55, 0, 56, 0, 
	57, 0, 0, 58, 60, 61, 59, 0, 
	0, 0, 0, 62, 63, 64, 63, 63, 
	66, 65, 62, 3, 67, 8, 67, 0, 
	68, 0, 69, 0, 70, 0, 71, 0, 
	72, 0, 73, 0, 74, 0, 75, 0, 
	76, 0, 77, 0, 78, 0, 79, 0, 
	80, 0, 82, 81, 84, 83, 84, 85, 
	86, 87, 88, 86, 89, 90, 88, 91, 
	92, 93, 94, 85, 83, 84, 95, 83, 
	84, 96, 83, 84, 97, 83, 84, 98, 
	83, 84, 99, 83, 84, 100, 83, 84, 
	101, 83, 84, 102, 83, 84, 103, 83, 
	84, 104, 83, 84, 105, 83, 84, 106, 
	83, 84, 107, 83, 84, 108, 83, 84, 
	109, 83, 111, 110, 112, 113, 114, 115, 
	116, 117, 118, 119, 120, 121, 122, 123, 
	124, 125, 110, 0, 126, 0, 127, 0, 
	72, 72, 72, 72, 0, 57, 128, 0, 
	129, 0, 130, 0, 131, 0, 132, 0, 
	133, 0, 135, 134, 137, 136, 137, 138, 
	139, 140, 139, 138, 136, 137, 141, 136, 
	137, 142, 136, 137, 143, 136, 137, 144, 
	136, 137, 145, 136, 137, 146, 136, 137, 
	147, 136, 137, 148, 136, 137, 149, 136, 
	137, 150, 136, 151, 137, 136, 152, 137, 
	136, 137, 153, 136, 154, 0, 155, 0, 
	156, 0, 157, 0, 158, 0, 159, 0, 
	160, 0, 161, 0, 162, 0, 163, 0, 
	164, 0, 165, 0, 166, 0, 168, 167, 
	170, 169, 170, 171, 172, 173, 172, 174, 
	175, 176, 177, 171, 169, 170, 178, 169, 
	170, 179, 169, 170, 180, 169, 170, 181, 
	169, 170, 182, 169, 170, 183, 169, 170, 
	184, 169, 170, 185, 169, 170, 186, 169, 
	170, 187, 169, 170, 188, 169, 170, 189, 
	169, 170, 190, 169, 170, 191, 169, 170, 
	192, 169, 170, 193, 169, 170, 194, 169, 
	170, 195, 169, 170, 196, 169, 170, 197, 
	169, 170, 198, 169, 170, 199, 169, 170, 
	200, 169, 170, 201, 169, 170, 202, 169, 
	170, 203, 169, 170, 198, 169, 170, 204, 
	169, 170, 205, 169, 170, 206, 169, 170, 
	207, 169, 170, 208, 169, 170, 209, 169, 
	170, 210, 169, 170, 211, 169, 170, 212, 
	169, 170, 213, 169, 214, 170, 169, 198, 
	170, 169, 170, 215, 169, 170, 216, 217, 
	169, 170, 218, 169, 170, 219, 169, 170, 
	220, 169, 170, 197, 169, 170, 221, 169, 
	170, 222, 169, 170, 223, 169, 170, 224, 
	169, 170, 225, 169, 170, 226, 169, 170, 
	227, 169, 170, 228, 169, 170, 229, 169, 
	170, 230, 169, 170, 231, 169, 170, 232, 
	169, 170, 216, 169, 233, 0, 234, 0, 
	235, 0, 236, 0, 72, 0, 237, 0, 
	238, 239, 0, 240, 0, 241, 0, 242, 
	0, 243, 0, 244, 0, 245, 0, 247, 
	246, 249, 248, 249, 250, 251, 252, 253, 
	251, 254, 255, 256, 253, 257, 258, 259, 
	260, 250, 248, 249, 261, 248, 249, 262, 
	248, 249, 263, 248, 249, 264, 248, 249, 
	265, 248, 249, 266, 248, 249, 267, 248, 
	249, 268, 248, 249, 269, 248, 249, 270, 
	248, 249, 271, 248, 249, 272, 248, 249, 
	273, 248, 249, 274, 248, 249, 275, 248, 
	249, 276, 248, 249, 277, 248, 249, 278, 
	248, 249, 279, 248, 249, 280, 248, 249, 
	281, 248, 249, 282, 248, 249, 283, 248, 
	249, 284, 248, 249, 285, 248, 249, 286, 
	248, 249, 287, 248, 249, 275, 248, 249, 
	288, 248, 249, 289, 248, 249, 280, 280, 
	280, 280, 248, 249, 290, 248, 249, 291, 
	248, 249, 292, 248, 249, 293, 248, 249, 
	294, 248, 249, 295, 248, 249, 296, 248, 
	249, 297, 248, 249, 298, 248, 249, 299, 
	248, 300, 249, 248, 287, 249, 248, 249, 
	301, 248, 249, 302, 248, 249, 303, 248, 
	249, 304, 248, 249, 280, 248, 249, 305, 
	248, 249, 306, 307, 248, 249, 308, 248, 
	249, 309, 248, 249, 310, 248, 249, 286, 
	248, 249, 311, 248, 249, 312, 248, 249, 
	313, 248, 249, 314, 248, 249, 315, 248, 
	249, 316, 248, 249, 317, 248, 249, 318, 
	248, 249, 319, 248, 249, 320, 248, 249, 
	321, 248, 249, 322, 248, 249, 306, 248, 
	323, 0, 324, 0, 325, 0, 326, 0, 
	327, 0, 328, 0, 329, 0, 330, 0, 
	331, 0, 332, 0, 333, 0, 334, 0, 
	335, 0, 336, 0, 337, 0, 338, 0, 
	339, 0, 340, 0, 341, 0, 343, 342, 
	345, 344, 345, 346, 347, 348, 349, 347, 
	350, 351, 349, 352, 353, 354, 355, 346, 
	344, 345, 356, 344, 345, 357, 344, 345, 
	358, 344, 345, 359, 344, 345, 360, 344, 
	345, 361, 344, 345, 362, 344, 345, 363, 
	344, 345, 364, 344, 345, 365, 344, 345, 
	366, 344, 345, 367, 344, 345, 368, 344, 
	345, 369, 344, 345, 370, 344, 345, 371, 
	344, 345, 372, 344, 345, 373, 344, 345, 
	374, 344, 345, 375, 344, 345, 376, 344, 
	345, 377, 344, 345, 375, 375, 375, 375, 
	344, 345, 378, 344, 345, 379, 344, 345, 
	380, 344, 345, 381, 344, 345, 382, 344, 
	345, 383, 344, 345, 384, 344, 345, 385, 
	344, 345, 386, 344, 345, 387, 344, 388, 
	345, 344, 389, 345, 344, 345, 370, 344, 
	345, 390, 344, 345, 391, 344, 345, 392, 
	344, 345, 393, 344, 345, 375, 344, 345, 
	394, 344, 345, 395, 344, 345, 396, 344, 
	345, 397, 344, 345, 398, 344, 345, 399, 
	344, 345, 389, 344, 400, 401, 400, 0, 
	404, 403, 405, 406, 403, 402, 0, 408, 
	409, 407, 0, 408, 407, 404, 410, 408, 
	409, 410, 407, 404, 411, 412, 413, 414, 
	415, 416, 417, 418, 419, 420, 421, 422, 
	423, 424, 425, 411, 0, 84, 426, 83, 
	84, 427, 83, 84, 428, 83, 84, 429, 
	83, 84, 430, 83, 84, 431, 83, 84, 
	432, 83, 84, 430, 430, 430, 430, 83, 
	84, 433, 83, 84, 434, 83, 84, 435, 
	83, 84, 436, 83, 84, 437, 83, 84, 
	438, 83, 84, 439, 83, 84, 440, 83, 
	84, 441, 83, 84, 442, 83, 443, 84, 
	83, 444, 84, 83, 84, 109, 83, 84, 
	445, 83, 84, 446, 83, 84, 447, 83, 
	84, 448, 83, 84, 430, 83, 84, 449, 
	83, 84, 450, 451, 83, 84, 452, 83, 
	84, 453, 83, 84, 454, 83, 84, 455, 
	83, 84, 444, 83, 84, 456, 83, 84, 
	457, 83, 84, 458, 83, 84, 459, 83, 
	84, 460, 83, 84, 461, 83, 84, 462, 
	83, 84, 463, 83, 84, 464, 83, 84, 
	465, 83, 84, 466, 83, 84, 467, 83, 
	84, 450, 83, 468, 0
]

class << self
	attr_accessor :_lexer_trans_targs
	private :_lexer_trans_targs, :_lexer_trans_targs=
end
self._lexer_trans_targs = [
	0, 2, 4, 4, 5, 15, 17, 31, 
	34, 37, 42, 69, 72, 94, 41, 168, 
	173, 321, 3, 6, 7, 8, 9, 8, 
	8, 9, 8, 10, 10, 10, 11, 10, 
	10, 10, 11, 12, 13, 14, 4, 14, 
	15, 4, 16, 18, 19, 20, 21, 22, 
	23, 24, 25, 26, 27, 28, 29, 30, 
	373, 32, 33, 33, 4, 16, 35, 36, 
	4, 35, 34, 36, 38, 39, 40, 41, 
	31, 43, 44, 45, 46, 47, 48, 49, 
	50, 51, 52, 51, 52, 52, 4, 53, 
	67, 327, 332, 335, 331, 348, 353, 54, 
	55, 56, 57, 58, 59, 60, 61, 62, 
	63, 64, 65, 66, 4, 68, 4, 4, 
	5, 15, 17, 31, 34, 37, 42, 69, 
	72, 94, 41, 168, 173, 321, 70, 71, 
	73, 74, 75, 76, 77, 78, 79, 80, 
	79, 80, 80, 4, 81, 82, 83, 84, 
	85, 86, 87, 88, 89, 90, 91, 92, 
	93, 68, 95, 96, 97, 98, 99, 100, 
	101, 102, 103, 104, 105, 106, 107, 108, 
	109, 108, 109, 109, 4, 110, 124, 132, 
	137, 149, 111, 112, 113, 114, 115, 116, 
	117, 118, 119, 120, 121, 122, 123, 4, 
	125, 126, 127, 128, 129, 130, 131, 68, 
	133, 134, 135, 136, 138, 139, 140, 141, 
	142, 143, 144, 145, 146, 147, 148, 150, 
	151, 155, 152, 153, 154, 156, 157, 158, 
	159, 160, 161, 162, 163, 164, 165, 166, 
	167, 169, 170, 171, 172, 174, 175, 251, 
	176, 177, 178, 179, 180, 181, 182, 183, 
	182, 183, 183, 4, 184, 198, 199, 204, 
	212, 215, 203, 227, 232, 185, 186, 187, 
	188, 189, 190, 191, 192, 193, 194, 195, 
	196, 197, 4, 68, 200, 201, 202, 203, 
	198, 205, 206, 207, 208, 209, 210, 211, 
	213, 214, 216, 217, 218, 219, 220, 221, 
	222, 223, 224, 225, 226, 228, 229, 230, 
	231, 233, 234, 238, 235, 236, 237, 239, 
	240, 241, 242, 243, 244, 245, 246, 247, 
	248, 249, 250, 252, 253, 254, 255, 256, 
	257, 258, 259, 260, 261, 262, 263, 264, 
	265, 266, 267, 268, 269, 270, 271, 272, 
	271, 272, 272, 4, 273, 287, 288, 293, 
	296, 292, 309, 314, 274, 275, 276, 277, 
	278, 279, 280, 281, 282, 283, 284, 285, 
	286, 4, 68, 289, 290, 291, 292, 287, 
	294, 295, 297, 298, 299, 300, 301, 302, 
	303, 304, 305, 306, 307, 308, 310, 311, 
	312, 313, 315, 316, 317, 318, 319, 320, 
	321, 322, 323, 325, 326, 324, 322, 323, 
	324, 322, 325, 326, 5, 15, 17, 31, 
	34, 37, 42, 69, 72, 94, 41, 168, 
	173, 321, 328, 329, 330, 331, 67, 333, 
	334, 336, 337, 338, 339, 340, 341, 342, 
	343, 344, 345, 346, 347, 349, 350, 351, 
	352, 354, 355, 360, 356, 357, 358, 359, 
	361, 362, 363, 364, 365, 366, 367, 368, 
	369, 370, 371, 372, 0
]

class << self
	attr_accessor :_lexer_trans_actions
	private :_lexer_trans_actions, :_lexer_trans_actions=
end
self._lexer_trans_actions = [
	43, 0, 0, 54, 3, 1, 0, 29, 
	1, 29, 29, 29, 29, 29, 29, 29, 
	29, 35, 0, 0, 0, 7, 135, 48, 
	0, 102, 9, 5, 45, 130, 45, 0, 
	33, 122, 33, 33, 0, 11, 106, 0, 
	0, 114, 25, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 57, 0, 110, 23, 0, 27, 
	118, 27, 51, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 57, 140, 0, 54, 0, 72, 33, 
	84, 84, 84, 84, 84, 84, 84, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 15, 15, 31, 126, 
	60, 57, 31, 63, 57, 63, 63, 63, 
	63, 63, 63, 63, 63, 66, 0, 0, 
	0, 0, 0, 0, 0, 0, 57, 140, 
	0, 54, 0, 81, 84, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 21, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 57, 
	140, 0, 54, 0, 69, 33, 84, 84, 
	84, 84, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 13, 
	0, 0, 0, 0, 0, 0, 0, 13, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 57, 140, 
	0, 54, 0, 75, 33, 84, 84, 84, 
	84, 84, 84, 84, 84, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 17, 17, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 57, 140, 
	0, 54, 0, 78, 33, 84, 84, 84, 
	84, 84, 84, 84, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 19, 19, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 37, 37, 54, 37, 87, 0, 
	0, 39, 0, 0, 93, 90, 41, 96, 
	90, 96, 96, 96, 96, 96, 96, 96, 
	96, 99, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0
]

class << self
	attr_accessor :_lexer_eof_actions
	private :_lexer_eof_actions, :_lexer_eof_actions=
end
self._lexer_eof_actions = [
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
	43, 43, 43, 43, 43, 43
]

class << self
	attr_accessor :lexer_start
end
self.lexer_start = 1;
class << self
	attr_accessor :lexer_first_final
end
self.lexer_first_final = 373;
class << self
	attr_accessor :lexer_error
end
self.lexer_error = 0;

class << self
	attr_accessor :lexer_en_main
end
self.lexer_en_main = 1;


# line 128 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
      end
 
      def scan(data)
        data = (data + "\n%_FEATURE_END_%").unpack("c*") # Explicit EOF simplifies things considerably
        eof = pe = data.length
 
        @line_number = 1
        @last_newline = 0
 
        
# line 739 "lib/gherkin/rb_lexer/it.rb"
begin
	p ||= 0
	pe ||= data.length
	cs = lexer_start
end

# line 138 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
        
# line 748 "lib/gherkin/rb_lexer/it.rb"
begin
	_klen, _trans, _keys, _acts, _nacts = nil
	_goto_level = 0
	_resume = 10
	_eof_trans = 15
	_again = 20
	_test_eof = 30
	_out = 40
	while true
	_trigger_goto = false
	if _goto_level <= 0
	if p == pe
		_goto_level = _test_eof
		next
	end
	if cs == 0
		_goto_level = _out
		next
	end
	end
	if _goto_level <= _resume
	_keys = _lexer_key_offsets[cs]
	_trans = _lexer_index_offsets[cs]
	_klen = _lexer_single_lengths[cs]
	_break_match = false
	
	begin
	  if _klen > 0
	     _lower = _keys
	     _upper = _keys + _klen - 1

	     loop do
	        break if _upper < _lower
	        _mid = _lower + ( (_upper - _lower) >> 1 )

	        if data[p] < _lexer_trans_keys[_mid]
	           _upper = _mid - 1
	        elsif data[p] > _lexer_trans_keys[_mid]
	           _lower = _mid + 1
	        else
	           _trans += (_mid - _keys)
	           _break_match = true
	           break
	        end
	     end # loop
	     break if _break_match
	     _keys += _klen
	     _trans += _klen
	  end
	  _klen = _lexer_range_lengths[cs]
	  if _klen > 0
	     _lower = _keys
	     _upper = _keys + (_klen << 1) - 2
	     loop do
	        break if _upper < _lower
	        _mid = _lower + (((_upper-_lower) >> 1) & ~1)
	        if data[p] < _lexer_trans_keys[_mid]
	          _upper = _mid - 2
	        elsif data[p] > _lexer_trans_keys[_mid+1]
	          _lower = _mid + 2
	        else
	          _trans += ((_mid - _keys) >> 1)
	          _break_match = true
	          break
	        end
	     end # loop
	     break if _break_match
	     _trans += _klen
	  end
	end while false
	_trans = _lexer_indicies[_trans]
	cs = _lexer_trans_targs[_trans]
	if _lexer_trans_actions[_trans] != 0
		_acts = _lexer_trans_actions[_trans]
		_nacts = _lexer_actions[_acts]
		_acts += 1
		while _nacts > 0
			_nacts -= 1
			_acts += 1
			case _lexer_actions[_acts - 1]
when 0 then
# line 9 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          @content_start = p
          @current_line = @line_number
          @start_col = p - @last_newline - "#{@keyword}:".length
        		end
when 1 then
# line 15 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          @current_line = @line_number
          @start_col = p - @last_newline
        		end
when 2 then
# line 20 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          @content_start = p
        		end
when 3 then
# line 24 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          @docstring_content_type_start = p
        		end
when 4 then
# line 27 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          @docstring_content_type_end = p
        		end
when 5 then
# line 31 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          con = unindent(@start_col, utf8_pack(data[@content_start...@next_keyword_start-1]).sub(/(\r?\n)?([\t ])*\Z/, '').gsub(/\\"\\"\\"/, '"""'))
          con_type = utf8_pack(data[@docstring_content_type_start...@docstring_content_type_end]).strip
          @listener.doc_string(con_type, con, @current_line) 
        		end
when 6 then
# line 36 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          p = store_keyword_content(:feature, data, p, eof)
        		end
when 7 then
# line 40 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          p = store_keyword_content(:background, data, p, eof)
        		end
when 8 then
# line 44 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          p = store_keyword_content(:scenario, data, p, eof)
        		end
when 9 then
# line 48 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          p = store_keyword_content(:scenario_outline, data, p, eof)
        		end
when 10 then
# line 52 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          p = store_keyword_content(:examples, data, p, eof)
        		end
when 11 then
# line 56 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          con = utf8_pack(data[@content_start...p]).strip
          @listener.step(@keyword, con, @current_line)
        		end
when 12 then
# line 61 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          con = utf8_pack(data[@content_start...p]).strip
          @listener.comment(con, @line_number)
          @keyword_start = nil
        		end
when 13 then
# line 67 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          con = utf8_pack(data[@content_start...p]).strip
          @listener.tag(con, @current_line)
          @keyword_start = nil
        		end
when 14 then
# line 73 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          @line_number += 1
        		end
when 15 then
# line 77 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          @last_newline = p + 1
        		end
when 16 then
# line 81 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          @keyword_start ||= p
        		end
when 17 then
# line 85 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          @keyword = utf8_pack(data[@keyword_start...p]).sub(/:$/,'')
          @keyword_start = nil
        		end
when 18 then
# line 90 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          @next_keyword_start = p
        		end
when 19 then
# line 94 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          p = p - 1
          current_row = []
          @current_line = @line_number
        		end
when 20 then
# line 100 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          @content_start = p
        		end
when 21 then
# line 104 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          con = utf8_pack(data[@content_start...p]).strip
          current_row << con.gsub(/\\\|/, "|").gsub(/\\n/, "\n").gsub(/\\\\/, "\\")
        		end
when 22 then
# line 109 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          @listener.row(current_row, @current_line)
        		end
when 23 then
# line 113 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          if cs < lexer_first_final
            content = current_line_content(data, p)
            raise Gherkin::Lexer::LexingError.new("Lexing error on line %d: '%s'. See http://wiki.github.com/cucumber/gherkin/lexingerror for more information." % [@line_number, content])
          else
            @listener.eof
          end
        		end
# line 992 "lib/gherkin/rb_lexer/it.rb"
			end # action switch
		end
	end
	if _trigger_goto
		next
	end
	end
	if _goto_level <= _again
	if cs == 0
		_goto_level = _out
		next
	end
	p += 1
	if p != pe
		_goto_level = _resume
		next
	end
	end
	if _goto_level <= _test_eof
	if p == eof
	__acts = _lexer_eof_actions[cs]
	__nacts =  _lexer_actions[__acts]
	__acts += 1
	while __nacts > 0
		__nacts -= 1
		__acts += 1
		case _lexer_actions[__acts - 1]
when 23 then
# line 113 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
		begin

          if cs < lexer_first_final
            content = current_line_content(data, p)
            raise Gherkin::Lexer::LexingError.new("Lexing error on line %d: '%s'. See http://wiki.github.com/cucumber/gherkin/lexingerror for more information." % [@line_number, content])
          else
            @listener.eof
          end
        		end
# line 1031 "lib/gherkin/rb_lexer/it.rb"
		end # eof action switch
	end
	if _trigger_goto
		next
	end
end
	end
	if _goto_level <= _out
		break
	end
	end
	end

# line 139 "/Users/ahellesoy/scm/gherkin/tasks/../ragel/i18n/it.rb.rl"
      end

      def unindent(startcol, text)
        text.gsub(/^[\t ]{0,#{startcol}}/, "")
      end

      def store_keyword_content(event, data, p, eof)
        end_point = (!@next_keyword_start or (p == eof)) ? p : @next_keyword_start
        content = unindent(@start_col + 2, utf8_pack(data[@content_start...end_point])).rstrip
        content_lines = content.split("\n")
        name = content_lines.shift || ""
        name.strip!
        description = content_lines.join("\n")
        @listener.__send__(event, @keyword, name, description, @current_line)
        @next_keyword_start ? @next_keyword_start - 1 : p
      ensure
        @next_keyword_start = nil
      end
      
      def current_line_content(data, p)
        rest = data[@last_newline..-1]
        utf8_pack(rest[0..rest.index(10)||-1]).strip # 10 is \n
      end

      if (RUBY_VERSION =~ /^1\.9/)
        def utf8_pack(array)
          array.pack("c*").force_encoding("UTF-8")
        end
      else
        def utf8_pack(array)
          array.pack("c*")
        end
      end
    end
  end
end
