// Room: /d/tangmen/xiaowu.c

inherit ROOM;

void create()
{
        set("short", "药庄小屋");
	set("long", @LONG
迎门的墙上挂着一幅人物图，靠墙是一张梳妆台，一个穿素
色服装的妇人面墙而坐在椅子上，一手拿着一页纸，一手抚摩着
一本放再梳妆台上的旧书。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"yz_xiaoyuan",
]));

	set("objects", ([
	__DIR__"npc/tangfuren" : 1,
]));

        set("item_desc", ([
       "纸":"似乎上面写了几行字，一角被手压住，看不到。\n",
       "paper":"似乎上面写了几行字，一角被手压住，看不到。\n",
       "字":"莲子心中苦，X X 腹内酸。\n",
       "zi":"莲子心中苦，X X 腹内酸。\n",
       "book":"书页很黄，看来很久远了，因为被手压着，看不清书上写了什么。\n",
       "旧书":"书页很黄，看来很久远了，因为被手压着，看不清书上写了什么。\n",
]));

	setup();
	replace_program(ROOM);
}

