#ifndef __SCHEMES_H__
#define __SCHEMES_H__

#include "sol.h"

struct scheme {
	int width; /* column alignment */
	int height; /* height of a card */
	int overlap; /* no of lines to draw when cards overlapp */
	char** card[_NUM_CARDS_internal];
	char** facedown;
	char** placeholder;
	char** halfstack; /* left half of stack (for spider) */
	int* halfcard; /* byte offset of right half of cards (for spider) */
};

#define ULCARD(s, r) (char*[]) \
{"╭───╮",\
 "│"s" "r"│",\
 "│ "s" │",\
 "╰───╯"}
#define RULCARD(s, r) \
	ULCARD("\033[91m" s "\033[39m", r)
#define BULCARD(s, r) \
	ULCARD("\033[37m" s "\033[39m", r)
#define USCARD(c) (char*[]){c}

const struct scheme unicode_large_mono = {
	.width = 5,
	.height = 4,
	.overlap = 2,
	.card = {
		[NO_CARD] = (char*[]){"     ","     ","     ","     "},
		[CLU_A] = ULCARD("♣","A"), [DIA_A] = ULCARD("♦","A"),
		[HEA_A] = ULCARD("♥","A"), [SPA_A] = ULCARD("♠","A"),
		[CLU_2] = ULCARD("♣","2"), [DIA_2] = ULCARD("♦","2"),
		[HEA_2] = ULCARD("♥","2"), [SPA_2] = ULCARD("♠","2"),
		[CLU_3] = ULCARD("♣","3"), [DIA_3] = ULCARD("♦","3"),
		[HEA_3] = ULCARD("♥","3"), [SPA_3] = ULCARD("♠","3"),
		[CLU_4] = ULCARD("♣","4"), [DIA_4] = ULCARD("♦","4"),
		[HEA_4] = ULCARD("♥","4"), [SPA_4] = ULCARD("♠","4"),
		[CLU_5] = ULCARD("♣","5"), [DIA_5] = ULCARD("♦","5"),
		[HEA_5] = ULCARD("♥","5"), [SPA_5] = ULCARD("♠","5"),
		[CLU_6] = ULCARD("♣","6"), [DIA_6] = ULCARD("♦","6"),
		[HEA_6] = ULCARD("♥","6"), [SPA_6] = ULCARD("♠","6"),
		[CLU_7] = ULCARD("♣","7"), [DIA_7] = ULCARD("♦","7"),
		[HEA_7] = ULCARD("♥","7"), [SPA_7] = ULCARD("♠","7"),
		[CLU_8] = ULCARD("♣","8"), [DIA_8] = ULCARD("♦","8"),
		[HEA_8] = ULCARD("♥","8"), [SPA_8] = ULCARD("♠","8"),
		[CLU_9] = ULCARD("♣","9"), [DIA_9] = ULCARD("♦","9"),
		[HEA_9] = ULCARD("♥","9"), [SPA_9] = ULCARD("♠","9"),
		[CLU_X] = ULCARD("♣","X"), [DIA_X] = ULCARD("♦","X"),
		[HEA_X] = ULCARD("♥","X"), [SPA_X] = ULCARD("♠","X"),
		[CLU_J] = ULCARD("♣","J"), [DIA_J] = ULCARD("♦","J"),
		[HEA_J] = ULCARD("♥","J"), [SPA_J] = ULCARD("♠","J"),
		[CLU_Q] = ULCARD("♣","Q"), [DIA_Q] = ULCARD("♦","Q"),
		[HEA_Q] = ULCARD("♥","Q"), [SPA_Q] = ULCARD("♠","Q"),
		[CLU_K] = ULCARD("♣","K"), [DIA_K] = ULCARD("♦","K"),
		[HEA_K] = ULCARD("♥","K"), [SPA_K] = ULCARD("♠","K"),
	},
	.facedown = (char*[]){
		"╭───╮",
		"│▚▚▚│",
		"│▚▚▚│",
		"╰───╯"
	},
	.placeholder = (char*[]){
		"╭╌╌╌╮",
		"╎   ╎",
		"╎   ╎",
		"╰╌╌╌╯"
	},
	.halfstack = (char*[]) {
		"╭─",
		"│▚",
		"│▚",
		"╰─"
	},
	.halfcard = (int[]){6, 6, 4, 6},
};
const struct scheme unicode_large_color = {
	.width = 5,
	.height = 4,
	.overlap = 2,
	.card = {
		[NO_CARD] = (char*[]){"     ","     ","     ","     "},
		[CLU_A] = BULCARD("♣","A"), [DIA_A] = RULCARD("♦","A"),
		[HEA_A] = RULCARD("♥","A"), [SPA_A] = BULCARD("♠","A"),
		[CLU_2] = BULCARD("♣","2"), [DIA_2] = RULCARD("♦","2"),
		[HEA_2] = RULCARD("♥","2"), [SPA_2] = BULCARD("♠","2"),
		[CLU_3] = BULCARD("♣","3"), [DIA_3] = RULCARD("♦","3"),
		[HEA_3] = RULCARD("♥","3"), [SPA_3] = BULCARD("♠","3"),
		[CLU_4] = BULCARD("♣","4"), [DIA_4] = RULCARD("♦","4"),
		[HEA_4] = RULCARD("♥","4"), [SPA_4] = BULCARD("♠","4"),
		[CLU_5] = BULCARD("♣","5"), [DIA_5] = RULCARD("♦","5"),
		[HEA_5] = RULCARD("♥","5"), [SPA_5] = BULCARD("♠","5"),
		[CLU_6] = BULCARD("♣","6"), [DIA_6] = RULCARD("♦","6"),
		[HEA_6] = RULCARD("♥","6"), [SPA_6] = BULCARD("♠","6"),
		[CLU_7] = BULCARD("♣","7"), [DIA_7] = RULCARD("♦","7"),
		[HEA_7] = RULCARD("♥","7"), [SPA_7] = BULCARD("♠","7"),
		[CLU_8] = BULCARD("♣","8"), [DIA_8] = RULCARD("♦","8"),
		[HEA_8] = RULCARD("♥","8"), [SPA_8] = BULCARD("♠","8"),
		[CLU_9] = BULCARD("♣","9"), [DIA_9] = RULCARD("♦","9"),
		[HEA_9] = RULCARD("♥","9"), [SPA_9] = BULCARD("♠","9"),
		[CLU_X] = BULCARD("♣","X"), [DIA_X] = RULCARD("♦","X"),
		[HEA_X] = RULCARD("♥","X"), [SPA_X] = BULCARD("♠","X"),
		[CLU_J] = BULCARD("♣","J"), [DIA_J] = RULCARD("♦","J"),
		[HEA_J] = RULCARD("♥","J"), [SPA_J] = BULCARD("♠","J"),
		[CLU_Q] = BULCARD("♣","Q"), [DIA_Q] = RULCARD("♦","Q"),
		[HEA_Q] = RULCARD("♥","Q"), [SPA_Q] = BULCARD("♠","Q"),
		[CLU_K] = BULCARD("♣","K"), [DIA_K] = RULCARD("♦","K"),
		[HEA_K] = RULCARD("♥","K"), [SPA_K] = BULCARD("♠","K"),
	},
	.facedown = (char*[]){
		"╭───╮",
		"│\033[94m▚▚▚\033[39m│",
		"│\033[94m▚▚▚\033[39m│",
		"╰───╯"
	},
	.placeholder = (char*[]){
		"╭╌╌╌╮",
		"╎   ╎",
		"╎   ╎",
		"╰╌╌╌╯"
	},
	.halfstack = (char*[]) {
		"╭─",
		"│\033[94m▚\033[39m",
		"│\033[94m▚\033[39m",
		"╰─"
	},
	.halfcard = (int[]){6, 16, 4, 6},
};
const struct scheme unicode_small_mono = {
	.width = 2,
	.height = 1,
	.overlap = 1,
	.card = {
		[NO_CARD] = (char*[]){"  "},
		[CLU_A] = USCARD("🃑 "), [DIA_A] = USCARD("🃁 "),
		[HEA_A] = USCARD("🂱 "), [SPA_A] = USCARD("🂡 "),
		[CLU_2] = USCARD("🃒 "), [DIA_2] = USCARD("🃂 "),
		[HEA_2] = USCARD("🂲 "), [SPA_2] = USCARD("🂢 "),
		[CLU_3] = USCARD("🃓 "), [DIA_3] = USCARD("🃃 "),
		[HEA_3] = USCARD("🂳 "), [SPA_3] = USCARD("🂣 "),
		[CLU_4] = USCARD("🃔 "), [DIA_4] = USCARD("🃄 "),
		[HEA_4] = USCARD("🂴 "), [SPA_4] = USCARD("🂤 "),
		[CLU_5] = USCARD("🃕 "), [DIA_5] = USCARD("🃅 "),
		[HEA_5] = USCARD("🂵 "), [SPA_5] = USCARD("🂥 "),
		[CLU_6] = USCARD("🃖 "), [DIA_6] = USCARD("🃆 "),
		[HEA_6] = USCARD("🂶 "), [SPA_6] = USCARD("🂦 "),
		[CLU_7] = USCARD("🃗 "), [DIA_7] = USCARD("🃇 "),
		[HEA_7] = USCARD("🂷 "), [SPA_7] = USCARD("🂧 "),
		[CLU_8] = USCARD("🃘 "), [DIA_8] = USCARD("🃈 "),
		[HEA_8] = USCARD("🂸 "), [SPA_8] = USCARD("🂨 "),
		[CLU_9] = USCARD("🃙 "), [DIA_9] = USCARD("🃉 "),
		[HEA_9] = USCARD("🂹 "), [SPA_9] = USCARD("🂩 "),
		[CLU_X] = USCARD("🃚 "), [DIA_X] = USCARD("🃊 "),
		[HEA_X] = USCARD("🂺 "), [SPA_X] = USCARD("🂪 "),
		[CLU_J] = USCARD("🃛 "), [DIA_J] = USCARD("🃋 "),
		[HEA_J] = USCARD("🂻 "), [SPA_J] = USCARD("🂫 "),
		[CLU_Q] = USCARD("🃝 "), [DIA_Q] = USCARD("🃍 "),
		[HEA_Q] = USCARD("🂽 "), [SPA_Q] = USCARD("🂭 "),
		[CLU_K] = USCARD("🃞 "), [DIA_K] = USCARD("🃎 "),
		[HEA_K] = USCARD("🂾 "), [SPA_K] = USCARD("🂮 "),
	},
	.facedown = (char*[]){"🂠 "},
	.placeholder = (char*[]){"❲❳"},
	.halfstack = (char*[]){"🂠 "},
	.halfcard = (int[]){0},
};
#endif
