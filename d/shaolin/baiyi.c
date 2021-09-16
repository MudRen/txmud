// Room: /d/shaolin/baiyi.c

inherit ROOM;

void create()
{
	set("short", "白衣殿");
	set("long", @LONG
这里是少林寺的白衣殿，正中供奉着白衣观世音的圣像，只
见她面目慈祥，左手持净瓶，右手挥杨柳，端坐在金毛吼上的莲
花宝座上，庄严气派。左右是善财童子和小龙女。大殿中香烟氲
氤。从这里向西是过道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rroad5",
]));
        set(SAFE_ENV, 1);

	set("objects", ([
	__DIR__"npc/huiming" : 1,
]));

	setup();
	replace_program(ROOM);
}
