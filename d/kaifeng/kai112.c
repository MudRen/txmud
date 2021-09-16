// Room: /u/w/wangs/b/kai112.c

inherit ROOM;

void create()
{
	set("short", "香粉屋");
	set("long", @LONG
这里是开封城最大的一家胭脂店。此处陈放着应有尽有的各
类胭脂香粉，品种特别全。开封城的大姑娘，小媳妇都爱到这里
来逛，也有一些小伙子经常光顾这里，买一些胭脂香粉送给心爱
的姑娘。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai106",
]));
        set("objects",([
        __DIR__"npc/fengboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
